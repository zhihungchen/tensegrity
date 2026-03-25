// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/SensorsStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__SENSORS_STAMPED__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__SENSORS_STAMPED__STRUCT_HPP_

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
// Member 'sensors'
#include "tensegrity_interfaces/msg/detail/sensor__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__SensorsStamped __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__SensorsStamped __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SensorsStamped_
{
  using Type = SensorsStamped_<ContainerAllocator>;

  explicit SensorsStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit SensorsStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _sensors_type =
    std::vector<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>>;
  _sensors_type sensors;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__sensors(
    const std::vector<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>> & _arg)
  {
    this->sensors = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__SensorsStamped
    std::shared_ptr<tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__SensorsStamped
    std::shared_ptr<tensegrity_interfaces::msg::SensorsStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorsStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->sensors != other.sensors) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorsStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorsStamped_

// alias to use template instance with default allocator
using SensorsStamped =
  tensegrity_interfaces::msg::SensorsStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__SENSORS_STAMPED__STRUCT_HPP_
