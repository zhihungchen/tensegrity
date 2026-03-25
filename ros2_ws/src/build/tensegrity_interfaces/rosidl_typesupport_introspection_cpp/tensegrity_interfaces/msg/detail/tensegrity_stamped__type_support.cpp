// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tensegrity_interfaces:msg/TensegrityStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__struct.hpp"
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

void TensegrityStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tensegrity_interfaces::msg::TensegrityStamped(_init);
}

void TensegrityStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tensegrity_interfaces::msg::TensegrityStamped *>(message_memory);
  typed_message->~TensegrityStamped();
}

size_t size_function__TensegrityStamped__motors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Motor> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TensegrityStamped__motors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Motor> *>(untyped_member);
  return &member[index];
}

void * get_function__TensegrityStamped__motors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tensegrity_interfaces::msg::Motor> *>(untyped_member);
  return &member[index];
}

void fetch_function__TensegrityStamped__motors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tensegrity_interfaces::msg::Motor *>(
    get_const_function__TensegrityStamped__motors(untyped_member, index));
  auto & value = *reinterpret_cast<tensegrity_interfaces::msg::Motor *>(untyped_value);
  value = item;
}

void assign_function__TensegrityStamped__motors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tensegrity_interfaces::msg::Motor *>(
    get_function__TensegrityStamped__motors(untyped_member, index));
  const auto & value = *reinterpret_cast<const tensegrity_interfaces::msg::Motor *>(untyped_value);
  item = value;
}

void resize_function__TensegrityStamped__motors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tensegrity_interfaces::msg::Motor> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TensegrityStamped__sensors(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Sensor> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TensegrityStamped__sensors(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Sensor> *>(untyped_member);
  return &member[index];
}

void * get_function__TensegrityStamped__sensors(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tensegrity_interfaces::msg::Sensor> *>(untyped_member);
  return &member[index];
}

void fetch_function__TensegrityStamped__sensors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tensegrity_interfaces::msg::Sensor *>(
    get_const_function__TensegrityStamped__sensors(untyped_member, index));
  auto & value = *reinterpret_cast<tensegrity_interfaces::msg::Sensor *>(untyped_value);
  value = item;
}

void assign_function__TensegrityStamped__sensors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tensegrity_interfaces::msg::Sensor *>(
    get_function__TensegrityStamped__sensors(untyped_member, index));
  const auto & value = *reinterpret_cast<const tensegrity_interfaces::msg::Sensor *>(untyped_value);
  item = value;
}

void resize_function__TensegrityStamped__sensors(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tensegrity_interfaces::msg::Sensor> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TensegrityStamped__imus(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Imu> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TensegrityStamped__imus(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Imu> *>(untyped_member);
  return &member[index];
}

void * get_function__TensegrityStamped__imus(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tensegrity_interfaces::msg::Imu> *>(untyped_member);
  return &member[index];
}

void fetch_function__TensegrityStamped__imus(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tensegrity_interfaces::msg::Imu *>(
    get_const_function__TensegrityStamped__imus(untyped_member, index));
  auto & value = *reinterpret_cast<tensegrity_interfaces::msg::Imu *>(untyped_value);
  value = item;
}

void assign_function__TensegrityStamped__imus(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tensegrity_interfaces::msg::Imu *>(
    get_function__TensegrityStamped__imus(untyped_member, index));
  const auto & value = *reinterpret_cast<const tensegrity_interfaces::msg::Imu *>(untyped_value);
  item = value;
}

void resize_function__TensegrityStamped__imus(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tensegrity_interfaces::msg::Imu> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TensegrityStamped__nodes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Node> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TensegrityStamped__nodes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tensegrity_interfaces::msg::Node> *>(untyped_member);
  return &member[index];
}

void * get_function__TensegrityStamped__nodes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tensegrity_interfaces::msg::Node> *>(untyped_member);
  return &member[index];
}

void fetch_function__TensegrityStamped__nodes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tensegrity_interfaces::msg::Node *>(
    get_const_function__TensegrityStamped__nodes(untyped_member, index));
  auto & value = *reinterpret_cast<tensegrity_interfaces::msg::Node *>(untyped_value);
  value = item;
}

void assign_function__TensegrityStamped__nodes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tensegrity_interfaces::msg::Node *>(
    get_function__TensegrityStamped__nodes(untyped_member, index));
  const auto & value = *reinterpret_cast<const tensegrity_interfaces::msg::Node *>(untyped_value);
  item = value;
}

