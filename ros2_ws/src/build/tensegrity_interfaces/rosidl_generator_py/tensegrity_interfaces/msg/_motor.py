# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensegrity_interfaces:msg/Motor.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Motor(type):
    """Metaclass of message 'Motor'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tensegrity_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tensegrity_interfaces.msg.Motor')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__motor
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__motor
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__motor
            cls._TYPE_SUPPORT = module.type_support_msg__msg__motor
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__motor

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Motor(metaclass=Metaclass_Motor):
    """Message class 'Motor'."""

    __slots__ = [
        '_id',
        '_position',
        '_target',
        '_speed',
        '_done',
        '_error',
        '_d_error',
        '_cum_error',
        '_encoder_counts',
        '_encoder_length',
    ]

    _fields_and_field_types = {
        'id': 'int8',
        'position': 'double',
        'target': 'double',
        'speed': 'double',
        'done': 'boolean',
        'error': 'double',
        'd_error': 'double',
        'cum_error': 'double',
        'encoder_counts': 'int64',
        'encoder_length': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.id = kwargs.get('id', int())
        self.position = kwargs.get('position', float())
        self.target = kwargs.get('target', float())
        self.speed = kwargs.get('speed', float())
        self.done = kwargs.get('done', bool())
        self.error = kwargs.get('error', float())
        self.d_error = kwargs.get('d_error', float())
        self.cum_error = kwargs.get('cum_error', float())
        self.encoder_counts = kwargs.get('encoder_counts', int())
        self.encoder_length = kwargs.get('encoder_length', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.id != other.id:
            return False
        if self.position != other.position:
            return False
        if self.target != other.target:
            return False
        if self.speed != other.speed:
            return False
        if self.done != other.done:
            return False
        if self.error != other.error:
            return False
        if self.d_error != other.d_error:
            return False
        if self.cum_error != other.cum_error:
            return False
        if self.encoder_counts != other.encoder_counts:
            return False
        if self.encoder_length != other.encoder_length:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'id' field must be an integer in [-128, 127]"
        self._id = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'position' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'position' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._position = value

    @builtins.property
    def target(self):
        """Message field 'target'."""
        return self._target

    @target.setter
    def target(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'target' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._target = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed = value

    @builtins.property
    def done(self):
        """Message field 'done'."""
        return self._done

    @done.setter
    def done(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'done' field must be of type 'bool'"
        self._done = value

    @builtins.property
    def error(self):
        """Message field 'error'."""
        return self._error

    @error.setter
    def error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'error' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'error' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._error = value

    @builtins.property
    def d_error(self):
        """Message field 'd_error'."""
        return self._d_error

    @d_error.setter
    def d_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'd_error' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'd_error' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._d_error = value

    @builtins.property
    def cum_error(self):
        """Message field 'cum_error'."""
        return self._cum_error

    @cum_error.setter
    def cum_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cum_error' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'cum_error' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._cum_error = value

    @builtins.property
    def encoder_counts(self):
        """Message field 'encoder_counts'."""
        return self._encoder_counts

    @encoder_counts.setter
    def encoder_counts(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'encoder_counts' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'encoder_counts' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._encoder_counts = value

    @builtins.property
    def encoder_length(self):
        """Message field 'encoder_length'."""
        return self._encoder_length

    @encoder_length.setter
    def encoder_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'encoder_length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'encoder_length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._encoder_length = value
