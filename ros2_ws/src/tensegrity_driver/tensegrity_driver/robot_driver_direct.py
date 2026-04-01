#!/usr/bin/env python3
"""
ROS2 direct motor driver only.

Features:
- subscribes to /motor_cmd
- optional timed motor sequence from JSON: explicit motor_command_json_file, or
  auto-load under package motor_scripts/ when scan is on (see motor_command_json_dir default)
  (tries basename param; if default motor_command.json is missing, uses motor_command.example.json)
- tensegrity_core background RX updates state; timer publishes via get_latest_state()
- direct mode: /motor_cmd + optional motor_script JSON (script runs in its own thread)
- control modes: idle / direct / gait (this node only uses idle + direct; gait reserved)
- publishes control_msg for monitoring
- stops all motors on shutdown

JSON format (stdlib json): top-level object with required "commands" array.
Optional "defaults": { "motor_id": int, "hold_s": float }.
Each commands[] entry is either a number (speed, uses defaults) or an object
with required "speed" and optional "motor_id", "hold_s".

Incoming /motor_cmd updates _pending_motor_cmd immediately; the JSON scheduler
still advances on its clock and overwrites pending at the next segment boundary.

Example:
  {"defaults": {"motor_id": 2, "hold_s": 0.5}, "commands": [30, {"speed": 0}]}
"""

import json
import os
import threading
import time
from pathlib import Path
from typing import List, Optional, Tuple
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from std_msgs.msg import Header

from tensegrity_core.robot_config import RobotConfig
from tensegrity_core.robot_core import TensegrityCore
from tensegrity_core.udp_client import UdpClient
from tensegrity_core.fake_udp_client import FakeUdpClient

from tensegrity_driver.control_mode import ControlMode, ControlModeHolder

from tensegrity_interfaces.msg import (
    Motor,
    Info,
    Sensor,
    Imu,
    TensegrityStamped,
    MotorCommand,
)

JsonMotorSegment = Tuple[int, float, float]


def _default_motor_scripts_directory() -> str:
    """
    Default folder for motor JSON scripts:
    - Installed: share/tensegrity_driver/motor_scripts
    - Source tree: tensegrity_driver/motor_scripts (next to the inner package dir)
    """
    try:
        from ament_index_python.packages import get_package_share_directory

        share = Path(get_package_share_directory("tensegrity_driver"))
        return str(share / "motor_scripts")
    except Exception:
        pass
    # robot_driver_direct.py -> tensegrity_driver/tensegrity_driver/ -> repo motor_scripts/
    return str(Path(__file__).resolve().parent.parent / "motor_scripts")


def _pick_motor_json_in_dir(json_dir: Path, basename: str) -> Optional[Path]:
    """
    Resolve which JSON file to load under json_dir.
    Use basename if that file exists. If basename is the default motor_command.json and it
    is missing, use motor_command.example.json (shipped in motor_scripts/) so a plain
    `ros2 run ... robot_driver_direct` runs a script without renaming files.
    """
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


def _load_motor_command_json(
    path: str, num_motors: int
) -> List[JsonMotorSegment]:
    """Parse motor command JSON into [(motor_id, speed, hold_s), ...]."""
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
            h = def_hold
        elif isinstance(item, dict):
            if "speed" not in item:
                raise ValueError(f"commands[{i}] missing 'speed'")
            mid = int(item.get("motor_id", def_motor))
            spd = float(item["speed"])
            h = float(item["hold_s"]) if "hold_s" in item else def_hold
        else:
            raise ValueError(f"commands[{i}] must be a number or object")

        if not (0 <= mid < num_motors):
            raise ValueError(
                f"commands[{i}]: motor_id={mid} out of range for num_motors={num_motors}"
            )
        if h < 0.0:
            raise ValueError(f"commands[{i}]: hold_s must be >= 0")
        out.append((mid, spd, h))

    return out


