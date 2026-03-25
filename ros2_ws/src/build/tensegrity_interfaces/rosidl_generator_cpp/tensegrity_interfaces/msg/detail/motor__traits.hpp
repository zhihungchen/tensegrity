// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/Motor.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/motor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Motor & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << ", ";
  }

  // member: target
  {
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: done
  {
    out << "done: ";
    rosidl_generator_traits::value_to_yaml(msg.done, out);
    out << ", ";
  }

  // member: error
  {
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << ", ";
  }

  // member: d_error
  {
    out << "d_error: ";
    rosidl_generator_traits::value_to_yaml(msg.d_error, out);
    out << ", ";
  }

  // member: cum_error
  {
    out << "cum_error: ";
    rosidl_generator_traits::value_to_yaml(msg.cum_error, out);
    out << ", ";
  }

  // member: encoder_counts
  {
    out << "encoder_counts: ";
    rosidl_generator_traits::value_to_yaml(msg.encoder_counts, out);
    out << ", ";
  }

  // member: encoder_length
  {
    out << "encoder_length: ";
    rosidl_generator_traits::value_to_yaml(msg.encoder_length, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Motor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }

  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: done
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "done: ";
    rosidl_generator_traits::value_to_yaml(msg.done, out);
    out << "\n";
  }

  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << "\n";
  }

  // member: d_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d_error: ";
    rosidl_generator_traits::value_to_yaml(msg.d_error, out);
    out << "\n";
  }

  // member: cum_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cum_error: ";
    rosidl_generator_traits::value_to_yaml(msg.cum_error, out);
    out << "\n";
  }

  // member: encoder_counts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "encoder_counts: ";
    rosidl_generator_traits::value_to_yaml(msg.encoder_counts, out);
    out << "\n";
  }

  // member: encoder_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "encoder_length: ";
    rosidl_generator_traits::value_to_yaml(msg.encoder_length, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Motor & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::Motor & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::Motor & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::Motor>()
{
  return "tensegrity_interfaces::msg::Motor";
}

template<>
inline const char * name<tensegrity_interfaces::msg::Motor>()
{
  return "tensegrity_interfaces/msg/Motor";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::Motor>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::Motor>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tensegrity_interfaces::msg::Motor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__TRAITS_HPP_
