from __future__ import annotations

import os
from pathlib import Path
from typing import Optional, Sequence, Tuple

from std_msgs.msg import Header

from tensegrity_core.robot_core import TensegrityCore
from tensegrity_core.state_snapshot import RobotStateSnapshot
from tensegrity_interfaces.msg import Imu, Info, Motor, Sensor, TensegrityStamped, Trajectory


def resolve_resource_paths() -> Tuple[str, str]:
    from ament_index_python.packages import get_package_share_directory

    share_dir = get_package_share_directory("tensegrity_driver")
    pkg_root = Path(share_dir)

    calibration_file = str(pkg_root / "calibration" / "calibration_charles.xls")
    states_path = str(pkg_root / "states" / "quasi_static.json")

    # Fallback for source-tree runs.
    if not os.path.isfile(calibration_file):
        calibration_file = str(
            Path(__file__).resolve().parents[1] / "calibration" / "calibration_charles.xls"
        )

    if not os.path.isfile(states_path):
        states_path = str(
            Path(__file__).resolve().parents[1] / "states" / "quasi_static.json"
        )

    return calibration_file, states_path


def build_common_control_msg(node, core: TensegrityCore, snap: Optional[RobotStateSnapshot] = None) -> TensegrityStamped:
    if snap is None:
        snap = core.get_latest_state()

    msg = TensegrityStamped()
    msg.header = Header()
    msg.header.stamp = node.get_clock().now().to_msg()
    msg.header.frame_id = ""

    info = Info()
    info.min_length = int(min(255, core.min_length))
    info.range = int(min(255, core.RANGE))
    info.max_range = 0
    info.min_range = 0
    info.range024 = 0
    info.range135 = 0
    info.max_speed = int(max(-128, min(127, core.max_speed)))
    info.tol = core.tol
    info.low_tol = core.low_tol
    info.p = core.P
    info.i = core.I
    info.d = core.D
    info.dist_weight = 0.0
    info.ang_weight = 0.0
    info.prog_weight = 0.0
    msg.info = info

    for i in range(core.num_sensors):
        sensor = Sensor()
        sensor.id = i
        sensor.length = float(snap.length[i])
        sensor.capacitance = float(snap.cap[i])
        msg.sensors.append(sensor)

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

    return msg


def append_motor(
    msg: TensegrityStamped,
    *,
    motor_id: int,
    position: float,
    target: float,
    speed: float,
    done: bool,
    error: float,
    d_error: float,
    cum_error: float,
    encoder_counts: int,
    encoder_length: float,
) -> None:
    motor = Motor()
    motor.id = int(max(-128, min(127, motor_id)))
    motor.position = float(position)
    motor.target = float(target)
    motor.speed = float(speed)
    motor.done = bool(done)
    motor.error = float(error)
    motor.d_error = float(d_error)
    motor.cum_error = float(cum_error)
    motor.encoder_counts = int(encoder_counts)
    motor.encoder_length = float(encoder_length)
    msg.motors.append(motor)


def attach_empty_trajectory(msg: TensegrityStamped) -> None:
    traj = Trajectory()
    traj.trajectory_segment = 0
    msg.trajectory = traj


def update_core_from_control_msg(core: TensegrityCore, msg: TensegrityStamped) -> None:
    with core._state_lock:
        for i, motor in enumerate(msg.motors[: core.num_motors]):
            core.pos[i] = float(motor.position)
            core.current_motor_speeds[i] = int(round(float(motor.speed)))
            core.encoder_counts[i] = int(motor.encoder_counts)
            core.encoder_length[i] = float(motor.encoder_length)

        for i, sensor in enumerate(msg.sensors[: core.num_sensors]):
            core.length[i] = float(sensor.length)
            core.cap[i] = float(sensor.capacitance)

        for i, imu in enumerate(msg.imus[: len(core.accelerometer)]):
            core.accelerometer[i][0] = float(imu.ax)
            core.accelerometer[i][1] = float(imu.ay)
            core.accelerometer[i][2] = float(imu.az)
            core.gyroscope[i][0] = float(imu.gx)
            core.gyroscope[i][1] = float(imu.gy)
            core.gyroscope[i][2] = float(imu.gz)

        if core.addresses:
            core.addresses = [("sim", idx) for idx in range(len(core.addresses))]


def copy_speeds_with_update(
    current_speeds: Sequence[int], motor_id: int, speed: float
) -> list[int]:
    speeds = [int(v) for v in current_speeds]
    if 0 <= motor_id < len(speeds):
        speeds[motor_id] = int(round(speed))
    return speeds
