// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'trajectory'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const State & msg,
  std::ostream & out)
{
  out << "{";
  // member: trajectory
  {
    if (msg.trajectory.size() == 0) {
      out << "trajectory: []";
    } else {
      out << "trajectory: [";
      size_t pending_items = msg.trajectory.size();
      for (auto item : msg.trajectory) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: prev_action
  {
    out << "prev_action: ";
    rosidl_generator_traits::value_to_yaml(msg.prev_action, out);
    out << ", ";
  }

  // member: reverse_the_gait
  {
    out << "reverse_the_gait: ";
    rosidl_generator_traits::value_to_yaml(msg.reverse_the_gait, out);
    out << ", ";
  }

  // member: bar_height_changed
  {
    out << "bar_height_changed: ";
    rosidl_generator_traits::value_to_yaml(msg.bar_height_changed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const State & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.trajectory.size() == 0) {
      out << "trajectory: []\n";
    } else {
      out << "trajectory:\n";
      for (auto item : msg.trajectory) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: prev_action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prev_action: ";
    rosidl_generator_traits::value_to_yaml(msg.prev_action, out);
    out << "\n";
  }

  // member: reverse_the_gait
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reverse_the_gait: ";
    rosidl_generator_traits::value_to_yaml(msg.reverse_the_gait, out);
    out << "\n";
  }

  // member: bar_height_changed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bar_height_changed: ";
    rosidl_generator_traits::value_to_yaml(msg.bar_height_changed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const State & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::State & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::State & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::State>()
{
  return "tensegrity_interfaces::msg::State";
}

template<>
inline const char * name<tensegrity_interfaces::msg::State>()
{
  return "tensegrity_interfaces/msg/State";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::State>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::State>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensegrity_interfaces::msg::State>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__TRAITS_HPP_
