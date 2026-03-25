// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/Info.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_Info_prog_weight
{
public:
  explicit Init_Info_prog_weight(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::Info prog_weight(::tensegrity_interfaces::msg::Info::_prog_weight_type arg)
  {
    msg_.prog_weight = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_ang_weight
{
public:
  explicit Init_Info_ang_weight(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_prog_weight ang_weight(::tensegrity_interfaces::msg::Info::_ang_weight_type arg)
  {
    msg_.ang_weight = std::move(arg);
    return Init_Info_prog_weight(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_dist_weight
{
public:
  explicit Init_Info_dist_weight(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_ang_weight dist_weight(::tensegrity_interfaces::msg::Info::_dist_weight_type arg)
  {
    msg_.dist_weight = std::move(arg);
    return Init_Info_ang_weight(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_d
{
public:
  explicit Init_Info_d(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_dist_weight d(::tensegrity_interfaces::msg::Info::_d_type arg)
  {
    msg_.d = std::move(arg);
    return Init_Info_dist_weight(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_i
{
public:
  explicit Init_Info_i(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_d i(::tensegrity_interfaces::msg::Info::_i_type arg)
  {
    msg_.i = std::move(arg);
    return Init_Info_d(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_p
{
public:
  explicit Init_Info_p(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_i p(::tensegrity_interfaces::msg::Info::_p_type arg)
  {
    msg_.p = std::move(arg);
    return Init_Info_i(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_low_tol
{
public:
  explicit Init_Info_low_tol(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_p low_tol(::tensegrity_interfaces::msg::Info::_low_tol_type arg)
  {
    msg_.low_tol = std::move(arg);
    return Init_Info_p(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_tol
{
public:
  explicit Init_Info_tol(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_low_tol tol(::tensegrity_interfaces::msg::Info::_tol_type arg)
  {
    msg_.tol = std::move(arg);
    return Init_Info_low_tol(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_max_speed
{
public:
  explicit Init_Info_max_speed(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_tol max_speed(::tensegrity_interfaces::msg::Info::_max_speed_type arg)
  {
    msg_.max_speed = std::move(arg);
    return Init_Info_tol(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_range135
{
public:
  explicit Init_Info_range135(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_max_speed range135(::tensegrity_interfaces::msg::Info::_range135_type arg)
  {
    msg_.range135 = std::move(arg);
    return Init_Info_max_speed(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_range024
{
public:
  explicit Init_Info_range024(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_range135 range024(::tensegrity_interfaces::msg::Info::_range024_type arg)
  {
    msg_.range024 = std::move(arg);
    return Init_Info_range135(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_min_range
{
public:
  explicit Init_Info_min_range(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_range024 min_range(::tensegrity_interfaces::msg::Info::_min_range_type arg)
  {
    msg_.min_range = std::move(arg);
    return Init_Info_range024(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_max_range
{
public:
  explicit Init_Info_max_range(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_min_range max_range(::tensegrity_interfaces::msg::Info::_max_range_type arg)
  {
    msg_.max_range = std::move(arg);
    return Init_Info_min_range(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_range
{
public:
  explicit Init_Info_range(::tensegrity_interfaces::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_max_range range(::tensegrity_interfaces::msg::Info::_range_type arg)
  {
    msg_.range = std::move(arg);
    return Init_Info_max_range(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

class Init_Info_min_length
{
public:
  Init_Info_min_length()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Info_range min_length(::tensegrity_interfaces::msg::Info::_min_length_type arg)
  {
    msg_.min_length = std::move(arg);
    return Init_Info_range(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Info msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::Info>()
{
  return tensegrity_interfaces::msg::builder::Init_Info_min_length();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__BUILDER_HPP_
