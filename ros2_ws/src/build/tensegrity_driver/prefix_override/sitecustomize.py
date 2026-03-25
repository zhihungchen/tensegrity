import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/pracsys/Desktop/tensegrity/ros2_ws/src/install/tensegrity_driver'
