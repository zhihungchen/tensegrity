// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/StampedIndex.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__STAMPED_INDEX__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__STAMPED_INDEX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/stamped_index__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_StampedIndex_id
{
public:
  explicit Init_StampedIndex_id(::tensegrity_interfaces::msg::StampedIndex & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::StampedIndex id(::tensegrity_interfaces::msg::StampedIndex::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::StampedIndex msg_;
};

class Init_StampedIndex_header
{
public:
  Init_StampedIndex_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StampedIndex_id header(::tensegrity_interfaces::msg::StampedIndex::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_StampedIndex_id(msg_);
  }

private:
  ::tensegrity_interfaces::msg::StampedIndex msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::StampedIndex>()
{
  return tensegrity_interfaces::msg::builder::Init_StampedIndex_header();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__STAMPED_INDEX__BUILDER_HPP_
