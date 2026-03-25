# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensegrity_interfaces:msg/TensegrityStamped.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TensegrityStamped(type):
    """Metaclass of message 'TensegrityStamped'."""

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
                'tensegrity_interfaces.msg.TensegrityStamped')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__tensegrity_stamped
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__tensegrity_stamped
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__tensegrity_stamped
            cls._TYPE_SUPPORT = module.type_support_msg__msg__tensegrity_stamped
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__tensegrity_stamped

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from tensegrity_interfaces.msg import Imu
            if Imu.__class__._TYPE_SUPPORT is None:
                Imu.__class__.__import_type_support__()

            from tensegrity_interfaces.msg import Info
            if Info.__class__._TYPE_SUPPORT is None:
                Info.__class__.__import_type_support__()

            from tensegrity_interfaces.msg import Motor
            if Motor.__class__._TYPE_SUPPORT is None:
                Motor.__class__.__import_type_support__()

            from tensegrity_interfaces.msg import Node
            if Node.__class__._TYPE_SUPPORT is None:
                Node.__class__.__import_type_support__()

            from tensegrity_interfaces.msg import Sensor
            if Sensor.__class__._TYPE_SUPPORT is None:
                Sensor.__class__.__import_type_support__()

            from tensegrity_interfaces.msg import Trajectory
            if Trajectory.__class__._TYPE_SUPPORT is None:
                Trajectory.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TensegrityStamped(metaclass=Metaclass_TensegrityStamped):
    """Message class 'TensegrityStamped'."""

    __slots__ = [
        '_header',
        '_info',
        '_motors',
        '_sensors',
        '_imus',
        '_nodes',
        '_trajectory',
        '_actions',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'info': 'tensegrity_interfaces/Info',
        'motors': 'sequence<tensegrity_interfaces/Motor>',
        'sensors': 'sequence<tensegrity_interfaces/Sensor>',
        'imus': 'sequence<tensegrity_interfaces/Imu>',
        'nodes': 'sequence<tensegrity_interfaces/Node>',
        'trajectory': 'tensegrity_interfaces/Trajectory',
        'actions': 'sequence<string>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Info'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Motor')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Sensor')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Imu')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Node')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Trajectory'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from tensegrity_interfaces.msg import Info
        self.info = kwargs.get('info', Info())
        self.motors = kwargs.get('motors', [])
        self.sensors = kwargs.get('sensors', [])
        self.imus = kwargs.get('imus', [])
        self.nodes = kwargs.get('nodes', [])
        from tensegrity_interfaces.msg import Trajectory
        self.trajectory = kwargs.get('trajectory', Trajectory())
        self.actions = kwargs.get('actions', [])

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
        if self.header != other.header:
            return False
        if self.info != other.info:
            return False
        if self.motors != other.motors:
            return False
        if self.sensors != other.sensors:
            return False
        if self.imus != other.imus:
            return False
        if self.nodes != other.nodes:
            return False
        if self.trajectory != other.trajectory:
            return False
        if self.actions != other.actions:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if __debug__:
            from tensegrity_interfaces.msg import Info
            assert \
                isinstance(value, Info), \
                "The 'info' field must be a sub message of type 'Info'"
        self._info = value

    @builtins.property
    def motors(self):
        """Message field 'motors'."""
        return self._motors

    @motors.setter
    def motors(self, value):
        if __debug__:
            from tensegrity_interfaces.msg import Motor
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
                 all(isinstance(v, Motor) for v in value) and
                 True), \
                "The 'motors' field must be a set or sequence and each value of type 'Motor'"
        self._motors = value

    @builtins.property
    def sensors(self):
        """Message field 'sensors'."""
        return self._sensors

    @sensors.setter
    def sensors(self, value):
        if __debug__:
            from tensegrity_interfaces.msg import Sensor
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
                 all(isinstance(v, Sensor) for v in value) and
                 True), \
                "The 'sensors' field must be a set or sequence and each value of type 'Sensor'"
        self._sensors = value

    @builtins.property
    def imus(self):
        """Message field 'imus'."""
        return self._imus

    @imus.setter
    def imus(self, value):
        if __debug__:
            from tensegrity_interfaces.msg import Imu
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
                 all(isinstance(v, Imu) for v in value) and
                 True), \
                "The 'imus' field must be a set or sequence and each value of type 'Imu'"
        self._imus = value

    @builtins.property
    def nodes(self):
        """Message field 'nodes'."""
        return self._nodes

    @nodes.setter
    def nodes(self, value):
        if __debug__:
            from tensegrity_interfaces.msg import Node
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
                 all(isinstance(v, Node) for v in value) and
                 True), \
                "The 'nodes' field must be a set or sequence and each value of type 'Node'"
        self._nodes = value

    @builtins.property
    def trajectory(self):
        """Message field 'trajectory'."""
        return self._trajectory

    @trajectory.setter
    def trajectory(self, value):
        if __debug__:
            from tensegrity_interfaces.msg import Trajectory
            assert \
                isinstance(value, Trajectory), \
                "The 'trajectory' field must be a sub message of type 'Trajectory'"
        self._trajectory = value

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
