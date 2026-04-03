#!/usr/bin/env python3
"""Launch RealSense RGB-D publisher with defaults matching pipeline.launch.py topics."""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    rgb_topic = LaunchConfiguration('rgb_topic')
    depth_topic = LaunchConfiguration('depth_topic')

    return LaunchDescription(
        [
            DeclareLaunchArgument('rgb_topic', default_value='/rgb_images'),
            DeclareLaunchArgument('depth_topic', default_value='/depth_images'),
            DeclareLaunchArgument('frame_id', default_value='camera_color_optical_frame'),
            DeclareLaunchArgument('output_dir', default_value=''),
            DeclareLaunchArgument('save_camera_config', default_value='true'),
            DeclareLaunchArgument('enable_preview', default_value='true'),
            Node(
                package='tensegrity_realsense',
                executable='image_publisher_ros2',
                name='realsense_image_publisher',
                output='screen',
                parameters=[
                    {
                        'rgb_topic': rgb_topic,
                        'depth_topic': depth_topic,
                        'frame_id': LaunchConfiguration('frame_id'),
                        'output_dir': LaunchConfiguration('output_dir'),
                        'save_camera_config': ParameterValue(
                            LaunchConfiguration('save_camera_config'), value_type=bool
                        ),
                        'enable_preview': ParameterValue(
                            LaunchConfiguration('enable_preview'), value_type=bool
                        ),
                    }
                ],
            ),
        ]
    )
