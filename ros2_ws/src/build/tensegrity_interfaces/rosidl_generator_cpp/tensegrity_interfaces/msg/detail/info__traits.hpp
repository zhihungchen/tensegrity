// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/Info.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Info & msg,
  std::ostream & out)
{
  out << "{";
  // member: min_length
  {
    out << "min_length: ";
    rosidl_generator_traits::value_to_yaml(msg.min_length, out);
    out << ", ";
  }

  // member: range
  {
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << ", ";
  }

  // member: max_range
  {
    out << "max_range: ";
    rosidl_generator_traits::value_to_yaml(msg.max_range, out);
    out << ", ";
  }

  // member: min_range
  {
    out << "min_range: ";
    rosidl_generator_traits::value_to_yaml(msg.min_range, out);
    out << ", ";
  }

  // member: range024
  {
    out << "range024: ";
    rosidl_generator_traits::value_to_yaml(msg.range024, out);
    out << ", ";
  }

  // member: range135
  {
    out << "range135: ";
    rosidl_generator_traits::value_to_yaml(msg.range135, out);
    out << ", ";
  }

  // member: max_speed
  {
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
    out << ", ";
  }

  // member: tol
  {
    out << "tol: ";
    rosidl_generator_traits::value_to_yaml(msg.tol, out);
    out << ", ";
  }

  // member: low_tol
  {
    out << "low_tol: ";
    rosidl_generator_traits::value_to_yaml(msg.low_tol, out);
    out << ", ";
  }

  // member: p
  {
    out << "p: ";
    rosidl_generator_traits::value_to_yaml(msg.p, out);
    out << ", ";
  }

  // member: i
  {
    out << "i: ";
    rosidl_generator_traits::value_to_yaml(msg.i, out);
    out << ", ";
  }

  // member: d
  {
    out << "d: ";
    rosidl_generator_traits::value_to_yaml(msg.d, out);
    out << ", ";
  }

  // member: dist_weight
  {
    out << "dist_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_weight, out);
    out << ", ";
  }

  // member: ang_weight
  {
    out << "ang_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.ang_weight, out);
    out << ", ";
  }

  // member: prog_weight
  {
    out << "prog_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.prog_weight, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Info & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: min_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_length: ";
    rosidl_generator_traits::value_to_yaml(msg.min_length, out);
    out << "\n";
  }

  // member: range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range: ";
    rosidl_generator_traits::value_to_yaml(msg.range, out);
    out << "\n";
  }

  // member: max_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_range: ";
    rosidl_generator_traits::value_to_yaml(msg.max_range, out);
    out << "\n";
  }

  // member: min_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_range: ";
    rosidl_generator_traits::value_to_yaml(msg.min_range, out);
    out << "\n";
  }

  // member: range024
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range024: ";
    rosidl_generator_traits::value_to_yaml(msg.range024, out);
    out << "\n";
  }

  // member: range135
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range135: ";
    rosidl_generator_traits::value_to_yaml(msg.range135, out);
    out << "\n";
  }

  // member: max_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.max_speed, out);
    out << "\n";
  }

  // member: tol
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tol: ";
    rosidl_generator_traits::value_to_yaml(msg.tol, out);
    out << "\n";
  }

  // member: low_tol
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "low_tol: ";
    rosidl_generator_traits::value_to_yaml(msg.low_tol, out);
    out << "\n";
  }

  // member: p
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p: ";
    rosidl_generator_traits::value_to_yaml(msg.p, out);
    out << "\n";
  }

  // member: i
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "i: ";
    rosidl_generator_traits::value_to_yaml(msg.i, out);
    out << "\n";
  }

  // member: d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d: ";
    rosidl_generator_traits::value_to_yaml(msg.d, out);
    out << "\n";
  }

  // member: dist_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dist_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.dist_weight, out);
    out << "\n";
  }

  // member: ang_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ang_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.ang_weight, out);
    out << "\n";
  }

  // member: prog_weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prog_weight: ";
    rosidl_generator_traits::value_to_yaml(msg.prog_weight, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Info & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::Info & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::Info & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::Info>()
{
  return "tensegrity_interfaces::msg::Info";
}

template<>
inline const char * name<tensegrity_interfaces::msg::Info>()
{
  return "tensegrity_interfaces/msg/Info";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::Info>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::Info>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tensegrity_interfaces::msg::Info>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__TRAITS_HPP_
