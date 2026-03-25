// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/StampedIndex.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__STAMPED_INDEX__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__STAMPED_INDEX__STRUCT_H_

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

/// Struct defined in msg/StampedIndex in the package tensegrity_interfaces.
typedef struct tensegrity_interfaces__msg__StampedIndex
{
  std_msgs__msg__Header header;
  int32_t id;
} tensegrity_interfaces__msg__StampedIndex;

// Struct for a sequence of tensegrity_interfaces__msg__StampedIndex.
typedef struct tensegrity_interfaces__msg__StampedIndex__Sequence
{
  tensegrity_interfaces__msg__StampedIndex * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__StampedIndex__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__STAMPED_INDEX__STRUCT_H_
