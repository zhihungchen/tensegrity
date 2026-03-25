// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/Sensor.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/sensor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_Sensor_capacitance
{
public:
  explicit Init_Sensor_capacitance(::tensegrity_interfaces::msg::Sensor & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::Sensor capacitance(::tensegrity_interfaces::msg::Sensor::_capacitance_type arg)
  {
    msg_.capacitance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Sensor msg_;
};

class Init_Sensor_length
{
public:
  explicit Init_Sensor_length(::tensegrity_interfaces::msg::Sensor & msg)
  : msg_(msg)
  {}
  Init_Sensor_capacitance length(::tensegrity_interfaces::msg::Sensor::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_Sensor_capacitance(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Sensor msg_;
};

class Init_Sensor_id
{
public:
  Init_Sensor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sensor_length id(::tensegrity_interfaces::msg::Sensor::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Sensor_length(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Sensor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::Sensor>()
{
  return tensegrity_interfaces::msg::builder::Init_Sensor_id();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__BUILDER_HPP_
