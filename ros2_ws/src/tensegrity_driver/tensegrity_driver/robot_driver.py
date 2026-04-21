#!/usr/bin/env python3
"""
ROS2 gait driver with switchable real/sim backends.

The gait/action logic remains in this node. Only the final motor output transport
changes between the real hardware backend and the existing simulator bridge.
"""

from typing import List

import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy

from tensegrity_core.fake_udp_client import FakeUdpClient
from tensegrity_core.robot_config import RobotConfig
from tensegrity_core.robot_core import TensegrityCore
from tensegrity_core.udp_client import UdpClient
from tensegrity_driver.control_mode import ControlMode, ControlModeHolder
from tensegrity_driver.control_msg_utils import (
    append_motor,
    attach_empty_trajectory,
    build_common_control_msg,
    resolve_resource_paths,
)
from tensegrity_driver.driver_backends import RealRobotBackend, SimBridgeBackend
from tensegrity_interfaces.msg import Action, State, TensegrityStamped


class TensegrityDriverNode(Node):
    def __init__(self, cfg: RobotConfig = None):
        super().__init__("tensegrity_driver")
        self.cfg = cfg if cfg is not None else RobotConfig()
        self.core = None
        self._backend = None
        self._backend_name = "real"
        self._last_action_msg = None
        self._mode_holder = ControlModeHolder(ControlMode.IDLE)

        self.declare_parameter("backend", "real")
        self.declare_parameter("sim_motor_speeds_topic", "/sim_motor_speeds")
        self.declare_parameter("sim_control_topic", self.cfg.ros_control_topic)
        self.declare_parameter("use_fake_udp", False)
        self.declare_parameter("fake_udp_hz", 50.0)

        self._backend_name = str(self.get_parameter("backend").value).strip().lower()
        if self._backend_name not in {"real", "sim"}:
            raise ValueError("backend must be 'real' or 'sim'")

        sim_motor_speeds_topic = str(
            self.get_parameter("sim_motor_speeds_topic").value
        ).strip()
        sim_control_topic = str(self.get_parameter("sim_control_topic").value).strip()
        use_fake_udp = bool(self.get_parameter("use_fake_udp").value)
        fake_udp_hz = float(self.get_parameter("fake_udp_hz").value)

        qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
        )
        self.control_pub = None
        self.state_pub = self.create_publisher(State, "/state_msg", qos)
        self.action_sub = self.create_subscription(
            Action, "/action_msg", self._action_callback, qos
        )

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

        self.get_logger().info(
            f"Driver initialized with backend={self._backend_name}; press s to stop, q to quit"
        )
        self.timer = self.create_timer(1.0 / 50.0, self._timer_callback)

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
        else:
            udp = UdpClient(self.cfg.UDP_IP, self.cfg.UDP_PORT, self.cfg.recv_buf_size)

        core = TensegrityCore(self.cfg, udp_client=udp)
        core.initialize(
            mode="ssh",
            calibration_file=calibration_file,
            states_path=states_path,
        )
        return core

    def _action_callback(self, msg: Action):
        self._last_action_msg = msg
        if not msg.actions:
            return
        action_name = msg.actions[0]
        core = self.core
        if core is None or core.controller is None:
            return
        action_to_states = self._get_action_to_states()
        if action_name in action_to_states:
            states = np.array(action_to_states[action_name], dtype=float)
            if states.shape[1] == core.num_motors:
                core.set_states(states)

    def _get_action_to_states(self):
        num = self.cfg.num_motors
        roll = [
            [1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
            [1.0, 1.0, 0.1, 1.0, 1.0, 0.1],
            [0.0, 1.0, 1.0, 0.0, 1.0, 0.1],
        ]
        if num != 6:
            roll = [([1.0] * num)] * 3
        return {
            "roll": roll,
            "cw": [
                [1.0] * num,
                [1.0] * num,
                [0.0, 0.0, 0.0, 1.0, 0.0, 1.0][:num],
                [0.0, 0.0, 0.0, 0.0, 0.0, 0.7][:num],
                [0.0, 0.0, 0.7, 0.0, 1.0, 1.0][:num],
            ],
            "ccw": [
                [1.0] * num,
                [1.0] * num,
                [1.0, 1.0, 1.0, 0.0, 1.0, 1.0][:num],
                [1.0, 0.0, 1.0, 0.0, 1.0, 1.0][:num],
                [0.0, 0.0, 0.0, 0.0, 0.0, 0.0][:num],
            ],
        }

    def _update_control_mode_from_core(self) -> None:
        """Idle when disarmed or paused; GAIT when armed and gait controller is active."""
        if self.core.quitting:
            return
        desired = ControlMode.IDLE
        if (
            self.core.keep_going
            and self.core.armed
            and self.core.controller is not None
        ):
            desired = ControlMode.GAIT
        prev = self._mode_holder.get()
        if prev == desired:
            return
        self._mode_holder.set(desired)
        if desired == ControlMode.IDLE:
            self._backend.stop_all()

    def _dispatch_motor_speeds(
        self, speeds: List[int], required_mode: ControlMode
    ) -> bool:
        if self._mode_holder.get() != required_mode:
            return False
        self._backend.send_motor_speeds(speeds)
        return True

    def _build_control_msg(self):
        c = self.core
        snap = c.get_latest_state()
        ctl = c.controller
        gait_step = ctl.state if ctl is not None else (c.state if c.state is not None else 0)
        msg = build_common_control_msg(self, c, snap)
        for i in range(c.num_motors):
            append_motor(
                msg,
                motor_id=i,
                position=snap.pos[i],
                target=float(c.states[gait_step, i]) if c.states is not None else 0.0,
                speed=float(ctl.command[i] * c.max_speed) if ctl is not None else 0.0,
                done=bool(ctl.done[i]) if ctl is not None else False,
                error=float(ctl.error[i]) if ctl is not None else 0.0,
                d_error=float(ctl.d_error[i]) if ctl is not None else 0.0,
                cum_error=float(ctl.cum_error[i]) if ctl is not None else 0.0,
                encoder_counts=snap.encoder_counts[i],
                encoder_length=snap.encoder_length[i],
            )
        attach_empty_trajectory(msg)
        return msg

    def _build_state_msg(
        self, prev_action="", reverse_the_gait=False, bar_height_changed=False
    ):
        msg = State()
        msg.prev_action = prev_action
        msg.reverse_the_gait = reverse_the_gait
        msg.bar_height_changed = bar_height_changed
        return msg

    def _timer_callback(self):
        if self.core.quitting:
            return
        try:
            intent = self.core.bus.snapshot()
            if intent.stop:
                self.core.keep_going = False
                self._backend.stop_all()
            if intent.armed_toggle:
                self.core.armed = not self.core.armed
                self.get_logger().info("Armed: %s" % self.core.armed)
            if intent.quit:
                self._backend.stop_all()
                self.core.quitting = True
                rclpy.shutdown()
                return
            self.core.bus.clear_edge_flags()

            self._update_control_mode_from_core()
            mode = self._mode_holder.get()

            if self._backend_name == "real":
                self.core.apply_manual_jog(intent)

            if (
                mode == ControlMode.GAIT
                and self.core.keep_going
                and self.core.armed
                and self.core.controller is not None
                and (
                    (self._backend_name == "real" and self._backend.is_ready())
                    or (
                        self._backend_name == "sim"
                        and self._backend.latest_control_msg() is not None
                    )
                )
            ):
                snap = self.core.get_latest_state()
                _, _ = self.core.controller.step(
                    snap.pos,
                    length=snap.length,
                    cap=snap.cap,
                )
                self.core.state = self.core.controller.state
                speeds = [
                    int(round(self.core.controller.command[i] * self.core.max_speed))
                    for i in range(self.core.num_motors)
                ]
                self._dispatch_motor_speeds(speeds, ControlMode.GAIT)

            if self.control_pub is not None and self._backend.should_publish_control():
                self.control_pub.publish(self._build_control_msg())
            if self.state_pub.get_subscription_count() > 0:
                self.state_pub.publish(self._build_state_msg())
        except Exception as e:
            self.get_logger().error("Driver error: %s" % e)
            self.core.keep_going = False
            self._backend.stop_all()

    def destroy_node(self):
        try:
            if self.core is not None:
                self.get_logger().info("Stopping RX and motors before shutdown")
                self._backend.stop_all()
                self._backend.stop()
        except Exception as e:
            self.get_logger().warn("Shutdown cleanup: %s" % e)
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = TensegrityDriverNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()