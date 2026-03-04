from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
    packages=['tensegrity_core', 'tensegrity_core.controllers', 'tensegrity_core.inputs'],
    package_dir={'': 'src'},
)

setup(**d)
