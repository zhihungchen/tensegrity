from setuptools import setup

package_name = 'tensegrity_controller'

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
    description='ROS2 controller for tensegrity',
    license='TODO',
)
