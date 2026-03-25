// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/MotorsStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/motors_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorsStamped_motors
{
public:
  explicit Init_MotorsStamped_motors(::tensegrity_interfaces::msg::MotorsStamped & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::MotorsStamped motors(::tensegrity_interfaces::msg::MotorsStamped::_motors_type arg)
  {
    msg_.motors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::MotorsStamped msg_;
};

class Init_MotorsStamped_info
{
public:
  explicit Init_MotorsStamped_info(::tensegrity_interfaces::msg::MotorsStamped & msg)
  : msg_(msg)
  {}
  Init_MotorsStamped_motors info(::tensegrity_interfaces::msg::MotorsStamped::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MotorsStamped_motors(msg_);
  }

private:
  ::tensegrity_interfaces::msg::MotorsStamped msg_;
};

class Init_MotorsStamped_header
{
public:
  Init_MotorsStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorsStamped_info header(::tensegrity_interfaces::msg::MotorsStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorsStamped_info(msg_);
  }

private:
  ::tensegrity_interfaces::msg::MotorsStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::MotorsStamped>()
{
  return tensegrity_interfaces::msg::builder::Init_MotorsStamped_header();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__BUILDER_HPP_
