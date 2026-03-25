// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/TensegrityStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'info'
#include "tensegrity_interfaces/msg/detail/info__traits.hpp"
// Member 'motors'
#include "tensegrity_interfaces/msg/detail/motor__traits.hpp"
// Member 'sensors'
#include "tensegrity_interfaces/msg/detail/sensor__traits.hpp"
// Member 'imus'
#include "tensegrity_interfaces/msg/detail/imu__traits.hpp"
// Member 'nodes'
#include "tensegrity_interfaces/msg/detail/node__traits.hpp"
// Member 'trajectory'
#include "tensegrity_interfaces/msg/detail/trajectory__traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TensegrityStamped & msg,
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
    out << ", ";
  }

  // member: sensors
  {
    if (msg.sensors.size() == 0) {
      out << "sensors: []";
    } else {
      out << "sensors: [";
      size_t pending_items = msg.sensors.size();
      for (auto item : msg.sensors) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
    out << ", ";
  }

  // member: nodes
  {
    if (msg.nodes.size() == 0) {
      out << "nodes: []";
    } else {
      out << "nodes: [";
      size_t pending_items = msg.nodes.size();
      for (auto item : msg.nodes) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
    out << ", ";
  }

  // member: actions
  {
    if (msg.actions.size() == 0) {
      out << "actions: []";
    } else {
      out << "actions: [";
      size_t pending_items = msg.actions.size();
      for (auto item : msg.actions) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const TensegrityStamped & msg,
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

  // member: sensors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sensors.size() == 0) {
      out << "sensors: []\n";
    } else {
      out << "sensors:\n";
      for (auto item : msg.sensors) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
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

  // member: nodes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.nodes.size() == 0) {
      out << "nodes: []\n";
    } else {
      out << "nodes:\n";
      for (auto item : msg.nodes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
  }

  // member: actions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.actions.size() == 0) {
      out << "actions: []\n";
    } else {
      out << "actions:\n";
      for (auto item : msg.actions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TensegrityStamped & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::TensegrityStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::TensegrityStamped & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::TensegrityStamped>()
{
  return "tensegrity_interfaces::msg::TensegrityStamped";
}

template<>
inline const char * name<tensegrity_interfaces::msg::TensegrityStamped>()
{
  return "tensegrity_interfaces/msg/TensegrityStamped";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::TensegrityStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::TensegrityStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensegrity_interfaces::msg::TensegrityStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__TRAITS_HPP_
