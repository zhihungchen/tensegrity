"""Minimal control-mode enum for motor authority (idle / direct / gait)."""

from enum import Enum, auto
import threading


class ControlMode(Enum):
    IDLE = auto()
    DIRECT = auto()
    GAIT = auto()


class ControlModeHolder:
    """Thread-safe current mode. Only one of {direct, gait} may command motors at a time."""

    def __init__(self, initial: ControlMode = ControlMode.IDLE):
        self._lock = threading.Lock()
        self._mode = initial

    def get(self) -> ControlMode:
        with self._lock:
            return self._mode

    def set(self, mode: ControlMode) -> ControlMode:
        with self._lock:
            prev = self._mode
            self._mode = mode
            return prev
