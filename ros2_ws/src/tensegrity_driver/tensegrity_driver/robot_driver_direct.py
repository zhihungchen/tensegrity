#!/usr/bin/env python3
"""
ROS2 direct motor driver with switchable real/sim backends.

Features:
- subscribes to /motor_speeds as the low-level command topic
- optional timed motor sequence from JSON
- uses TensegrityCore for shared driver state and keyboard control
- supports backend=real (TensegrityCore UDP) or backend=sim (ROS bridge topic)
- publishes /control_msg only in real mode
"""

import json
import threading
import time
from pathlib import Path
from typing import List, Optional, Tuple

import rclpy
from rclpy.node import Node
from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy
from std_msgs.msg import Float64MultiArray

from tensegrity_core.fake_udp_client import FakeUdpClient
from tensegrity_core.robot_config import RobotConfig
from tensegrity_core.robot_core import TensegrityCore
from tensegrity_core.udp_client import UdpClient
from tensegrity_driver.control_mode import ControlMode, ControlModeHolder
from tensegrity_driver.control_msg_utils import (
    append_motor,
    build_common_control_msg,
    copy_speeds_with_update,
    resolve_resource_paths,
)
from tensegrity_driver.driver_backends import RealRobotBackend, SimBridgeBackend
from tensegrity_interfaces.msg import TensegrityStamped


JsonMotorSegment = Tuple[int, float, float]


def _default_motor_scripts_directory() -> str:
    try:
        from ament_index_python.packages import get_package_share_directory

        share = Path(get_package_share_directory("tensegrity_driver"))
        return str(share / "motor_scripts")
    except Exception:
        return str(Path(__file__).resolve().parent.parent / "motor_scripts")


def _pick_motor_json_in_dir(json_dir: Path, basename: str) -> Optional[Path]:
    d = json_dir.expanduser()
    if not d.is_dir():
        return None
    primary = d / basename
    if primary.is_file():
        return primary
    if basename == "motor_command.json":
        alt = d / "motor_command.example.json"
        if alt.is_file():
            return alt
    return None


def _load_motor_command_json(path: str, num_motors: int) -> List[JsonMotorSegment]:
    p = Path(path).expanduser()
    if not p.is_file():
        raise FileNotFoundError(f"motor JSON path not found: {p}")

    with p.open(encoding="utf-8") as fp:
        data = json.load(fp)

    if not isinstance(data, dict):
        raise ValueError("JSON root must be an object")

    raw_defaults = data.get("defaults") or {}
    if not isinstance(raw_defaults, dict):
        raise ValueError("'defaults' must be an object")
    def_motor = int(raw_defaults.get("motor_id", 2))
    def_hold = float(raw_defaults.get("hold_s", 0.5))

    raw_cmds = data.get("commands")
    if raw_cmds is None:
        raise ValueError("JSON must contain 'commands' array")
    if not isinstance(raw_cmds, list) or len(raw_cmds) == 0:
        raise ValueError("'commands' must be a non-empty array")

    out: List[JsonMotorSegment] = []
    for i, item in enumerate(raw_cmds):
        if isinstance(item, (int, float)):
            mid = def_motor
            spd = float(item)
            hold = def_hold
        elif isinstance(item, dict):
            if "speed" not in item:
                raise ValueError(f"commands[{i}] missing 'speed'")
            mid = int(item.get("motor_id", def_motor))
            spd = float(item["speed"])
            hold = float(item["hold_s"]) if "hold_s" in item else def_hold
        else:
            raise ValueError(f"commands[{i}] must be a number or object")

        if not (0 <= mid < num_motors):
            raise ValueError(
                f"commands[{i}]: motor_id={mid} out of range for num_motors={num_motors}"
            )
        if hold < 0.0:
            raise ValueError(f"commands[{i}]: hold_s must be >= 0")
        out.append((mid, spd, hold))

    return out


