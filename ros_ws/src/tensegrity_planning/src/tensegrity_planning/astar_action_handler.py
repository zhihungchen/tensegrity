"""
A* / MPC action handler: converts Action messages (with endcaps, COMs, PAs)
into gait states and range parameters for the driver/core.
Uses symmetry_reduction_utils for transform_gait and bottom-node bookkeeping.
"""
import numpy as np
from . import symmetry_reduction_utils as sym

# Base gaits (canonical form; will be transformed by bottom_nodes)
_ROLL = np.array([
    [1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 1],
    [1.0, 1.0, 0.1, 1.0, 1.0, 0.1],
    [0.0, 1.0, 1.0, 0.0, 1.0, 0.1],
], dtype=float)
_CW = np.array([
    [1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 1],
    [0, 0, 0, 1, 0, 1],
    [0, 0, 0, 0, 0, 0.7],
    [0, 0, 0.7, 0, 1, 1],
], dtype=float)
_CCW = np.array([
    [1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 1, 1],
    [1, 1, 1, 0, 1, 1],
    [1, 0, 1, 0, 1, 1],
    [0, 0, 0, 0, 0, 0],
], dtype=float)

ALL_GAITS = {"roll": _ROLL, "cw": _CW, "ccw": _CCW}


def bottom3(nodes):
    """Return 3-tuple of node indices with lowest z (bottom nodes). nodes: (N,3) array."""
    try:
        if nodes is None or len(nodes) < 6:
            return None
        nodes = np.asarray(nodes)
        if nodes.ndim == 1:
            nodes = np.reshape(nodes, (-1, 3))
        z_values = np.array([nodes[i, 2] for i in range(min(6, len(nodes)))])
        bottom_nodes = tuple(sorted(np.argpartition(z_values, 3)[:3]))
        return bottom_nodes
    except Exception:
        return None


def apply_astar_action(msg, prev_bottom_nodes, prev_gait, reverse_the_gait, num_motors=6):
    """
    Apply an A* Action message (with endcaps and actions) to compute new gait states
    and range parameters.

    Args:
        msg: tensegrity_interfaces/Action (actions[], endcaps[], COMs, PAs)
        prev_bottom_nodes: 3-tuple or None (from previous step)
        prev_gait: 'roll' | 'cw' | 'ccw'
        reverse_the_gait: bool
        num_motors: 6

    Returns:
        (states, RANGE024, RANGE135, tol, new_prev_bottom_nodes, new_prev_gait)
        or None if message should be handled as simple action name only.
    """
    if not msg.actions:
        return None
    action = msg.actions[0]
    num_motors = int(num_motors)

    # Build endcaps array from msg
    endcaps = None
    if msg.endcaps and len(msg.endcaps) >= 6:
        endcaps = np.array([[p.x, p.y, p.z] for p in msg.endcaps[:6]])

    bottom_nodes = bottom3(endcaps) if endcaps is not None else None
    if bottom_nodes is not None and bottom_nodes not in sym.prev_nodes.keys():
        bottom_nodes = prev_bottom_nodes
    if bottom_nodes is None:
        bottom_nodes = prev_bottom_nodes or (0, 2, 5)

    # Planning placeholder: go to neutral
    if "planning" in action.lower():
        states = np.ones((4, num_motors), dtype=float)
        return (states, 100.0, 100.0, 0.15, prev_bottom_nodes, prev_gait)

    if action == "cw":
        next_states = ALL_GAITS["cw"]
        if next_states.shape[1] != num_motors:
            next_states = next_states[:, :num_motors]
        new_prev = sym.prev_nodes.get(bottom_nodes, prev_bottom_nodes)
        transformed = sym.transform_gait(next_states, bottom_nodes)
        if transformed is None:
            return None
        return (transformed, 100.0, 100.0, 0.15, new_prev, "cw")

    if action == "ccw":
        next_states = ALL_GAITS["ccw"]
        if next_states.shape[1] != num_motors:
            next_states = next_states[:, :num_motors]
        new_prev = sym.prev_nodes.get(bottom_nodes, prev_bottom_nodes)
        transformed = sym.transform_gait(next_states, bottom_nodes)
        if transformed is None:
            return None
        return (transformed, 100.0, 100.0, 0.15, new_prev, "ccw")

    # Roll or range action (e.g. "100_120")
    next_states = ALL_GAITS["roll"]
    if next_states.shape[1] != num_motors:
        next_states = next_states[:, :num_motors]
    new_prev = sym.next_nodes.get(bottom_nodes, prev_bottom_nodes)
    transformed = sym.transform_gait(next_states, bottom_nodes)
    if transformed is None:
        return None
    if reverse_the_gait:
        transformed = sym.reverse_gait(transformed, bottom_nodes)
        if transformed is None:
            transformed = next_states  # fallback

    # Parse range from action string (e.g. "100_120" -> RANGE135=100, RANGE024=120)
    RANGE135 = 100.0
    RANGE024 = 100.0
    if "_" in action and "planning" not in action.lower():
        parts = action.split("_")
        if len(parts) >= 2:
            try:
                RANGE135 = float(parts[0])
                RANGE024 = float(parts[1])
            except ValueError:
                pass
    tol = 0.35 if (RANGE135 >= 130 or RANGE024 >= 130) else 0.15
    return (transformed, RANGE024, RANGE135, tol, new_prev, "roll")
