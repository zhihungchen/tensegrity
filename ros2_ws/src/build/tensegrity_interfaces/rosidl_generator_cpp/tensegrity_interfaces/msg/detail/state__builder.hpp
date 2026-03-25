// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_State_bar_height_changed
{
public:
  explicit Init_State_bar_height_changed(::tensegrity_interfaces::msg::State & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::State bar_height_changed(::tensegrity_interfaces::msg::State::_bar_height_changed_type arg)
  {
    msg_.bar_height_changed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::State msg_;
};

class Init_State_reverse_the_gait
{
public:
  explicit Init_State_reverse_the_gait(::tensegrity_interfaces::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_bar_height_changed reverse_the_gait(::tensegrity_interfaces::msg::State::_reverse_the_gait_type arg)
  {
    msg_.reverse_the_gait = std::move(arg);
    return Init_State_bar_height_changed(msg_);
  }

private:
  ::tensegrity_interfaces::msg::State msg_;
};

class Init_State_prev_action
{
public:
  explicit Init_State_prev_action(::tensegrity_interfaces::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_reverse_the_gait prev_action(::tensegrity_interfaces::msg::State::_prev_action_type arg)
  {
    msg_.prev_action = std::move(arg);
    return Init_State_reverse_the_gait(msg_);
  }

private:
  ::tensegrity_interfaces::msg::State msg_;
};

class Init_State_trajectory
{
public:
  Init_State_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_prev_action trajectory(::tensegrity_interfaces::msg::State::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_State_prev_action(msg_);
  }

private:
  ::tensegrity_interfaces::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::State>()
{
  return tensegrity_interfaces::msg::builder::Init_State_trajectory();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__BUILDER_HPP_
