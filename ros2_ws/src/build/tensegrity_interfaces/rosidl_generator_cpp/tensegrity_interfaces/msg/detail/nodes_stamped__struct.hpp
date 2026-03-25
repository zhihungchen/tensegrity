// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tensegrity_interfaces:msg/NodesStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__STRUCT_HPP_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__STRUCT_HPP_

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
// Member 'reconstructed_nodes'
// Member 'mocap_nodes'
#include "tensegrity_interfaces/msg/detail/node__struct.hpp"
// Member 'imus'
#include "tensegrity_interfaces/msg/detail/imu__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tensegrity_interfaces__msg__NodesStamped __attribute__((deprecated))
#else
# define DEPRECATED__tensegrity_interfaces__msg__NodesStamped __declspec(deprecated)
#endif

namespace tensegrity_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NodesStamped_
{
  using Type = NodesStamped_<ContainerAllocator>;

  explicit NodesStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit NodesStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _reconstructed_nodes_type =
    std::vector<tensegrity_interfaces::msg::Node_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Node_<ContainerAllocator>>>;
  _reconstructed_nodes_type reconstructed_nodes;
  using _mocap_nodes_type =
    std::vector<tensegrity_interfaces::msg::Node_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Node_<ContainerAllocator>>>;
  _mocap_nodes_type mocap_nodes;
  using _imus_type =
    std::vector<tensegrity_interfaces::msg::Imu_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Imu_<ContainerAllocator>>>;
  _imus_type imus;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__reconstructed_nodes(
    const std::vector<tensegrity_interfaces::msg::Node_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Node_<ContainerAllocator>>> & _arg)
  {
    this->reconstructed_nodes = _arg;
    return *this;
  }
  Type & set__mocap_nodes(
    const std::vector<tensegrity_interfaces::msg::Node_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Node_<ContainerAllocator>>> & _arg)
  {
    this->mocap_nodes = _arg;
    return *this;
  }
  Type & set__imus(
    const std::vector<tensegrity_interfaces::msg::Imu_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tensegrity_interfaces::msg::Imu_<ContainerAllocator>>> & _arg)
  {
    this->imus = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tensegrity_interfaces__msg__NodesStamped
    std::shared_ptr<tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tensegrity_interfaces__msg__NodesStamped
    std::shared_ptr<tensegrity_interfaces::msg::NodesStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NodesStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->reconstructed_nodes != other.reconstructed_nodes) {
      return false;
    }
    if (this->mocap_nodes != other.mocap_nodes) {
      return false;
    }
    if (this->imus != other.imus) {
      return false;
    }
    return true;
  }
  bool operator!=(const NodesStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NodesStamped_

// alias to use template instance with default allocator
using NodesStamped =
  tensegrity_interfaces::msg::NodesStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tensegrity_interfaces

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__STRUCT_HPP_
