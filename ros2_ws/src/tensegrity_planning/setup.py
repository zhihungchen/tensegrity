from setuptools import setup

package_name = 'tensegrity_planning'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='pracsys',
    maintainer_email='pracsys@todo.todo',
    description='ROS2 planning for tensegrity',
    license='TODO',
    entry_points={
        'console_scripts': [
            'astar_planner_node = tensegrity_planning.astar_planner_node:main',
            'rl_planner_node = tensegrity_planning.rl_planner_node:main',
        ],
    },
)
