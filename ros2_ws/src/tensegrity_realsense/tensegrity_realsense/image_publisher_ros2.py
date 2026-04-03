#!/usr/bin/env python3
"""ROS 2 RealSense RGB-D publisher (port of src/image_publisher.py)."""
import json
import os
import threading
import time
from typing import Optional

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from rclpy.qos import HistoryPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Image


class RealSenseImagePublisher(Node):
    """Streams aligned color + depth to ROS topics; optional OpenCV preview and disk capture."""

    def __init__(self):
        super().__init__('realsense_image_publisher')

        self.declare_parameter('rgb_topic', '/rgb_images')
        self.declare_parameter('depth_topic', '/depth_images')
        self.declare_parameter('frame_id', 'camera_color_optical_frame')
        self.declare_parameter('color_width', 640)
        self.declare_parameter('color_height', 480)
        self.declare_parameter('depth_width', 640)
        self.declare_parameter('depth_height', 480)
        self.declare_parameter('fps', 30)
        self.declare_parameter('output_dir', '')
        self.declare_parameter('save_camera_config', True)
        self.declare_parameter('enable_preview', True)

        qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
        )
        rgb_t = self.get_parameter('rgb_topic').get_parameter_value().string_value
        depth_t = self.get_parameter('depth_topic').get_parameter_value().string_value
        self._frame_id = self.get_parameter('frame_id').get_parameter_value().string_value

        self._bridge = CvBridge()
        self._color_pub = self.create_publisher(Image, rgb_t, qos)
        self._depth_pub = self.create_publisher(Image, depth_t, qos)

        self._output_dir = self.get_parameter('output_dir').get_parameter_value().string_value.strip()
        self._save_camera_config = (
            self.get_parameter('save_camera_config').get_parameter_value().bool_value
        )
        self._enable_preview = self.get_parameter('enable_preview').get_parameter_value().bool_value

        cw = self.get_parameter('color_width').get_parameter_value().integer_value
        ch = self.get_parameter('color_height').get_parameter_value().integer_value
        dw = self.get_parameter('depth_width').get_parameter_value().integer_value
        dh = self.get_parameter('depth_height').get_parameter_value().integer_value
        fps = self.get_parameter('fps').get_parameter_value().integer_value
        if fps < 1:
            fps = 30

        # Built in capture thread after lazy-import of pyrealsense2 (optional pip dep).
        self._color_w, self._color_h = cw, ch
        self._depth_w, self._depth_h = dw, dh
        self._fps = fps

        self._quit = threading.Event()
        self._capture_thread: Optional[threading.Thread] = None
        self._period = 1.0 / float(fps)

    def start_capture_thread(self):
        self._capture_thread = threading.Thread(target=self._capture_loop, daemon=True)
        self._capture_thread.start()

    def stop_capture_thread(self):
        self._quit.set()
        if self._capture_thread is not None:
            self._capture_thread.join(timeout=15.0)
            self._capture_thread = None

    def _ensure_output_dirs(self):
        if not self._output_dir:
            return
        os.makedirs(self._output_dir, exist_ok=True)
        os.makedirs(os.path.join(self._output_dir, 'color'), exist_ok=True)
        os.makedirs(os.path.join(self._output_dir, 'depth'), exist_ok=True)

    def _write_camera_config(self, output_dir: str, color_intrinsics, depth_scale: int):
        cam_info = {
            'id': os.path.basename(output_dir) or 'realsense',
            'im_w': color_intrinsics.width,
            'im_h': color_intrinsics.height,
            'depth_scale': depth_scale,
            'cam_intr': [
                [color_intrinsics.fx, 0.0, color_intrinsics.ppx],
                [0.0, color_intrinsics.fy, color_intrinsics.ppy],
                [0.0, 0.0, 1.0],
            ],
        }
        path = os.path.join(output_dir, 'config.json')
        with open(path, 'w', encoding='utf-8') as f:
            json.dump(cam_info, f, indent=4)
        self.get_logger().info('Camera info saved to %s' % path)

    def _capture_loop(self):
        try:
            import pyrealsense2 as rs
        except ImportError:
            self.get_logger().fatal(
                'Missing pyrealsense2. Install Intel RealSense Python bindings for the same '
                'Python as ROS 2, e.g.: python3 -m pip install pyrealsense2'
            )
            rclpy.shutdown()
            return

        rs_config = rs.config()
        # L515: depth 1024x768 z16, color 1280x720 bgr8 @ 30
        # D435 / default: 640x480 (see original src/image_publisher.py)
        rs_config.enable_stream(
            rs.stream.depth, self._depth_w, self._depth_h, rs.format.z16, self._fps
        )
        rs_config.enable_stream(
            rs.stream.color, self._color_w, self._color_h, rs.format.bgr8, self._fps
        )

        self._ensure_output_dirs()
        pipeline = rs.pipeline()
        try:
            profile = pipeline.start(rs_config)
        except Exception as e:
            self.get_logger().error('Failed to start RealSense pipeline: %s' % e)
            rclpy.shutdown()
            return

        align = rs.align(rs.stream.color)
        color_profile = rs.video_stream_profile(profile.get_stream(rs.stream.color))
        color_intrinsics = color_profile.get_intrinsics()
        self.get_logger().info('Camera intrinsics: %s' % color_intrinsics)

        depth_sensor = profile.get_device().first_depth_sensor()
        depth_scale = int(round(1.0 / depth_sensor.get_depth_scale()))
        self.get_logger().info('Depth scale: %s' % depth_scale)

        if self._save_camera_config and self._output_dir:
            self._write_camera_config(self._output_dir, color_intrinsics, depth_scale)

        save_frames = False
        save_count = 0

        preview_active = False
        if self._enable_preview:
            try:
                cv2.namedWindow('RealSense', cv2.WINDOW_AUTOSIZE)
                preview_active = True
            except cv2.error as e:
                self.get_logger().warning(
                    'OpenCV has no GUI backend (often opencv-python-headless). For a live '
                    'window: python3 -m pip uninstall -y opencv-python-headless && '
                    'python3 -m pip install opencv-python. On Ubuntu you may need '
                    'libgtk-3-0. Error was: %s. Publishing without preview; or use rqt_image_view.'
                    % e
                )

        try:
            while rclpy.ok() and not self._quit.is_set():
                t0 = time.monotonic()
                try:
                    # Short timeout so Ctrl+C / shutdown stops the thread quickly (not stuck in wait).
                    frames = pipeline.wait_for_frames(timeout_ms=250)
                except Exception:
                    if self._quit.is_set() or not rclpy.ok():
                        break
                    continue
                aligned = align.process(frames)
                depth_frame = aligned.get_depth_frame()
                color_frame = aligned.get_color_frame()
                if not depth_frame or not color_frame:
                    continue

                depth_image = np.asanyarray(depth_frame.get_data())
                color_image = np.asanyarray(color_frame.get_data())

                stamp = self.get_clock().now().to_msg()
                color_msg = self._bridge.cv2_to_imgmsg(
                    cv2.cvtColor(color_image, cv2.COLOR_BGR2RGB), 'rgb8'
                )
                depth_msg = self._bridge.cv2_to_imgmsg(depth_image, 'mono16')
                color_msg.header.stamp = stamp
                depth_msg.header.stamp = stamp
                color_msg.header.frame_id = self._frame_id
                depth_msg.header.frame_id = self._frame_id

                try:
                    self._color_pub.publish(color_msg)
                    self._depth_pub.publish(depth_msg)
                except Exception:
                    break

                if preview_active:
                    depth_colormap = cv2.applyColorMap(
                        cv2.convertScaleAbs(depth_image, alpha=0.03), cv2.COLORMAP_JET
                    )
                    images = np.hstack((color_image, depth_colormap))
                    cv2.imshow('RealSense', images)
                    key = cv2.waitKey(1)
                    if (key & 0xFF) == ord('q'):
                        self._quit.set()
                        rclpy.shutdown()
                        break
                    if (key & 0xFF) == ord('s'):
                        save_frames = True
                        self.get_logger().info('Saving images to %s' % self._output_dir)
                    if save_frames and self._output_dir:
                        cv2.imwrite(
                            os.path.join(self._output_dir, 'color', str(save_count).zfill(4) + '.png'),
                            color_image,
                        )
                        cv2.imwrite(
                            os.path.join(self._output_dir, 'depth', str(save_count).zfill(4) + '.png'),
                            depth_image,
                        )
                        save_count += 1
                        if save_count % 50 == 0:
                            self.get_logger().info('%d frames saved.' % save_count)

                elapsed = time.monotonic() - t0
                sleep_t = self._period - elapsed
                if sleep_t > 0:
                    time.sleep(sleep_t)
        finally:
            if preview_active:
                try:
                    cv2.destroyWindow('RealSense')
                except cv2.error:
                    pass
            pipeline.stop()


def main(args=None):
    rclpy.init(args=args)
    node = RealSenseImagePublisher()
    node.start_capture_thread()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.stop_capture_thread()
        try:
            node.destroy_node()
        except Exception:
            pass
        try:
            if rclpy.ok():
                rclpy.shutdown()
        except Exception:
            pass


if __name__ == '__main__':
    main()