class TensegrityDirectDriverNode(Node):
    def __init__(self, cfg: RobotConfig = None):
        super().__init__("tensegrity_direct_driver")

        self.cfg = cfg if cfg is not None else RobotConfig()
        self.core = None

        # Keep only the most recent direct command
        self._pending_motor_cmd = None

        # Optional JSON timed sequence (playback in _script_worker thread)
        self._json_active = False
        self._json_loop = False
        self._json_segments: Optional[List[JsonMotorSegment]] = None
        self._script_stop = threading.Event()
        self._script_thread: Optional[threading.Thread] = None
        self._mode_holder = ControlModeHolder(ControlMode.IDLE)

        qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
        )

        self.control_pub = self.create_publisher(
            TensegrityStamped,
            self.cfg.ros_control_topic,
            qos,
        )

        self.motor_cmd_sub = self.create_subscription(
            MotorCommand, # message type
            "/motor_cmd", # topic name
            self._motor_cmd_callback,
            qos, # qos profile
        )

        calibration_file, states_path = self._resolve_resource_paths()

        self.declare_parameter("use_fake_udp", False)
        self.declare_parameter("fake_udp_hz", 50.0)
        self.declare_parameter("motor_command_json_file", "")
        self.declare_parameter("motor_command_json_loop", False)
        self.declare_parameter(
            "motor_command_json_dir", _default_motor_scripts_directory()
        )
        self.declare_parameter("motor_command_json_basename", "motor_command.json")
        self.declare_parameter("motor_command_json_scan", True)

        use_fake_udp = bool(self.get_parameter("use_fake_udp").value)
        fake_udp_hz = float(self.get_parameter("fake_udp_hz").value)
        jf = self.get_parameter("motor_command_json_file").value
        json_file = jf.strip() if isinstance(jf, str) else ""
        self._json_loop = bool(self.get_parameter("motor_command_json_loop").value)
        json_scan = bool(self.get_parameter("motor_command_json_scan").value)
        jdir = self.get_parameter("motor_command_json_dir").value
        json_dir = jdir.strip() if isinstance(jdir, str) else _default_motor_scripts_directory()
        jbase = self.get_parameter("motor_command_json_basename").value
        json_basename = (
            jbase.strip() if isinstance(jbase, str) and jbase.strip() else "motor_command.json"
        )

        if use_fake_udp:
            udp = FakeUdpClient(
                num_arduino=self.cfg.num_arduino,
                port=self.cfg.UDP_PORT,
                hz=fake_udp_hz,
            )
            self.get_logger().info(
                f"Using FakeUdpClient at {fake_udp_hz:.1f} Hz for simulation"
            )
        else:
            udp = UdpClient(
                self.cfg.UDP_IP,
                self.cfg.UDP_PORT,
                self.cfg.recv_buf_size,
            )

        self.core = TensegrityCore(self.cfg, udp_client=udp)
        self.core.initialize(
            mode="basic",   # change to "ssh" if you are running without GUI/X11
            calibration_file=calibration_file,
            states_path=states_path,   # harmless even if we do not use gait
        )

        # Direct mode safety defaults
        self.core.keep_going = True
        self.core.quitting = False
        self.core.armed = True

        self.core.start()

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
            except (OSError, ValueError, json.JSONDecodeError) as e:
                self.get_logger().error(f"Failed to load motor JSON script: {e}")
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

        self.get_logger().info("Direct driver initialized. Listening on /motor_cmd")

    def _resolve_resource_paths(self):
        from ament_index_python.packages import get_package_share_directory

        share_dir = get_package_share_directory("tensegrity_driver")
        pkg_root = Path(share_dir)

        calibration_file = str(pkg_root / "calibration" / "calibration_charles.xls")
        states_path = str(pkg_root / "states" / "quasi_static.json")

        # Fallback for source-tree runs
        if not os.path.isfile(calibration_file):
            calibration_file = str(
                Path(__file__).resolve().parents[1]
                / "calibration"
                / "calibration_charles.xls"
            )

        if not os.path.isfile(states_path):
            states_path = str(
                Path(__file__).resolve().parents[1]
                / "states"
                / "quasi_static.json"
            )

        return calibration_file, states_path

    def _motor_cmd_callback(self, msg: MotorCommand):
        motor_id = int(msg.motor_id)
        speed = float(msg.speed)

        if not (0 <= motor_id < self.cfg.num_motors):
            self.get_logger().error(
                f"Invalid motor_id={motor_id}, expected 0..{self.cfg.num_motors - 1}"
            )
            return

        self._pending_motor_cmd = (motor_id, speed)
        self.get_logger().debug(
            f"Received /motor_cmd: motor_id={motor_id}, speed={speed}"
        )


    def _update_control_mode_from_core(self) -> None:
        """Map armed/keep_going to idle vs direct. Clears motor/script state when entering idle."""
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
            self._pending_motor_cmd = None
            self._json_active = False
            self.core.stop_all()

    def _dispatch_motor_speeds(
        self, speeds: List[int], required_mode: ControlMode
    ) -> bool:
        """
        Single gate for core.send_motor_speeds from this node.
        Executors (timer, script thread, future gait) must use this—not core.send_motor_speeds.
        Sends only if the current mode equals required_mode.
        """
        if self._mode_holder.get() != required_mode:
            return False
        self.core.send_motor_speeds(speeds)
        return True

    def _script_worker(self) -> None:
        """motor_script JSON timing in a separate thread; sends only when mode == DIRECT."""
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
                self._pending_motor_cmd = None
                try:
                    self.core.stop_all()
                except Exception:
                    pass
                self.get_logger().info("Motor JSON script finished; motors stopped.")
                idx = 0
                deadline = 0.0
                continue
            mid, spd, hold = segs[idx]
            seg_display = idx + 1
            idx += 1
            deadline = now + hold
            if self._mode_holder.get() != ControlMode.DIRECT:
                continue
            if not self._json_active:
                continue
            try:
                snap = self.core.get_latest_state()
                speeds = list(snap.current_motor_speeds)
                speeds[mid] = int(spd)
                if not self._dispatch_motor_speeds(speeds, ControlMode.DIRECT):
                    continue
                self.get_logger().info(
                    f"JSON segment {seg_display}/{len(segs)}: "
                    f"motor_id={mid}, speed={spd}, hold_s={hold}"
                )
            except Exception as e:
                self.get_logger().error(f"Motor script send error: {e}")


    def _build_control_msg(self):
        c = self.core
        snap = c.get_latest_state()

        msg = TensegrityStamped()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = ""

        info = Info()
        info.min_length = int(min(255, c.min_length))
        info.range = int(min(255, c.RANGE))
        info.max_range = 0
        info.min_range = 0
        info.range024 = 0
        info.range135 = 0
        info.max_speed = int(max(-128, min(127, c.max_speed)))
        info.tol = c.tol
        info.low_tol = c.low_tol
        info.p = c.P
        info.i = c.I
        info.d = c.D
        info.dist_weight = 0.0
        info.ang_weight = 0.0
        info.prog_weight = 0.0
        msg.info = info

        for i in range(c.num_motors):
            m = Motor()
            m.id = int(max(-128, min(127, i)))
            m.position = float(snap.pos[i])
            m.target = 0.0
            m.speed = float(snap.current_motor_speeds[i])
            m.done = False
            m.error = 0.0
            m.d_error = 0.0
            m.cum_error = 0.0
            m.encoder_counts = int(snap.encoder_counts[i])
            m.encoder_length = float(snap.encoder_length[i])
            msg.motors.append(m)

        for i in range(c.num_sensors):
            s = Sensor()
            s.id = i
            s.length = float(snap.length[i])
            s.capacitance = float(snap.cap[i])
            msg.sensors.append(s)

        for rod in range(3):
            imu = Imu()
            imu.id = rod
            imu.ax = float(snap.accelerometer[rod][0])
            imu.ay = float(snap.accelerometer[rod][1])
            imu.az = float(snap.accelerometer[rod][2])
            imu.gx = float(snap.gyroscope[rod][0])
            imu.gy = float(snap.gyroscope[rod][1])
            imu.gz = float(snap.gyroscope[rod][2])
            msg.imus.append(imu)

        return msg

    def _timer_callback(self):
        if self.core.quitting:
            return

        try:
            intent = self.core.bus.snapshot()

            if intent.stop:
                self.get_logger().info("STOP requested")
                self._pending_motor_cmd = None
                self._json_active = False
                self.core.keep_going = False
                self.core.stop_all()

            if intent.armed_toggle:
                self.core.armed = not self.core.armed
                self.get_logger().info(f"Armed: {self.core.armed}")
                if not self.core.armed:
                    self._pending_motor_cmd = None
                    self._json_active = False
                    self.core.stop_all()

            if intent.quit:
                self.get_logger().info("QUIT requested")
                self.core.stop_all()
                self.core.quitting = True
                rclpy.shutdown()
                return

            self.core.bus.clear_edge_flags()

            self._update_control_mode_from_core()

            mode = self._mode_holder.get()
            if mode == ControlMode.DIRECT:
                self.core.apply_manual_jog(intent)

            if (
                mode == ControlMode.DIRECT
                and self.core.keep_going
                and self.core.armed
                and self._pending_motor_cmd is not None
            ):
                motor_id, speed = self._pending_motor_cmd
                if not self.core.is_ready():
                    self.get_logger().warn(
                        f"Arduino for motor {motor_id} not ready yet; "
                        f"addresses={self.core.get_latest_state().addresses}"
                    )
                else:
                    try:
                        snap = self.core.get_latest_state()
                        speeds = list(snap.current_motor_speeds)
                        speeds[motor_id] = int(speed)
                        if self._dispatch_motor_speeds(speeds, ControlMode.DIRECT):
                            self.get_logger().debug(
                                f"Sent direct command: motor_id={motor_id}, speed={speed}"
                            )
                    except Exception as ex:
                        self.get_logger().warn(f"Direct motor send failed: {ex}")

            self.control_pub.publish(self._build_control_msg())

        except Exception as e:
            self.get_logger().error(f"Direct driver error: {e}")
            self.core.keep_going = False
            try:
                self.core.stop_all()
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
                self.get_logger().info("Stopping RX and motors before shutdown")
                self.core.stop()
                self.core.stop_all()
        except Exception as e:
            self.get_logger().warn(f"Failed to stop motors cleanly: {e}")

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