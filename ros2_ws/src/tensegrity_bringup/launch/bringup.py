#!/usr/bin/env python3
"""Launch tensegrity driver (and optionally planning nodes)."""
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tensegrity_driver',
            executable='tensegrity_driver_node',
            name='tensegrity_driver',
            output='screen',
        ),
    ])