void resize_function__TensegrityStamped__nodes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tensegrity_interfaces::msg::Node> *>(untyped_member);
  member->resize(size);
}

size_t size_function__TensegrityStamped__actions(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__TensegrityStamped__actions(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__TensegrityStamped__actions(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__TensegrityStamped__actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__TensegrityStamped__actions(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__TensegrityStamped__actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__TensegrityStamped__actions(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__TensegrityStamped__actions(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TensegrityStamped_message_member_array[8] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::TensegrityStamped, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tensegrity_interfaces::msg::Info>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::TensegrityStamped, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "motors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tensegrity_interfaces::msg::Motor>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::TensegrityStamped, motors),  // bytes offset in struct
    nullptr,  // default value
    size_function__TensegrityStamped__motors,  // size() function pointer
    get_const_function__TensegrityStamped__motors,  // get_const(index) function pointer
    get_function__TensegrityStamped__motors,  // get(index) function pointer
    fetch_function__TensegrityStamped__motors,  // fetch(index, &value) function pointer
    assign_function__TensegrityStamped__motors,  // assign(index, value) function pointer
    resize_function__TensegrityStamped__motors  // resize(index) function pointer
  },
  {
    "sensors",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tensegrity_interfaces::msg::Sensor>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::TensegrityStamped, sensors),  // bytes offset in struct
    nullptr,  // default value
    size_function__TensegrityStamped__sensors,  // size() function pointer
    get_const_function__TensegrityStamped__sensors,  // get_const(index) function pointer
    get_function__TensegrityStamped__sensors,  // get(index) function pointer
    fetch_function__TensegrityStamped__sensors,  // fetch(index, &value) function pointer
    assign_function__TensegrityStamped__sensors,  // assign(index, value) function pointer
    resize_function__TensegrityStamped__sensors  // resize(index) function pointer
  },
  {
    "imus",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tensegrity_interfaces::msg::Imu>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::TensegrityStamped, imus),  // bytes offset in struct
    nullptr,  // default value
    size_function__TensegrityStamped__imus,  // size() function pointer
    get_const_function__TensegrityStamped__imus,  // get_const(index) function pointer
    get_function__TensegrityStamped__imus,  // get(index) function pointer
    fetch_function__TensegrityStamped__imus,  // fetch(index, &value) function pointer
    assign_function__TensegrityStamped__imus,  // assign(index, value) function pointer
    resize_function__TensegrityStamped__imus  // resize(index) function pointer
  },
  {
    "nodes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tensegrity_interfaces::msg::Node>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::TensegrityStamped, nodes),  // bytes offset in struct
    nullptr,  // default value
    size_function__TensegrityStamped__nodes,  // size() function pointer
    get_const_function__TensegrityStamped__nodes,  // get_const(index) function pointer
    get_function__TensegrityStamped__nodes,  // get(index) function pointer
    fetch_function__TensegrityStamped__nodes,  // fetch(index, &value) function pointer
    assign_function__TensegrityStamped__nodes,  // assign(index, value) function pointer
    resize_function__TensegrityStamped__nodes  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tensegrity_interfaces::msg::Trajectory>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::TensegrityStamped, trajectory),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "actions",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tensegrity_interfaces::msg::TensegrityStamped, actions),  // bytes offset in struct
    nullptr,  // default value
    size_function__TensegrityStamped__actions,  // size() function pointer
    get_const_function__TensegrityStamped__actions,  // get_const(index) function pointer
    get_function__TensegrityStamped__actions,  // get(index) function pointer
    fetch_function__TensegrityStamped__actions,  // fetch(index, &value) function pointer
    assign_function__TensegrityStamped__actions,  // assign(index, value) function pointer
    resize_function__TensegrityStamped__actions  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TensegrityStamped_message_members = {
  "tensegrity_interfaces::msg",  // message namespace
  "TensegrityStamped",  // message name
  8,  // number of fields
  sizeof(tensegrity_interfaces::msg::TensegrityStamped),
  TensegrityStamped_message_member_array,  // message members
  TensegrityStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  TensegrityStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TensegrityStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TensegrityStamped_message_members,
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
get_message_type_support_handle<tensegrity_interfaces::msg::TensegrityStamped>()
{
  return &::tensegrity_interfaces::msg::rosidl_typesupport_introspection_cpp::TensegrityStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tensegrity_interfaces, msg, TensegrityStamped)() {
  return &::tensegrity_interfaces::msg::rosidl_typesupport_introspection_cpp::TensegrityStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
