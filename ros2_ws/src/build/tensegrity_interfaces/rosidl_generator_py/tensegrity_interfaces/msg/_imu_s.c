// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tensegrity_interfaces:msg/Imu.idl
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
#include "tensegrity_interfaces/msg/detail/imu__struct.h"
#include "tensegrity_interfaces/msg/detail/imu__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tensegrity_interfaces__msg__imu__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
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
    assert(strncmp("tensegrity_interfaces.msg._imu.Imu", full_classname_dest, 34) == 0);
  }
  tensegrity_interfaces__msg__Imu * ros_message = _ros_message;
  {  // id
    PyObject * field = PyObject_GetAttrString(_pymsg, "id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->id = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z
    PyObject * field = PyObject_GetAttrString(_pymsg, "z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ax
    PyObject * field = PyObject_GetAttrString(_pymsg, "ax");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ax = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // ay
    PyObject * field = PyObject_GetAttrString(_pymsg, "ay");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ay = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // az
    PyObject * field = PyObject_GetAttrString(_pymsg, "az");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->az = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gx
    PyObject * field = PyObject_GetAttrString(_pymsg, "gx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gx = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gy
    PyObject * field = PyObject_GetAttrString(_pymsg, "gy");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gy = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gz
    PyObject * field = PyObject_GetAttrString(_pymsg, "gz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gz = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mx
    PyObject * field = PyObject_GetAttrString(_pymsg, "mx");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mx = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // my
    PyObject * field = PyObject_GetAttrString(_pymsg, "my");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->my = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // mz
    PyObject * field = PyObject_GetAttrString(_pymsg, "mz");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mz = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tensegrity_interfaces__msg__imu__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Imu */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tensegrity_interfaces.msg._imu");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Imu");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tensegrity_interfaces__msg__Imu * ros_message = (tensegrity_interfaces__msg__Imu *)raw_ros_message;
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
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ax
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ax);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ax", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ay
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ay);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ay", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // az
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->az);
    {
      int rc = PyObject_SetAttrString(_pymessage, "az", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gy
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gy);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mx
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mx);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mx", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // my
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->my);
    {
      int rc = PyObject_SetAttrString(_pymessage, "my", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mz
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
