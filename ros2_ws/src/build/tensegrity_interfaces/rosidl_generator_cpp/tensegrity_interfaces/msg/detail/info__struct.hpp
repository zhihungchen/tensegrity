// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/Info.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__Info __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__Info __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Info_
{
  using Type = Info_<ContainerAllocator>;

  explicit Info_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_length = 0;
      this->range = 0;
      this->max_range = 0;
      this->min_range = 0;
      this->range024 = 0;
      this->range135 = 0;
      this->max_speed = 0;
      this->tol = 0.0;
      this->low_tol = 0.0;
      this->p = 0.0;
      this->i = 0.0;
      this->d = 0.0;
      this->dist_weight = 0.0;
      this->ang_weight = 0.0;
      this->prog_weight = 0.0;
    }
  }

  explicit Info_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_length = 0;
      this->range = 0;
      this->max_range = 0;
      this->min_range = 0;
      this->range024 = 0;
      this->range135 = 0;
      this->max_speed = 0;
      this->tol = 0.0;
      this->low_tol = 0.0;
      this->p = 0.0;
      this->i = 0.0;
      this->d = 0.0;
      this->dist_weight = 0.0;
      this->ang_weight = 0.0;
      this->prog_weight = 0.0;
    }
  }

  // field types and members
  using _min_length_type =
    uint8_t;
  _min_length_type min_length;
  using _range_type =
    uint8_t;
  _range_type range;
  using _max_range_type =
    uint8_t;
  _max_range_type max_range;
  using _min_range_type =
    uint8_t;
  _min_range_type min_range;
  using _range024_type =
    uint8_t;
  _range024_type range024;
  using _range135_type =
    uint8_t;
  _range135_type range135;
  using _max_speed_type =
    int8_t;
  _max_speed_type max_speed;
  using _tol_type =
    double;
  _tol_type tol;
  using _low_tol_type =
    double;
  _low_tol_type low_tol;
  using _p_type =
    double;
  _p_type p;
  using _i_type =
    double;
  _i_type i;
  using _d_type =
    double;
  _d_type d;
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
  Type & set__min_length(
    const uint8_t & _arg)
  {
    this->min_length = _arg;
    return *this;
  }
  Type & set__range(
    const uint8_t & _arg)
  {
    this->range = _arg;
    return *this;
  }
  Type & set__max_range(
    const uint8_t & _arg)
  {
    this->max_range = _arg;
    return *this;
  }
  Type & set__min_range(
    const uint8_t & _arg)
  {
    this->min_range = _arg;
    return *this;
  }
  Type & set__range024(
    const uint8_t & _arg)
  {
    this->range024 = _arg;
    return *this;
  }
  Type & set__range135(
    const uint8_t & _arg)
  {
    this->range135 = _arg;
    return *this;
  }
  Type & set__max_speed(
    const int8_t & _arg)
  {
    this->max_speed = _arg;
    return *this;
  }
  Type & set__tol(
    const double & _arg)
  {
    this->tol = _arg;
    return *this;
  }
  Type & set__low_tol(
    const double & _arg)
  {
    this->low_tol = _arg;
    return *this;
  }
  Type & set__p(
    const double & _arg)
  {
    this->p = _arg;
    return *this;
  }
  Type & set__i(
    const double & _arg)
  {
    this->i = _arg;
    return *this;
  }
  Type & set__d(
    const double & _arg)
  {
    this->d = _arg;
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
    tensegrity_interfaces::msg::Info_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::Info_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Info_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Info_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Info_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Info_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Info_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Info_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Info_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Info_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__Info
    std::shared_ptr<tensegrity_interfaces::msg::Info_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__Info
    std::shared_ptr<tensegrity_interfaces::msg::Info_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Info_ & other) const
  {
    if (this->min_length != other.min_length) {
      return false;
    }
    if (this->range != other.range) {
      return false;
    }
    if (this->max_range != other.max_range) {
      return false;
    }
    if (this->min_range != other.min_range) {
      return false;
    }
    if (this->range024 != other.range024) {
      return false;
    }
    if (this->range135 != other.range135) {
      return false;
    }
    if (this->max_speed != other.max_speed) {
      return false;
    }
    if (this->tol != other.tol) {
      return false;
    }
    if (this->low_tol != other.low_tol) {
      return false;
    }
    if (this->p != other.p) {
      return false;
    }
    if (this->i != other.i) {
      return false;
    }
    if (this->d != other.d) {
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
  bool operator!=(const Info_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Info_

// alias to use template instance with default allocator
using Info =
  tensegrity_interfaces::msg::Info_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__INFO__STRUCT_HPP_
