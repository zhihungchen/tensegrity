// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/Info.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Info in the package tensegrity_interfaces.
/**
  * ROS2: field names lowercase per ROS2 convention
 */
typedef struct tensegrity_interfaces__msg__Info
{
  uint8_t min_length;
  uint8_t range;
  uint8_t max_range;
  uint8_t min_range;
  uint8_t range024;
  uint8_t range135;
  int8_t max_speed;
  double tol;
  double low_tol;
  double p;
  double i;
  double d;
  double dist_weight;
  double ang_weight;
  double prog_weight;
} tensegrity_interfaces__msg__Info;

// Struct for a sequence of tensegrity_interfaces__msg__Info.
typedef struct tensegrity_interfaces__msg__Info__Sequence
{
  tensegrity_interfaces__msg__Info * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__Info__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__STRUCT_H_
