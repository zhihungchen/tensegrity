#!/usr/bin/env python3
"""
ROS2 gait driver: wraps TensegrityCore, publishes control_msg and state_msg,
subscribes to /action_msg and pushes actions into the core.

UDP RX runs in core.start() background thread; this timer does not call core.read().
Gait motor vectors go through _dispatch_motor_speeds(..., ControlMode.GAIT) only.
"""
import os
from pathlib import Path
from typing import List

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from std_msgs.msg import Header
from tensegrity_core.robot_config import RobotConfig
from tensegrity_core.robot_core import TensegrityCore
from tensegrity_core.udp_client import UdpClient
from tensegrity_driver.control_mode import ControlMode, ControlModeHolder
from tensegrity_interfaces.msg import (
    Motor,
    Info,
    Sensor,
    Imu,
    TensegrityStamped,
    State,
    Action,
    Trajectory,
)
import numpy as np


class TensegrityDriverNode(Node):
    def __init__(self, cfg: RobotConfig = None):
        super().__init__('tensegrity_driver')
        self.cfg = cfg if cfg is not None else RobotConfig()
        self.core = None
        self._last_action_msg = None
        self._mode_holder = ControlModeHolder(ControlMode.IDLE)

        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.RELIABLE, history=HistoryPolicy.KEEP_LAST)
        self.control_pub = self.create_publisher(
            TensegrityStamped,
            self.cfg.ros_control_topic,
            qos,
        )
        self.state_pub = self.create_publisher(State, '/state_msg', qos)
        self.action_sub = self.create_subscription(Action, '/action_msg', self._action_callback, qos)

        share_dir = self.get_package_share_directory('tensegrity_driver')
        pkg_root = Path(share_dir)
        calibration_file = str(pkg_root / 'calibration' / 'calibration_charles.xls')
        states_path = str(pkg_root / 'states' / 'quasi_static.json')
        if not os.path.isfile(calibration_file):
            calibration_file = str(Path(__file__).resolve().parents[1] / 'calibration' / 'calibration_charles.xls')
        if not os.path.isfile(states_path):
            states_path = str(Path(__file__).resolve().parents[1] / 'states' / 'quasi_static.json')

        udp = UdpClient(self.cfg.UDP_IP, self.cfg.UDP_PORT, self.cfg.recv_buf_size)
        self.core = TensegrityCore(self.cfg, udp_client=udp)
        self.core.initialize(
            mode='ssh',
            calibration_file=calibration_file,
            states_path=states_path,
        )
        self.get_logger().info('Driver initialized with core; press s to stop, q to quit')

        self.core.start()

        self.timer = self.create_timer(1.0 / 50.0, self._timer_callback)

    def get_package_share_directory(self, package_name):
        from ament_index_python.packages import get_package_share_directory
        return get_package_share_directory(package_name)

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
            'roll': roll,
            'cw': [
                [1.0] * num,
                [1.0] * num,
                [0.0, 0.0, 0.0, 1.0, 0.0, 1.0][:num],
                [0.0, 0.0, 0.0, 0.0, 0.0, 0.7][:num],
                [0.0, 0.0, 0.7, 0.0, 1.0, 1.0][:num],
            ],
            'ccw': [
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
            self.core.stop_all()

    def _dispatch_motor_speeds(
        self, speeds: List[int], required_mode: ControlMode
    ) -> bool:
        """
        Only gate for core.send_motor_speeds from this node.
        Gait stepping must use required_mode=GAIT so direct driver cannot conflict.
        """
        if self._mode_holder.get() != required_mode:
            return False
        self.core.send_motor_speeds(speeds)
        return True

    def _build_control_msg(self):
        c = self.core
        snap = c.get_latest_state()
        ctl = c.controller
        gait_step = ctl.state if ctl is not None else (c.state if c.state is not None else 0)
        msg = TensegrityStamped()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = ''
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
            m.target = (
                float(c.states[gait_step, i]) if c.states is not None else 0.0
            )
            m.speed = (
                float(ctl.command[i] * c.max_speed) if ctl is not None else 0.0
            )
            m.done = bool(ctl.done[i]) if ctl is not None else False
            m.error = float(ctl.error[i]) if ctl is not None else 0.0
            m.d_error = float(ctl.d_error[i]) if ctl is not None else 0.0
            m.cum_error = float(ctl.cum_error[i]) if ctl is not None else 0.0
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
        # Perception overlays (COM / planned path) expect `trajectory` to exist; populate when MPC data exists.
        traj = Trajectory()
        traj.trajectory_segment = 0
        msg.trajectory = traj
        return msg

    def _build_state_msg(self, prev_action='', reverse_the_gait=False, bar_height_changed=False):
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
                self.core.stop_all()
            if intent.armed_toggle:
                self.core.armed = not self.core.armed
                self.get_logger().info('Armed: %s' % self.core.armed)
            if intent.quit:
                self.core.stop_all()
                self.core.quitting = True
                rclpy.shutdown()
                return
            self.core.bus.clear_edge_flags()

            self._update_control_mode_from_core()
            mode = self._mode_holder.get()

            self.core.apply_manual_jog(intent)

            if (
                mode == ControlMode.GAIT
                and self.core.keep_going
                and self.core.is_ready()
                and self.core.armed
                and self.core.controller is not None
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

            self.control_pub.publish(self._build_control_msg())
            if self.state_pub.get_subscription_count() > 0 or self.state_pub.get_publisher_count() > 0:
                self.state_pub.publish(self._build_state_msg())
        except Exception as e:
            self.get_logger().error('Driver error: %s' % e)
            self.core.keep_going = False
            self.core.stop_all()

    def destroy_node(self):
        try:
            if self.core is not None:
                self.get_logger().info('Stopping RX and motors before shutdown')
                self.core.stop()
                self.core.stop_all()
        except Exception as e:
            self.get_logger().warn('Shutdown cleanup: %s' % e)
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


if __name__ == '__main__':
    main()