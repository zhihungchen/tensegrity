cmake_minimum_required(VERSION 3.8)
project(tensegrity_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Node.msg"
  "msg/Motor.msg"
  "msg/Info.msg"
  "msg/Sensor.msg"
  "msg/Imu.msg"
  "msg/MotorsStamped.msg"
  "msg/SensorsStamped.msg"
  "msg/ImuStamped.msg"
  "msg/NodesStamped.msg"
  "msg/StampedIndex.msg"
  "msg/Trajectory.msg"
  "msg/TensegrityStamped.msg"
  "msg/State.msg"
  "msg/Action.msg"
  DEPENDENCIES std_msgs geometry_msgs
)

ament_package()
