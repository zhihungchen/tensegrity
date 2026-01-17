#!/usr/bin/env python3
import rospy

from tensegrity_interfaces.msg import TensegrityStamped


class RosPublisher:
    def __init__(
        self,
        topic: str = "control_msg",
        queue_size: int = 10,
        node_name: str = "tensegrity",
        anonymous: bool = False,
    ) -> None:
        if not rospy.core.is_initialized():
            rospy.init_node(node_name, anonymous=anonymous)
        self.publisher = rospy.Publisher(topic, TensegrityStamped, queue_size=queue_size)

    def publish_control_msg(self, control_msg: TensegrityStamped) -> None:
        if control_msg.header.stamp == rospy.Time():
            control_msg.header.stamp = rospy.Time.now()
        self.publisher.publish(control_msg)

    def publish_control(self, control_msg: TensegrityStamped) -> None:
        self.publish_control_msg(control_msg)
