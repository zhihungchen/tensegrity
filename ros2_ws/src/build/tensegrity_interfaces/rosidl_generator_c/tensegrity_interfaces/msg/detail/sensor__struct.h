// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/Sensor.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Sensor in the package tensegrity_interfaces.
/**
  * each sensor has a unique id and specifies its length in millimeters and capacitance in picofarads
 */
typedef struct tensegrity_interfaces__msg__Sensor
{
  int8_t id;
  /// mm
  float length;
  /// pf
  float capacitance;
} tensegrity_interfaces__msg__Sensor;

// Struct for a sequence of tensegrity_interfaces__msg__Sensor.
typedef struct tensegrity_interfaces__msg__Sensor__Sequence
{
  tensegrity_interfaces__msg__Sensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__Sensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_H_
