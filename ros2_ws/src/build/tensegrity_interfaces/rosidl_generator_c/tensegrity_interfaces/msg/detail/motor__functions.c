// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensegrity_interfaces:msg/Motor.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/motor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tensegrity_interfaces__msg__Motor__init(tensegrity_interfaces__msg__Motor * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // position
  // target
  // speed
  // done
  // error
  // d_error
  // cum_error
  // encoder_counts
  // encoder_length
  return true;
}

void
tensegrity_interfaces__msg__Motor__fini(tensegrity_interfaces__msg__Motor * msg)
{
  if (!msg) {
    return;
  }
  // id
  // position
  // target
  // speed
  // done
  // error
  // d_error
  // cum_error
  // encoder_counts
  // encoder_length
}

bool
tensegrity_interfaces__msg__Motor__are_equal(const tensegrity_interfaces__msg__Motor * lhs, const tensegrity_interfaces__msg__Motor * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // position
  if (lhs->position != rhs->position) {
    return false;
  }
  // target
  if (lhs->target != rhs->target) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // done
  if (lhs->done != rhs->done) {
    return false;
  }
  // error
  if (lhs->error != rhs->error) {
    return false;
  }
  // d_error
  if (lhs->d_error != rhs->d_error) {
    return false;
  }
  // cum_error
  if (lhs->cum_error != rhs->cum_error) {
    return false;
  }
  // encoder_counts
  if (lhs->encoder_counts != rhs->encoder_counts) {
    return false;
  }
  // encoder_length
  if (lhs->encoder_length != rhs->encoder_length) {
    return false;
  }
  return true;
}

bool
tensegrity_interfaces__msg__Motor__copy(
  const tensegrity_interfaces__msg__Motor * input,
  tensegrity_interfaces__msg__Motor * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // position
  output->position = input->position;
  // target
  output->target = input->target;
  // speed
  output->speed = input->speed;
  // done
  output->done = input->done;
  // error
  output->error = input->error;
  // d_error
  output->d_error = input->d_error;
  // cum_error
  output->cum_error = input->cum_error;
  // encoder_counts
  output->encoder_counts = input->encoder_counts;
  // encoder_length
  output->encoder_length = input->encoder_length;
  return true;
}

tensegrity_interfaces__msg__Motor *
tensegrity_interfaces__msg__Motor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Motor * msg = (tensegrity_interfaces__msg__Motor *)allocator.allocate(sizeof(tensegrity_interfaces__msg__Motor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensegrity_interfaces__msg__Motor));
  bool success = tensegrity_interfaces__msg__Motor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensegrity_interfaces__msg__Motor__destroy(tensegrity_interfaces__msg__Motor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensegrity_interfaces__msg__Motor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensegrity_interfaces__msg__Motor__Sequence__init(tensegrity_interfaces__msg__Motor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Motor * data = NULL;

  if (size) {
    data = (tensegrity_interfaces__msg__Motor *)allocator.zero_allocate(size, sizeof(tensegrity_interfaces__msg__Motor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensegrity_interfaces__msg__Motor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensegrity_interfaces__msg__Motor__fini(&data[i - 1]);
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
tensegrity_interfaces__msg__Motor__Sequence__fini(tensegrity_interfaces__msg__Motor__Sequence * array)
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
      tensegrity_interfaces__msg__Motor__fini(&array->data[i]);
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

tensegrity_interfaces__msg__Motor__Sequence *
tensegrity_interfaces__msg__Motor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Motor__Sequence * array = (tensegrity_interfaces__msg__Motor__Sequence *)allocator.allocate(sizeof(tensegrity_interfaces__msg__Motor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensegrity_interfaces__msg__Motor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensegrity_interfaces__msg__Motor__Sequence__destroy(tensegrity_interfaces__msg__Motor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensegrity_interfaces__msg__Motor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensegrity_interfaces__msg__Motor__Sequence__are_equal(const tensegrity_interfaces__msg__Motor__Sequence * lhs, const tensegrity_interfaces__msg__Motor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensegrity_interfaces__msg__Motor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensegrity_interfaces__msg__Motor__Sequence__copy(
  const tensegrity_interfaces__msg__Motor__Sequence * input,
  tensegrity_interfaces__msg__Motor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensegrity_interfaces__msg__Motor);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensegrity_interfaces__msg__Motor * data =
      (tensegrity_interfaces__msg__Motor *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensegrity_interfaces__msg__Motor__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensegrity_interfaces__msg__Motor__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensegrity_interfaces__msg__Motor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
