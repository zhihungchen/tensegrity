#!/usr/bin/env python3
"""
Motor command simulation/integration test for robot_driver_direct.

This module validates the direct control path:
  /motor_speeds (Float64MultiArray) -> robot_driver_direct -> /control_msg (TensegrityStamped)

Modes:
  - fake: run robot_driver_direct with use_fake_udp:=true
  - real: run robot_driver_direct with use_fake_udp:=false
"""

import argparse
import time
from dataclasses import dataclass
from typing import Dict, List

import rclpy
from rclpy.node import Node
from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy
from std_msgs.msg import Float64MultiArray

from tensegrity_interfaces.msg import TensegrityStamped


@dataclass
class TestStep:
    motor_id: int
    speed: float


class MotorControlTestNode(Node):
    def __init__(self, args):
        super().__init__("motor_control_test")

        qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
        )

        self.mode = args.mode
        self.motor_id = args.motor_id
        self.timeout_s = args.timeout
        self.tol = args.tol
        self.step_sleep_s = args.step_sleep
        self.control_topic = args.control_topic
        self.motor_speeds_topic = args.motor_speeds_topic

        self._latest_speeds: Dict[int, float] = {}
        self._control_seen = False

        self._pub = self.create_publisher(Float64MultiArray, self.motor_speeds_topic, qos)
        self._sub = self.create_subscription(
            TensegrityStamped,
            self.control_topic,
            self._control_cb,
            qos,
        )

        self.sequence = [
            TestStep(motor_id=self.motor_id, speed=speed)
            for speed in _parse_sequence(args.sequence)
        ]

    def _control_cb(self, msg: TensegrityStamped):
        self._control_seen = True
        for motor in msg.motors:
            self._latest_speeds[int(motor.id)] = float(motor.speed)

    def _publish_motor_speeds(self, motor_id: int, speed: float):
        data = [0.0] * 6
        data[int(motor_id)] = float(speed)
        msg = Float64MultiArray()
        msg.data = data
        self._pub.publish(msg)
        self.get_logger().info(
            f"publish {self.motor_speeds_topic}: {data}"
        )

    def _spin_for(self, duration_s: float):
        end_t = time.monotonic() + max(0.0, duration_s)
        while rclpy.ok() and time.monotonic() < end_t:
            rclpy.spin_once(self, timeout_sec=0.05)

    def _wait_for_control_topic(self, timeout_s: float) -> bool:
        end_t = time.monotonic() + timeout_s
        while rclpy.ok() and time.monotonic() < end_t:
            rclpy.spin_once(self, timeout_sec=0.05)
            if self._control_seen:
                return True
        return False

    def _wait_motor_speed(self, motor_id: int, expected: float, timeout_s: float) -> bool:
        end_t = time.monotonic() + timeout_s
        while rclpy.ok() and time.monotonic() < end_t:
            rclpy.spin_once(self, timeout_sec=0.05)
            got = self._latest_speeds.get(motor_id)
            if got is not None and abs(got - expected) <= self.tol:
                return True
        return False

    def run_sequence(self) -> int:
        self.get_logger().info(
            f"Starting motor control test in mode={self.mode}. "
            f"Expect robot_driver_direct already running."
        )
        if self.mode == "real":
            self.get_logger().warn(
                "REAL mode selected: ensure area is clear and motors are safe before non-zero speeds."
            )

        if not self._wait_for_control_topic(timeout_s=self.timeout_s):
            self.get_logger().error(
                f"No data on {self.control_topic} within {self.timeout_s:.1f}s. "
                "Start robot_driver_direct first."
            )
            return 1

        self.get_logger().info(f"Detected {self.control_topic}; running {len(self.sequence)} steps.")
        all_ok = True
        for idx, step in enumerate(self.sequence, start=1):
            self._publish_motor_speeds(step.motor_id, step.speed)
            ok = self._wait_motor_speed(step.motor_id, step.speed, timeout_s=self.timeout_s)
            if ok:
                self.get_logger().info(
                    f"[{idx}/{len(self.sequence)}] PASS motor {step.motor_id} -> {step.speed:.3f}"
                )
            else:
                got = self._latest_speeds.get(step.motor_id)
                self.get_logger().error(
                    f"[{idx}/{len(self.sequence)}] FAIL motor {step.motor_id}: "
                    f"expected {step.speed:.3f}, got {got}"
                )
                all_ok = False
            self._spin_for(self.step_sleep_s)

        # Always command stop at end for safety.
        self._publish_motor_speeds(self.motor_id, 0.0)
        self._spin_for(0.2)

        if all_ok:
            self.get_logger().info("Motor control test PASSED.")
            return 0
        self.get_logger().error("Motor control test FAILED.")
        return 2


def _parse_sequence(seq_str: str) -> List[float]:
    parts = [p.strip() for p in seq_str.split(",") if p.strip()]
    if not parts:
        raise ValueError("sequence cannot be empty")
    return [float(v) for v in parts]


def _build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Run direct motor command test against robot_driver_direct."
    )
    parser.add_argument(
        "--mode",
        choices=["fake", "real"],
        default="fake",
        help="Test context hint. Driver launch controls actual UDP backend.",
    )
    parser.add_argument(
        "--motor-id",
        type=int,
        default=2,
        help="Motor id used for sequence test.",
    )
    parser.add_argument(
        "--sequence",
        type=str,
        default="30,0,-30",
        help="Comma-separated speed sequence (e.g. 30,0,-30).",
    )
    parser.add_argument(
        "--timeout",
        type=float,
        default=2.0,
        help="Per-step timeout in seconds.",
    )
    parser.add_argument(
        "--tol",
        type=float,
        default=1e-3,
        help="Absolute tolerance for comparing motor speed on /control_msg.",
    )
    parser.add_argument(
        "--step-sleep",
        type=float,
        default=0.2,
        help="Delay between test steps in seconds.",
    )
    parser.add_argument(
        "--control-topic",
        type=str,
        default="/control_msg",
        help="Observed control topic.",
    )
    parser.add_argument(
        "--motor-speeds-topic",
        type=str,
        default="/motor_speeds",
        help="Motor speed vector topic to publish.",
    )
    return parser


def main(args=None):
    parser = _build_arg_parser()
    cli_args = parser.parse_args(args=args)

    rclpy.init(args=None)
    node = MotorControlTestNode(cli_args)
    code = 1
    try:
        code = node.run_sequence()
    except Exception as exc:
        node.get_logger().error(f"Unexpected test error: {exc}")
        code = 3
    finally:
        try:
            node._publish_motor_speeds(node.motor_id, 0.0)
        except Exception:
            pass
        node.destroy_node()
        rclpy.shutdown()
    raise SystemExit(code)


if __name__ == "__main__":
    main()
