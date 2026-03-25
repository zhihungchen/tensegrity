// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/NodesStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/nodes_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'reconstructed_nodes'
// Member 'mocap_nodes'
#include "tensegrity_interfaces/msg/detail/node__traits.hpp"
// Member 'imus'
#include "tensegrity_interfaces/msg/detail/imu__traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const NodesStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: reconstructed_nodes
  {
    if (msg.reconstructed_nodes.size() == 0) {
      out << "reconstructed_nodes: []";
    } else {
      out << "reconstructed_nodes: [";
      size_t pending_items = msg.reconstructed_nodes.size();
      for (auto item : msg.reconstructed_nodes) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: mocap_nodes
  {
    if (msg.mocap_nodes.size() == 0) {
      out << "mocap_nodes: []";
    } else {
      out << "mocap_nodes: [";
      size_t pending_items = msg.mocap_nodes.size();
      for (auto item : msg.mocap_nodes) {
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NodesStamped & msg,
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

  // member: reconstructed_nodes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.reconstructed_nodes.size() == 0) {
      out << "reconstructed_nodes: []\n";
    } else {
      out << "reconstructed_nodes:\n";
      for (auto item : msg.reconstructed_nodes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: mocap_nodes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.mocap_nodes.size() == 0) {
      out << "mocap_nodes: []\n";
    } else {
      out << "mocap_nodes:\n";
      for (auto item : msg.mocap_nodes) {
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NodesStamped & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::NodesStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::NodesStamped & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::NodesStamped>()
{
  return "tensegrity_interfaces::msg::NodesStamped";
}

template<>
inline const char * name<tensegrity_interfaces::msg::NodesStamped>()
{
  return "tensegrity_interfaces/msg/NodesStamped";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::NodesStamped>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::NodesStamped>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensegrity_interfaces::msg::NodesStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__TRAITS_HPP_
