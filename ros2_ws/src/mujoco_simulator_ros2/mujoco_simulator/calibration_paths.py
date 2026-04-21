"""Resolve capacitance calibration JSON without hard-coding ROS1 only."""

from __future__ import annotations

import os
from typing import Optional


def resolve_new_calibration_json(explicit: Optional[str] = None) -> Optional[str]:
    """
    Return path to new_calibration.json if found, else None.

    Search order:
    1. explicit path (if file exists)
    2. TENSEGRITY_CALIBRATION_JSON environment variable
    3. ROS2 share: mujoco_simulator_ros2/calibration/new_calibration.json (ament_index)
    4. ROS1 package tensegrity_simulation/calibration/new_calibration.json (rospkg)
    """
    if explicit:
        p = os.path.expanduser(explicit)
        if os.path.isfile(p):
            return p

    env = os.environ.get("TENSEGRITY_CALIBRATION_JSON", "").strip()
    if env:
        p = os.path.expanduser(env)
        if os.path.isfile(p):
            return p

    try:
        from ament_index_python.packages import get_package_share_directory

        share = get_package_share_directory("mujoco_simulator_ros2")
        p = os.path.join(share, "calibration", "new_calibration.json")
        if os.path.isfile(p):
            return p
    except Exception:
        pass

    try:
        import rospkg

        pkg = rospkg.RosPack().get_path("tensegrity_simulation")
        p = os.path.join(pkg, "calibration", "new_calibration.json")
        if os.path.isfile(p):
            return p
    except Exception:
        pass

    return None
