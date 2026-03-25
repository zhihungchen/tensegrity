// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tensegrity_interfaces:msg/NodesStamped.idl
// generated code does not contain a copyright notice

#ifndef TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__FUNCTIONS_H_
#define TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tensegrity_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tensegrity_interfaces/msg/detail/nodes_stamped__struct.h"

/// Initialize msg/NodesStamped message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tensegrity_interfaces__msg__NodesStamped
 * )) before or use
 * tensegrity_interfaces__msg__NodesStamped__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
bool
tensegrity_interfaces__msg__NodesStamped__init(tensegrity_interfaces__msg__NodesStamped * msg);

/// Finalize msg/NodesStamped message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
void
tensegrity_interfaces__msg__NodesStamped__fini(tensegrity_interfaces__msg__NodesStamped * msg);

/// Create msg/NodesStamped message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tensegrity_interfaces__msg__NodesStamped__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
tensegrity_interfaces__msg__NodesStamped *
tensegrity_interfaces__msg__NodesStamped__create();

/// Destroy msg/NodesStamped message.
/**
 * It calls
 * tensegrity_interfaces__msg__NodesStamped__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
void
tensegrity_interfaces__msg__NodesStamped__destroy(tensegrity_interfaces__msg__NodesStamped * msg);

/// Check for msg/NodesStamped message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
bool
tensegrity_interfaces__msg__NodesStamped__are_equal(const tensegrity_interfaces__msg__NodesStamped * lhs, const tensegrity_interfaces__msg__NodesStamped * rhs);

/// Copy a msg/NodesStamped message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
bool
tensegrity_interfaces__msg__NodesStamped__copy(
  const tensegrity_interfaces__msg__NodesStamped * input,
  tensegrity_interfaces__msg__NodesStamped * output);

/// Initialize array of msg/NodesStamped messages.
/**
 * It allocates the memory for the number of elements and calls
 * tensegrity_interfaces__msg__NodesStamped__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
bool
tensegrity_interfaces__msg__NodesStamped__Sequence__init(tensegrity_interfaces__msg__NodesStamped__Sequence * array, size_t size);

/// Finalize array of msg/NodesStamped messages.
/**
 * It calls
 * tensegrity_interfaces__msg__NodesStamped__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
void
tensegrity_interfaces__msg__NodesStamped__Sequence__fini(tensegrity_interfaces__msg__NodesStamped__Sequence * array);

/// Create array of msg/NodesStamped messages.
/**
 * It allocates the memory for the array and calls
 * tensegrity_interfaces__msg__NodesStamped__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
tensegrity_interfaces__msg__NodesStamped__Sequence *
tensegrity_interfaces__msg__NodesStamped__Sequence__create(size_t size);

/// Destroy array of msg/NodesStamped messages.
/**
 * It calls
 * tensegrity_interfaces__msg__NodesStamped__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
void
tensegrity_interfaces__msg__NodesStamped__Sequence__destroy(tensegrity_interfaces__msg__NodesStamped__Sequence * array);

/// Check for msg/NodesStamped message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
bool
tensegrity_interfaces__msg__NodesStamped__Sequence__are_equal(const tensegrity_interfaces__msg__NodesStamped__Sequence * lhs, const tensegrity_interfaces__msg__NodesStamped__Sequence * rhs);

/// Copy an array of msg/NodesStamped messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tensegrity_interfaces
bool
tensegrity_interfaces__msg__NodesStamped__Sequence__copy(
  const tensegrity_interfaces__msg__NodesStamped__Sequence * input,
  tensegrity_interfaces__msg__NodesStamped__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TENSEGRITY_INTERFACES__MSG__DETAIL__NODES_STAMPED__FUNCTIONS_H_
