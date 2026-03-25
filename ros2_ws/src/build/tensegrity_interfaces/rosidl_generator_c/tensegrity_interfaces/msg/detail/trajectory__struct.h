// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
// Member 'coms'
// Member 'pas'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Trajectory in the package tensegrity_interfaces.
/**
  * This is a message that represents the trajectory following and MPC predictions for a tensegrity robot.  Trajectory is a sequence of points along the desired trajectory.  coms is a sequence of predicted centers of mass for the robot.  pas is a sequence of predicted principal axis unit vectors.  This message depends on geometry_msgs/Point
 */
typedef struct tensegrity_interfaces__msg__Trajectory
{
  geometry_msgs__msg__Point__Sequence trajectory;
  geometry_msgs__msg__Point__Sequence coms;
  geometry_msgs__msg__Point__Sequence pas;
  int8_t trajectory_segment;
} tensegrity_interfaces__msg__Trajectory;

// Struct for a sequence of tensegrity_interfaces__msg__Trajectory.
typedef struct tensegrity_interfaces__msg__Trajectory__Sequence
{
  tensegrity_interfaces__msg__Trajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__Trajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__STRUCT_H_
