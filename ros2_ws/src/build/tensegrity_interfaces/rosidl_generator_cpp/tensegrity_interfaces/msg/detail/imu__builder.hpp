// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tensegrity_interfaces:msg/Imu.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__BUILDER_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tensegrity_interfaces/msg/detail/imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tensegrity_interfaces
{

namespace msg
{

namespace builder
{

class Init_Imu_mz
{
public:
  explicit Init_Imu_mz(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  ::tensegrity_interfaces::msg::Imu mz(::tensegrity_interfaces::msg::Imu::_mz_type arg)
  {
    msg_.mz = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_my
{
public:
  explicit Init_Imu_my(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_mz my(::tensegrity_interfaces::msg::Imu::_my_type arg)
  {
    msg_.my = std::move(arg);
    return Init_Imu_mz(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_mx
{
public:
  explicit Init_Imu_mx(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_my mx(::tensegrity_interfaces::msg::Imu::_mx_type arg)
  {
    msg_.mx = std::move(arg);
    return Init_Imu_my(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_gz
{
public:
  explicit Init_Imu_gz(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_mx gz(::tensegrity_interfaces::msg::Imu::_gz_type arg)
  {
    msg_.gz = std::move(arg);
    return Init_Imu_mx(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_gy
{
public:
  explicit Init_Imu_gy(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_gz gy(::tensegrity_interfaces::msg::Imu::_gy_type arg)
  {
    msg_.gy = std::move(arg);
    return Init_Imu_gz(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_gx
{
public:
  explicit Init_Imu_gx(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_gy gx(::tensegrity_interfaces::msg::Imu::_gx_type arg)
  {
    msg_.gx = std::move(arg);
    return Init_Imu_gy(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_az
{
public:
  explicit Init_Imu_az(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_gx az(::tensegrity_interfaces::msg::Imu::_az_type arg)
  {
    msg_.az = std::move(arg);
    return Init_Imu_gx(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_ay
{
public:
  explicit Init_Imu_ay(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_az ay(::tensegrity_interfaces::msg::Imu::_ay_type arg)
  {
    msg_.ay = std::move(arg);
    return Init_Imu_az(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_ax
{
public:
  explicit Init_Imu_ax(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_ay ax(::tensegrity_interfaces::msg::Imu::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_Imu_ay(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_z
{
public:
  explicit Init_Imu_z(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_ax z(::tensegrity_interfaces::msg::Imu::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Imu_ax(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_y
{
public:
  explicit Init_Imu_y(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_z y(::tensegrity_interfaces::msg::Imu::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Imu_z(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_x
{
public:
  explicit Init_Imu_x(::tensegrity_interfaces::msg::Imu & msg)
  : msg_(msg)
  {}
  Init_Imu_y x(::tensegrity_interfaces::msg::Imu::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Imu_y(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

class Init_Imu_id
{
public:
  Init_Imu_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Imu_x id(::tensegrity_interfaces::msg::Imu::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Imu_x(msg_);
  }

private:
  ::tensegrity_interfaces::msg::Imu msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tensegrity_interfaces::msg::Imu>()
{
  return tensegrity_interfaces::msg::builder::Init_Imu_id();
}

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__IMU__BUILDER_HPP_
