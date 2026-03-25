// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensegrity_interfaces:msg/Info.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tensegrity_interfaces__msg__Info__init(tensegrity_interfaces__msg__Info * msg)
{
  if (!msg) {
    return false;
  }
  // min_length
  // range
  // max_range
  // min_range
  // range024
  // range135
  // max_speed
  // tol
  // low_tol
  // p
  // i
  // d
  // dist_weight
  // ang_weight
  // prog_weight
  return true;
}

void
tensegrity_interfaces__msg__Info__fini(tensegrity_interfaces__msg__Info * msg)
{
  if (!msg) {
    return;
  }
  // min_length
  // range
  // max_range
  // min_range
  // range024
  // range135
  // max_speed
  // tol
  // low_tol
  // p
  // i
  // d
  // dist_weight
  // ang_weight
  // prog_weight
}

bool
tensegrity_interfaces__msg__Info__are_equal(const tensegrity_interfaces__msg__Info * lhs, const tensegrity_interfaces__msg__Info * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // min_length
  if (lhs->min_length != rhs->min_length) {
    return false;
  }
  // range
  if (lhs->range != rhs->range) {
    return false;
  }
  // max_range
  if (lhs->max_range != rhs->max_range) {
    return false;
  }
  // min_range
  if (lhs->min_range != rhs->min_range) {
    return false;
  }
  // range024
  if (lhs->range024 != rhs->range024) {
    return false;
  }
  // range135
  if (lhs->range135 != rhs->range135) {
    return false;
  }
  // max_speed
  if (lhs->max_speed != rhs->max_speed) {
    return false;
  }
  // tol
  if (lhs->tol != rhs->tol) {
    return false;
  }
  // low_tol
  if (lhs->low_tol != rhs->low_tol) {
    return false;
  }
  // p
  if (lhs->p != rhs->p) {
    return false;
  }
  // i
  if (lhs->i != rhs->i) {
    return false;
  }
  // d
  if (lhs->d != rhs->d) {
    return false;
  }
  // dist_weight
  if (lhs->dist_weight != rhs->dist_weight) {
    return false;
  }
  // ang_weight
  if (lhs->ang_weight != rhs->ang_weight) {
    return false;
  }
  // prog_weight
  if (lhs->prog_weight != rhs->prog_weight) {
    return false;
  }
  return true;
}

bool
tensegrity_interfaces__msg__Info__copy(
  const tensegrity_interfaces__msg__Info * input,
  tensegrity_interfaces__msg__Info * output)
{
  if (!input || !output) {
    return false;
  }
  // min_length
  output->min_length = input->min_length;
  // range
  output->range = input->range;
  // max_range
  output->max_range = input->max_range;
  // min_range
  output->min_range = input->min_range;
  // range024
  output->range024 = input->range024;
  // range135
  output->range135 = input->range135;
  // max_speed
  output->max_speed = input->max_speed;
  // tol
  output->tol = input->tol;
  // low_tol
  output->low_tol = input->low_tol;
  // p
  output->p = input->p;
  // i
  output->i = input->i;
  // d
  output->d = input->d;
  // dist_weight
  output->dist_weight = input->dist_weight;
  // ang_weight
  output->ang_weight = input->ang_weight;
  // prog_weight
  output->prog_weight = input->prog_weight;
  return true;
}

tensegrity_interfaces__msg__Info *
tensegrity_interfaces__msg__Info__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Info * msg = (tensegrity_interfaces__msg__Info *)allocator.allocate(sizeof(tensegrity_interfaces__msg__Info), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensegrity_interfaces__msg__Info));
  bool success = tensegrity_interfaces__msg__Info__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensegrity_interfaces__msg__Info__destroy(tensegrity_interfaces__msg__Info * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensegrity_interfaces__msg__Info__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensegrity_interfaces__msg__Info__Sequence__init(tensegrity_interfaces__msg__Info__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Info * data = NULL;

  if (size) {
    data = (tensegrity_interfaces__msg__Info *)allocator.zero_allocate(size, sizeof(tensegrity_interfaces__msg__Info), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensegrity_interfaces__msg__Info__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensegrity_interfaces__msg__Info__fini(&data[i - 1]);
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
tensegrity_interfaces__msg__Info__Sequence__fini(tensegrity_interfaces__msg__Info__Sequence * array)
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
      tensegrity_interfaces__msg__Info__fini(&array->data[i]);
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

tensegrity_interfaces__msg__Info__Sequence *
tensegrity_interfaces__msg__Info__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Info__Sequence * array = (tensegrity_interfaces__msg__Info__Sequence *)allocator.allocate(sizeof(tensegrity_interfaces__msg__Info__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensegrity_interfaces__msg__Info__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensegrity_interfaces__msg__Info__Sequence__destroy(tensegrity_interfaces__msg__Info__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensegrity_interfaces__msg__Info__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensegrity_interfaces__msg__Info__Sequence__are_equal(const tensegrity_interfaces__msg__Info__Sequence * lhs, const tensegrity_interfaces__msg__Info__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensegrity_interfaces__msg__Info__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensegrity_interfaces__msg__Info__Sequence__copy(
  const tensegrity_interfaces__msg__Info__Sequence * input,
  tensegrity_interfaces__msg__Info__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensegrity_interfaces__msg__Info);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensegrity_interfaces__msg__Info * data =
      (tensegrity_interfaces__msg__Info *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensegrity_interfaces__msg__Info__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensegrity_interfaces__msg__Info__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensegrity_interfaces__msg__Info__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
