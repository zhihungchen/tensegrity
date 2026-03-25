// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__STRUCT_H_

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
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'prev_action'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/State in the package tensegrity_interfaces.
/**
  * This is a message that represents state of a tensegrity robot to be passed to a model-predictive controller.  Trajectory is a sequence of waypoints along the desired trajectory.  prev_action is the previous action that MPC will use as a key to its internal lookup table.  reverse_the_gait is a boolean that tells the planner if the robot is rolling forward or backward during this segment of the trajectory.  This message depends on geometry_msgs/Point.
 */
typedef struct tensegrity_interfaces__msg__State
{
  geometry_msgs__msg__Point__Sequence trajectory;
  rosidl_runtime_c__String prev_action;
  bool reverse_the_gait;
  bool bar_height_changed;
} tensegrity_interfaces__msg__State;

// Struct for a sequence of tensegrity_interfaces__msg__State.
typedef struct tensegrity_interfaces__msg__State__Sequence
{
  tensegrity_interfaces__msg__State * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__State__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__STRUCT_H_
