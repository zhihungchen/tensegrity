// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tensegrity_interfaces:msg/Info.idl
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
#include "tensegrity_interfaces/msg/detail/info__struct.h"
#include "tensegrity_interfaces/msg/detail/info__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tensegrity_interfaces__msg__info__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("tensegrity_interfaces.msg._info.Info", full_classname_dest, 36) == 0);
  }
  tensegrity_interfaces__msg__Info * ros_message = _ros_message;
  {  // min_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->min_length = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // range
    PyObject * field = PyObject_GetAttrString(_pymsg, "range");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->range = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // max_range
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_range");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_range = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // min_range
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_range");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->min_range = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // range024
    PyObject * field = PyObject_GetAttrString(_pymsg, "range024");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->range024 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // range135
    PyObject * field = PyObject_GetAttrString(_pymsg, "range135");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->range135 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // max_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_speed = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // tol
    PyObject * field = PyObject_GetAttrString(_pymsg, "tol");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tol = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // low_tol
    PyObject * field = PyObject_GetAttrString(_pymsg, "low_tol");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->low_tol = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p
    PyObject * field = PyObject_GetAttrString(_pymsg, "p");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // i
    PyObject * field = PyObject_GetAttrString(_pymsg, "i");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->i = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // d
    PyObject * field = PyObject_GetAttrString(_pymsg, "d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->d = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dist_weight
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist_weight");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dist_weight = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ang_weight
    PyObject * field = PyObject_GetAttrString(_pymsg, "ang_weight");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ang_weight = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // prog_weight
    PyObject * field = PyObject_GetAttrString(_pymsg, "prog_weight");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->prog_weight = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tensegrity_interfaces__msg__info__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Info */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tensegrity_interfaces.msg._info");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Info");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tensegrity_interfaces__msg__Info * ros_message = (tensegrity_interfaces__msg__Info *)raw_ros_message;
  {  // min_length
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->min_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_range
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->max_range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_range
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->min_range);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range024
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->range024);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range024", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // range135
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->range135);
    {
      int rc = PyObject_SetAttrString(_pymessage, "range135", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_speed
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->max_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tol
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tol);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tol", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // low_tol
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->low_tol);
    {
      int rc = PyObject_SetAttrString(_pymessage, "low_tol", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // i
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->i);
    {
      int rc = PyObject_SetAttrString(_pymessage, "i", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dist_weight
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dist_weight);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist_weight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ang_weight
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ang_weight);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ang_weight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // prog_weight
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->prog_weight);
    {
      int rc = PyObject_SetAttrString(_pymessage, "prog_weight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
