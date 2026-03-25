// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/SensorsStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__SENSORS_STAMPED__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__SENSORS_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/sensors_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_SensorsStamped_sensors
{
public:
  explicit Init_SensorsStamped_sensors(::tensegrity_interfaces::msg::SensorsStamped & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::SensorsStamped sensors(::tensegrity_interfaces::msg::SensorsStamped::_sensors_type arg)
  {
    msg_.sensors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::SensorsStamped msg_;
};

class Init_SensorsStamped_header
{
public:
  Init_SensorsStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SensorsStamped_sensors header(::tensegrity_interfaces::msg::SensorsStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SensorsStamped_sensors(msg_);
  }

private:
  ::tensegrity_interfaces::msg::SensorsStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::SensorsStamped>()
{
  return tensegrity_interfaces::msg::builder::Init_SensorsStamped_header();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__SENSORS_STAMPED__BUILDER_HPP_
