# Thread-safe copy of robot telemetry for ROS and control (no ROS dependency here).
from dataclasses import dataclass
from typing import List, Optional, Tuple

Addr = Tuple[str, int]


@dataclass
class RobotStateSnapshot:
    """Immutable snapshot of mutable core state at one instant (lists are copies)."""

    pos: List[float]
    cap: List[float]
    length: List[float]
    encoder_counts: List[int]
    encoder_length: List[float]
    current_motor_speeds: List[int]
    accelerometer: List[List[float]]
    gyroscope: List[List[float]]
    which_Arduino: Optional[int]
    addresses: List[Optional[Addr]]

    @property
    def is_ready(self) -> bool:
        return None not in self.addresses
