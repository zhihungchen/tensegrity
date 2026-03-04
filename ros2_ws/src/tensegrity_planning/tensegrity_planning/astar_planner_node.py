#!/usr/bin/env python3
"""ROS2 A* planner node (stub). Full implementation when tensegrity_perception is ROS2."""
import rclpy
from rclpy.node import Node
from tensegrity_interfaces.msg import State, Action


class AstarPlannerNode(Node):
    def __init__(self):
        super().__init__('astar_planner_node')
        self.sub = self.create_subscription(State, '/state_msg', self._callback, 10)
        self.pub = self.create_publisher(Action, '/action_msg', 10)
        self.get_logger().info('A* planner node (stub) running; connect perception for full planning.')

    def _callback(self, msg):
        pass


def main(args=None):
    rclpy.init(args=args)
    node = AstarPlannerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
