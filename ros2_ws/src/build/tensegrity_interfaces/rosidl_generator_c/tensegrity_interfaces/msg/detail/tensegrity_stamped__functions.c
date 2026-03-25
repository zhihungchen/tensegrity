// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensegrity_interfaces:msg/TensegrityStamped.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `info`
#include "tensegrity_interfaces/msg/detail/info__functions.h"
// Member `motors`
#include "tensegrity_interfaces/msg/detail/motor__functions.h"
// Member `sensors`
#include "tensegrity_interfaces/msg/detail/sensor__functions.h"
// Member `imus`
#include "tensegrity_interfaces/msg/detail/imu__functions.h"
// Member `nodes`
#include "tensegrity_interfaces/msg/detail/node__functions.h"
// Member `trajectory`
#include "tensegrity_interfaces/msg/detail/trajectory__functions.h"
// Member `actions`
#include "rosidl_runtime_c/string_functions.h"

bool
tensegrity_interfaces__msg__TensegrityStamped__init(tensegrity_interfaces__msg__TensegrityStamped * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
    return false;
  }
  // info
  if (!tensegrity_interfaces__msg__Info__init(&msg->info)) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
    return false;
  }
  // motors
  if (!tensegrity_interfaces__msg__Motor__Sequence__init(&msg->motors, 0)) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
    return false;
  }
  // sensors
  if (!tensegrity_interfaces__msg__Sensor__Sequence__init(&msg->sensors, 0)) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
    return false;
  }
  // imus
  if (!tensegrity_interfaces__msg__Imu__Sequence__init(&msg->imus, 0)) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
    return false;
  }
  // nodes
  if (!tensegrity_interfaces__msg__Node__Sequence__init(&msg->nodes, 0)) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
    return false;
  }
  // trajectory
  if (!tensegrity_interfaces__msg__Trajectory__init(&msg->trajectory)) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
    return false;
  }
  // actions
  if (!rosidl_runtime_c__String__Sequence__init(&msg->actions, 0)) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
    return false;
  }
  return true;
}

void
tensegrity_interfaces__msg__TensegrityStamped__fini(tensegrity_interfaces__msg__TensegrityStamped * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // info
  tensegrity_interfaces__msg__Info__fini(&msg->info);
  // motors
  tensegrity_interfaces__msg__Motor__Sequence__fini(&msg->motors);
  // sensors
  tensegrity_interfaces__msg__Sensor__Sequence__fini(&msg->sensors);
  // imus
  tensegrity_interfaces__msg__Imu__Sequence__fini(&msg->imus);
  // nodes
  tensegrity_interfaces__msg__Node__Sequence__fini(&msg->nodes);
  // trajectory
  tensegrity_interfaces__msg__Trajectory__fini(&msg->trajectory);
  // actions
  rosidl_runtime_c__String__Sequence__fini(&msg->actions);
}

bool
tensegrity_interfaces__msg__TensegrityStamped__are_equal(const tensegrity_interfaces__msg__TensegrityStamped * lhs, const tensegrity_interfaces__msg__TensegrityStamped * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // info
  if (!tensegrity_interfaces__msg__Info__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // motors
  if (!tensegrity_interfaces__msg__Motor__Sequence__are_equal(
      &(lhs->motors), &(rhs->motors)))
  {
    return false;
  }
  // sensors
  if (!tensegrity_interfaces__msg__Sensor__Sequence__are_equal(
      &(lhs->sensors), &(rhs->sensors)))
  {
    return false;
  }
  // imus
  if (!tensegrity_interfaces__msg__Imu__Sequence__are_equal(
      &(lhs->imus), &(rhs->imus)))
  {
    return false;
  }
  // nodes
  if (!tensegrity_interfaces__msg__Node__Sequence__are_equal(
      &(lhs->nodes), &(rhs->nodes)))
  {
    return false;
  }
  // trajectory
  if (!tensegrity_interfaces__msg__Trajectory__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  // actions
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->actions), &(rhs->actions)))
  {
    return false;
  }
  return true;
}

