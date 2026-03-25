// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tensegrity_interfaces:msg/Imu.idl
// generated code does not contain a copyright notice
#include "tensegrity_interfaces/msg/detail/imu__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tensegrity_interfaces__msg__Imu__init(tensegrity_interfaces__msg__Imu * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // x
  // y
  // z
  // ax
  // ay
  // az
  // gx
  // gy
  // gz
  // mx
  // my
  // mz
  return true;
}

void
tensegrity_interfaces__msg__Imu__fini(tensegrity_interfaces__msg__Imu * msg)
{
  if (!msg) {
    return;
  }
  // id
  // x
  // y
  // z
  // ax
  // ay
  // az
  // gx
  // gy
  // gz
  // mx
  // my
  // mz
}

bool
tensegrity_interfaces__msg__Imu__are_equal(const tensegrity_interfaces__msg__Imu * lhs, const tensegrity_interfaces__msg__Imu * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // ax
  if (lhs->ax != rhs->ax) {
    return false;
  }
  // ay
  if (lhs->ay != rhs->ay) {
    return false;
  }
  // az
  if (lhs->az != rhs->az) {
    return false;
  }
  // gx
  if (lhs->gx != rhs->gx) {
    return false;
  }
  // gy
  if (lhs->gy != rhs->gy) {
    return false;
  }
  // gz
  if (lhs->gz != rhs->gz) {
    return false;
  }
  // mx
  if (lhs->mx != rhs->mx) {
    return false;
  }
  // my
  if (lhs->my != rhs->my) {
    return false;
  }
  // mz
  if (lhs->mz != rhs->mz) {
    return false;
  }
  return true;
}

bool
tensegrity_interfaces__msg__Imu__copy(
  const tensegrity_interfaces__msg__Imu * input,
  tensegrity_interfaces__msg__Imu * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // ax
  output->ax = input->ax;
  // ay
  output->ay = input->ay;
  // az
  output->az = input->az;
  // gx
  output->gx = input->gx;
  // gy
  output->gy = input->gy;
  // gz
  output->gz = input->gz;
  // mx
  output->mx = input->mx;
  // my
  output->my = input->my;
  // mz
  output->mz = input->mz;
  return true;
}

tensegrity_interfaces__msg__Imu *
tensegrity_interfaces__msg__Imu__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Imu * msg = (tensegrity_interfaces__msg__Imu *)allocator.allocate(sizeof(tensegrity_interfaces__msg__Imu), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tensegrity_interfaces__msg__Imu));
  bool success = tensegrity_interfaces__msg__Imu__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tensegrity_interfaces__msg__Imu__destroy(tensegrity_interfaces__msg__Imu * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tensegrity_interfaces__msg__Imu__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tensegrity_interfaces__msg__Imu__Sequence__init(tensegrity_interfaces__msg__Imu__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Imu * data = NULL;

  if (size) {
    data = (tensegrity_interfaces__msg__Imu *)allocator.zero_allocate(size, sizeof(tensegrity_interfaces__msg__Imu), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tensegrity_interfaces__msg__Imu__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tensegrity_interfaces__msg__Imu__fini(&data[i - 1]);
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
tensegrity_interfaces__msg__Imu__Sequence__fini(tensegrity_interfaces__msg__Imu__Sequence * array)
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
      tensegrity_interfaces__msg__Imu__fini(&array->data[i]);
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

tensegrity_interfaces__msg__Imu__Sequence *
tensegrity_interfaces__msg__Imu__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tensegrity_interfaces__msg__Imu__Sequence * array = (tensegrity_interfaces__msg__Imu__Sequence *)allocator.allocate(sizeof(tensegrity_interfaces__msg__Imu__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tensegrity_interfaces__msg__Imu__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tensegrity_interfaces__msg__Imu__Sequence__destroy(tensegrity_interfaces__msg__Imu__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tensegrity_interfaces__msg__Imu__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tensegrity_interfaces__msg__Imu__Sequence__are_equal(const tensegrity_interfaces__msg__Imu__Sequence * lhs, const tensegrity_interfaces__msg__Imu__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tensegrity_interfaces__msg__Imu__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tensegrity_interfaces__msg__Imu__Sequence__copy(
  const tensegrity_interfaces__msg__Imu__Sequence * input,
  tensegrity_interfaces__msg__Imu__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tensegrity_interfaces__msg__Imu);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tensegrity_interfaces__msg__Imu * data =
      (tensegrity_interfaces__msg__Imu *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tensegrity_interfaces__msg__Imu__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tensegrity_interfaces__msg__Imu__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tensegrity_interfaces__msg__Imu__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
