# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tensegrity_interfaces:msg/NodesStamped.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NodesStamped(type):
    """Metaclass of message 'NodesStamped'."""

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
                'tensegrity_interfaces.msg.NodesStamped')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nodes_stamped
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nodes_stamped
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nodes_stamped
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nodes_stamped
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nodes_stamped

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from tensegrity_interfaces.msg import Imu
            if Imu.__class__._TYPE_SUPPORT is None:
                Imu.__class__.__import_type_support__()

            from tensegrity_interfaces.msg import Node
            if Node.__class__._TYPE_SUPPORT is None:
                Node.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NodesStamped(metaclass=Metaclass_NodesStamped):
    """Message class 'NodesStamped'."""

    __slots__ = [
        '_header',
        '_reconstructed_nodes',
        '_mocap_nodes',
        '_imus',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'reconstructed_nodes': 'sequence<tensegrity_interfaces/Node>',
        'mocap_nodes': 'sequence<tensegrity_interfaces/Node>',
        'imus': 'sequence<tensegrity_interfaces/Imu>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Node')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Node')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tensegrity_interfaces', 'msg'], 'Imu')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.reconstructed_nodes = kwargs.get('reconstructed_nodes', [])
        self.mocap_nodes = kwargs.get('mocap_nodes', [])
        self.imus = kwargs.get('imus', [])

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
        if self.reconstructed_nodes != other.reconstructed_nodes:
            return False
        if self.mocap_nodes != other.mocap_nodes:
            return False
        if self.imus != other.imus:
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
    def reconstructed_nodes(self):
        """Message field 'reconstructed_nodes'."""
        return self._reconstructed_nodes

    @reconstructed_nodes.setter
    def reconstructed_nodes(self, value):
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
                "The 'reconstructed_nodes' field must be a set or sequence and each value of type 'Node'"
        self._reconstructed_nodes = value

    @builtins.property
    def mocap_nodes(self):
        """Message field 'mocap_nodes'."""
        return self._mocap_nodes

    @mocap_nodes.setter
    def mocap_nodes(self, value):
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
                "The 'mocap_nodes' field must be a set or sequence and each value of type 'Node'"
        self._mocap_nodes = value

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
