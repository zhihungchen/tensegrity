// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tensegrity_interfaces:msg/TensegrityStamped.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__struct.h"
#include "tensegrity_interfaces/msg/detail/tensegrity_stamped__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

// Nested array functions includes
#include "tensegrity_interfaces/msg/detail/imu__functions.h"
#include "tensegrity_interfaces/msg/detail/motor__functions.h"
#include "tensegrity_interfaces/msg/detail/node__functions.h"
#include "tensegrity_interfaces/msg/detail/sensor__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool tensegrity_interfaces__msg__info__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tensegrity_interfaces__msg__info__convert_to_py(void * raw_ros_message);
bool tensegrity_interfaces__msg__motor__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tensegrity_interfaces__msg__motor__convert_to_py(void * raw_ros_message);
bool tensegrity_interfaces__msg__sensor__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tensegrity_interfaces__msg__sensor__convert_to_py(void * raw_ros_message);
bool tensegrity_interfaces__msg__imu__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tensegrity_interfaces__msg__imu__convert_to_py(void * raw_ros_message);
bool tensegrity_interfaces__msg__node__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tensegrity_interfaces__msg__node__convert_to_py(void * raw_ros_message);
bool tensegrity_interfaces__msg__trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tensegrity_interfaces__msg__trajectory__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tensegrity_interfaces__msg__tensegrity_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("tensegrity_interfaces.msg._tensegrity_stamped.TensegrityStamped", full_classname_dest, 63) == 0);
  }
  tensegrity_interfaces__msg__TensegrityStamped * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // info
    PyObject * field = PyObject_GetAttrString(_pymsg, "info");
    if (!field) {
      return false;
    }
    if (!tensegrity_interfaces__msg__info__convert_from_py(field, &ros_message->info)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // motors
    PyObject * field = PyObject_GetAttrString(_pymsg, "motors");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'motors'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!tensegrity_interfaces__msg__Motor__Sequence__init(&(ros_message->motors), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create tensegrity_interfaces__msg__Motor__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    tensegrity_interfaces__msg__Motor * dest = ros_message->motors.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!tensegrity_interfaces__msg__motor__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // sensors
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensors");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'sensors'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!tensegrity_interfaces__msg__Sensor__Sequence__init(&(ros_message->sensors), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create tensegrity_interfaces__msg__Sensor__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    tensegrity_interfaces__msg__Sensor * dest = ros_message->sensors.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!tensegrity_interfaces__msg__sensor__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // imus
    PyObject * field = PyObject_GetAttrString(_pymsg, "imus");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'imus'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!tensegrity_interfaces__msg__Imu__Sequence__init(&(ros_message->imus), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create tensegrity_interfaces__msg__Imu__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    tensegrity_interfaces__msg__Imu * dest = ros_message->imus.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!tensegrity_interfaces__msg__imu__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // nodes
    PyObject * field = PyObject_GetAttrString(_pymsg, "nodes");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'nodes'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!tensegrity_interfaces__msg__Node__Sequence__init(&(ros_message->nodes), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create tensegrity_interfaces__msg__Node__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    tensegrity_interfaces__msg__Node * dest = ros_message->nodes.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!tensegrity_interfaces__msg__node__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // trajectory
    PyObject * field = PyObject_GetAttrString(_pymsg, "trajectory");
    if (!field) {
      return false;
    }
    if (!tensegrity_interfaces__msg__trajectory__convert_from_py(field, &ros_message->trajectory)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // actions
    PyObject * field = PyObject_GetAttrString(_pymsg, "actions");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'actions'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__String__Sequence__init(&(ros_message->actions), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create String__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      rosidl_runtime_c__String * dest = ros_message->actions.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyUnicode_Check(item));
        PyObject * encoded_item = PyUnicode_AsUTF8String(item);
        if (!encoded_item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        rosidl_runtime_c__String__assign(&dest[i], PyBytes_AS_STRING(encoded_item));
        Py_DECREF(encoded_item);
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tensegrity_interfaces__msg__tensegrity_stamped__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TensegrityStamped */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tensegrity_interfaces.msg._tensegrity_stamped");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TensegrityStamped");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tensegrity_interfaces__msg__TensegrityStamped * ros_message = (tensegrity_interfaces__msg__TensegrityStamped *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // info
    PyObject * field = NULL;
    field = tensegrity_interfaces__msg__info__convert_to_py(&ros_message->info);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "info", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // motors
    PyObject * field = NULL;
    size_t size = ros_message->motors.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    tensegrity_interfaces__msg__Motor * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->motors.data[i]);
      PyObject * pyitem = tensegrity_interfaces__msg__motor__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "motors", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sensors
    PyObject * field = NULL;
    size_t size = ros_message->sensors.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    tensegrity_interfaces__msg__Sensor * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->sensors.data[i]);
      PyObject * pyitem = tensegrity_interfaces__msg__sensor__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensors", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // imus
    PyObject * field = NULL;
    size_t size = ros_message->imus.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    tensegrity_interfaces__msg__Imu * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->imus.data[i]);
      PyObject * pyitem = tensegrity_interfaces__msg__imu__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "imus", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nodes
    PyObject * field = NULL;
    size_t size = ros_message->nodes.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    tensegrity_interfaces__msg__Node * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->nodes.data[i]);
      PyObject * pyitem = tensegrity_interfaces__msg__node__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "nodes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trajectory
    PyObject * field = NULL;
    field = tensegrity_interfaces__msg__trajectory__convert_to_py(&ros_message->trajectory);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "trajectory", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // actions
    PyObject * field = NULL;
    size_t size = ros_message->actions.size;
    rosidl_runtime_c__String * src = ros_message->actions.data;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      PyObject * decoded_item = PyUnicode_DecodeUTF8(src[i].data, strlen(src[i].data), "replace");
      if (!decoded_item) {
        return NULL;
      }
      int rc = PyList_SetItem(field, i, decoded_item);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "actions", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
