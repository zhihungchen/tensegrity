// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tensegrity_interfaces:msg/StampedIndex.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tensegrity_interfaces/msg/detail/stamped_index__rosidl_typesupport_introspection_c.h"
#include "tensegrity_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tensegrity_interfaces/msg/detail/stamped_index__functions.h"
#include "tensegrity_interfaces/msg/detail/stamped_index__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tensegrity_interfaces__msg__StampedIndex__init(message_memory);
}

void tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_fini_function(void * message_memory)
{
  tensegrity_interfaces__msg__StampedIndex__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__StampedIndex, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__StampedIndex, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_members = {
  "tensegrity_interfaces__msg",  // message namespace
  "StampedIndex",  // message name
  2,  // number of fields
  sizeof(tensegrity_interfaces__msg__StampedIndex),
  tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_member_array,  // message members
  tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_init_function,  // function to initialize message memory (memory has to be allocated)
  tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_type_support_handle = {
  0,
  &tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tensegrity_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, StampedIndex)() {
  tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_type_support_handle.typesupport_identifier) {
    tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tensegrity_interfaces__msg__StampedIndex__rosidl_typesupport_introspection_c__StampedIndex_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
