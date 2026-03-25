// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tensegrity_interfaces:msg/ImuStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tensegrity_interfaces/msg/detail/imu_stamped__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tensegrity_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ImuStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tensegrity_interfaces::msg::ImuStamped(_init);
}

void ImuStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tensegrity_interfaces::msg::ImuStamped *>(message_memory);
  typed_message->~ImuStamped();
}

size_t size_function__ImuStamped__imus(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Imu> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ImuStamped__imus(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Imu> *>(untyped_member);
  return &member[index];
}

void * get_function__ImuStamped__imus(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tensegrity_interfaces::msg::Imu> *>(untyped_member);
  return &member[index];
}

void fetch_function__ImuStamped__imus(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tensegrity_interfaces::msg::Imu *>(
    get_const_function__ImuStamped__imus(untyped_member, index));
  auto & value = *reinterpret_cast<tensegrity_interfaces::msg::Imu *>(untyped_value);
  value = item;
}

void assign_function__ImuStamped__imus(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tensegrity_interfaces::msg::Imu *>(
    get_function__ImuStamped__imus(untyped_member, index));
  const auto & value = *reinterpret_cast<const tensegrity_interfaces::msg::Imu *>(untyped_value);
  item = value;
}

void resize_function__ImuStamped__imus(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tensegrity_interfaces::msg::Imu> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ImuStamped_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::ImuStamped, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "imus",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tensegrity_interfaces::msg::Imu>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::ImuStamped, imus),  // bytes offset in struct
    nullptr,  // default value
    size_function__ImuStamped__imus,  // size() function pointer
    get_const_function__ImuStamped__imus,  // get_const(index) function pointer
    get_function__ImuStamped__imus,  // get(index) function pointer
    fetch_function__ImuStamped__imus,  // fetch(index, &value) function pointer
    assign_function__ImuStamped__imus,  // assign(index, value) function pointer
    resize_function__ImuStamped__imus  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ImuStamped_message_members = {
  "tensegrity_interfaces::msg",  // message namespace
  "ImuStamped",  // message name
  2,  // number of fields
  sizeof(tensegrity_interfaces::msg::ImuStamped),
  ImuStamped_message_member_array,  // message members
  ImuStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  ImuStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ImuStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ImuStamped_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tensegrity_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tensegrity_interfaces::msg::ImuStamped>()
{
  return &::tensegrity_interfaces::msg::rosidl_typesupport_introspection_cpp::ImuStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tensegrity_interfaces, msg, ImuStamped)() {
  return &::tensegrity_interfaces::msg::rosidl_typesupport_introspection_cpp::ImuStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
