// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Imu in the package tensegrity_interfaces.
/**
  * the global orientation of the bar according to the IMU
  * this message encodes a unit vector pointing in the y-direction of the IMU given by id
 */
typedef struct tensegrity_interfaces__msg__Imu
{
  int8_t id;
  double x;
  double y;
  double z;
  /// float64 q1
  /// float64 q2
  /// float64 q3
  /// float64 q4
  double ax;
  double ay;
  double az;
  double gx;
  double gy;
  double gz;
  double mx;
  double my;
  double mz;
} tensegrity_interfaces__msg__Imu;

// Struct for a sequence of tensegrity_interfaces__msg__Imu.
typedef struct tensegrity_interfaces__msg__Imu__Sequence
{
  tensegrity_interfaces__msg__Imu * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__Imu__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__STRUCT_H_
