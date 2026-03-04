from __future__ import annotations
from dataclasses import dataclass
from threading import Lock
from typing import Optional

@dataclass
class ControlIntent:
    quit: bool = False
    stop: bool = False          # emergency stop / stop motors
    armed_toggle: bool = False  # toggle armed
    armed_set: Optional[bool] = None  # explicit set if needed later

    # manual jog (for calibration)
    selected_motor: int | None = None
    jog_dir: int = 0          # -1 back, +1 forward, 0 none
    jog_active: bool = False  # level intent (hold key)
    jog_speed: float | None = None  # optional override

class CommandBus:
    def __init__(self):
        self._lock = Lock()
        self._intent = ControlIntent()

    def snapshot(self) -> ControlIntent:
        with self._lock:
            return ControlIntent(**self._intent.__dict__)

    def clear_edge_flags(self):
        """Clear one-shot flags after core consumed them."""
        with self._lock:
            self._intent.stop = False
            self._intent.armed_toggle = False
            self._intent.quit = False

    def request_quit(self):
        with self._lock:
            self._intent.quit = True
            self._intent.stop = True  # safety

    def request_stop(self):
        with self._lock:
            self._intent.stop = True

    def toggle_armed(self):
        with self._lock:
            self._intent.armed_toggle = True

    # ---- API for calibration ---- #

    def select_motor(self, idx: int):
        with self._lock:
            self._intent.selected_motor = idx

    def set_jog(self, direction: int, active: bool, speed: float | None = None):
        # direction: -1, 0, +1
        with self._lock:
            self._intent.jog_dir = int(direction)
            self._intent.jog_active = bool(active)
            self._intent.jog_speed = speed

    def clear_level_controls(self):
        """Optional: clear level controls (e.g., on stop)."""
        with self._lock:
            self._intent.jog_dir = 0
            self._intent.jog_active = False
            self._intent.jog_speed = None
