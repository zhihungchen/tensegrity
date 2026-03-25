// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from tensegrity_interfaces:msg/TensegrityStamped.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace tensegrity_interfaces
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _TensegrityStamped_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _TensegrityStamped_type_support_ids_t;

static const _TensegrityStamped_type_support_ids_t _TensegrityStamped_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _TensegrityStamped_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _TensegrityStamped_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _TensegrityStamped_type_support_symbol_names_t _TensegrityStamped_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, tensegrity_interfaces, msg, TensegrityStamped)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tensegrity_interfaces, msg, TensegrityStamped)),
  }
};

typedef struct _TensegrityStamped_type_support_data_t
{
  void * data[2];
} _TensegrityStamped_type_support_data_t;

static _TensegrityStamped_type_support_data_t _TensegrityStamped_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _TensegrityStamped_message_typesupport_map = {
  2,
  "tensegrity_interfaces",
  &_TensegrityStamped_message_typesupport_ids.typesupport_identifier[0],
  &_TensegrityStamped_message_typesupport_symbol_names.symbol_name[0],
  &_TensegrityStamped_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t TensegrityStamped_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_TensegrityStamped_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace tensegrity_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tensegrity_interfaces::msg::TensegrityStamped>()
{
  return &::tensegrity_interfaces::msg::rosidl_typesupport_cpp::TensegrityStamped_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, tensegrity_interfaces, msg, TensegrityStamped)() {
  return get_message_type_support_handle<tensegrity_interfaces::msg::TensegrityStamped>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
