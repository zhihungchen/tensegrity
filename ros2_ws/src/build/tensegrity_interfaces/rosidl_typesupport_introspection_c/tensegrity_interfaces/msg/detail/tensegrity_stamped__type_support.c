// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tensegrity_interfaces:msg/TensegrityStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__rosidl_typesupport_introspection_c.h"
#include "tensegrity_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__functions.h"
#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `info`
#include "tensegrity_interfaces/msg/info.h"
// Member `info`
#include "tensegrity_interfaces/msg/detail/info__rosidl_typesupport_introspection_c.h"
// Member `motors`
#include "tensegrity_interfaces/msg/motor.h"
// Member `motors`
#include "tensegrity_interfaces/msg/detail/motor__rosidl_typesupport_introspection_c.h"
// Member `sensors`
#include "tensegrity_interfaces/msg/sensor.h"
// Member `sensors`
#include "tensegrity_interfaces/msg/detail/sensor__rosidl_typesupport_introspection_c.h"
// Member `imus`
#include "tensegrity_interfaces/msg/imu.h"
// Member `imus`
#include "tensegrity_interfaces/msg/detail/imu__rosidl_typesupport_introspection_c.h"
// Member `nodes`
#include "tensegrity_interfaces/msg/node.h"
// Member `nodes`
#include "tensegrity_interfaces/msg/detail/node__rosidl_typesupport_introspection_c.h"
// Member `trajectory`
#include "tensegrity_interfaces/msg/trajectory.h"
// Member `trajectory`
#include "tensegrity_interfaces/msg/detail/trajectory__rosidl_typesupport_introspection_c.h"
// Member `actions`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tensegrity_interfaces__msg__TensegrityStamped__init(message_memory);
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_fini_function(void * message_memory)
{
  tensegrity_interfaces__msg__TensegrityStamped__fini(message_memory);
}

