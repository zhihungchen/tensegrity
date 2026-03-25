# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensegrity_interfaces:msg/State.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_State(type):
    """Metaclass of message 'State'."""

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
                'tensegrity_interfaces.msg.State')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__state

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class State(metaclass=Metaclass_State):
    """Message class 'State'."""

    __slots__ = [
        '_trajectory',
        '_prev_action',
        '_reverse_the_gait',
        '_bar_height_changed',
    ]

    _fields_and_field_types = {
        'trajectory': 'sequence<geometry_msgs/Point>',
        'prev_action': 'string',
        'reverse_the_gait': 'boolean',
        'bar_height_changed': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.trajectory = kwargs.get('trajectory', [])
        self.prev_action = kwargs.get('prev_action', str())
        self.reverse_the_gait = kwargs.get('reverse_the_gait', bool())
        self.bar_height_changed = kwargs.get('bar_height_changed', bool())

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
        if self.trajectory != other.trajectory:
            return False
        if self.prev_action != other.prev_action:
            return False
        if self.reverse_the_gait != other.reverse_the_gait:
            return False
        if self.bar_height_changed != other.bar_height_changed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def trajectory(self):
        """Message field 'trajectory'."""
        return self._trajectory

    @trajectory.setter
    def trajectory(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'trajectory' field must be a set or sequence and each value of type 'Point'"
        self._trajectory = value

    @builtins.property
    def prev_action(self):
        """Message field 'prev_action'."""
        return self._prev_action

    @prev_action.setter
    def prev_action(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'prev_action' field must be of type 'str'"
        self._prev_action = value

    @builtins.property
    def reverse_the_gait(self):
        """Message field 'reverse_the_gait'."""
        return self._reverse_the_gait

    @reverse_the_gait.setter
    def reverse_the_gait(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reverse_the_gait' field must be of type 'bool'"
        self._reverse_the_gait = value

    @builtins.property
    def bar_height_changed(self):
        """Message field 'bar_height_changed'."""
        return self._bar_height_changed

    @bar_height_changed.setter
    def bar_height_changed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'bar_height_changed' field must be of type 'bool'"
        self._bar_height_changed = value
