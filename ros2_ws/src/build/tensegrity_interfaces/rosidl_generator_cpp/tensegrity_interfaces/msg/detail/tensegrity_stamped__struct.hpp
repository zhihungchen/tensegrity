// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/TensegrityStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'info'
#include "tensegrity_interfaces/msg/detail/info__struct.hpp"
// Member 'motors'
#include "tensegrity_interfaces/msg/detail/motor__struct.hpp"
// Member 'sensors'
#include "tensegrity_interfaces/msg/detail/sensor__struct.hpp"
// Member 'imus'
#include "tensegrity_interfaces/msg/detail/imu__struct.hpp"
// Member 'nodes'
#include "tensegrity_interfaces/msg/detail/node__struct.hpp"
// Member 'trajectory'
#include "tensegrity_interfaces/msg/detail/trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__TensegrityStamped __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__TensegrityStamped __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TensegrityStamped_
{
  using Type = TensegrityStamped_<ContainerAllocator>;

  explicit TensegrityStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    info(_init),
    trajectory(_init)
  {
    (void)_init;
  }

  explicit TensegrityStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    info(_alloc, _init),
    trajectory(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _info_type =
    tensegrity_interfaces::msg::Info_<ContainerAllocator>;
  _info_type info;
  using _motors_type =
    std::vector<tensegrity_interfaces::msg::Motor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Motor_<ContainerAllocator>>>;
  _motors_type motors;
  using _sensors_type =
    std::vector<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>>;
  _sensors_type sensors;
  using _imus_type =
    std::vector<tensegrity_interfaces::msg::Imu_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Imu_<ContainerAllocator>>>;
  _imus_type imus;
  using _nodes_type =
    std::vector<tensegrity_interfaces::msg::Node_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Node_<ContainerAllocator>>>;
  _nodes_type nodes;
  using _trajectory_type =
    tensegrity_interfaces::msg::Trajectory_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _actions_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _actions_type actions;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__info(
    const tensegrity_interfaces::msg::Info_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__motors(
    const std::vector<tensegrity_interfaces::msg::Motor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Motor_<ContainerAllocator>>> & _arg)
  {
    this->motors = _arg;
    return *this;
  }
  Type & set__sensors(
    const std::vector<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>> & _arg)
  {
    this->sensors = _arg;
    return *this;
  }
  Type & set__imus(
    const std::vector<tensegrity_interfaces::msg::Imu_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Imu_<ContainerAllocator>>> & _arg)
  {
    this->imus = _arg;
    return *this;
  }
  Type & set__nodes(
    const std::vector<tensegrity_interfaces::msg::Node_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Node_<ContainerAllocator>>> & _arg)
  {
    this->nodes = _arg;
    return *this;
  }
  Type & set__trajectory(
    const tensegrity_interfaces::msg::Trajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__actions(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->actions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__TensegrityStamped
    std::shared_ptr<tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__TensegrityStamped
    std::shared_ptr<tensegrity_interfaces::msg::TensegrityStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TensegrityStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->info != other.info) {
      return false;
    }
    if (this->motors != other.motors) {
      return false;
    }
    if (this->sensors != other.sensors) {
      return false;
    }
    if (this->imus != other.imus) {
      return false;
    }
    if (this->nodes != other.nodes) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->actions != other.actions) {
      return false;
    }
    return true;
  }
  bool operator!=(const TensegrityStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TensegrityStamped_

// alias to use template instance with default allocator
using TensegrityStamped =
  tensegrity_interfaces::msg::TensegrityStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__TENSEGRITY_STAMPED__STRUCT_HPP_
