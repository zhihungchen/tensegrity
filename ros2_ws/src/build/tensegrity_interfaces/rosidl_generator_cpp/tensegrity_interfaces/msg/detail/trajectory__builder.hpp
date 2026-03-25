// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_Trajectory_trajectory_segment
{
public:
  explicit Init_Trajectory_trajectory_segment(::tensegrity_interfaces::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::Trajectory trajectory_segment(::tensegrity_interfaces::msg::Trajectory::_trajectory_segment_type arg)
  {
    msg_.trajectory_segment = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Trajectory msg_;
};

class Init_Trajectory_pas
{
public:
  explicit Init_Trajectory_pas(::tensegrity_interfaces::msg::Trajectory & msg)
  : msg_(msg)
  {}
  Init_Trajectory_trajectory_segment pas(::tensegrity_interfaces::msg::Trajectory::_pas_type arg)
  {
    msg_.pas = std::move(arg);
    return Init_Trajectory_trajectory_segment(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Trajectory msg_;
};

class Init_Trajectory_coms
{
public:
  explicit Init_Trajectory_coms(::tensegrity_interfaces::msg::Trajectory & msg)
  : msg_(msg)
  {}
  Init_Trajectory_pas coms(::tensegrity_interfaces::msg::Trajectory::_coms_type arg)
  {
    msg_.coms = std::move(arg);
    return Init_Trajectory_pas(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Trajectory msg_;
};

class Init_Trajectory_trajectory
{
public:
  Init_Trajectory_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_coms trajectory(::tensegrity_interfaces::msg::Trajectory::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return Init_Trajectory_coms(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::Trajectory>()
{
  return tensegrity_interfaces::msg::builder::Init_Trajectory_trajectory();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
