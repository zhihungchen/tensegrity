// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensegrity_interfaces:msg/State.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `trajectory`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `prev_action`
#include "rosidl_runtime_c/string_functions.h"

bool
tensegrity_interfaces__msg__State__init(tensegrity_interfaces__msg__State * msg)
{
  if (!msg) {
    return false;
  }
  // trajectory
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->trajectory, 0)) {
    tensegrity_interfaces__msg__State__fini(msg);
    return false;
  }
  // prev_action
  if (!rosidl_runtime_c__String__init(&msg->prev_action)) {
    tensegrity_interfaces__msg__State__fini(msg);
    return false;
  }
  // reverse_the_gait
  // bar_height_changed
  return true;
}

void
tensegrity_interfaces__msg__State__fini(tensegrity_interfaces__msg__State * msg)
{
  if (!msg) {
    return;
  }
  // trajectory
  geometry_msgs__msg__Point__Sequence__fini(&msg->trajectory);
  // prev_action
  rosidl_runtime_c__String__fini(&msg->prev_action);
  // reverse_the_gait
  // bar_height_changed
}

bool
tensegrity_interfaces__msg__State__are_equal(const tensegrity_interfaces__msg__State * lhs, const tensegrity_interfaces__msg__State * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // trajectory
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  // prev_action
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->prev_action), &(rhs->prev_action)))
  {
    return false;
  }
  // reverse_the_gait
  if (lhs->reverse_the_gait != rhs->reverse_the_gait) {
    return false;
  }
  // bar_height_changed
  if (lhs->bar_height_changed != rhs->bar_height_changed) {
    return false;
  }
  return true;
}

bool
tensegrity_interfaces__msg__State__copy(
  const tensegrity_interfaces__msg__State * input,
  tensegrity_interfaces__msg__State * output)
{
  if (!input || !output) {
    return false;
  }
  // trajectory
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  // prev_action
  if (!rosidl_runtime_c__String__copy(
      &(input->prev_action), &(output->prev_action)))
  {
    return false;
  }
  // reverse_the_gait
  output->reverse_the_gait = input->reverse_the_gait;
  // bar_height_changed
  output->bar_height_changed = input->bar_height_changed;
  return true;
}

tensegrity_interfaces__msg__State *
tensegrity_interfaces__msg__State__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__State * msg = (tensegrity_interfaces__msg__State *)allocator.allocate(sizeof(tensegrity_interfaces__msg__State), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensegrity_interfaces__msg__State));
  bool success = tensegrity_interfaces__msg__State__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensegrity_interfaces__msg__State__destroy(tensegrity_interfaces__msg__State * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensegrity_interfaces__msg__State__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensegrity_interfaces__msg__State__Sequence__init(tensegrity_interfaces__msg__State__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__State * data = NULL;

  if (size) {
    data = (tensegrity_interfaces__msg__State *)allocator.zero_allocate(size, sizeof(tensegrity_interfaces__msg__State), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensegrity_interfaces__msg__State__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensegrity_interfaces__msg__State__fini(&data[i - 1]);
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
tensegrity_interfaces__msg__State__Sequence__fini(tensegrity_interfaces__msg__State__Sequence * array)
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
      tensegrity_interfaces__msg__State__fini(&array->data[i]);
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

tensegrity_interfaces__msg__State__Sequence *
tensegrity_interfaces__msg__State__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__State__Sequence * array = (tensegrity_interfaces__msg__State__Sequence *)allocator.allocate(sizeof(tensegrity_interfaces__msg__State__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensegrity_interfaces__msg__State__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensegrity_interfaces__msg__State__Sequence__destroy(tensegrity_interfaces__msg__State__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensegrity_interfaces__msg__State__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensegrity_interfaces__msg__State__Sequence__are_equal(const tensegrity_interfaces__msg__State__Sequence * lhs, const tensegrity_interfaces__msg__State__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensegrity_interfaces__msg__State__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensegrity_interfaces__msg__State__Sequence__copy(
  const tensegrity_interfaces__msg__State__Sequence * input,
  tensegrity_interfaces__msg__State__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensegrity_interfaces__msg__State);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensegrity_interfaces__msg__State * data =
      (tensegrity_interfaces__msg__State *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensegrity_interfaces__msg__State__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensegrity_interfaces__msg__State__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensegrity_interfaces__msg__State__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
