// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tensegrity_interfaces:msg/Action.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__TRAITS_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tensegrity_interfaces/msg/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'coms'
// Member 'pas'
// Member 'endcaps'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace tensegrity_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Action & msg,
  std::ostream & out)
{
  out << "{";
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
    out << ", ";
  }

  // member: cost
  {
    out << "cost: ";
    rosidl_generator_traits::value_to_yaml(msg.cost, out);
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

  // member: endcaps
  {
    if (msg.endcaps.size() == 0) {
      out << "endcaps: []";
    } else {
      out << "endcaps: [";
      size_t pending_items = msg.endcaps.size();
      for (auto item : msg.endcaps) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
  const Action & msg,
  std::ostream & out, size_t indentation = 0)
{
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

  // member: cost
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cost: ";
    rosidl_generator_traits::value_to_yaml(msg.cost, out);
    out << "\n";
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

  // member: endcaps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.endcaps.size() == 0) {
      out << "endcaps: []\n";
    } else {
      out << "endcaps:\n";
      for (auto item : msg.endcaps) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
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

inline std::string to_yaml(const Action & msg, bool use_flow_style = false)
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
  const tensegrity_interfaces::msg::Action & msg,
  std::ostream & out, size_t indentation = 0)
{
  tensegrity_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tensegrity_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tensegrity_interfaces::msg::Action & msg)
{
  return tensegrity_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tensegrity_interfaces::msg::Action>()
{
  return "tensegrity_interfaces::msg::Action";
}

template<>
inline const char * name<tensegrity_interfaces::msg::Action>()
{
  return "tensegrity_interfaces/msg/Action";
}

template<>
struct has_fixed_size<tensegrity_interfaces::msg::Action>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tensegrity_interfaces::msg::Action>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tensegrity_interfaces::msg::Action>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__TRAITS_HPP_