class TensegrityDirectDriverNode(Node):
    def __init__(self, cfg: RobotConfig = None):
        super().__init__("tensegrity_direct_driver")

        self.cfg = cfg if cfg is not None else RobotConfig()
        self.core: Optional[TensegrityCore] = None
        self._backend = None
        self._backend_name = "real"
        self._pending_motor_speeds: Optional[List[int]] = None

        self._json_active = False
        self._json_loop = False
        self._json_segments: Optional[List[JsonMotorSegment]] = None
        self._script_stop = threading.Event()
        self._script_thread: Optional[threading.Thread] = None
        self._mode_holder = ControlModeHolder(ControlMode.IDLE)

        self.declare_parameter("backend", "real")
        self.declare_parameter("motor_speeds_topic", "/motor_speeds")
        self.declare_parameter("sim_motor_speeds_topic", "/sim_motor_speeds")
        self.declare_parameter("sim_control_topic", self.cfg.ros_control_topic)
        self.declare_parameter("use_fake_udp", False)
        self.declare_parameter("fake_udp_hz", 50.0)
        self.declare_parameter("motor_command_json_file", "")
        self.declare_parameter("motor_command_json_loop", False)
        self.declare_parameter(
            "motor_command_json_dir", _default_motor_scripts_directory()
        )
        self.declare_parameter("motor_command_json_basename", "motor_command.json")
        self.declare_parameter("motor_command_json_scan", True)

        self._backend_name = str(self.get_parameter("backend").value).strip().lower()
        if self._backend_name not in {"real", "sim"}:
            raise ValueError("backend must be 'real' or 'sim'")

        motor_speeds_topic = str(self.get_parameter("motor_speeds_topic").value).strip()
        sim_motor_speeds_topic = str(
            self.get_parameter("sim_motor_speeds_topic").value
        ).strip()
        sim_control_topic = str(self.get_parameter("sim_control_topic").value).strip()
        use_fake_udp = bool(self.get_parameter("use_fake_udp").value)
        fake_udp_hz = float(self.get_parameter("fake_udp_hz").value)
        jf = self.get_parameter("motor_command_json_file").value
        json_file = jf.strip() if isinstance(jf, str) else ""
        self._json_loop = bool(self.get_parameter("motor_command_json_loop").value)
        json_scan = bool(self.get_parameter("motor_command_json_scan").value)
        jdir = self.get_parameter("motor_command_json_dir").value
        json_dir = (
            jdir.strip() if isinstance(jdir, str) else _default_motor_scripts_directory()
        )
        jbase = self.get_parameter("motor_command_json_basename").value
        json_basename = (
            jbase.strip() if isinstance(jbase, str) and jbase.strip() else "motor_command.json"
        )

        qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
        )

        self.motor_speeds_sub = self.create_subscription(
            Float64MultiArray,
            motor_speeds_topic,
            self._motor_speeds_callback,
            qos,
        )

        self.control_pub = None

        calibration_file, states_path = resolve_resource_paths()
        self.core = self._build_core(
            calibration_file=calibration_file,
            states_path=states_path,
            use_fake_udp=use_fake_udp or self._backend_name == "sim",
            fake_udp_hz=fake_udp_hz,
        )

        if self._backend_name == "real":
            self._backend = RealRobotBackend(self.core)
            self._backend.start()
            self.control_pub = self.create_publisher(
                TensegrityStamped,
                self.cfg.ros_control_topic,
                qos,
            )
        else:
            self._backend = SimBridgeBackend(
                self,
                num_motors=self.cfg.num_motors,
                motor_topic=sim_motor_speeds_topic,
                control_topic=sim_control_topic,
                mirror_core=self.core,
            )
            if sim_motor_speeds_topic == motor_speeds_topic:
                self.get_logger().warn(
                    "sim_motor_speeds_topic matches motor_speeds_topic; "
                    "use distinct topics to avoid command loops."
                )

        self.timer = self.create_timer(1.0 / 50.0, self._timer_callback)

        path_to_load: Optional[str] = None
        if json_file:
            path_to_load = json_file
        elif json_scan:
            picked = _pick_motor_json_in_dir(Path(json_dir), json_basename)
            if picked is not None:
                path_to_load = str(picked.resolve())

        if path_to_load:
            try:
                self._json_segments = _load_motor_command_json(
                    path_to_load, self.cfg.num_motors
                )
                self._json_active = True
                self.get_logger().info(
                    f"Motor JSON script loaded ({len(self._json_segments)} segment(s)): {path_to_load}"
                )
            except (OSError, ValueError, json.JSONDecodeError) as exc:
                self.get_logger().error(f"Failed to load motor JSON script: {exc}")
                self._json_segments = None
                self._json_active = False
        elif json_scan and not json_file:
            self.get_logger().info(
                f"Motor JSON: no script in {Path(json_dir).expanduser()} "
                f"(tried {json_basename!r}"
                + (
                    " then motor_command.example.json"
                    if json_basename == "motor_command.json"
                    else ""
                )
                + "); direct mode without JSON. Add a file, set motor_command_json_file, or "
                "motor_command_json_scan:=false."
            )

        if self._json_active and self._json_segments:
            self._script_stop.clear()
            self._script_thread = threading.Thread(
                target=self._script_worker,
                daemon=True,
                name="motor_script",
            )
            self._script_thread.start()

        self.get_logger().info(
            f"Direct driver initialized with backend={self._backend_name}; "
            f"listening on {motor_speeds_topic}"
        )

    def _build_core(
        self,
        *,
        calibration_file: str,
        states_path: str,
        use_fake_udp: bool,
        fake_udp_hz: float,
    ) -> TensegrityCore:
        if use_fake_udp:
            udp = FakeUdpClient(
                num_arduino=self.cfg.num_arduino,
                port=self.cfg.UDP_PORT,
                hz=fake_udp_hz,
            )
            self.get_logger().info(
                f"Using FakeUdpClient at {fake_udp_hz:.1f} Hz for shared driver state"
            )
        else:
            udp = UdpClient(
                self.cfg.UDP_IP,
                self.cfg.UDP_PORT,
                self.cfg.recv_buf_size,
            )

        core = TensegrityCore(self.cfg, udp_client=udp)
        core.initialize(
            mode="basic",
            calibration_file=calibration_file,
            states_path=states_path,
        )
        core.keep_going = True
        core.quitting = False
        core.armed = True
        return core

    def _motor_speeds_callback(self, msg: Float64MultiArray) -> None:
        data = list(msg.data)
        if len(data) < self.cfg.num_motors:
            self.get_logger().error(
                f"Invalid /motor_speeds length={len(data)}, expected at least {self.cfg.num_motors}"
            )
            return

        self._pending_motor_speeds = [
            int(round(float(data[i]))) for i in range(self.cfg.num_motors)
        ]
        self.get_logger().debug(f"Received /motor_speeds: {self._pending_motor_speeds}")

    def _update_control_mode_from_core(self) -> None:
        if self.core.quitting:
            return
        desired = (
            ControlMode.DIRECT
            if (self.core.keep_going and self.core.armed)
            else ControlMode.IDLE
        )
        prev = self._mode_holder.get()
        if prev == desired:
            return
        self._mode_holder.set(desired)
        if desired == ControlMode.IDLE:
            self._pending_motor_speeds = None
            self._json_active = False
            self._backend.stop_all()

    def _dispatch_motor_speeds(
        self, speeds: List[int], required_mode: ControlMode
    ) -> bool:
        if self._mode_holder.get() != required_mode:
            return False
        self._backend.send_motor_speeds(speeds)
        return True

    def _script_worker(self) -> None:
        segs = self._json_segments
        if not segs:
            return
        idx = 0
        deadline = 0.0
        while not self._script_stop.is_set():
            if not self._json_active:
                time.sleep(0.05)
                continue
            if self._mode_holder.get() != ControlMode.DIRECT:
                time.sleep(0.02)
                continue
            now = time.monotonic()
            if now < deadline:
                time.sleep(min(0.02, max(0.0, deadline - now)))
                continue
            if idx >= len(segs):
                if self._json_loop:
                    idx = 0
                    deadline = now
                    continue
                self._json_active = False
                self._pending_motor_speeds = None
                try:
                    self._backend.stop_all()
                except Exception:
                    pass
                self.get_logger().info("Motor JSON script finished; motors stopped.")
                idx = 0
                deadline = 0.0
                continue

            motor_id, speed, hold = segs[idx]
            seg_display = idx + 1
            idx += 1
            deadline = now + hold
            if self._mode_holder.get() != ControlMode.DIRECT or not self._json_active:
                continue
            try:
                snap = self.core.get_latest_state()
                speeds = copy_speeds_with_update(
                    snap.current_motor_speeds, motor_id, speed
                )
                self._pending_motor_speeds = list(speeds)
                if not self._dispatch_motor_speeds(speeds, ControlMode.DIRECT):
                    continue
                self.get_logger().info(
                    f"JSON segment {seg_display}/{len(segs)}: "
                    f"motor_id={motor_id}, speed={speed}, hold_s={hold}"
                )
            except Exception as exc:
                self.get_logger().error(f"Motor script send error: {exc}")

    def _build_control_msg(self):
        snap = self.core.get_latest_state()
        msg = build_common_control_msg(self, self.core, snap)
        for i in range(self.core.num_motors):
            append_motor(
                msg,
                motor_id=i,
                position=snap.pos[i],
                target=0.0,
                speed=snap.current_motor_speeds[i],
                done=False,
                error=0.0,
                d_error=0.0,
                cum_error=0.0,
                encoder_counts=snap.encoder_counts[i],
                encoder_length=snap.encoder_length[i],
            )
        return msg

    def _timer_callback(self):
        if self.core.quitting:
            return

        try:
            intent = self.core.bus.snapshot()

            if intent.stop:
                self.get_logger().info("STOP requested")
                self._pending_motor_speeds = None
                self._json_active = False
                self.core.keep_going = False
                self._backend.stop_all()

            if intent.armed_toggle:
                self.core.armed = not self.core.armed
                self.get_logger().info(f"Armed: {self.core.armed}")
                if not self.core.armed:
                    self._pending_motor_speeds = None
                    self._json_active = False
                    self._backend.stop_all()

            if intent.quit:
                self.get_logger().info("QUIT requested")
                self._backend.stop_all()
                self.core.quitting = True
                rclpy.shutdown()
                return

            self.core.bus.clear_edge_flags()
            self._update_control_mode_from_core()

            if self._backend_name == "real" and self._mode_holder.get() == ControlMode.DIRECT:
                self.core.apply_manual_jog(intent)

            if (
                self._mode_holder.get() == ControlMode.DIRECT
                and self.core.keep_going
                and self.core.armed
                and self._pending_motor_speeds is not None
            ):
                if self._backend_name == "real" and not self._backend.is_ready():
                    self.get_logger().warn(
                        f"Real backend not ready yet; addresses={self.core.get_latest_state().addresses}"
                    )
                else:
                    try:
                        if self._dispatch_motor_speeds(
                            self._pending_motor_speeds, ControlMode.DIRECT
                        ):
                            self.get_logger().debug(
                                f"Sent direct speeds: {self._pending_motor_speeds}"
                            )
                    except Exception as exc:
                        self.get_logger().warn(f"Direct motor send failed: {exc}")

            if self.control_pub is not None and self._backend.should_publish_control():
                self.control_pub.publish(self._build_control_msg())

        except Exception as exc:
            self.get_logger().error(f"Direct driver error: {exc}")
            self.core.keep_going = False
            try:
                self._backend.stop_all()
            except Exception:
                pass

    def destroy_node(self):
        self._script_stop.set()
        try:
            if self._script_thread is not None and self._script_thread.is_alive():
                self._script_thread.join(timeout=1.0)
        except Exception:
            pass
        try:
            if self.core is not None:
                self.get_logger().info("Stopping motors before shutdown")
                self._backend.stop_all()
                self._backend.stop()
        except Exception as exc:
            self.get_logger().warn(f"Failed to stop motors cleanly: {exc}")

        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = TensegrityDirectDriverNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()