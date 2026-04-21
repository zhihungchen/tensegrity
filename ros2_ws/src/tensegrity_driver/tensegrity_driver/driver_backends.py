from __future__ import annotations

from typing import List, Optional

from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy
from std_msgs.msg import Float64MultiArray

from tensegrity_core.robot_core import TensegrityCore
from tensegrity_interfaces.msg import TensegrityStamped

from tensegrity_driver.control_msg_utils import update_core_from_control_msg


class DriverBackend:
    def start(self) -> None:
        pass

    def stop(self) -> None:
        pass

    def is_ready(self) -> bool:
        return True

    def send_motor_speeds(self, speeds: List[int]) -> None:
        raise NotImplementedError

    def stop_all(self) -> None:
        raise NotImplementedError

    def should_publish_control(self) -> bool:
        return True

    def latest_control_msg(self) -> Optional[TensegrityStamped]:
        return None


class RealRobotBackend(DriverBackend):
    def __init__(self, core: TensegrityCore):
        self.core = core

    def start(self) -> None:
        self.core.start()

    def stop(self) -> None:
        self.core.stop()

    def is_ready(self) -> bool:
        return self.core.is_ready()

    def send_motor_speeds(self, speeds: List[int]) -> None:
        self.core.send_motor_speeds(speeds)

    def stop_all(self) -> None:
        self.core.stop_all()


class SimBridgeBackend(DriverBackend):
    def __init__(
        self,
        node,
        *,
        num_motors: int,
        motor_topic: str,
        control_topic: str,
        mirror_core: Optional[TensegrityCore] = None,
    ):
        self._node = node
        self._num_motors = num_motors
        self._mirror_core = mirror_core
        self._latest_control_msg: Optional[TensegrityStamped] = None
        self._latest_commanded_speeds: List[int] = [0] * num_motors

        qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
        )
        self._motor_pub = node.create_publisher(Float64MultiArray, motor_topic, qos)
        self._control_sub = node.create_subscription(
            TensegrityStamped,
            control_topic,
            self._control_callback,
            qos,
        )

    def _control_callback(self, msg: TensegrityStamped) -> None:
        self._latest_control_msg = msg
        if self._mirror_core is not None:
            update_core_from_control_msg(self._mirror_core, msg)

    def send_motor_speeds(self, speeds: List[int]) -> None:
        if len(speeds) != self._num_motors:
            raise ValueError(
                f"Expected {self._num_motors} motor speeds, got {len(speeds)}"
            )

        msg = Float64MultiArray()
        msg.data = [float(s) for s in speeds]
        self._latest_commanded_speeds = [int(round(s)) for s in speeds]
        self._motor_pub.publish(msg)

        if self._mirror_core is not None:
            with self._mirror_core._state_lock:
                self._mirror_core.current_motor_speeds = list(self._latest_commanded_speeds)

    def stop_all(self) -> None:
        self.send_motor_speeds([0] * self._num_motors)

    def should_publish_control(self) -> bool:
        return False

    def latest_control_msg(self) -> Optional[TensegrityStamped]:
        return self._latest_control_msg
