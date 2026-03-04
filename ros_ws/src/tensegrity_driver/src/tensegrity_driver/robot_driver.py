#!/usr/bin/env python3
"""
Thin ROS1 driver: wraps TensegrityCore, publishes control_msg and state_msg,
subscribes to /action_msg and pushes actions into the core (set_states/set_gait_state).
No duplicated robot logic; all hardware and control in tensegrity_core.
"""
import os
from pathlib import Path
import rospy
import rospkg
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
    State,
    Action,
)
from geometry_msgs.msg import Point
import numpy as np

try:
    from tensegrity_planning.astar_action_handler import apply_astar_action
    _ASTAR_AVAILABLE = True
except ImportError:
    _ASTAR_AVAILABLE = False


class TensegrityRobot:
    """ROS1 driver node: wraps TensegrityCore, pub/sub only. Supports A* Action (endcaps, transform_gait)."""

    def __init__(self, cfg: RobotConfig = None):
        self.cfg = cfg if cfg is not None else RobotConfig()
        self.core = None
        self._last_action_msg = None
        self.control_pub = None
        self.state_pub = None
        self.action_sub = None
        # A* / MPC state for State message and next action handling
        self._prev_bottom_nodes = (0, 2, 5)
        self._prev_gait = "roll"
        self._reverse_the_gait = False
        self._prev_action_str = "100_100"

    def initialize(self):
        rospy.init_node(self.cfg.ros_node_name, anonymous=True)
        self.control_pub = rospy.Publisher(
            self.cfg.ros_control_topic,
            TensegrityStamped,
            queue_size=self.cfg.ros_queue_size,
        )
        self.state_pub = rospy.Publisher(
            "/state_msg",
            State,
            queue_size=self.cfg.ros_queue_size,
        )
        self.action_sub = rospy.Subscriber(
            "/action_msg",
            Action,
            self._action_callback,
            queue_size=10,
        )

        try:
            package_path = rospkg.RosPack().get_path("tensegrity_driver")
        except rospkg.common.ResourceNotFound:
            package_path = str(Path(__file__).resolve().parents[2])
        pkg_root = Path(package_path)
        calibration_file = str(pkg_root / "calibration" / "calibration_charles.xls")
        if not os.path.isfile(calibration_file):
            calibration_file = str(pkg_root / "src" / "tensegrity_driver" / "calibration" / "calibration_charles.xls")
        if not os.path.isfile(calibration_file):
            calibration_file = str(Path(__file__).resolve().parents[2] / "calibration" / "calibration_charles.xls")
        states_path = str(pkg_root / "src" / "states" / "quasi_static.json")
        if not os.path.isfile(states_path):
            states_path = str(pkg_root / "states" / "quasi_static.json")
        if not os.path.isfile(states_path):
            states_path = str(Path(__file__).resolve().parents[2] / "src" / "states" / "quasi_static.json")

        udp = UdpClient(self.cfg.UDP_IP, self.cfg.UDP_PORT, self.cfg.recv_buf_size)
        self.core = TensegrityCore(self.cfg, udp_client=udp)
        self.core.initialize(
            mode="basic",
            calibration_file=calibration_file,
            states_path=states_path,
        )
        print("[INFO] Driver initialized with core; press s to stop, q to quit")

    def _action_callback(self, msg: Action):
        """Store latest action; push into core. Prefer A* handler when endcaps present."""
        self._last_action_msg = msg
        if not msg.actions:
            return
        core = self.core
        if core is None or core.controller is None:
            return

        # A* / MPC: full Action with endcaps -> transform_gait, set ranges
        if _ASTAR_AVAILABLE and msg.endcaps and len(msg.endcaps) >= 6:
            result = apply_astar_action(
                msg,
                self._prev_bottom_nodes,
                self._prev_gait,
                self._reverse_the_gait,
                core.num_motors,
            )
            if result is not None:
                states, R024, R135, tol, self._prev_bottom_nodes, self._prev_gait = result
                core.set_states(states)
                core.set_ranges(R024, R135)
                core.tol = tol
                self._prev_action_str = (
                    f"{int(R135)}_{int(R024)}" if self._prev_gait == "roll" else self._prev_gait
                )
                core.set_gait_state(1)  # start from step 1 of new gait (skip transition)
                rospy.loginfo("A* action applied: %s", msg.actions[0])
                return
        # Fallback: simple action name -> fixed state table
        action_name = msg.actions[0]
        action_to_states = self._get_action_to_states()
        if action_name in action_to_states:
            states = np.array(action_to_states[action_name], dtype=float)
            if states.shape[1] == core.num_motors:
                core.set_states(states)

    def _get_action_to_states(self):
        """Optional: action name -> list of state rows. Override or load from file."""
        num = self.cfg.num_motors
        roll = [
            [1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
            [1.0, 1.0, 0.1, 1.0, 1.0, 0.1],
            [0.0, 1.0, 1.0, 0.0, 1.0, 0.1],
        ]
        if num != 6:
            roll = [([1.0] * num)] * 3
        return {
            "roll": roll,
            "cw": [
                [1.0] * num,
                [1.0] * num,
                [0.0, 0.0, 0.0, 1.0, 0.0, 1.0][:num],
                [0.0, 0.0, 0.0, 0.0, 0.0, 0.7][:num],
                [0.0, 0.0, 0.7, 0.0, 1.0, 1.0][:num],
            ],
            "ccw": [
                [1.0] * num,
                [1.0] * num,
                [1.0, 1.0, 1.0, 0.0, 1.0, 1.0][:num],
                [1.0, 0.0, 1.0, 0.0, 1.0, 1.0][:num],
                [0.0, 0.0, 0.0, 0.0, 0.0, 0.0][:num],
            ],
        }

    def _build_control_msg(self):
        """Build TensegrityStamped from core state."""
        c = self.core
        msg = TensegrityStamped()
        msg.header = Header(stamp=rospy.Time.now(), frame_id="")
        info = Info()
        info.min_length = int(min(255, c.min_length))
        info.RANGE = int(min(255, c.RANGE))
        info.MAX_RANGE = 0
        info.MIN_RANGE = 0
        info.RANGE024 = int(min(255, max(0, c.RANGE024)))
        info.RANGE135 = int(min(255, max(0, c.RANGE135)))
        info.max_speed = int(max(-128, min(127, c.max_speed)))
        info.tol = c.tol
        info.low_tol = c.low_tol
        info.P = c.P
        info.I = c.I
        info.D = c.D
        info.dist_weight = 0.0
        info.ang_weight = 0.0
        info.prog_weight = 0.0
        msg.info = info
        for i in range(c.num_motors):
            m = Motor()
            m.id = int(max(-128, min(127, i)))
            m.position = c.pos[i]
            m.target = c.states[c.state, i] if c.states is not None else 0.0
            m.speed = c.command[i] * c.max_speed
            m.done = bool(c.done[i])
            m.error = c.controller.error[i] if c.controller else 0.0
            m.d_error = c.controller.d_error[i] if c.controller else 0.0
            m.cum_error = c.controller.cum_error[i] if c.controller else 0.0
            m.encoder_counts = int(c.encoder_counts[i])
            m.encoder_length = c.encoder_length[i]
            msg.motors.append(m)
        for i in range(c.num_sensors):
            s = Sensor()
            s.id = i
            s.length = c.length[i]
            s.capacitance = c.cap[i]
            msg.sensors.append(s)
        for rod in range(3):
            imu = Imu()
            imu.id = rod
            imu.ax = c.accelerometer[rod][0]
            imu.ay = c.accelerometer[rod][1]
            imu.az = c.accelerometer[rod][2]
            imu.gx = c.gyroscope[rod][0]
            imu.gy = c.gyroscope[rod][1]
            imu.gz = c.gyroscope[rod][2]
            msg.imus.append(imu)
        return msg

    def _build_state_msg(self, prev_action="", reverse_the_gait=False, bar_height_changed=False):
        """Build State for planner (e.g. MPC)."""
        msg = State()
        msg.prev_action = prev_action
        msg.reverse_the_gait = reverse_the_gait
        msg.bar_height_changed = bar_height_changed
        return msg

    def run(self):
        self.initialize()
        rate = rospy.Rate(50)
        while not rospy.is_shutdown() and not self.core.quitting:
            try:
                intent = self.core.bus.snapshot()
                if intent.stop:
                    self.core.keep_going = False
                    self.core.stop_all()
                if intent.armed_toggle:
                    self.core.armed = not self.core.armed
                    rospy.loginfo("Armed: %s", self.core.armed)
                if intent.quit:
                    self.core.stop_all()
                    self.core.quitting = True
                    break
                self.core.bus.clear_edge_flags()

                self.core.read()
                self.core.apply_manual_jog(intent)

                if (
                    self.core.keep_going
                    and None not in self.core.addresses
                    and self.core.armed
                    and self.core.controller is not None
                ):
                    msg_list, _ = self.core.controller.step(
                        self.core.pos,
                        length=self.core.length,
                        cap=self.core.cap,
                    )
                    self.core.send_command(
                        " ".join(msg_list),
                        self.core.addresses[self.core.which_Arduino],
                        0,
                    )

                self.control_pub.publish(self._build_control_msg())
                if self.state_pub.get_num_connections() > 0:
                    self.state_pub.publish(
                        self._build_state_msg(
                            prev_action=getattr(self, "_prev_action_str", "100_100"),
                            reverse_the_gait=self._reverse_the_gait,
                        )
                    )
            except Exception as e:
                rospy.logerr("Driver error: %s", e)
                self.core.keep_going = False
                self.core.stop_all()
                break
            rate.sleep()


if __name__ == "__main__":
    robot = TensegrityRobot()
    robot.run()
