// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensegrity_interfaces:msg/ImuStamped.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/imu_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `imus`
#include "tensegrity_interfaces/msg/detail/imu__functions.h"

bool
tensegrity_interfaces__msg__ImuStamped__init(tensegrity_interfaces__msg__ImuStamped * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tensegrity_interfaces__msg__ImuStamped__fini(msg);
    return false;
  }
  // imus
  if (!tensegrity_interfaces__msg__Imu__Sequence__init(&msg->imus, 0)) {
    tensegrity_interfaces__msg__ImuStamped__fini(msg);
    return false;
  }
  return true;
}

void
tensegrity_interfaces__msg__ImuStamped__fini(tensegrity_interfaces__msg__ImuStamped * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // imus
  tensegrity_interfaces__msg__Imu__Sequence__fini(&msg->imus);
}

bool
tensegrity_interfaces__msg__ImuStamped__are_equal(const tensegrity_interfaces__msg__ImuStamped * lhs, const tensegrity_interfaces__msg__ImuStamped * rhs)
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
  // imus
  if (!tensegrity_interfaces__msg__Imu__Sequence__are_equal(
      &(lhs->imus), &(rhs->imus)))
  {
    return false;
  }
  return true;
}

bool
tensegrity_interfaces__msg__ImuStamped__copy(
  const tensegrity_interfaces__msg__ImuStamped * input,
  tensegrity_interfaces__msg__ImuStamped * output)
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
  // imus
  if (!tensegrity_interfaces__msg__Imu__Sequence__copy(
      &(input->imus), &(output->imus)))
  {
    return false;
  }
  return true;
}

tensegrity_interfaces__msg__ImuStamped *
tensegrity_interfaces__msg__ImuStamped__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__ImuStamped * msg = (tensegrity_interfaces__msg__ImuStamped *)allocator.allocate(sizeof(tensegrity_interfaces__msg__ImuStamped), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensegrity_interfaces__msg__ImuStamped));
  bool success = tensegrity_interfaces__msg__ImuStamped__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensegrity_interfaces__msg__ImuStamped__destroy(tensegrity_interfaces__msg__ImuStamped * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensegrity_interfaces__msg__ImuStamped__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensegrity_interfaces__msg__ImuStamped__Sequence__init(tensegrity_interfaces__msg__ImuStamped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__ImuStamped * data = NULL;

  if (size) {
    data = (tensegrity_interfaces__msg__ImuStamped *)allocator.zero_allocate(size, sizeof(tensegrity_interfaces__msg__ImuStamped), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensegrity_interfaces__msg__ImuStamped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensegrity_interfaces__msg__ImuStamped__fini(&data[i - 1]);
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
tensegrity_interfaces__msg__ImuStamped__Sequence__fini(tensegrity_interfaces__msg__ImuStamped__Sequence * array)
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
      tensegrity_interfaces__msg__ImuStamped__fini(&array->data[i]);
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

tensegrity_interfaces__msg__ImuStamped__Sequence *
tensegrity_interfaces__msg__ImuStamped__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__ImuStamped__Sequence * array = (tensegrity_interfaces__msg__ImuStamped__Sequence *)allocator.allocate(sizeof(tensegrity_interfaces__msg__ImuStamped__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensegrity_interfaces__msg__ImuStamped__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensegrity_interfaces__msg__ImuStamped__Sequence__destroy(tensegrity_interfaces__msg__ImuStamped__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensegrity_interfaces__msg__ImuStamped__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensegrity_interfaces__msg__ImuStamped__Sequence__are_equal(const tensegrity_interfaces__msg__ImuStamped__Sequence * lhs, const tensegrity_interfaces__msg__ImuStamped__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensegrity_interfaces__msg__ImuStamped__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensegrity_interfaces__msg__ImuStamped__Sequence__copy(
  const tensegrity_interfaces__msg__ImuStamped__Sequence * input,
  tensegrity_interfaces__msg__ImuStamped__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensegrity_interfaces__msg__ImuStamped);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensegrity_interfaces__msg__ImuStamped * data =
      (tensegrity_interfaces__msg__ImuStamped *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensegrity_interfaces__msg__ImuStamped__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensegrity_interfaces__msg__ImuStamped__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensegrity_interfaces__msg__ImuStamped__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
