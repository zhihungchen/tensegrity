#!/usr/bin/env python3
"""ROS2 A* planner node: subscribes to state, publishes actions; polls get_pose when perception is up."""
import rclpy
from rclpy.node import Node
from tensegrity_interfaces.msg import State, Action

from tensegrity_planning.planner_perception import attach_get_pose_client


class AstarPlannerNode(Node):
    def __init__(self):
        super().__init__('astar_planner_node')
        self.sub = self.create_subscription(State, '/state_msg', self._callback, 10)
        self.pub = self.create_publisher(Action, '/action_msg', 10)
        self._pose_client, self._pose_timer = attach_get_pose_client(self, period_sec=1.0)
        self.get_logger().info(
            'A* planner node running; get_pose polled when service exists (full A* logic TODO).'
        )

    def _callback(self, msg):
        pass


def main(args=None):
    rclpy.init(args=args)
    node = AstarPlannerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
