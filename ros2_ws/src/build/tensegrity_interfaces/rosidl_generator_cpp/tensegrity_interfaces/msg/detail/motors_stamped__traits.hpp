// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/MotorsStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/motors_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'info'
#include "tensegrity_interfaces/msg/detail/info__traits.hpp"
// Member 'motors'
#include "tensegrity_interfaces/msg/detail/motor__traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorsStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: motors
  {
    if (msg.motors.size() == 0) {
      out << "motors: []";
    } else {
      out << "motors: [";
      size_t pending_items = msg.motors.size();
      for (auto item : msg.motors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorsStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: motors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motors.size() == 0) {
      out << "motors: []\n";
    } else {
      out << "motors:\n";
      for (auto item : msg.motors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorsStamped & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tensegrity_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tensegrity_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tensegrity_interfaces::msg::MotorsStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::MotorsStamped & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::MotorsStamped>()
{
  return "tensegrity_interfaces::msg::MotorsStamped";
}

template<>
inline const char * name<tensegrity_interfaces::msg::MotorsStamped>()
{
  return "tensegrity_interfaces/msg/MotorsStamped";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::MotorsStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::MotorsStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensegrity_interfaces::msg::MotorsStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__TRAITS_HPP_
