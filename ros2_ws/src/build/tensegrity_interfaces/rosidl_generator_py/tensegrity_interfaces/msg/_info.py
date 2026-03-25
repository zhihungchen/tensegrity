# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensegrity_interfaces:msg/Info.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Info(type):
    """Metaclass of message 'Info'."""

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
                'tensegrity_interfaces.msg.Info')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__info

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Info(metaclass=Metaclass_Info):
    """Message class 'Info'."""

    __slots__ = [
        '_min_length',
        '_range',
        '_max_range',
        '_min_range',
        '_range024',
        '_range135',
        '_max_speed',
        '_tol',
        '_low_tol',
        '_p',
        '_i',
        '_d',
        '_dist_weight',
        '_ang_weight',
        '_prog_weight',
    ]

    _fields_and_field_types = {
        'min_length': 'uint8',
        'range': 'uint8',
        'max_range': 'uint8',
        'min_range': 'uint8',
        'range024': 'uint8',
        'range135': 'uint8',
        'max_speed': 'int8',
        'tol': 'double',
        'low_tol': 'double',
        'p': 'double',
        'i': 'double',
        'd': 'double',
        'dist_weight': 'double',
        'ang_weight': 'double',
        'prog_weight': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.min_length = kwargs.get('min_length', int())
        self.range = kwargs.get('range', int())
        self.max_range = kwargs.get('max_range', int())
        self.min_range = kwargs.get('min_range', int())
        self.range024 = kwargs.get('range024', int())
        self.range135 = kwargs.get('range135', int())
        self.max_speed = kwargs.get('max_speed', int())
        self.tol = kwargs.get('tol', float())
        self.low_tol = kwargs.get('low_tol', float())
        self.p = kwargs.get('p', float())
        self.i = kwargs.get('i', float())
        self.d = kwargs.get('d', float())
        self.dist_weight = kwargs.get('dist_weight', float())
        self.ang_weight = kwargs.get('ang_weight', float())
        self.prog_weight = kwargs.get('prog_weight', float())

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
        if self.min_length != other.min_length:
            return False
        if self.range != other.range:
            return False
        if self.max_range != other.max_range:
            return False
        if self.min_range != other.min_range:
            return False
        if self.range024 != other.range024:
            return False
        if self.range135 != other.range135:
            return False
        if self.max_speed != other.max_speed:
            return False
        if self.tol != other.tol:
            return False
        if self.low_tol != other.low_tol:
            return False
        if self.p != other.p:
            return False
        if self.i != other.i:
            return False
        if self.d != other.d:
            return False
        if self.dist_weight != other.dist_weight:
            return False
        if self.ang_weight != other.ang_weight:
            return False
        if self.prog_weight != other.prog_weight:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def min_length(self):
        """Message field 'min_length'."""
        return self._min_length

    @min_length.setter
    def min_length(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min_length' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'min_length' field must be an unsigned integer in [0, 255]"
        self._min_length = value

    @builtins.property  # noqa: A003
    def range(self):  # noqa: A003
        """Message field 'range'."""
        return self._range

    @range.setter  # noqa: A003
    def range(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'range' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'range' field must be an unsigned integer in [0, 255]"
        self._range = value

    @builtins.property
    def max_range(self):
        """Message field 'max_range'."""
        return self._max_range

    @max_range.setter
    def max_range(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_range' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'max_range' field must be an unsigned integer in [0, 255]"
        self._max_range = value

    @builtins.property
    def min_range(self):
        """Message field 'min_range'."""
        return self._min_range

    @min_range.setter
    def min_range(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min_range' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'min_range' field must be an unsigned integer in [0, 255]"
        self._min_range = value

    @builtins.property
    def range024(self):
        """Message field 'range024'."""
        return self._range024

    @range024.setter
    def range024(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'range024' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'range024' field must be an unsigned integer in [0, 255]"
        self._range024 = value

    @builtins.property
    def range135(self):
        """Message field 'range135'."""
        return self._range135

    @range135.setter
    def range135(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'range135' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'range135' field must be an unsigned integer in [0, 255]"
        self._range135 = value

    @builtins.property
    def max_speed(self):
        """Message field 'max_speed'."""
        return self._max_speed

    @max_speed.setter
    def max_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_speed' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'max_speed' field must be an integer in [-128, 127]"
        self._max_speed = value

    @builtins.property
    def tol(self):
        """Message field 'tol'."""
        return self._tol

    @tol.setter
    def tol(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tol' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tol' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tol = value

    @builtins.property
    def low_tol(self):
        """Message field 'low_tol'."""
        return self._low_tol

    @low_tol.setter
    def low_tol(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'low_tol' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'low_tol' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._low_tol = value

    @builtins.property
    def p(self):
        """Message field 'p'."""
        return self._p

    @p.setter
    def p(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p = value

    @builtins.property
    def i(self):
        """Message field 'i'."""
        return self._i

    @i.setter
    def i(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'i' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'i' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._i = value

    @builtins.property
    def d(self):
        """Message field 'd'."""
        return self._d

    @d.setter
    def d(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'd' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'd' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._d = value

    @builtins.property
    def dist_weight(self):
        """Message field 'dist_weight'."""
        return self._dist_weight

    @dist_weight.setter
    def dist_weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dist_weight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dist_weight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dist_weight = value

    @builtins.property
    def ang_weight(self):
        """Message field 'ang_weight'."""
        return self._ang_weight

    @ang_weight.setter
    def ang_weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ang_weight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'ang_weight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._ang_weight = value

    @builtins.property
    def prog_weight(self):
        """Message field 'prog_weight'."""
        return self._prog_weight

    @prog_weight.setter
    def prog_weight(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'prog_weight' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'prog_weight' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._prog_weight = value
