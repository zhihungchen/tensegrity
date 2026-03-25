from setuptools import find_packages
from setuptools import setup

setup(
    name='tensegrity_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('tensegrity_interfaces', 'tensegrity_interfaces.*')),
)
