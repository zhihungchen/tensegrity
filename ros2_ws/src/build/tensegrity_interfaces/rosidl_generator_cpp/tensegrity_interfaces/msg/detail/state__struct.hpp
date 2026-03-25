// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/State.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'trajectory'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__State __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__State __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct State_
{
  using Type = State_<ContainerAllocator>;

  explicit State_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->prev_action = "";
      this->reverse_the_gait = false;
      this->bar_height_changed = false;
    }
  }

  explicit State_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : prev_action(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->prev_action = "";
      this->reverse_the_gait = false;
      this->bar_height_changed = false;
    }
  }

  // field types and members
  using _trajectory_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _trajectory_type trajectory;
  using _prev_action_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _prev_action_type prev_action;
  using _reverse_the_gait_type =
    bool;
  _reverse_the_gait_type reverse_the_gait;
  using _bar_height_changed_type =
    bool;
  _bar_height_changed_type bar_height_changed;

  // setters for named parameter idiom
  Type & set__trajectory(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__prev_action(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->prev_action = _arg;
    return *this;
  }
  Type & set__reverse_the_gait(
    const bool & _arg)
  {
    this->reverse_the_gait = _arg;
    return *this;
  }
  Type & set__bar_height_changed(
    const bool & _arg)
  {
    this->bar_height_changed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::State_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::State_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::State_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::State_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::State_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::State_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::State_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::State_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::State_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::State_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__State
    std::shared_ptr<tensegrity_interfaces::msg::State_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__State
    std::shared_ptr<tensegrity_interfaces::msg::State_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const State_ & other) const
  {
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->prev_action != other.prev_action) {
      return false;
    }
    if (this->reverse_the_gait != other.reverse_the_gait) {
      return false;
    }
    if (this->bar_height_changed != other.bar_height_changed) {
      return false;
    }
    return true;
  }
  bool operator!=(const State_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct State_

// alias to use template instance with default allocator
using State =
  tensegrity_interfaces::msg::State_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__STATE__STRUCT_HPP_
