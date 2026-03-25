// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensegrity_interfaces:msg/Trajectory.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `trajectory`
// Member `coms`
// Member `pas`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
tensegrity_interfaces__msg__Trajectory__init(tensegrity_interfaces__msg__Trajectory * msg)
{
  if (!msg) {
    return false;
  }
  // trajectory
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->trajectory, 0)) {
    tensegrity_interfaces__msg__Trajectory__fini(msg);
    return false;
  }
  // coms
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->coms, 0)) {
    tensegrity_interfaces__msg__Trajectory__fini(msg);
    return false;
  }
  // pas
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->pas, 0)) {
    tensegrity_interfaces__msg__Trajectory__fini(msg);
    return false;
  }
  // trajectory_segment
  return true;
}

void
tensegrity_interfaces__msg__Trajectory__fini(tensegrity_interfaces__msg__Trajectory * msg)
{
  if (!msg) {
    return;
  }
  // trajectory
  geometry_msgs__msg__Point__Sequence__fini(&msg->trajectory);
  // coms
  geometry_msgs__msg__Point__Sequence__fini(&msg->coms);
  // pas
  geometry_msgs__msg__Point__Sequence__fini(&msg->pas);
  // trajectory_segment
}

bool
tensegrity_interfaces__msg__Trajectory__are_equal(const tensegrity_interfaces__msg__Trajectory * lhs, const tensegrity_interfaces__msg__Trajectory * rhs)
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
  // coms
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->coms), &(rhs->coms)))
  {
    return false;
  }
  // pas
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->pas), &(rhs->pas)))
  {
    return false;
  }
  // trajectory_segment
  if (lhs->trajectory_segment != rhs->trajectory_segment) {
    return false;
  }
  return true;
}

bool
tensegrity_interfaces__msg__Trajectory__copy(
  const tensegrity_interfaces__msg__Trajectory * input,
  tensegrity_interfaces__msg__Trajectory * output)
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
  // coms
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->coms), &(output->coms)))
  {
    return false;
  }
  // pas
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->pas), &(output->pas)))
  {
    return false;
  }
  // trajectory_segment
  output->trajectory_segment = input->trajectory_segment;
  return true;
}

tensegrity_interfaces__msg__Trajectory *
tensegrity_interfaces__msg__Trajectory__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Trajectory * msg = (tensegrity_interfaces__msg__Trajectory *)allocator.allocate(sizeof(tensegrity_interfaces__msg__Trajectory), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensegrity_interfaces__msg__Trajectory));
  bool success = tensegrity_interfaces__msg__Trajectory__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensegrity_interfaces__msg__Trajectory__destroy(tensegrity_interfaces__msg__Trajectory * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensegrity_interfaces__msg__Trajectory__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensegrity_interfaces__msg__Trajectory__Sequence__init(tensegrity_interfaces__msg__Trajectory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Trajectory * data = NULL;

  if (size) {
    data = (tensegrity_interfaces__msg__Trajectory *)allocator.zero_allocate(size, sizeof(tensegrity_interfaces__msg__Trajectory), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensegrity_interfaces__msg__Trajectory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensegrity_interfaces__msg__Trajectory__fini(&data[i - 1]);
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
tensegrity_interfaces__msg__Trajectory__Sequence__fini(tensegrity_interfaces__msg__Trajectory__Sequence * array)
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
      tensegrity_interfaces__msg__Trajectory__fini(&array->data[i]);
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

tensegrity_interfaces__msg__Trajectory__Sequence *
tensegrity_interfaces__msg__Trajectory__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Trajectory__Sequence * array = (tensegrity_interfaces__msg__Trajectory__Sequence *)allocator.allocate(sizeof(tensegrity_interfaces__msg__Trajectory__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensegrity_interfaces__msg__Trajectory__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensegrity_interfaces__msg__Trajectory__Sequence__destroy(tensegrity_interfaces__msg__Trajectory__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensegrity_interfaces__msg__Trajectory__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensegrity_interfaces__msg__Trajectory__Sequence__are_equal(const tensegrity_interfaces__msg__Trajectory__Sequence * lhs, const tensegrity_interfaces__msg__Trajectory__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensegrity_interfaces__msg__Trajectory__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensegrity_interfaces__msg__Trajectory__Sequence__copy(
  const tensegrity_interfaces__msg__Trajectory__Sequence * input,
  tensegrity_interfaces__msg__Trajectory__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensegrity_interfaces__msg__Trajectory);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensegrity_interfaces__msg__Trajectory * data =
      (tensegrity_interfaces__msg__Trajectory *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensegrity_interfaces__msg__Trajectory__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensegrity_interfaces__msg__Trajectory__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensegrity_interfaces__msg__Trajectory__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
