// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/Node.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__NODE__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__NODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/node__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_Node_z
{
public:
  explicit Init_Node_z(::tensegrity_interfaces::msg::Node & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::Node z(::tensegrity_interfaces::msg::Node::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Node msg_;
};

class Init_Node_y
{
public:
  explicit Init_Node_y(::tensegrity_interfaces::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_z y(::tensegrity_interfaces::msg::Node::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Node_z(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Node msg_;
};

class Init_Node_x
{
public:
  explicit Init_Node_x(::tensegrity_interfaces::msg::Node & msg)
  : msg_(msg)
  {}
  Init_Node_y x(::tensegrity_interfaces::msg::Node::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Node_y(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Node msg_;
};

class Init_Node_id
{
public:
  Init_Node_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Node_x id(::tensegrity_interfaces::msg::Node::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Node_x(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Node msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::Node>()
{
  return tensegrity_interfaces::msg::builder::Init_Node_id();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__NODE__BUILDER_HPP_
