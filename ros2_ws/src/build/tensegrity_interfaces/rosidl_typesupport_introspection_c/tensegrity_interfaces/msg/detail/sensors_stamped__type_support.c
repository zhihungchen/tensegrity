// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tensegrity_interfaces:msg/SensorsStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tensegrity_interfaces/msg/detail/sensors_stamped__rosidl_typesupport_introspection_c.h"
#include "tensegrity_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tensegrity_interfaces/msg/detail/sensors_stamped__functions.h"
#include "tensegrity_interfaces/msg/detail/sensors_stamped__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `sensors`
#include "tensegrity_interfaces/msg/sensor.h"
// Member `sensors`
#include "tensegrity_interfaces/msg/detail/sensor__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tensegrity_interfaces__msg__SensorsStamped__init(message_memory);
}

void tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_fini_function(void * message_memory)
{
  tensegrity_interfaces__msg__SensorsStamped__fini(message_memory);
}

size_t tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__size_function__SensorsStamped__sensors(
  const void * untyped_member)
{
  const tensegrity_interfaces__msg__Sensor__Sequence * member =
    (const tensegrity_interfaces__msg__Sensor__Sequence *)(untyped_member);
  return member->size;
}

const void * tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__get_const_function__SensorsStamped__sensors(
  const void * untyped_member, size_t index)
{
  const tensegrity_interfaces__msg__Sensor__Sequence * member =
    (const tensegrity_interfaces__msg__Sensor__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__get_function__SensorsStamped__sensors(
  void * untyped_member, size_t index)
{
  tensegrity_interfaces__msg__Sensor__Sequence * member =
    (tensegrity_interfaces__msg__Sensor__Sequence *)(untyped_member);
  return &member->data[index];
}

void tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__fetch_function__SensorsStamped__sensors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tensegrity_interfaces__msg__Sensor * item =
    ((const tensegrity_interfaces__msg__Sensor *)
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__get_const_function__SensorsStamped__sensors(untyped_member, index));
  tensegrity_interfaces__msg__Sensor * value =
    (tensegrity_interfaces__msg__Sensor *)(untyped_value);
  *value = *item;
}

void tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__assign_function__SensorsStamped__sensors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tensegrity_interfaces__msg__Sensor * item =
    ((tensegrity_interfaces__msg__Sensor *)
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__get_function__SensorsStamped__sensors(untyped_member, index));
  const tensegrity_interfaces__msg__Sensor * value =
    (const tensegrity_interfaces__msg__Sensor *)(untyped_value);
  *item = *value;
}

bool tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__resize_function__SensorsStamped__sensors(
  void * untyped_member, size_t size)
{
  tensegrity_interfaces__msg__Sensor__Sequence * member =
    (tensegrity_interfaces__msg__Sensor__Sequence *)(untyped_member);
  tensegrity_interfaces__msg__Sensor__Sequence__fini(member);
  return tensegrity_interfaces__msg__Sensor__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__SensorsStamped, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sensors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces__msg__SensorsStamped, sensors),  // bytes offset in struct
    NULL,  // default value
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__size_function__SensorsStamped__sensors,  // size() function pointer
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__get_const_function__SensorsStamped__sensors,  // get_const(index) function pointer
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__get_function__SensorsStamped__sensors,  // get(index) function pointer
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__fetch_function__SensorsStamped__sensors,  // fetch(index, &value) function pointer
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__assign_function__SensorsStamped__sensors,  // assign(index, value) function pointer
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__resize_function__SensorsStamped__sensors  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_members = {
  "tensegrity_interfaces__msg",  // message namespace
  "SensorsStamped",  // message name
  2,  // number of fields
  sizeof(tensegrity_interfaces__msg__SensorsStamped),
  tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_member_array,  // message members
  tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_type_support_handle = {
  0,
  &tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tensegrity_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, SensorsStamped)() {
  tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tensegrity_interfaces, msg, Sensor)();
  if (!tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_type_support_handle.typesupport_identifier) {
    tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tensegrity_interfaces__msg__SensorsStamped__rosidl_typesupport_introspection_c__SensorsStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
