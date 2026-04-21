"""
Optional: launch MuJoCo UDP simulator as subprocess (ROS disabled) + ROS2 bridge.

The simulator lives in the vendored Python package ``mujoco_simulator`` inside
``mujoco_simulator_ros2``. Default XML is under share/xml_models/.

If ``simulator_script`` is empty, the launch file uses the installed console
script ``tensegrity_udp_simulator`` from this package (after ``colcon build``
and ``source install/setup.bash``). Override with an absolute path to
``tensegrity_udp_simulator.py`` for a source checkout, or pass any compatible
executable.

When invoking the ``.py`` file directly, set ``PYTHONPATH`` to the colcon
package root (the directory that contains the ``mujoco_simulator/`` folder).
"""

import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, OpaqueFunction
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

try:
    from ament_index_python.packages import get_package_prefix
except ImportError:
    get_package_prefix = None  # type: ignore


def _launch_setup(context, *args, **kwargs):
    script = LaunchConfiguration('simulator_script').perform(context).strip()
    xml_model = LaunchConfiguration('xml_model').perform(context)
    if not script and get_package_prefix is not None:
        try:
            candidate = os.path.join(
                get_package_prefix('mujoco_simulator_ros2'),
                'lib',
                'mujoco_simulator_ros2',
                'tensegrity_udp_simulator',
            )
            if os.path.isfile(candidate):
                script = candidate
        except Exception:
            pass
    actions = []
    if script and os.path.isfile(script):
        actions.append(
            ExecuteProcess(
                cmd=[script, xml_model, '--no-ros'],
                output='screen',
                shell=False,
            )
        )
    actions.append(
        Node(
            package='mujoco_simulator_ros2',
            executable='udp_simulator_bridge_node',
            name='udp_simulator_bridge',
            output='screen',
            parameters=[
                {
                    'control_pub_topic': LaunchConfiguration('control_pub_topic').perform(context),
                    'control_sub_topic': LaunchConfiguration('control_sub_topic').perform(context),
                    'calibration_json': LaunchConfiguration('calibration_json').perform(context),
                }
            ],
        )
    )
    return actions


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument(
                'simulator_script',
                default_value='',
                description=(
                    'Simulator executable or .py path (empty = use install-space '
                    'tensegrity_udp_simulator if present, else skip subprocess)'
                ),
            ),
            DeclareLaunchArgument(
                'xml_model',
                default_value=PathJoinSubstitution(
                    [
                        FindPackageShare('mujoco_simulator_ros2'),
                        'xml_models',
                        '3bar_new_platform_all_cables.xml',
                    ]
                ),
                description='MuJoCo XML path (default: installed share/xml_models/3bar_new_platform_all_cables.xml)',
            ),
            DeclareLaunchArgument('control_pub_topic', default_value='control_msg'),
            DeclareLaunchArgument('control_sub_topic', default_value='control_cmd'),
            DeclareLaunchArgument('calibration_json', default_value=''),
            OpaqueFunction(function=_launch_setup),
        ]
    )
