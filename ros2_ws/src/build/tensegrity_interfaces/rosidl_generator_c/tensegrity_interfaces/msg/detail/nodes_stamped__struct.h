// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/NodesStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'reconstructed_nodes'
// Member 'mocap_nodes'
#include "tensegrity_interfaces/msg/detail/node__struct.h"
// Member 'imus'
#include "tensegrity_interfaces/msg/detail/imu__struct.h"

/// Struct defined in msg/NodesStamped in the package tensegrity_interfaces.
/**
  * this is a timestamped message that contains an array of sensor information
 */
typedef struct tensegrity_interfaces__msg__NodesStamped
{
  std_msgs__msg__Header header;
  tensegrity_interfaces__msg__Node__Sequence reconstructed_nodes;
  tensegrity_interfaces__msg__Node__Sequence mocap_nodes;
  tensegrity_interfaces__msg__Imu__Sequence imus;
} tensegrity_interfaces__msg__NodesStamped;

// Struct for a sequence of tensegrity_interfaces__msg__NodesStamped.
typedef struct tensegrity_interfaces__msg__NodesStamped__Sequence
{
  tensegrity_interfaces__msg__NodesStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__NodesStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__STRUCT_H_
