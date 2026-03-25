// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tensegrity_interfaces:msg/Motor.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__STRUCT_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Motor in the package tensegrity_interfaces.
/**
  * each motor has a unique id and specifies its target length, current position, and commanded speed.  Speed is positive if the motor is extending and negative if it is contracting.  Done is true if the motor has reached the target within the tolerance.  The three error terms (proportional, derivative, and cumulative) are those used in the PID calculation for this motor.  The other two fields are the raw encoder counts and the tendon length as measured by the encoder, taking into account the encoder's resolution, the gear ratio, and the winch diameter.
 */
typedef struct tensegrity_interfaces__msg__Motor
{
  int8_t id;
  double position;
  double target;
  double speed;
  bool done;
  double error;
  double d_error;
  double cum_error;
  int64_t encoder_counts;
  double encoder_length;
} tensegrity_interfaces__msg__Motor;

// Struct for a sequence of tensegrity_interfaces__msg__Motor.
typedef struct tensegrity_interfaces__msg__Motor__Sequence
{
  tensegrity_interfaces__msg__Motor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tensegrity_interfaces__msg__Motor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__STRUCT_H_
