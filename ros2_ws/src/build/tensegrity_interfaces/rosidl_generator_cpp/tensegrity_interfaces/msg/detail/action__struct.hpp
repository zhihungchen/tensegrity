// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/Action.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'coms'
// Member 'pas'
// Member 'endcaps'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__Action __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__Action __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Action_
{
  using Type = Action_<ContainerAllocator>;

  explicit Action_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cost = 0.0;
      this->dist_weight = 0.0;
      this->ang_weight = 0.0;
      this->prog_weight = 0.0;
    }
  }

  explicit Action_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cost = 0.0;
      this->dist_weight = 0.0;
      this->ang_weight = 0.0;
      this->prog_weight = 0.0;
    }
  }

  // field types and members
  using _actions_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _actions_type actions;
  using _cost_type =
    double;
  _cost_type cost;
  using _coms_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _coms_type coms;
  using _pas_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _pas_type pas;
  using _endcaps_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _endcaps_type endcaps;
  using _dist_weight_type =
    double;
  _dist_weight_type dist_weight;
  using _ang_weight_type =
    double;
  _ang_weight_type ang_weight;
  using _prog_weight_type =
    double;
  _prog_weight_type prog_weight;

  // setters for named parameter idiom
  Type & set__actions(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->actions = _arg;
    return *this;
  }
  Type & set__cost(
    const double & _arg)
  {
    this->cost = _arg;
    return *this;
  }
  Type & set__coms(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->coms = _arg;
    return *this;
  }
  Type & set__pas(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->pas = _arg;
    return *this;
  }
  Type & set__endcaps(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->endcaps = _arg;
    return *this;
  }
  Type & set__dist_weight(
    const double & _arg)
  {
    this->dist_weight = _arg;
    return *this;
  }
  Type & set__ang_weight(
    const double & _arg)
  {
    this->ang_weight = _arg;
    return *this;
  }
  Type & set__prog_weight(
    const double & _arg)
  {
    this->prog_weight = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::Action_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::Action_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Action_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Action_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Action_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Action_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Action_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Action_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Action_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Action_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__Action
    std::shared_ptr<tensegrity_interfaces::msg::Action_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__Action
    std::shared_ptr<tensegrity_interfaces::msg::Action_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Action_ & other) const
  {
    if (this->actions != other.actions) {
      return false;
    }
    if (this->cost != other.cost) {
      return false;
    }
    if (this->coms != other.coms) {
      return false;
    }
    if (this->pas != other.pas) {
      return false;
    }
    if (this->endcaps != other.endcaps) {
      return false;
    }
    if (this->dist_weight != other.dist_weight) {
      return false;
    }
    if (this->ang_weight != other.ang_weight) {
      return false;
    }
    if (this->prog_weight != other.prog_weight) {
      return false;
    }
    return true;
  }
  bool operator!=(const Action_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Action_

// alias to use template instance with default allocator
using Action =
  tensegrity_interfaces::msg::Action_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__ACTION__STRUCT_HPP_
