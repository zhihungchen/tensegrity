// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/MotorsStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__MotorsStamped __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__MotorsStamped __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorsStamped_
{
  using Type = MotorsStamped_<ContainerAllocator>;

  explicit MotorsStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    info(_init)
  {
    (void)_init;
  }

  explicit MotorsStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    info(_alloc, _init)
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

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__MotorsStamped
    std::shared_ptr<tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__MotorsStamped
    std::shared_ptr<tensegrity_interfaces::msg::MotorsStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorsStamped_ & other) const
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
    return true;
  }
  bool operator!=(const MotorsStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorsStamped_

// alias to use template instance with default allocator
using MotorsStamped =
  tensegrity_interfaces::msg::MotorsStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__MOTORS_STAMPED__STRUCT_HPP_
