// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/MotorsStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__STRUCT_H_

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
// Member 'info'
#include "tensegrity_interfaces/msg/detail/info__struct.h"
// Member 'motors'
#include "tensegrity_interfaces/msg/detail/motor__struct.h"

/// Struct defined in msg/MotorsStamped in the package tensegrity_interfaces.
/**
  * this is a timestamped message that contains an array of motor control information
 */
typedef struct tensegrity_interfaces__msg__MotorsStamped
{
  std_msgs__msg__Header header;
  tensegrity_interfaces__msg__Info info;
  tensegrity_interfaces__msg__Motor__Sequence motors;
} tensegrity_interfaces__msg__MotorsStamped;

// Struct for a sequence of tensegrity_interfaces__msg__MotorsStamped.
typedef struct tensegrity_interfaces__msg__MotorsStamped__Sequence
{
  tensegrity_interfaces__msg__MotorsStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__MotorsStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__STRUCT_H_
