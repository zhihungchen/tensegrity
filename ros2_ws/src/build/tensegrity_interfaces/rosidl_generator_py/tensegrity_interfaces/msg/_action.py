# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensegrity_interfaces:msg/Action.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Action(type):
    """Metaclass of message 'Action'."""

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
                'tensegrity_interfaces.msg.Action')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__action
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__action
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__action
            cls._TYPE_SUPPORT = module.type_support_msg__msg__action
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__action

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


class Action(metaclass=Metaclass_Action):
    """Message class 'Action'."""

    __slots__ = [
        '_actions',
        '_cost',
        '_coms',
        '_pas',
        '_endcaps',
        '_dist_weight',
        '_ang_weight',
        '_prog_weight',
    ]

    _fields_and_field_types = {
        'actions': 'sequence<string>',
        'cost': 'double',
        'coms': 'sequence<geometry_msgs/Point>',
        'pas': 'sequence<geometry_msgs/Point>',
        'endcaps': 'sequence<geometry_msgs/Point>',
        'dist_weight': 'double',
        'ang_weight': 'double',
        'prog_weight': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.actions = kwargs.get('actions', [])
        self.cost = kwargs.get('cost', float())
        self.coms = kwargs.get('coms', [])
        self.pas = kwargs.get('pas', [])
        self.endcaps = kwargs.get('endcaps', [])
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
        if self.actions != other.actions:
            return False
        if self.cost != other.cost:
            return False
        if self.coms != other.coms:
            return False
        if self.pas != other.pas:
            return False
        if self.endcaps != other.endcaps:
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
    def actions(self):
        """Message field 'actions'."""
        return self._actions

    @actions.setter
    def actions(self, value):
        if __debug__:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'actions' field must be a set or sequence and each value of type 'str'"
        self._actions = value

    @builtins.property
    def cost(self):
        """Message field 'cost'."""
        return self._cost

    @cost.setter
    def cost(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cost' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'cost' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._cost = value

    @builtins.property
    def coms(self):
        """Message field 'coms'."""
        return self._coms

    @coms.setter
    def coms(self, value):
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
                "The 'coms' field must be a set or sequence and each value of type 'Point'"
        self._coms = value

    @builtins.property
    def pas(self):
        """Message field 'pas'."""
        return self._pas

    @pas.setter
    def pas(self, value):
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
                "The 'pas' field must be a set or sequence and each value of type 'Point'"
        self._pas = value

    @builtins.property
    def endcaps(self):
        """Message field 'endcaps'."""
        return self._endcaps

    @endcaps.setter
    def endcaps(self, value):
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
                "The 'endcaps' field must be a set or sequence and each value of type 'Point'"
        self._endcaps = value

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
