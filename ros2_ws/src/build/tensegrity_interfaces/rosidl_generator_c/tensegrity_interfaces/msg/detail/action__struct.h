// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/Action.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'actions'
#include "rosidl_runtime_c/string.h"
// Member 'coms'
// Member 'pas'
// Member 'endcaps'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Action in the package tensegrity_interfaces.
/**
  * This is a message that represents the MPC-selected actions for a tensegrity robot.  The variable actions is a sequence of k strings that represent the depth-k motion plan from MPC.  coms and pas are the current center of mass and principal axis plus the k predicted future coms and pas corresponding to the selected sequence of actions. This message depends on geometry_msgs/Point.
 */
typedef struct tensegrity_interfaces__msg__Action
{
  rosidl_runtime_c__String__Sequence actions;
  double cost;
  geometry_msgs__msg__Point__Sequence coms;
  geometry_msgs__msg__Point__Sequence pas;
  geometry_msgs__msg__Point__Sequence endcaps;
  double dist_weight;
  double ang_weight;
  double prog_weight;
} tensegrity_interfaces__msg__Action;

// Struct for a sequence of tensegrity_interfaces__msg__Action.
typedef struct tensegrity_interfaces__msg__Action__Sequence
{
  tensegrity_interfaces__msg__Action * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__Action__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__STRUCT_H_
