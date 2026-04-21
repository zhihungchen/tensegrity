#!/usr/bin/env python3
"""
ROS2 ↔ MuJoCo UDP simulator bridge (Stage 0).

Run the simulator separately with ROS disabled, e.g.:
  python tensegrity_udp_simulator.py path/to/model.xml --no-ros

This node:
  - Binds UDP local_bind_port (default 2392), sends motor commands to simulator:command_port.
  - Receives Arduino-style sensor packets and publishes tensegrity_interfaces/TensegrityStamped.
  - Subscribes to TensegrityStamped (motor speeds) or std_msgs/Float64MultiArray (6 speeds).

Mirrors the UDP contract used by run_tensegrity_hybrid_mppi_simulator.TensegrityRobot.
"""

from __future__ import annotations

import json
import os
import socket
import threading
from typing import List, Optional

import numpy as np
import rclpy
from ament_index_python.packages import get_package_share_directory
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray

from tensegrity_interfaces.msg import Imu, Info, Motor, Sensor, TensegrityStamped, Trajectory


class UdpSimulatorBridgeNode(Node):
    """Bridges ROS2 topics to the MuJoCo UDP hardware-emulation protocol."""

    def __init__(self) -> None:
        super().__init__('udp_simulator_bridge')

        self.declare_parameter('simulator_host', '127.0.0.1')
        self.declare_parameter('command_port', 2390)
        self.declare_parameter('local_bind_host', '127.0.0.1')
        self.declare_parameter('local_bind_port', 2392)
        self.declare_parameter('offset', 3)
        self.declare_parameter('publish_rate_hz', 100.0)
        self.declare_parameter('use_float64_motor_topic', False)
        self.declare_parameter('motor_speeds_topic', 'motor_speeds')
        self.declare_parameter('control_sub_topic', 'control_cmd')
        self.declare_parameter('control_pub_topic', 'control_msg')
        self.declare_parameter('calibration_json', '')

        host = self.get_parameter('simulator_host').get_parameter_value().string_value
        self._cmd_port = self.get_parameter('command_port').get_parameter_value().integer_value
        bind_host = self.get_parameter('local_bind_host').get_parameter_value().string_value
        bind_port = self.get_parameter('local_bind_port').get_parameter_value().integer_value
        self._offset = self.get_parameter('offset').get_parameter_value().integer_value
        rate = self.get_parameter('publish_rate_hz').get_parameter_value().double_value
        use_float = self.get_parameter('use_float64_motor_topic').get_parameter_value().bool_value
        motor_topic = self.get_parameter('motor_speeds_topic').get_parameter_value().string_value
        control_sub = self.get_parameter('control_sub_topic').get_parameter_value().string_value
        control_pub = self.get_parameter('control_pub_topic').get_parameter_value().string_value
        calib_param = self.get_parameter('calibration_json').get_parameter_value().string_value

        self._sim_addr = (host, int(self._cmd_port))
        self._num_sensors = 9
        self._num_motors = 6
        self._num_imus = 3
        self._num_arduino = 3
        self._min_length = 90
        self._range024 = 110
        self._range135 = 110
        self._max_speed = 80
        self._gear_ratio = 150
        self._winch_diameter = 6.35
        self._encoder_resolution = 12
        self._flip = [1, -1, 1, 1, -1, -1]

        self._cap = [0.0] * self._num_sensors
        self._length = [0.0] * self._num_sensors
        self._encoder_counts = [0] * self._num_motors
        self._accelerometer = [[0.0, 0.0, 0.0] for _ in range(3)]
        self._gyroscope = [[0.0, 0.0, 0.0] for _ in range(3)]
        self._pos = [0.0] * self._num_motors
        self._speed = [0.0] * self._num_motors
        self._done = [False] * self._num_motors
        self._which_arduino: Optional[int] = None
        self._addresses: List[Optional[tuple]] = [None] * self._num_arduino

        self._m, self._b = self._load_calibration(calib_param)
        self._lock = threading.Lock()

        self._sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self._sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self._sock.bind((bind_host, int(bind_port)))
        self._sock.settimeout(0.05)

        init_cmd = '0 0 0 ' + ' '.join(['0'] * self._num_motors)
        try:
            self._sock.sendto(init_cmd.encode('utf-8'), self._sim_addr)
            self.get_logger().info(f'Handshake sent to simulator at {self._sim_addr}')
        except OSError as e:
            self.get_logger().warn(f'Handshake send failed: {e}')

        self._pub = self.create_publisher(TensegrityStamped, control_pub, 10)
        if use_float:
            self.create_subscription(Float64MultiArray, motor_topic, self._on_motor_array, 10)
        else:
            self.create_subscription(TensegrityStamped, control_sub, self._on_control_cmd, 10)

        period = 1.0 / max(rate, 1.0)
        self._timer = self.create_timer(period, self._publish_tick)

        self._shutdown = threading.Event()
        self._rx_thread = threading.Thread(target=self._recv_loop, daemon=True)
        self._rx_thread.start()

        self.get_logger().info(
            f'UDP bridge bound {bind_host}:{bind_port} → simulator {host}:{self._cmd_port}; '
            f'publishing {control_pub} at {rate} Hz'
        )

    def _load_calibration(self, calib_param: str):
        path = calib_param.strip()
        if not path:
            path = os.environ.get('TENSEGRITY_CALIBRATION_JSON', '')
        if not path:
            try:
                share = get_package_share_directory('mujoco_simulator_ros2')
                candidate = os.path.join(share, 'calibration', 'new_calibration.json')
                if os.path.isfile(candidate):
                    path = candidate
            except Exception:
                pass
        m = np.ones(self._num_sensors, dtype=np.float64)
        b = np.full(self._num_sensors, 50.0, dtype=np.float64)
        if path and os.path.isfile(path):
            try:
                with open(path, 'r', encoding='utf-8') as f:
                    data = json.load(f)
                m = np.array(data.get('m'), dtype=np.float64)
                b = np.array(data.get('b'), dtype=np.float64)
                self.get_logger().info(f'Loaded calibration from {path}')
            except Exception as e:
                self.get_logger().warn(f'Calibration load failed ({path}): {e}; using defaults')
        else:
            self.get_logger().warn('Using default linear calibration (m=1, b=50)')
        return m, b

    def _on_motor_array(self, msg: Float64MultiArray) -> None:
        data = list(msg.data)
        if len(data) < self._num_motors:
            self.get_logger().warn('motor_speeds: expected at least 6 values')
            return
        speeds = [float(data[i]) for i in range(self._num_motors)]
        self._send_motor_udp(speeds)

    def _on_control_cmd(self, msg: TensegrityStamped) -> None:
        if len(msg.motors) < self._num_motors:
            return
        speeds = [float(msg.motors[i].speed) for i in range(self._num_motors)]
        self._send_motor_udp(speeds)

    def _send_motor_udp(self, speeds: List[float]) -> None:
        with self._lock:
            for i, s in enumerate(speeds):
                self._speed[i] = s
        parts = ['0'] * self._offset + [str(s) for s in speeds]
        line = ' '.join(parts)
        try:
            self._sock.sendto(line.encode('utf-8'), self._sim_addr)
        except OSError as e:
            self.get_logger().warn(f'UDP send failed: {e}')

    def _recv_loop(self) -> None:
        arduino_info_in = [False] * self._num_arduino
        while not self._shutdown.is_set():
            try:
                data, addr = self._sock.recvfrom(255)
            except socket.timeout:
                continue
            except OSError:
                break
            try:
                received_data = data.decode('utf-8')
                sensor_values = received_data.split()
                sensor_array = [float(value) for value in sensor_values]
                if len(sensor_array) != 13:
                    continue
                arduino_id = int(sensor_array[0])
                with self._lock:
                    if self._addresses[arduino_id] is None:
                        self._addresses[arduino_id] = addr
                    self._which_arduino = arduino_id
                    arduino_info_in[arduino_id] = True

                    if sensor_array[1] == 0.2 or sensor_array[2] == 0.2 or sensor_array[3] == 0.2:
                        self.get_logger().warn(f'MPR121/I2C warning on Arduino {arduino_id}')

                    if arduino_id == 0:
                        self._cap[4] = sensor_array[1]
                        self._cap[2] = sensor_array[2]
                        self._cap[8] = sensor_array[3]
                        self._encoder_counts[0] = int(sensor_array[5])
                        self._encoder_counts[1] = int(sensor_array[6])
                    elif arduino_id == 1:
                        self._cap[3] = sensor_array[1]
                        self._cap[1] = sensor_array[2]
                        self._cap[7] = sensor_array[3]
                        self._encoder_counts[2] = int(sensor_array[5])
                        self._encoder_counts[3] = int(sensor_array[6])
                    elif arduino_id == 2:
                        self._cap[5] = sensor_array[1]
                        self._cap[0] = sensor_array[2]
                        self._cap[6] = sensor_array[3]
                        self._encoder_counts[4] = int(sensor_array[5])
                        self._encoder_counts[5] = int(sensor_array[6])

                    if 0.2 not in self._cap:
                        for i in range(len(self._cap)):
                            self._length[i] = (self._cap[i] - self._b[i]) / self._m[i]
                        for i in range(self._num_motors):
                            rng = self._range135 if i < 3 else self._range024
                            self._pos[i] = (self._length[i] - self._min_length) / rng

                    aid = self._which_arduino
                    self._accelerometer[aid][0] = sensor_array[7]
                    self._accelerometer[aid][1] = sensor_array[8]
                    self._accelerometer[aid][2] = sensor_array[9]
                    self._gyroscope[aid][0] = sensor_array[10]
                    self._gyroscope[aid][1] = sensor_array[11]
                    self._gyroscope[aid][2] = sensor_array[12]

                if all(arduino_info_in):
                    arduino_info_in = [False] * self._num_arduino
            except (ValueError, IndexError) as e:
                self.get_logger().debug(f'Bad UDP packet: {e}')

    def _publish_tick(self) -> None:
        msg = TensegrityStamped()
        msg.header.stamp = self.get_clock().now().to_msg()

        info = Info()
        info.min_length = int(self._min_length)
        info.range024 = int(self._range024)
        info.range135 = int(self._range135)
        info.max_speed = int(self._max_speed)
        info.tol = 0.1
        info.low_tol = 0.1
        info.p = 6.0
        info.i = 0.01
        info.d = 0.5
        msg.info = info

        with self._lock:
            for motor_id in range(self._num_motors):
                motor = Motor()
                motor.id = motor_id
                motor.position = float(self._pos[motor_id])
                motor.target = 0.0
                motor.speed = float(self._speed[motor_id])
                motor.done = bool(self._done[motor_id])
                enc = self._encoder_counts[motor_id]
                motor.encoder_counts = int(enc)
                motor.encoder_length = float(
                    enc / self._encoder_resolution / self._gear_ratio * np.pi * self._winch_diameter
                )
                msg.motors.append(motor)

            for sensor_id in range(self._num_sensors):
                s = Sensor()
                s.id = sensor_id
                s.length = float(self._length[sensor_id])
                s.capacitance = float(self._cap[sensor_id])
                msg.sensors.append(s)

            for rod in range(self._num_imus):
                imu = Imu()
                imu.id = rod
                imu.x = 0.0
                imu.y = 0.0
                imu.z = 0.0
                imu.ax = float(self._accelerometer[rod][0])
                imu.ay = float(self._accelerometer[rod][1])
                imu.az = float(self._accelerometer[rod][2])
                imu.gx = float(self._gyroscope[rod][0])
                imu.gy = float(self._gyroscope[rod][1])
                imu.gz = float(self._gyroscope[rod][2])
                imu.mx = 0.0
                imu.my = 0.0
                imu.mz = 0.0
                msg.imus.append(imu)

        msg.trajectory = Trajectory()
        msg.trajectory.coms = []
        msg.trajectory.pas = []
        msg.trajectory.trajectory = []
        self._pub.publish(msg)


def main() -> None:
    rclpy.init()
    node = UdpSimulatorBridgeNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node._shutdown.set()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