bool
tensegrity_interfaces__msg__TensegrityStamped__copy(
  const tensegrity_interfaces__msg__TensegrityStamped * input,
  tensegrity_interfaces__msg__TensegrityStamped * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // info
  if (!tensegrity_interfaces__msg__Info__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // motors
  if (!tensegrity_interfaces__msg__Motor__Sequence__copy(
      &(input->motors), &(output->motors)))
  {
    return false;
  }
  // sensors
  if (!tensegrity_interfaces__msg__Sensor__Sequence__copy(
      &(input->sensors), &(output->sensors)))
  {
    return false;
  }
  // imus
  if (!tensegrity_interfaces__msg__Imu__Sequence__copy(
      &(input->imus), &(output->imus)))
  {
    return false;
  }
  // nodes
  if (!tensegrity_interfaces__msg__Node__Sequence__copy(
      &(input->nodes), &(output->nodes)))
  {
    return false;
  }
  // trajectory
  if (!tensegrity_interfaces__msg__Trajectory__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  // actions
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->actions), &(output->actions)))
  {
    return false;
  }
  return true;
}

tensegrity_interfaces__msg__TensegrityStamped *
tensegrity_interfaces__msg__TensegrityStamped__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__TensegrityStamped * msg = (tensegrity_interfaces__msg__TensegrityStamped *)allocator.allocate(sizeof(tensegrity_interfaces__msg__TensegrityStamped), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensegrity_interfaces__msg__TensegrityStamped));
  bool success = tensegrity_interfaces__msg__TensegrityStamped__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensegrity_interfaces__msg__TensegrityStamped__destroy(tensegrity_interfaces__msg__TensegrityStamped * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensegrity_interfaces__msg__TensegrityStamped__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensegrity_interfaces__msg__TensegrityStamped__Sequence__init(tensegrity_interfaces__msg__TensegrityStamped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__TensegrityStamped * data = NULL;

  if (size) {
    data = (tensegrity_interfaces__msg__TensegrityStamped *)allocator.zero_allocate(size, sizeof(tensegrity_interfaces__msg__TensegrityStamped), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensegrity_interfaces__msg__TensegrityStamped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensegrity_interfaces__msg__TensegrityStamped__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tensegrity_interfaces__msg__TensegrityStamped__Sequence__fini(tensegrity_interfaces__msg__TensegrityStamped__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tensegrity_interfaces__msg__TensegrityStamped__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tensegrity_interfaces__msg__TensegrityStamped__Sequence *
tensegrity_interfaces__msg__TensegrityStamped__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__TensegrityStamped__Sequence * array = (tensegrity_interfaces__msg__TensegrityStamped__Sequence *)allocator.allocate(sizeof(tensegrity_interfaces__msg__TensegrityStamped__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensegrity_interfaces__msg__TensegrityStamped__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensegrity_interfaces__msg__TensegrityStamped__Sequence__destroy(tensegrity_interfaces__msg__TensegrityStamped__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensegrity_interfaces__msg__TensegrityStamped__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensegrity_interfaces__msg__TensegrityStamped__Sequence__are_equal(const tensegrity_interfaces__msg__TensegrityStamped__Sequence * lhs, const tensegrity_interfaces__msg__TensegrityStamped__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensegrity_interfaces__msg__TensegrityStamped__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensegrity_interfaces__msg__TensegrityStamped__Sequence__copy(
  const tensegrity_interfaces__msg__TensegrityStamped__Sequence * input,
  tensegrity_interfaces__msg__TensegrityStamped__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensegrity_interfaces__msg__TensegrityStamped);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensegrity_interfaces__msg__TensegrityStamped * data =
      (tensegrity_interfaces__msg__TensegrityStamped *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensegrity_interfaces__msg__TensegrityStamped__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensegrity_interfaces__msg__TensegrityStamped__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensegrity_interfaces__msg__TensegrityStamped__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
