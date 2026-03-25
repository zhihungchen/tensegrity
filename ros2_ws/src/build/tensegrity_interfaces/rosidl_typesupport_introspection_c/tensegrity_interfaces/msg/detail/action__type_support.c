// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tensegrity_interfaces:msg/Action.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tensegrity_interfaces/msg/detail/action__rosidl_typesupport_introspection_c.h"
#include "tensegrity_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tensegrity_interfaces/msg/detail/action__functions.h"
#include "tensegrity_interfaces/msg/detail/action__struct.h"


// Include directives for member types
// Member `actions`
#include "rosidl_runtime_c/string_functions.h"
// Member `coms`
// Member `pas`
// Member `endcaps`
#include "geometry_msgs/msg/point.h"
// Member `coms`
// Member `pas`
// Member `endcaps`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tensegrity_interfaces__msg__Action__init(message_memory);
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_fini_function(void * message_memory)
{
  tensegrity_interfaces__msg__Action__fini(message_memory);
}

size_t tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__size_function__Action__actions(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__actions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__actions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__fetch_function__Action__actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__actions(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__assign_function__Action__actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__actions(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__resize_function__Action__actions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__size_function__Action__coms(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__coms(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__coms(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__fetch_function__Action__coms(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__coms(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__assign_function__Action__coms(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__coms(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__resize_function__Action__coms(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__size_function__Action__pas(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__pas(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__pas(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__fetch_function__Action__pas(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__pas(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__assign_function__Action__pas(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__pas(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__resize_function__Action__pas(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__size_function__Action__endcaps(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__endcaps(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__endcaps(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__fetch_function__Action__endcaps(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__endcaps(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__assign_function__Action__endcaps(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__endcaps(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__resize_function__Action__endcaps(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_member_array[8] = {
  {
    "actions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__Action, actions),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__size_function__Action__actions,  // size() function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__actions,  // get_const(index) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__actions,  // get(index) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__fetch_function__Action__actions,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__assign_function__Action__actions,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__resize_function__Action__actions  // resize(index) function pointer
  },
  {
    "cost",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__Action, cost),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "coms",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__Action, coms),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__size_function__Action__coms,  // size() function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__coms,  // get_const(index) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__coms,  // get(index) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__fetch_function__Action__coms,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__assign_function__Action__coms,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__resize_function__Action__coms  // resize(index) function pointer
  },
  {
    "pas",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__Action, pas),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__size_function__Action__pas,  // size() function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__pas,  // get_const(index) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__pas,  // get(index) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__fetch_function__Action__pas,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__assign_function__Action__pas,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__resize_function__Action__pas  // resize(index) function pointer
  },
  {
    "endcaps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__Action, endcaps),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__size_function__Action__endcaps,  // size() function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_const_function__Action__endcaps,  // get_const(index) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__get_function__Action__endcaps,  // get(index) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__fetch_function__Action__endcaps,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__assign_function__Action__endcaps,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__resize_function__Action__endcaps  // resize(index) function pointer
  },
  {
    "dist_weight",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__Action, dist_weight),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ang_weight",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__Action, ang_weight),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "prog_weight",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__Action, prog_weight),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_members = {
  "tensegrity_interfaces__msg",  // message namespace
  "Action",  // message name
  8,  // number of fields
  sizeof(tensegrity_interfaces__msg__Action),
  tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_member_array,  // message members
  tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_init_function,  // function to initialize message memory (memory has to be allocated)
  tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_type_support_handle = {
  0,
  &tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tensegrity_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, Action)() {
  tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_type_support_handle.typesupport_identifier) {
    tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tensegrity_interfaces__msg__Action__rosidl_typesupport_introspection_c__Action_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
