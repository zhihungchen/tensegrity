import os
from glob import glob

from setuptools import find_packages, setup

package_name = 'mujoco_simulator_ros2'

_this_dir = os.path.dirname(os.path.abspath(__file__))
_calib_local = os.path.join(_this_dir, 'calibration', 'new_calibration.json')
_calib_files = ['calibration/new_calibration.json'] if os.path.isfile(_calib_local) else []

# Vendored MuJoCo assets (full copy under this package for self-contained tests/install).
_xml_models_root = os.path.join(_this_dir, 'xml_models')


def _collect_xml_models_data_files():
    """Map share/mujoco_simulator_ros2/xml_models/... -> relpaths for setuptools."""
    if not os.path.isdir(_xml_models_root):
        return []
    rows = []
    install_base = 'share/' + package_name + '/xml_models'
    for dirpath, _dirnames, filenames in os.walk(_xml_models_root):
        rel_sub = os.path.relpath(dirpath, _xml_models_root)
        dest = install_base if rel_sub == '.' else os.path.join(install_base, rel_sub)
        rel_files = []
        for name in filenames:
            if name.startswith('.'):
                continue
            full = os.path.join(dirpath, name)
            rel_files.append(os.path.relpath(full, _this_dir))
        if rel_files:
            rows.append((dest, rel_files))
    return rows


_xml_model_data_files = _collect_xml_models_data_files()

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    include_package_data=True,
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.py')),
        ('share/' + package_name + '/scripts', glob('scripts/*')),
        ('share/' + package_name, ['README.md']),
    ]
    + ([('share/' + package_name + '/calibration', _calib_files)] if _calib_files else [])
    + _xml_model_data_files,
    install_requires=['setuptools', 'numpy'],
    zip_safe=False,
    maintainer='pracsys',
    maintainer_email='pracsys@todo.todo',
    description='ROS2 bridge for MuJoCo UDP tensegrity simulator',
    license='TODO',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'udp_simulator_bridge_node = mujoco_simulator_ros2.udp_simulator_bridge_node:main',
            'tensegrity_udp_simulator = mujoco_simulator.tensegrity_udp_simulator:main',
        ],
    },
)
