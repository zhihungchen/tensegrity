#!/usr/bin/env python3
"""Driver + perception tracking (RGB-D + /control_msg). Optional planner nodes via launch args."""
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    share = get_package_share_directory('tensegrity_perception')
    data_cfg = os.path.join(share, 'configs', 'data_cfg.json')
    model_yml = os.path.join(share, 'configs', 'model_params.yaml')
    rod = os.path.join(share, 'mesh', 'rod_strut_placeholder.obj')
    top = os.path.join(share, 'mesh', 'end_cap_top_new.obj')
    bottom = os.path.join(share, 'mesh', 'end_cap_bottom_new.obj')

    rgb_topic = LaunchConfiguration('rgb_topic')
    depth_topic = LaunchConfiguration('depth_topic')
    control_topic = LaunchConfiguration('control_topic')
    trajectory_topic = LaunchConfiguration('trajectory_topic')

    return LaunchDescription(
        [
            DeclareLaunchArgument('rgb_topic', default_value='/rgb_images'),
            DeclareLaunchArgument('depth_topic', default_value='/depth_images'),
            DeclareLaunchArgument('control_topic', default_value='/control_msg'),
            DeclareLaunchArgument('trajectory_topic', default_value='/trajectory_images'),
            DeclareLaunchArgument('launch_driver', default_value='true'),
            DeclareLaunchArgument('launch_perception', default_value='true'),
            DeclareLaunchArgument('launch_astar', default_value='false'),
            DeclareLaunchArgument('launch_rl', default_value='false'),
            Node(
                package='tensegrity_driver',
                executable='tensegrity_driver_node',
                name='tensegrity_driver',
                output='screen',
                condition=IfCondition(LaunchConfiguration('launch_driver')),
            ),
            Node(
                package='tensegrity_perception',
                executable='tracking_node',
                name='tracking_service',
                output='screen',
                condition=IfCondition(LaunchConfiguration('launch_perception')),
                parameters=[
                    {
                        'data_cfg_file': data_cfg,
                        'rod_mesh_file': rod,
                        'top_endcap_mesh_file': top,
                        'bottom_endcap_mesh_file': bottom,
                        'model_params_yaml': model_yml,
                        'rgb_topic': rgb_topic,
                        'depth_topic': depth_topic,
                        'control_topic': control_topic,
                        'trajectory_topic': trajectory_topic,
                    }
                ],
            ),
            Node(
                package='tensegrity_planning',
                executable='astar_planner_node',
                name='astar_planner_node',
                output='screen',
                condition=IfCondition(LaunchConfiguration('launch_astar')),
            ),
            Node(
                package='tensegrity_planning',
                executable='rl_planner_node',
                name='rl_planner_node',
                output='screen',
                condition=IfCondition(LaunchConfiguration('launch_rl')),
            ),
        ]
    )
