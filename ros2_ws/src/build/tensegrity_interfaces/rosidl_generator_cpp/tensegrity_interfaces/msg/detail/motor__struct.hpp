// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/Motor.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__Motor __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__Motor __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Motor_
{
  using Type = Motor_<ContainerAllocator>;

  explicit Motor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->position = 0.0;
      this->target = 0.0;
      this->speed = 0.0;
      this->done = false;
      this->error = 0.0;
      this->d_error = 0.0;
      this->cum_error = 0.0;
      this->encoder_counts = 0ll;
      this->encoder_length = 0.0;
    }
  }

  explicit Motor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->position = 0.0;
      this->target = 0.0;
      this->speed = 0.0;
      this->done = false;
      this->error = 0.0;
      this->d_error = 0.0;
      this->cum_error = 0.0;
      this->encoder_counts = 0ll;
      this->encoder_length = 0.0;
    }
  }

  // field types and members
  using _id_type =
    int8_t;
  _id_type id;
  using _position_type =
    double;
  _position_type position;
  using _target_type =
    double;
  _target_type target;
  using _speed_type =
    double;
  _speed_type speed;
  using _done_type =
    bool;
  _done_type done;
  using _error_type =
    double;
  _error_type error;
  using _d_error_type =
    double;
  _d_error_type d_error;
  using _cum_error_type =
    double;
  _cum_error_type cum_error;
  using _encoder_counts_type =
    int64_t;
  _encoder_counts_type encoder_counts;
  using _encoder_length_type =
    double;
  _encoder_length_type encoder_length;

  // setters for named parameter idiom
  Type & set__id(
    const int8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__position(
    const double & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__target(
    const double & _arg)
  {
    this->target = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__done(
    const bool & _arg)
  {
    this->done = _arg;
    return *this;
  }
  Type & set__error(
    const double & _arg)
  {
    this->error = _arg;
    return *this;
  }
  Type & set__d_error(
    const double & _arg)
  {
    this->d_error = _arg;
    return *this;
  }
  Type & set__cum_error(
    const double & _arg)
  {
    this->cum_error = _arg;
    return *this;
  }
  Type & set__encoder_counts(
    const int64_t & _arg)
  {
    this->encoder_counts = _arg;
    return *this;
  }
  Type & set__encoder_length(
    const double & _arg)
  {
    this->encoder_length = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::Motor_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::Motor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Motor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Motor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Motor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Motor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Motor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Motor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Motor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Motor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__Motor
    std::shared_ptr<tensegrity_interfaces::msg::Motor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__Motor
    std::shared_ptr<tensegrity_interfaces::msg::Motor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Motor_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->target != other.target) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->done != other.done) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    if (this->d_error != other.d_error) {
      return false;
    }
    if (this->cum_error != other.cum_error) {
      return false;
    }
    if (this->encoder_counts != other.encoder_counts) {
      return false;
    }
    if (this->encoder_length != other.encoder_length) {
      return false;
    }
    return true;
  }
  bool operator!=(const Motor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Motor_

// alias to use template instance with default allocator
using Motor =
  tensegrity_interfaces::msg::Motor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__MOTOR__STRUCT_HPP_