size_t tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__motors(
  const void * untyped_member)
{
  const tensegrity_interfaces__msg__Motor__Sequence * member =
    (const tensegrity_interfaces__msg__Motor__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__motors(
  const void * untyped_member, size_t index)
{
  const tensegrity_interfaces__msg__Motor__Sequence * member =
    (const tensegrity_interfaces__msg__Motor__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__motors(
  void * untyped_member, size_t index)
{
  tensegrity_interfaces__msg__Motor__Sequence * member =
    (tensegrity_interfaces__msg__Motor__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__motors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tensegrity_interfaces__msg__Motor * item =
    ((const tensegrity_interfaces__msg__Motor *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__motors(untyped_member, index));
  tensegrity_interfaces__msg__Motor * value =
    (tensegrity_interfaces__msg__Motor *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__motors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tensegrity_interfaces__msg__Motor * item =
    ((tensegrity_interfaces__msg__Motor *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__motors(untyped_member, index));
  const tensegrity_interfaces__msg__Motor * value =
    (const tensegrity_interfaces__msg__Motor *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__motors(
  void * untyped_member, size_t size)
{
  tensegrity_interfaces__msg__Motor__Sequence * member =
    (tensegrity_interfaces__msg__Motor__Sequence *)(untyped_member);
  tensegrity_interfaces__msg__Motor__Sequence__fini(member);
  return tensegrity_interfaces__msg__Motor__Sequence__init(member, size);
}

size_t tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__sensors(
  const void * untyped_member)
{
  const tensegrity_interfaces__msg__Sensor__Sequence * member =
    (const tensegrity_interfaces__msg__Sensor__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__sensors(
  const void * untyped_member, size_t index)
{
  const tensegrity_interfaces__msg__Sensor__Sequence * member =
    (const tensegrity_interfaces__msg__Sensor__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__sensors(
  void * untyped_member, size_t index)
{
  tensegrity_interfaces__msg__Sensor__Sequence * member =
    (tensegrity_interfaces__msg__Sensor__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__sensors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tensegrity_interfaces__msg__Sensor * item =
    ((const tensegrity_interfaces__msg__Sensor *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__sensors(untyped_member, index));
  tensegrity_interfaces__msg__Sensor * value =
    (tensegrity_interfaces__msg__Sensor *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__sensors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tensegrity_interfaces__msg__Sensor * item =
    ((tensegrity_interfaces__msg__Sensor *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__sensors(untyped_member, index));
  const tensegrity_interfaces__msg__Sensor * value =
    (const tensegrity_interfaces__msg__Sensor *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__sensors(
  void * untyped_member, size_t size)
{
  tensegrity_interfaces__msg__Sensor__Sequence * member =
    (tensegrity_interfaces__msg__Sensor__Sequence *)(untyped_member);
  tensegrity_interfaces__msg__Sensor__Sequence__fini(member);
  return tensegrity_interfaces__msg__Sensor__Sequence__init(member, size);
}

size_t tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__imus(
  const void * untyped_member)
{
  const tensegrity_interfaces__msg__Imu__Sequence * member =
    (const tensegrity_interfaces__msg__Imu__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__imus(
  const void * untyped_member, size_t index)
{
  const tensegrity_interfaces__msg__Imu__Sequence * member =
    (const tensegrity_interfaces__msg__Imu__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__imus(
  void * untyped_member, size_t index)
{
  tensegrity_interfaces__msg__Imu__Sequence * member =
    (tensegrity_interfaces__msg__Imu__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__imus(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tensegrity_interfaces__msg__Imu * item =
    ((const tensegrity_interfaces__msg__Imu *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__imus(untyped_member, index));
  tensegrity_interfaces__msg__Imu * value =
    (tensegrity_interfaces__msg__Imu *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__imus(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tensegrity_interfaces__msg__Imu * item =
    ((tensegrity_interfaces__msg__Imu *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__imus(untyped_member, index));
  const tensegrity_interfaces__msg__Imu * value =
    (const tensegrity_interfaces__msg__Imu *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__imus(
  void * untyped_member, size_t size)
{
  tensegrity_interfaces__msg__Imu__Sequence * member =
    (tensegrity_interfaces__msg__Imu__Sequence *)(untyped_member);
  tensegrity_interfaces__msg__Imu__Sequence__fini(member);
  return tensegrity_interfaces__msg__Imu__Sequence__init(member, size);
}

size_t tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__nodes(
  const void * untyped_member)
{
  const tensegrity_interfaces__msg__Node__Sequence * member =
    (const tensegrity_interfaces__msg__Node__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__nodes(
  const void * untyped_member, size_t index)
{
  const tensegrity_interfaces__msg__Node__Sequence * member =
    (const tensegrity_interfaces__msg__Node__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__nodes(
  void * untyped_member, size_t index)
{
  tensegrity_interfaces__msg__Node__Sequence * member =
    (tensegrity_interfaces__msg__Node__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__nodes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tensegrity_interfaces__msg__Node * item =
    ((const tensegrity_interfaces__msg__Node *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__nodes(untyped_member, index));
  tensegrity_interfaces__msg__Node * value =
    (tensegrity_interfaces__msg__Node *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__nodes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tensegrity_interfaces__msg__Node * item =
    ((tensegrity_interfaces__msg__Node *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__nodes(untyped_member, index));
  const tensegrity_interfaces__msg__Node * value =
    (const tensegrity_interfaces__msg__Node *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__nodes(
  void * untyped_member, size_t size)
{
  tensegrity_interfaces__msg__Node__Sequence * member =
    (tensegrity_interfaces__msg__Node__Sequence *)(untyped_member);
  tensegrity_interfaces__msg__Node__Sequence__fini(member);
  return tensegrity_interfaces__msg__Node__Sequence__init(member, size);
}

size_t tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__actions(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__actions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__actions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__actions(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__actions(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__actions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__TensegrityStamped, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__TensegrityStamped, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__TensegrityStamped, motors),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__motors,  // size() function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__motors,  // get_const(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__motors,  // get(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__motors,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__motors,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__motors  // resize(index) function pointer
  },
  {
    "sensors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__TensegrityStamped, sensors),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__sensors,  // size() function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__sensors,  // get_const(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__sensors,  // get(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__sensors,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__sensors,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__sensors  // resize(index) function pointer
  },
  {
    "imus",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__TensegrityStamped, imus),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__imus,  // size() function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__imus,  // get_const(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__imus,  // get(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__imus,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__imus,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__imus  // resize(index) function pointer
  },
  {
    "nodes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__TensegrityStamped, nodes),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__nodes,  // size() function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__nodes,  // get_const(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__nodes,  // get(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__nodes,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__nodes,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__nodes  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__TensegrityStamped, trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "actions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__TensegrityStamped, actions),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__size_function__TensegrityStamped__actions,  // size() function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_const_function__TensegrityStamped__actions,  // get_const(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__get_function__TensegrityStamped__actions,  // get(index) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__fetch_function__TensegrityStamped__actions,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__assign_function__TensegrityStamped__actions,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__resize_function__TensegrityStamped__actions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_members = {
  "tensegrity_interfaces__msg",  // message namespace
  "TensegrityStamped",  // message name
  8,  // number of fields
  sizeof(tensegrity_interfaces__msg__TensegrityStamped),
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array,  // message members
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_type_support_handle = {
  0,
  &tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tensegrity_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, TensegrityStamped)() {
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, Info)();
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, Motor)();
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, Sensor)();
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, Imu)();
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, Node)();
  tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, Trajectory)();
  if (!tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_type_support_handle.typesupport_identifier) {
    tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tensegrity_interfaces__msg__TensegrityStamped__rosidl_typesupport_introspection_c__TensegrityStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
