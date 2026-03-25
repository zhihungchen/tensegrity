// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/ImuStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__STRUCT_H_

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
// Member 'imus'
#include "tensegrity_interfaces/msg/detail/imu__struct.h"

/// Struct defined in msg/ImuStamped in the package tensegrity_interfaces.
/**
  * the acceleration in x,y,z and the global orientation angles from the IMU
 */
typedef struct tensegrity_interfaces__msg__ImuStamped
{
  std_msgs__msg__Header header;
  tensegrity_interfaces__msg__Imu__Sequence imus;
} tensegrity_interfaces__msg__ImuStamped;

// Struct for a sequence of tensegrity_interfaces__msg__ImuStamped.
typedef struct tensegrity_interfaces__msg__ImuStamped__Sequence
{
  tensegrity_interfaces__msg__ImuStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__ImuStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__STRUCT_H_
