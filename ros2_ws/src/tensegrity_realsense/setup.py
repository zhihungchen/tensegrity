from setuptools import find_packages, setup

package_name = 'tensegrity_realsense'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/image_publisher_ros2.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='pracsys',
    maintainer_email='pracsys@todo.todo',
    description='RealSense RGB-D publisher for tensegrity ROS2 stack',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'image_publisher_ros2 = tensegrity_realsense.image_publisher_ros2:main',
        ],
    },
)
