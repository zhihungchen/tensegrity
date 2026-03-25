// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/ImuStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/imu_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'imus'
#include "tensegrity_interfaces/msg/detail/imu__traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ImuStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: imus
  {
    if (msg.imus.size() == 0) {
      out << "imus: []";
    } else {
      out << "imus: [";
      size_t pending_items = msg.imus.size();
      for (auto item : msg.imus) {
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
  const ImuStamped & msg,
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

  // member: imus
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.imus.size() == 0) {
      out << "imus: []\n";
    } else {
      out << "imus:\n";
      for (auto item : msg.imus) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ImuStamped & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::ImuStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::ImuStamped & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::ImuStamped>()
{
  return "tensegrity_interfaces::msg::ImuStamped";
}

template<>
inline const char * name<tensegrity_interfaces::msg::ImuStamped>()
{
  return "tensegrity_interfaces/msg/ImuStamped";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::ImuStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::ImuStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensegrity_interfaces::msg::ImuStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__IMU_STAMPED__TRAITS_HPP_
