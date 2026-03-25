// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/Sensor.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__Sensor __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__Sensor __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Sensor_
{
  using Type = Sensor_<ContainerAllocator>;

  explicit Sensor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->length = 0.0f;
      this->capacitance = 0.0f;
    }
  }

  explicit Sensor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->length = 0.0f;
      this->capacitance = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    int8_t;
  _id_type id;
  using _length_type =
    float;
  _length_type length;
  using _capacitance_type =
    float;
  _capacitance_type capacitance;

  // setters for named parameter idiom
  Type & set__id(
    const int8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__length(
    const float & _arg)
  {
    this->length = _arg;
    return *this;
  }
  Type & set__capacitance(
    const float & _arg)
  {
    this->capacitance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::Sensor_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::Sensor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Sensor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Sensor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Sensor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__Sensor
    std::shared_ptr<tensegrity_interfaces::msg::Sensor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__Sensor
    std::shared_ptr<tensegrity_interfaces::msg::Sensor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Sensor_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->capacitance != other.capacitance) {
      return false;
    }
    return true;
  }
  bool operator!=(const Sensor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Sensor_

// alias to use template instance with default allocator
using Sensor =
  tensegrity_interfaces::msg::Sensor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__SENSOR__STRUCT_HPP_
