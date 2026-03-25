// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__Imu __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__Imu __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Imu_
{
  using Type = Imu_<ContainerAllocator>;

  explicit Imu_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->gx = 0.0;
      this->gy = 0.0;
      this->gz = 0.0;
      this->mx = 0.0;
      this->my = 0.0;
      this->mz = 0.0;
    }
  }

  explicit Imu_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->ax = 0.0;
      this->ay = 0.0;
      this->az = 0.0;
      this->gx = 0.0;
      this->gy = 0.0;
      this->gz = 0.0;
      this->mx = 0.0;
      this->my = 0.0;
      this->mz = 0.0;
    }
  }

  // field types and members
  using _id_type =
    int8_t;
  _id_type id;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _ax_type =
    double;
  _ax_type ax;
  using _ay_type =
    double;
  _ay_type ay;
  using _az_type =
    double;
  _az_type az;
  using _gx_type =
    double;
  _gx_type gx;
  using _gy_type =
    double;
  _gy_type gy;
  using _gz_type =
    double;
  _gz_type gz;
  using _mx_type =
    double;
  _mx_type mx;
  using _my_type =
    double;
  _my_type my;
  using _mz_type =
    double;
  _mz_type mz;

  // setters for named parameter idiom
  Type & set__id(
    const int8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__ax(
    const double & _arg)
  {
    this->ax = _arg;
    return *this;
  }
  Type & set__ay(
    const double & _arg)
  {
    this->ay = _arg;
    return *this;
  }
  Type & set__az(
    const double & _arg)
  {
    this->az = _arg;
    return *this;
  }
  Type & set__gx(
    const double & _arg)
  {
    this->gx = _arg;
    return *this;
  }
  Type & set__gy(
    const double & _arg)
  {
    this->gy = _arg;
    return *this;
  }
  Type & set__gz(
    const double & _arg)
  {
    this->gz = _arg;
    return *this;
  }
  Type & set__mx(
    const double & _arg)
  {
    this->mx = _arg;
    return *this;
  }
  Type & set__my(
    const double & _arg)
  {
    this->my = _arg;
    return *this;
  }
  Type & set__mz(
    const double & _arg)
  {
    this->mz = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::Imu_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::Imu_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Imu_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::Imu_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Imu_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Imu_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::Imu_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::Imu_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Imu_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::Imu_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__Imu
    std::shared_ptr<tensegrity_interfaces::msg::Imu_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__Imu
    std::shared_ptr<tensegrity_interfaces::msg::Imu_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Imu_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->ax != other.ax) {
      return false;
    }
    if (this->ay != other.ay) {
      return false;
    }
    if (this->az != other.az) {
      return false;
    }
    if (this->gx != other.gx) {
      return false;
    }
    if (this->gy != other.gy) {
      return false;
    }
    if (this->gz != other.gz) {
      return false;
    }
    if (this->mx != other.mx) {
      return false;
    }
    if (this->my != other.my) {
      return false;
    }
    if (this->mz != other.mz) {
      return false;
    }
    return true;
  }
  bool operator!=(const Imu_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Imu_

// alias to use template instance with default allocator
using Imu =
  tensegrity_interfaces::msg::Imu_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__STRUCT_HPP_
