// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'trajectory'
// Member 'coms'
// Member 'pas'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Trajectory & msg,
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

  // member: coms
  {
    if (msg.coms.size() == 0) {
      out << "coms: []";
    } else {
      out << "coms: [";
      size_t pending_items = msg.coms.size();
      for (auto item : msg.coms) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pas
  {
    if (msg.pas.size() == 0) {
      out << "pas: []";
    } else {
      out << "pas: [";
      size_t pending_items = msg.pas.size();
      for (auto item : msg.pas) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: trajectory_segment
  {
    out << "trajectory_segment: ";
    rosidl_generator_traits::value_to_yaml(msg.trajectory_segment, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Trajectory & msg,
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

  // member: coms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.coms.size() == 0) {
      out << "coms: []\n";
    } else {
      out << "coms:\n";
      for (auto item : msg.coms) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: pas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pas.size() == 0) {
      out << "pas: []\n";
    } else {
      out << "pas:\n";
      for (auto item : msg.pas) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: trajectory_segment
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory_segment: ";
    rosidl_generator_traits::value_to_yaml(msg.trajectory_segment, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Trajectory & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::Trajectory & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::Trajectory>()
{
  return "tensegrity_interfaces::msg::Trajectory";
}

template<>
inline const char * name<tensegrity_interfaces::msg::Trajectory>()
{
  return "tensegrity_interfaces/msg/Trajectory";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensegrity_interfaces::msg::Trajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
