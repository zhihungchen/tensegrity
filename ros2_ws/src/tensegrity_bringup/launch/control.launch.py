#!/usr/bin/env python3
"""Launch the tensegrity control stack."""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    launch_driver = LaunchConfiguration('launch_driver')
    control_topic = LaunchConfiguration('control_topic')

    return LaunchDescription([
        DeclareLaunchArgument('launch_driver', default_value='true'),
        DeclareLaunchArgument('control_topic', default_value='/control_msg'),

        Node(
            package='tensegrity_driver',
            executable='tensegrity_driver_node',
            name='tensegrity_driver',
            output='screen',
            condition=IfCondition(launch_driver),
            parameters=[
                {'control_topic': control_topic},
            ],
        ),
    ])