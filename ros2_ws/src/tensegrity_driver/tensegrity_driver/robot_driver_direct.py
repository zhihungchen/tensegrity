#!/usr/bin/env python3
"""
ROS2 direct motor driver only.

Features:
- subscribes to /motor_cmd
- reads UDP packets to keep Arduino addresses and sensor states updated
- sends direct motor commands only
- publishes control_msg for monitoring
- stops all motors on shutdown
"""

import os
from pathlib import Path

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from std_msgs.msg import Header

from tensegrity_core.robot_config import RobotConfig
from tensegrity_core.robot_core import TensegrityCore
from tensegrity_core.udp_client import UdpClient

from tensegrity_interfaces.msg import (
    Motor,
    Info,
    Sensor,
    Imu,
    TensegrityStamped,
    MotorCommand,
)


class TensegrityDirectDriverNode(Node):
    def __init__(self, cfg: RobotConfig = None):
        super().__init__("tensegrity_direct_driver")

        self.cfg = cfg if cfg is not None else RobotConfig()
        self.core = None

        # Keep only the most recent direct command
        self._pending_motor_cmd = None

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
            MotorCommand,
            "/motor_cmd",
            self._motor_cmd_callback,
            qos,
        )

        calibration_file, states_path = self._resolve_resource_paths()

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

        self.timer = self.create_timer(1.0 / 50.0, self._timer_callback)

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
        self.get_logger().info(
            f"Received /motor_cmd: motor_id={motor_id}, speed={speed}"
        )

    def _build_control_msg(self):
        c = self.core

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
            m.position = float(c.pos[i])
            m.target = 0.0
            m.speed = float(c.current_motor_speeds[i])
            m.done = False
            m.error = 0.0
            m.d_error = 0.0
            m.cum_error = 0.0
            m.encoder_counts = int(c.encoder_counts[i])
            m.encoder_length = float(c.encoder_length[i])
            msg.motors.append(m)

        for i in range(c.num_sensors):
            s = Sensor()
            s.id = i
            s.length = float(c.length[i])
            s.capacitance = float(c.cap[i])
            msg.sensors.append(s)

        for rod in range(3):
            imu = Imu()
            imu.id = rod
            imu.ax = float(c.accelerometer[rod][0])
            imu.ay = float(c.accelerometer[rod][1])
            imu.az = float(c.accelerometer[rod][2])
            imu.gx = float(c.gyroscope[rod][0])
            imu.gy = float(c.gyroscope[rod][1])
            imu.gz = float(c.gyroscope[rod][2])
            msg.imus.append(imu)

        return msg

    def _timer_callback(self):
        if self.core.quitting:
            return

        try:
            # keyboard / bus events
            intent = self.core.bus.snapshot()

            if intent.stop:
                self.get_logger().info("STOP requested")
                self._pending_motor_cmd = None
                self.core.keep_going = False
                self.core.stop_all()

            if intent.armed_toggle:
                self.core.armed = not self.core.armed
                self.get_logger().info(f"Armed: {self.core.armed}")
                if not self.core.armed:
                    self._pending_motor_cmd = None
                    self.core.stop_all()

            if intent.quit:
                self.get_logger().info("QUIT requested")
                self.core.stop_all()
                self.core.quitting = True
                rclpy.shutdown()
                return

            self.core.bus.clear_edge_flags()

            # Always read UDP first so addresses / sensors stay fresh
            self.core.read()

            # Manual keyboard jog still allowed if you want it
            self.core.apply_manual_jog(intent)

            # Direct ROS motor command path only
            if self.core.keep_going and self.core.armed and self._pending_motor_cmd is not None:
                motor_id, speed = self._pending_motor_cmd

                target_arduino = self.core.motor_to_arduino(motor_id)
                target_addr = self.core.addresses[target_arduino]

                if target_addr is None:
                    self.get_logger().warn(
                        f"Arduino {target_arduino} for motor {motor_id} not ready yet. "
                        f"addresses={self.core.addresses}"
                    )
                else:
                    self.core.set_motor_speed(motor_id, speed)
                    self.get_logger().info(
                        f"Sent direct command: motor_id={motor_id}, speed={speed}, "
                        f"target_arduino={target_arduino}, addr={target_addr}"
                    )

            self.control_pub.publish(self._build_control_msg())

        except Exception as e:
            self.get_logger().error(f"Direct driver error: {e}")
            self.core.keep_going = False
            try:
                self.core.stop_all()
            except Exception:
                pass

    def destroy_node(self):
        try:
            if self.core is not None:
                self.get_logger().info("Stopping all motors before shutdown")
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