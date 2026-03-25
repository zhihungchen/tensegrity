// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/Action.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_Action_prog_weight
{
public:
  explicit Init_Action_prog_weight(::tensegrity_interfaces::msg::Action & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::Action prog_weight(::tensegrity_interfaces::msg::Action::_prog_weight_type arg)
  {
    msg_.prog_weight = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Action msg_;
};

class Init_Action_ang_weight
{
public:
  explicit Init_Action_ang_weight(::tensegrity_interfaces::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_prog_weight ang_weight(::tensegrity_interfaces::msg::Action::_ang_weight_type arg)
  {
    msg_.ang_weight = std::move(arg);
    return Init_Action_prog_weight(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Action msg_;
};

class Init_Action_dist_weight
{
public:
  explicit Init_Action_dist_weight(::tensegrity_interfaces::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_ang_weight dist_weight(::tensegrity_interfaces::msg::Action::_dist_weight_type arg)
  {
    msg_.dist_weight = std::move(arg);
    return Init_Action_ang_weight(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Action msg_;
};

class Init_Action_endcaps
{
public:
  explicit Init_Action_endcaps(::tensegrity_interfaces::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_dist_weight endcaps(::tensegrity_interfaces::msg::Action::_endcaps_type arg)
  {
    msg_.endcaps = std::move(arg);
    return Init_Action_dist_weight(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Action msg_;
};

class Init_Action_pas
{
public:
  explicit Init_Action_pas(::tensegrity_interfaces::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_endcaps pas(::tensegrity_interfaces::msg::Action::_pas_type arg)
  {
    msg_.pas = std::move(arg);
    return Init_Action_endcaps(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Action msg_;
};

class Init_Action_coms
{
public:
  explicit Init_Action_coms(::tensegrity_interfaces::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_pas coms(::tensegrity_interfaces::msg::Action::_coms_type arg)
  {
    msg_.coms = std::move(arg);
    return Init_Action_pas(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Action msg_;
};

class Init_Action_cost
{
public:
  explicit Init_Action_cost(::tensegrity_interfaces::msg::Action & msg)
  : msg_(msg)
  {}
  Init_Action_coms cost(::tensegrity_interfaces::msg::Action::_cost_type arg)
  {
    msg_.cost = std::move(arg);
    return Init_Action_coms(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Action msg_;
};

class Init_Action_actions
{
public:
  Init_Action_actions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Action_cost actions(::tensegrity_interfaces::msg::Action::_actions_type arg)
  {
    msg_.actions = std::move(arg);
    return Init_Action_cost(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Action msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::Action>()
{
  return tensegrity_interfaces::msg::builder::Init_Action_actions();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__BUILDER_HPP_
