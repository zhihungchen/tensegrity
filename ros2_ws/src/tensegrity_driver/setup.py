from setuptools import setup

package_name = 'tensegrity_driver'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/calibration', ['calibration/calibration_charles.xls']),
        ('share/' + package_name + '/states', ['states/quasi_static.json']),
        ('share/' + package_name + '/examples', ['examples/motor_command_script.example.json']),
        (
            'share/' + package_name + '/motor_scripts',
            ['motor_scripts/motor_command.example.json'],
        ),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='pracsys',
    maintainer_email='pracsys@todo.todo',
    description='ROS2 driver for tensegrity robot',
    license='TODO',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'tensegrity_driver_node = tensegrity_driver.robot_driver:main',
            'robot_driver_direct = tensegrity_driver.robot_driver_direct:main',
            'motor_control_test = tensegrity_driver.motor_control_test:main',
        ],
    },
)
