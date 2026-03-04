#!/usr/bin/env python3
import os
import numpy as np
import pickle
import rospy
import rospkg
import rosnode
from geometry_msgs.msg import Point
from tensegrity_interfaces.msg import State, Action
from tensegrity_perception.srv import GetPose, GetPoseRequest, GetPoseResponse, GetBarHeight
from scipy.spatial.transform import Rotation as R

from .astar import astar
from .Tensegrity_model_inputs import L


class MotionPlanner:
    def __init__(self, start, goal, boundary, obstacles=[], heur_type="dist"):
        sub_topic = '/state_msg'
        pub_topic = '/action_msg'
        self.sub = rospy.Subscriber(sub_topic, State, self.callback)
        self.pub = rospy.Publisher(pub_topic, Action, queue_size=10)

        try:
            package_path = rospkg.RosPack().get_path('tensegrity_planning')
        except Exception:
            package_path = os.path.join(os.path.dirname(__file__), '..', '..')
        filepath = os.path.join(package_path, 'calibration', 'new_platform_transformation_table.pkl')
        if not os.path.isfile(filepath):
            filepath = os.path.join(os.path.dirname(__file__), '..', '..', 'calibration', 'new_platform_transformation_table.pkl')
        with open(filepath, 'rb') as f:
            self.action_dict = pickle.load(f)

        self.primitives = ['100_100','120_120','140_140','100_120','120_100','100_140','140_100','120_140','140_120','ccw','cw']
        self.primitive_workspace = []
        for prim in self.primitives:
            full_prim = self.action_dict[prim+"__"+prim]
            angle = self.rotation_angle_from_matrix(full_prim[0])
            simple_prim = [float(full_prim[1][0]), float(full_prim[1][1]), angle]
            self.primitive_workspace.append(simple_prim)

        self.current_state = start
        self.goal = goal
        self.boundary = boundary
        self.obstacles = obstacles
        self.heur_type = heur_type
        self.obstacle_dim = (0.2, 0.2)
        self.goal_tol = 0.1
        self.goal_rot_tol = np.pi/2
        self.repeat_tol = 0.04
        self.grid_step = 0.01

        self.action_sequence = []
        self.Astar()
        self.count = 0
        self.COMs = []
        self.endcaps = []
        self.PAs = []

    def callback(self, msg):
        print('Action ' + str(self.count))
        if '/tracking_service' in rosnode.get_node_names():
            COM, axis, self.endcaps = self.get_pose()
            print('I could replan here')
            if True:
                self.current_state = (float(COM[0]), float(COM[1]), float(np.arctan2(axis[1], axis[0])))
                self.Astar()
                self.COMs = [COM.flatten()[:2].tolist()] + [[x,y] for x,y,_ in self.expected_path]
                self.PAs = [axis.flatten().tolist()] + [[np.cos(theta), np.sin(theta)] for _,_,theta in self.expected_path]

        if not self.action_sequence:
            return
        action_msg = Action()
        for act in self.action_sequence:
            action_msg.actions.append(act)
        for pt in self.COMs:
            point = Point()
            point.x = float(pt[0]) if hasattr(pt, '__len__') and len(pt) >= 1 else 0.0
            point.y = float(pt[1]) if hasattr(pt, '__len__') and len(pt) >= 2 else 0.0
            action_msg.COMs.append(point)
        endcaps_list = self.endcaps if isinstance(self.endcaps, np.ndarray) and self.endcaps.size > 0 else np.zeros((6, 3))
        if endcaps_list.ndim == 1:
            endcaps_list = np.reshape(endcaps_list, (-1, 3))
        for row in endcaps_list:
            point = Point()
            point.x = float(row[0])
            point.y = float(row[1])
            point.z = float(row[2])
            action_msg.endcaps.append(point)
        for pt in self.PAs:
            point = Point()
            point.x = float(pt[0]) if hasattr(pt, '__len__') and len(pt) >= 1 else 0.0
            point.y = float(pt[1]) if hasattr(pt, '__len__') and len(pt) >= 2 else 0.0
            action_msg.PAs.append(point)
        self.pub.publish(action_msg)
        if len(self.action_sequence) > 0:
            self.action_sequence.pop(0)
        self.count += 1

    def int_path_to_string_path(self, int_path):
        return [self.primitives[i] for i in int_path]

    def Astar(self):
        self.expected_path, path = astar(
            self.current_state, self.goal, self.primitive_workspace,
            tolerance=self.goal_tol, rot_tol=self.goal_rot_tol, obstacles=self.obstacles,
            repeat_tol=self.repeat_tol, single_push=False,
            stochastic=False, heur_type=self.heur_type, boundary=self.boundary,
            obstacle_dims=self.obstacle_dim, grid_step=self.grid_step
        )
        print('Path: ', path)
        if len(path) > 0:
            self.action_sequence = self.int_path_to_string_path(path)

    def run(self, rate):
        while not rospy.is_shutdown():
            rate.sleep()

    def get_pose(self):
        service_name = "get_pose"
        vectors = np.array([[0.0, 0.0, 0.0]])
        centers = []
        endcaps = []
        try:
            request = GetPoseRequest()
            get_pose_srv = rospy.ServiceProxy(service_name, GetPose)
            rospy.loginfo("Request sent. Waiting for response...")
            response = get_pose_srv(request)
            rospy.loginfo("Got response. Request success: %s", response.success)
            if response.success:
                for pose in response.poses:
                    rotation_matrix = R.from_quat([pose.orientation.x, pose.orientation.y, pose.orientation.z, pose.orientation.w]).as_matrix()
                    unit_vector = rotation_matrix[:, 2]
                    center = [pose.position.x, pose.position.y, pose.position.z]
                    endcaps.append(np.array(center) + L/2*unit_vector)
                    endcaps.append(np.array(center) - L/2*unit_vector)
                    centers.append(center)
                    vectors += unit_vector
                COM = np.mean(np.array(centers), axis=0)
                principal_axis = vectors/np.linalg.norm(vectors)
                endcaps = np.array(endcaps)/100
                COM = np.reshape(COM[0:2], (2, 1))
                principal_axis = principal_axis[:, 0:2]
                principal_axis = np.reshape(principal_axis, (2, 1))
        except rospy.ServiceException as e:
            rospy.loginfo("Service call failed: %s", e)
        if len(centers) == 0:
            COM = np.zeros((2, 1))
            principal_axis = np.array([[1.0], [0.0]])
            endcaps = np.zeros((6, 3))
        return COM, principal_axis, endcaps

    def rotation_angle_from_matrix(self, matrix):
        matrix = np.array(matrix)
        cos_theta = matrix[0, 0]
        sin_theta = matrix[1, 0]
        angle_radians = np.arctan2(sin_theta, cos_theta)
        if angle_radians < 0:
            angle_radians += 2*np.pi
        return float(angle_radians)


def main():
    start = (0.5, 1.1, np.pi/2)
    goal = (1.7, 0.2, 0)
    obstacles = ((0.5, 0.3), (0.5, 0.5), (1.1, 0.5), (1.1, 0.4))
    boundary = (-1, 3, -0.2, 1.4)

    rospy.init_node('motion_planner')
    planner = MotionPlanner(start, goal, boundary, obstacles, heur_type="dist")
    rate = rospy.Rate(30)
    planner.run(rate)


if __name__ == '__main__':
    main()
