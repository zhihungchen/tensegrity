from setuptools import setup

package_name = 'tensegrity_core'

setup(
    name=package_name,
    version='0.0.0',
    packages=['tensegrity_core', 'tensegrity_core.controllers', 'tensegrity_core.inputs'],
    package_dir={'': '.'},
    install_requires=['setuptools', 'numpy', 'scipy', 'xlrd'],
    zip_safe=True,
    maintainer='pracsys',
    maintainer_email='pracsys@todo.todo',
    description='ROS-free core library for tensegrity robot (no ROS dependency)',
    license='TODO',
)
