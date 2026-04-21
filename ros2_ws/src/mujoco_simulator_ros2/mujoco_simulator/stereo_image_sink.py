"""Optional stereo image publishing (ROS1); core simulator stays import-clean."""

from __future__ import annotations

from typing import Optional

import numpy as np


class StereoImageSink:
    """Publishes mock RGB + depth from the simulator camera thread."""

    @property
    def enabled(self) -> bool:
        return False

    def publish_rgb_depth(self, rgb: np.ndarray, depth_u16: np.ndarray) -> None:
        return


class NullStereoImageSink(StereoImageSink):
    @property
    def enabled(self) -> bool:
        return False

    def publish_rgb_depth(self, rgb: np.ndarray, depth_u16: np.ndarray) -> None:
        return


class Ros1StereoImageSink(StereoImageSink):
    """sensor_msgs Image publishing via rospy + cv_bridge (ROS1 only)."""

    def __init__(
        self,
        rgb_topic: str = "rgb_images",
        depth_topic: str = "depth_images",
        node_name: str = "tensegrity_udp_simulator",
    ):
        import rospy
        from cv_bridge import CvBridge
        from sensor_msgs.msg import Image

        try:
            rospy.init_node(node_name, anonymous=True)
        except rospy.exceptions.ROSException:
            pass
        self._bridge = CvBridge()
        self._rgb_pub = rospy.Publisher(rgb_topic, Image, queue_size=6)
        self._depth_pub = rospy.Publisher(depth_topic, Image, queue_size=6)

    @property
    def enabled(self) -> bool:
        return True

    def publish_rgb_depth(self, rgb: np.ndarray, depth_u16: np.ndarray) -> None:
        import rospy

        timestamp = rospy.get_rostime()
        color_msg = self._bridge.cv2_to_imgmsg(rgb, "rgb8")
        depth_msg = self._bridge.cv2_to_imgmsg(depth_u16, "mono16")
        color_msg.header.stamp = timestamp
        depth_msg.header.stamp = timestamp
        self._rgb_pub.publish(color_msg)
        self._depth_pub.publish(depth_msg)


def build_default_stereo_image_sink(enable: bool, sink: Optional[StereoImageSink] = None) -> StereoImageSink:
    """
    If sink is provided, return it.
    If enable is False, return NullStereoImageSink.
    Otherwise try ROS1 implementation; on ImportError return Null and warn once.
    """
    if sink is not None:
        return sink
    if not enable:
        return NullStereoImageSink()
    try:
        return Ros1StereoImageSink()
    except ImportError:
        print("Warning: ROS not available. Camera publishing will be disabled.")
        return NullStereoImageSink()
