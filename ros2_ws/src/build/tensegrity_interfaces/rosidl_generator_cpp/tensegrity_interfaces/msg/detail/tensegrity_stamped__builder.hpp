// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/TensegrityStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_TensegrityStamped_actions
{
public:
  explicit Init_TensegrityStamped_actions(::tensegrity_interfaces::msg::TensegrityStamped & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::TensegrityStamped actions(::tensegrity_interfaces::msg::TensegrityStamped::_actions_type arg)
  {
    msg_.actions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::TensegrityStamped msg_;
};

class Init_TensegrityStamped_trajectory
{
public:
  explicit Init_TensegrityStamped_trajectory(::tensegrity_interfaces::msg::TensegrityStamped & msg)
  : msg_(msg)
  {}
  Init_TensegrityStamped_actions trajectory(::tensegrity_interfaces::msg::TensegrityStamped::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_TensegrityStamped_actions(msg_);
  }

private:
  ::tensegrity_interfaces::msg::TensegrityStamped msg_;
};

class Init_TensegrityStamped_nodes
{
public:
  explicit Init_TensegrityStamped_nodes(::tensegrity_interfaces::msg::TensegrityStamped & msg)
  : msg_(msg)
  {}
  Init_TensegrityStamped_trajectory nodes(::tensegrity_interfaces::msg::TensegrityStamped::_nodes_type arg)
  {
    msg_.nodes = std::move(arg);
    return Init_TensegrityStamped_trajectory(msg_);
  }

private:
  ::tensegrity_interfaces::msg::TensegrityStamped msg_;
};

class Init_TensegrityStamped_imus
{
public:
  explicit Init_TensegrityStamped_imus(::tensegrity_interfaces::msg::TensegrityStamped & msg)
  : msg_(msg)
  {}
  Init_TensegrityStamped_nodes imus(::tensegrity_interfaces::msg::TensegrityStamped::_imus_type arg)
  {
    msg_.imus = std::move(arg);
    return Init_TensegrityStamped_nodes(msg_);
  }

private:
  ::tensegrity_interfaces::msg::TensegrityStamped msg_;
};

class Init_TensegrityStamped_sensors
{
public:
  explicit Init_TensegrityStamped_sensors(::tensegrity_interfaces::msg::TensegrityStamped & msg)
  : msg_(msg)
  {}
  Init_TensegrityStamped_imus sensors(::tensegrity_interfaces::msg::TensegrityStamped::_sensors_type arg)
  {
    msg_.sensors = std::move(arg);
    return Init_TensegrityStamped_imus(msg_);
  }

private:
  ::tensegrity_interfaces::msg::TensegrityStamped msg_;
};

class Init_TensegrityStamped_motors
{
public:
  explicit Init_TensegrityStamped_motors(::tensegrity_interfaces::msg::TensegrityStamped & msg)
  : msg_(msg)
  {}
  Init_TensegrityStamped_sensors motors(::tensegrity_interfaces::msg::TensegrityStamped::_motors_type arg)
  {
    msg_.motors = std::move(arg);
    return Init_TensegrityStamped_sensors(msg_);
  }

private:
  ::tensegrity_interfaces::msg::TensegrityStamped msg_;
};

class Init_TensegrityStamped_info
{
public:
  explicit Init_TensegrityStamped_info(::tensegrity_interfaces::msg::TensegrityStamped & msg)
  : msg_(msg)
  {}
  Init_TensegrityStamped_motors info(::tensegrity_interfaces::msg::TensegrityStamped::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_TensegrityStamped_motors(msg_);
  }

private:
  ::tensegrity_interfaces::msg::TensegrityStamped msg_;
};

class Init_TensegrityStamped_header
{
public:
  Init_TensegrityStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TensegrityStamped_info header(::tensegrity_interfaces::msg::TensegrityStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_TensegrityStamped_info(msg_);
  }

private:
  ::tensegrity_interfaces::msg::TensegrityStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::TensegrityStamped>()
{
  return tensegrity_interfaces::msg::builder::Init_TensegrityStamped_header();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__BUILDER_HPP_
