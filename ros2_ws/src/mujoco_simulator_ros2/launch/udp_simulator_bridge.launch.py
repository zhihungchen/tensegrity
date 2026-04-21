"""Launch the ROS2 UDP bridge node (simulator must be started separately with --no-ros)."""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _launch_bridge(context, *args, **kwargs):
    return [
        Node(
            package='mujoco_simulator_ros2',
            executable='udp_simulator_bridge_node',
            name='udp_simulator_bridge',
            output='screen',
            parameters=[
                {
                    'control_pub_topic': LaunchConfiguration('control_pub_topic').perform(context),
                    'control_sub_topic': LaunchConfiguration('control_sub_topic').perform(context),
                    'use_float64_motor_topic': LaunchConfiguration('use_float64_motor_topic').perform(
                        context
                    ).lower()
                    in ('true', '1', 'yes'),
                    'calibration_json': LaunchConfiguration('calibration_json').perform(context),
                }
            ],
        )
    ]


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument('control_pub_topic', default_value='control_msg'),
            DeclareLaunchArgument('control_sub_topic', default_value='control_cmd'),
            DeclareLaunchArgument('use_float64_motor_topic', default_value='false'),
            DeclareLaunchArgument('calibration_json', default_value=''),
            OpaqueFunction(function=_launch_bridge),
        ]
    )
