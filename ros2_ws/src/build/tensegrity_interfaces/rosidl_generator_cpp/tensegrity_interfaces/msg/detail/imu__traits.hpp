// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/imu__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Imu & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: ax
  {
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << ", ";
  }

  // member: ay
  {
    out << "ay: ";
    rosidl_generator_traits::value_to_yaml(msg.ay, out);
    out << ", ";
  }

  // member: az
  {
    out << "az: ";
    rosidl_generator_traits::value_to_yaml(msg.az, out);
    out << ", ";
  }

  // member: gx
  {
    out << "gx: ";
    rosidl_generator_traits::value_to_yaml(msg.gx, out);
    out << ", ";
  }

  // member: gy
  {
    out << "gy: ";
    rosidl_generator_traits::value_to_yaml(msg.gy, out);
    out << ", ";
  }

  // member: gz
  {
    out << "gz: ";
    rosidl_generator_traits::value_to_yaml(msg.gz, out);
    out << ", ";
  }

  // member: mx
  {
    out << "mx: ";
    rosidl_generator_traits::value_to_yaml(msg.mx, out);
    out << ", ";
  }

  // member: my
  {
    out << "my: ";
    rosidl_generator_traits::value_to_yaml(msg.my, out);
    out << ", ";
  }

  // member: mz
  {
    out << "mz: ";
    rosidl_generator_traits::value_to_yaml(msg.mz, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Imu & msg,
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

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: ax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << "\n";
  }

  // member: ay
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ay: ";
    rosidl_generator_traits::value_to_yaml(msg.ay, out);
    out << "\n";
  }

  // member: az
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "az: ";
    rosidl_generator_traits::value_to_yaml(msg.az, out);
    out << "\n";
  }

  // member: gx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gx: ";
    rosidl_generator_traits::value_to_yaml(msg.gx, out);
    out << "\n";
  }

  // member: gy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gy: ";
    rosidl_generator_traits::value_to_yaml(msg.gy, out);
    out << "\n";
  }

  // member: gz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gz: ";
    rosidl_generator_traits::value_to_yaml(msg.gz, out);
    out << "\n";
  }

  // member: mx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mx: ";
    rosidl_generator_traits::value_to_yaml(msg.mx, out);
    out << "\n";
  }

  // member: my
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my: ";
    rosidl_generator_traits::value_to_yaml(msg.my, out);
    out << "\n";
  }

  // member: mz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mz: ";
    rosidl_generator_traits::value_to_yaml(msg.mz, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Imu & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::Imu & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::Imu & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::Imu>()
{
  return "tensegrity_interfaces::msg::Imu";
}

template<>
inline const char * name<tensegrity_interfaces::msg::Imu>()
{
  return "tensegrity_interfaces/msg/Imu";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::Imu>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::Imu>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tensegrity_interfaces::msg::Imu>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__TRAITS_HPP_
