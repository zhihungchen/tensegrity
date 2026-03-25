// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/Motor.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/motor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_Motor_encoder_length
{
public:
  explicit Init_Motor_encoder_length(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::Motor encoder_length(::tensegrity_interfaces::msg::Motor::_encoder_length_type arg)
  {
    msg_.encoder_length = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_encoder_counts
{
public:
  explicit Init_Motor_encoder_counts(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_encoder_length encoder_counts(::tensegrity_interfaces::msg::Motor::_encoder_counts_type arg)
  {
    msg_.encoder_counts = std::move(arg);
    return Init_Motor_encoder_length(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_cum_error
{
public:
  explicit Init_Motor_cum_error(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_encoder_counts cum_error(::tensegrity_interfaces::msg::Motor::_cum_error_type arg)
  {
    msg_.cum_error = std::move(arg);
    return Init_Motor_encoder_counts(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_d_error
{
public:
  explicit Init_Motor_d_error(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_cum_error d_error(::tensegrity_interfaces::msg::Motor::_d_error_type arg)
  {
    msg_.d_error = std::move(arg);
    return Init_Motor_cum_error(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_error
{
public:
  explicit Init_Motor_error(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_d_error error(::tensegrity_interfaces::msg::Motor::_error_type arg)
  {
    msg_.error = std::move(arg);
    return Init_Motor_d_error(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_done
{
public:
  explicit Init_Motor_done(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_error done(::tensegrity_interfaces::msg::Motor::_done_type arg)
  {
    msg_.done = std::move(arg);
    return Init_Motor_error(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_speed
{
public:
  explicit Init_Motor_speed(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_done speed(::tensegrity_interfaces::msg::Motor::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Motor_done(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_target
{
public:
  explicit Init_Motor_target(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_speed target(::tensegrity_interfaces::msg::Motor::_target_type arg)
  {
    msg_.target = std::move(arg);
    return Init_Motor_speed(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_position
{
public:
  explicit Init_Motor_position(::tensegrity_interfaces::msg::Motor & msg)
  : msg_(msg)
  {}
  Init_Motor_target position(::tensegrity_interfaces::msg::Motor::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_Motor_target(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

class Init_Motor_id
{
public:
  Init_Motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Motor_position id(::tensegrity_interfaces::msg::Motor::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Motor_position(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Motor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::Motor>()
{
  return tensegrity_interfaces::msg::builder::Init_Motor_id();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__BUILDER_HPP_
