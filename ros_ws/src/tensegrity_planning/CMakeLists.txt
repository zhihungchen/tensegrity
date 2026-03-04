cmake_minimum_required(VERSION 3.0.2)
project(tensegrity_planning)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  geometry_msgs
  tensegrity_interfaces
)

catkin_python_setup()

catkin_package(
  CATKIN_DEPENDS rospy std_msgs geometry_msgs tensegrity_interfaces
)

install(DIRECTORY calibration/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/calibration
)

install(PROGRAMS
  scripts/astar_planner_node.py
  scripts/rl_planner_node.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
