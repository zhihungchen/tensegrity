// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/ImuStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/imu_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_ImuStamped_imus
{
public:
  explicit Init_ImuStamped_imus(::tensegrity_interfaces::msg::ImuStamped & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::ImuStamped imus(::tensegrity_interfaces::msg::ImuStamped::_imus_type arg)
  {
    msg_.imus = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::ImuStamped msg_;
};

class Init_ImuStamped_header
{
public:
  Init_ImuStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImuStamped_imus header(::tensegrity_interfaces::msg::ImuStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ImuStamped_imus(msg_);
  }

private:
  ::tensegrity_interfaces::msg::ImuStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::ImuStamped>()
{
  return tensegrity_interfaces::msg::builder::Init_ImuStamped_header();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__BUILDER_HPP_
