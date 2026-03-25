// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from tensegrity_interfaces:msg/Info.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/info__rosidl_typesupport_fastrtps_cpp.hpp"
#include "tensegrity_interfaces/msg/detail/info__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace tensegrity_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensegrity_interfaces
cdr_serialize(
  const tensegrity_interfaces::msg::Info & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: min_length
  cdr << ros_message.min_length;
  // Member: range
  cdr << ros_message.range;
  // Member: max_range
  cdr << ros_message.max_range;
  // Member: min_range
  cdr << ros_message.min_range;
  // Member: range024
  cdr << ros_message.range024;
  // Member: range135
  cdr << ros_message.range135;
  // Member: max_speed
  cdr << ros_message.max_speed;
  // Member: tol
  cdr << ros_message.tol;
  // Member: low_tol
  cdr << ros_message.low_tol;
  // Member: p
  cdr << ros_message.p;
  // Member: i
  cdr << ros_message.i;
  // Member: d
  cdr << ros_message.d;
  // Member: dist_weight
  cdr << ros_message.dist_weight;
  // Member: ang_weight
  cdr << ros_message.ang_weight;
  // Member: prog_weight
  cdr << ros_message.prog_weight;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensegrity_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  tensegrity_interfaces::msg::Info & ros_message)
{
  // Member: min_length
  cdr >> ros_message.min_length;

  // Member: range
  cdr >> ros_message.range;

  // Member: max_range
  cdr >> ros_message.max_range;

  // Member: min_range
  cdr >> ros_message.min_range;

  // Member: range024
  cdr >> ros_message.range024;

  // Member: range135
  cdr >> ros_message.range135;

  // Member: max_speed
  cdr >> ros_message.max_speed;

  // Member: tol
  cdr >> ros_message.tol;

  // Member: low_tol
  cdr >> ros_message.low_tol;

  // Member: p
  cdr >> ros_message.p;

  // Member: i
  cdr >> ros_message.i;

  // Member: d
  cdr >> ros_message.d;

  // Member: dist_weight
  cdr >> ros_message.dist_weight;

  // Member: ang_weight
  cdr >> ros_message.ang_weight;

  // Member: prog_weight
  cdr >> ros_message.prog_weight;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensegrity_interfaces
get_serialized_size(
  const tensegrity_interfaces::msg::Info & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: min_length
  {
    size_t item_size = sizeof(ros_message.min_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: range
  {
    size_t item_size = sizeof(ros_message.range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_range
  {
    size_t item_size = sizeof(ros_message.max_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: min_range
  {
    size_t item_size = sizeof(ros_message.min_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: range024
  {
    size_t item_size = sizeof(ros_message.range024);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: range135
  {
    size_t item_size = sizeof(ros_message.range135);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: max_speed
  {
    size_t item_size = sizeof(ros_message.max_speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: tol
  {
    size_t item_size = sizeof(ros_message.tol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: low_tol
  {
    size_t item_size = sizeof(ros_message.low_tol);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p
  {
    size_t item_size = sizeof(ros_message.p);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: i
  {
    size_t item_size = sizeof(ros_message.i);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: d
  {
    size_t item_size = sizeof(ros_message.d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: dist_weight
  {
    size_t item_size = sizeof(ros_message.dist_weight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ang_weight
  {
    size_t item_size = sizeof(ros_message.ang_weight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: prog_weight
  {
    size_t item_size = sizeof(ros_message.prog_weight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_tensegrity_interfaces
max_serialized_size_Info(
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


  // Member: min_length
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: max_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: min_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: range024
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: range135
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: max_speed
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: tol
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: low_tol
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: i
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: dist_weight
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: ang_weight
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: prog_weight
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
    using DataType = tensegrity_interfaces::msg::Info;
    is_plain =
      (
      offsetof(DataType, prog_weight) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Info__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const tensegrity_interfaces::msg::Info *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Info__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<tensegrity_interfaces::msg::Info *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Info__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const tensegrity_interfaces::msg::Info *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Info__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Info(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Info__callbacks = {
  "tensegrity_interfaces::msg",
  "Info",
  _Info__cdr_serialize,
  _Info__cdr_deserialize,
  _Info__get_serialized_size,
  _Info__max_serialized_size
};

static rosidl_message_type_support_t _Info__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Info__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace tensegrity_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_tensegrity_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<tensegrity_interfaces::msg::Info>()
{
  return &tensegrity_interfaces::msg::typesupport_fastrtps_cpp::_Info__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tensegrity_interfaces, msg, Info)() {
  return &tensegrity_interfaces::msg::typesupport_fastrtps_cpp::_Info__handle;
}

#ifdef __cplusplus
}
#endif
