// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tensegrity_interfaces:msg/Motor.idl
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
#include "tensegrity_interfaces/msg/detail/motor__struct.h"
#include "tensegrity_interfaces/msg/detail/motor__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tensegrity_interfaces__msg__motor__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
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
    assert(strncmp("tensegrity_interfaces.msg._motor.Motor", full_classname_dest, 38) == 0);
  }
  tensegrity_interfaces__msg__Motor * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // position
    PyObject * field = PyObject_GetAttrString(_pymsg, "position");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->position = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target
    PyObject * field = PyObject_GetAttrString(_pymsg, "target");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // done
    PyObject * field = PyObject_GetAttrString(_pymsg, "done");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->done = (Py_True == field);
    Py_DECREF(field);
  }
  {  // error
    PyObject * field = PyObject_GetAttrString(_pymsg, "error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->error = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // d_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "d_error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->d_error = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cum_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "cum_error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cum_error = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // encoder_counts
    PyObject * field = PyObject_GetAttrString(_pymsg, "encoder_counts");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->encoder_counts = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // encoder_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "encoder_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->encoder_length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tensegrity_interfaces__msg__motor__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Motor */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tensegrity_interfaces.msg._motor");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Motor");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tensegrity_interfaces__msg__Motor * ros_message = (tensegrity_interfaces__msg__Motor *)raw_ros_message;
  {  // id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // done
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->done ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "done", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // d_error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->d_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "d_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cum_error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cum_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cum_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // encoder_counts
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->encoder_counts);
    {
      int rc = PyObject_SetAttrString(_pymessage, "encoder_counts", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // encoder_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->encoder_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "encoder_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
