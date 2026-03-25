// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/NodesStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/nodes_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_NodesStamped_imus
{
public:
  explicit Init_NodesStamped_imus(::tensegrity_interfaces::msg::NodesStamped & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::NodesStamped imus(::tensegrity_interfaces::msg::NodesStamped::_imus_type arg)
  {
    msg_.imus = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::NodesStamped msg_;
};

class Init_NodesStamped_mocap_nodes
{
public:
  explicit Init_NodesStamped_mocap_nodes(::tensegrity_interfaces::msg::NodesStamped & msg)
  : msg_(msg)
  {}
  Init_NodesStamped_imus mocap_nodes(::tensegrity_interfaces::msg::NodesStamped::_mocap_nodes_type arg)
  {
    msg_.mocap_nodes = std::move(arg);
    return Init_NodesStamped_imus(msg_);
  }

private:
  ::tensegrity_interfaces::msg::NodesStamped msg_;
};

class Init_NodesStamped_reconstructed_nodes
{
public:
  explicit Init_NodesStamped_reconstructed_nodes(::tensegrity_interfaces::msg::NodesStamped & msg)
  : msg_(msg)
  {}
  Init_NodesStamped_mocap_nodes reconstructed_nodes(::tensegrity_interfaces::msg::NodesStamped::_reconstructed_nodes_type arg)
  {
    msg_.reconstructed_nodes = std::move(arg);
    return Init_NodesStamped_mocap_nodes(msg_);
  }

private:
  ::tensegrity_interfaces::msg::NodesStamped msg_;
};

class Init_NodesStamped_header
{
public:
  Init_NodesStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NodesStamped_reconstructed_nodes header(::tensegrity_interfaces::msg::NodesStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NodesStamped_reconstructed_nodes(msg_);
  }

private:
  ::tensegrity_interfaces::msg::NodesStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::NodesStamped>()
{
  return tensegrity_interfaces::msg::builder::Init_NodesStamped_header();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__BUILDER_HPP_
