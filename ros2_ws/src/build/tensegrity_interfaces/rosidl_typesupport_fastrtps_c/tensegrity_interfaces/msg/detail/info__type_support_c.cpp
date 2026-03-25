// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tensegrity_interfaces:msg/Info.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/info__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tensegrity_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tensegrity_interfaces/msg/detail/info__struct.h"
#include "tensegrity_interfaces/msg/detail/info__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Info__ros_msg_type = tensegrity_interfaces__msg__Info;

static bool _Info__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Info__ros_msg_type * ros_message = static_cast<const _Info__ros_msg_type *>(untyped_ros_message);
  // Field name: min_length
  {
    cdr << ros_message->min_length;
  }

  // Field name: range
  {
    cdr << ros_message->range;
  }

  // Field name: max_range
  {
    cdr << ros_message->max_range;
  }

  // Field name: min_range
  {
    cdr << ros_message->min_range;
  }

  // Field name: range024
  {
    cdr << ros_message->range024;
  }

  // Field name: range135
  {
    cdr << ros_message->range135;
  }

  // Field name: max_speed
  {
    cdr << ros_message->max_speed;
  }

  // Field name: tol
  {
    cdr << ros_message->tol;
  }

  // Field name: low_tol
  {
    cdr << ros_message->low_tol;
  }

  // Field name: p
  {
    cdr << ros_message->p;
  }

  // Field name: i
  {
    cdr << ros_message->i;
  }

  // Field name: d
  {
    cdr << ros_message->d;
  }

  // Field name: dist_weight
  {
    cdr << ros_message->dist_weight;
  }

  // Field name: ang_weight
  {
    cdr << ros_message->ang_weight;
  }

  // Field name: prog_weight
  {
    cdr << ros_message->prog_weight;
  }

  return true;
}

static bool _Info__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Info__ros_msg_type * ros_message = static_cast<_Info__ros_msg_type *>(untyped_ros_message);
  // Field name: min_length
  {
    cdr >> ros_message->min_length;
  }

  // Field name: range
  {
    cdr >> ros_message->range;
  }

  // Field name: max_range
  {
    cdr >> ros_message->max_range;
  }

  // Field name: min_range
  {
    cdr >> ros_message->min_range;
  }

  // Field name: range024
  {
    cdr >> ros_message->range024;
  }

  // Field name: range135
  {
    cdr >> ros_message->range135;
  }

  // Field name: max_speed
  {
    cdr >> ros_message->max_speed;
  }

  // Field name: tol
  {
    cdr >> ros_message->tol;
  }

  // Field name: low_tol
  {
    cdr >> ros_message->low_tol;
  }

  // Field name: p
  {
    cdr >> ros_message->p;
  }

  // Field name: i
  {
    cdr >> ros_message->i;
  }

  // Field name: d
  {
    cdr >> ros_message->d;
  }

  // Field name: dist_weight
  {
    cdr >> ros_message->dist_weight;
  }

  // Field name: ang_weight
  {
    cdr >> ros_message->ang_weight;
  }

  // Field name: prog_weight
  {
    cdr >> ros_message->prog_weight;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tensegrity_interfaces
size_t get_serialized_size_tensegrity_interfaces__msg__Info(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Info__ros_msg_type * ros_message = static_cast<const _Info__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name min_length
  {
    size_t item_size = sizeof(ros_message->min_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name range
  {
    size_t item_size = sizeof(ros_message->range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_range
  {
    size_t item_size = sizeof(ros_message->max_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name min_range
  {
    size_t item_size = sizeof(ros_message->min_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name range024
  {
    size_t item_size = sizeof(ros_message->range024);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name range135
  {
    size_t item_size = sizeof(ros_message->range135);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name max_speed
  {
    size_t item_size = sizeof(ros_message->max_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tol
  {
    size_t item_size = sizeof(ros_message->tol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name low_tol
  {
    size_t item_size = sizeof(ros_message->low_tol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p
  {
    size_t item_size = sizeof(ros_message->p);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name i
  {
    size_t item_size = sizeof(ros_message->i);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name d
  {
    size_t item_size = sizeof(ros_message->d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name dist_weight
  {
    size_t item_size = sizeof(ros_message->dist_weight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ang_weight
  {
    size_t item_size = sizeof(ros_message->ang_weight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name prog_weight
  {
    size_t item_size = sizeof(ros_message->prog_weight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Info__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tensegrity_interfaces__msg__Info(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tensegrity_interfaces
size_t max_serialized_size_tensegrity_interfaces__msg__Info(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: min_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: max_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: min_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: range024
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: range135
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: max_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: tol
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: low_tol
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: i
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: dist_weight
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: ang_weight
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: prog_weight
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tensegrity_interfaces__msg__Info;
    is_plain =
      (
      offsetof(DataType, prog_weight) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Info__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tensegrity_interfaces__msg__Info(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Info = {
  "tensegrity_interfaces::msg",
  "Info",
  _Info__cdr_serialize,
  _Info__cdr_deserialize,
  _Info__get_serialized_size,
  _Info__max_serialized_size
};

static rosidl_message_type_support_t _Info__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Info,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tensegrity_interfaces, msg, Info)() {
  return &_Info__type_support;
}

#if defined(__cplusplus)
}
#endif
