# robot_config.py
from dataclasses import dataclass, field
import numpy as np


@dataclass
class RobotConfig:
    # ---- Robot / hardware ----
    num_sensors: int = 9
    num_motors: int = 6
    num_imus: int = 2
    num_arduino: int = 3
    min_length: float = 100.0

    # ---- Ranges & speeds ----
    RANGE: float = 100.0
    LEFT_RANGE: float = 100.0
    max_speed: float = 70.0
    init_speed: float = 70.0

    # ---- PID & tolerances ----
    tol: float = 0.15
    low_tol: float = 0.15
    P: float = 10.0
    I: float = 0.01
    D: float = 0.5

    # ---- Motor direction ----
    flip: tuple = (1, 1, 1, 1, 1, 1)

    # ---- Encoder / mechanics ----
    gear_ratio: float = 150.0
    winch_diameter: float = 6.35
    encoder_resolution: float = 12.0

    # ---- UDP ----
    UDP_IP: str = "0.0.0.0"     # Listen to all interfaces
    UDP_PORT: int = 2390        # Must match Arduino sketch
    recv_buf_size: int = 255    # max bytes per packet

    # ---- ROS ----
    ros_node_name: str = "tensegrity_driver"
    ros_control_topic: str = "control_msg"
    ros_queue_size: int = 10

    # ---- Calibration file ----
    # relative file path in tensegrity package 
    calib_relpath: str = "calibration/calibration_charles.xls"

    # ---- Command layout ----
    # motor command starts from offset
    offset: int = 3

    # ---- states ----
    # This is just for demo, we try to init states from json now
    states: np.ndarray = field(
        default_factory=lambda: np.array([
            [1.0, 1.0, 0.1, 1.0, 1.0, 0.1],
            [0.0, 1.0, 1.0, 0.0, 1.0, 0.1],
            [1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
            [1.0, 0.1, 1.0, 1.0, 0.1, 1.0],
            [1.0, 1.0, 0.0, 1.0, 0.1, 0.0],
            [1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
            [0.1, 1.0, 1.0, 0.1, 1.0, 1.0],
            [1.0, 0.0, 1.0, 0.1, 0.0, 1.0],
            [1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        ], dtype=float)
    )
