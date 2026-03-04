# ROS2 migration plan

Single reference for migration status and remaining work.

## Completed

- **tensegrity_interfaces** — All messages (Action, State, TensegrityStamped, etc.) ported to ROS2.
- **tensegrity_core** — Shared logic (robot_core, udp_client, calibration, gait tables); used by driver.
- **tensegrity_driver** — Full driver node: UDP, publishes `control_msg` and `/state_msg`, subscribes to `/action_msg`, applies actions via core.
- **tensegrity_bringup** — Launch file for driver only (`ros2 launch tensegrity_bringup bringup.py`).
- **tensegrity_planning** — Package layout and runnable stub nodes for A* and RL planners.

## Partial / stubs

- **astar_planner_node** — Subscribes to `/state_msg`, publishes `/action_msg`; no A* logic yet. Full implementation depends on perception (pose/tracking).
- **rl_planner_node** — Same: runnable stub, no RL logic until perception is available.

See [tensegrity_interfaces/PERCEPTION_INTERFACE.md](src/tensegrity_interfaces/PERCEPTION_INTERFACE.md) for the perception service contract (GetPose, InitTracker, etc.).

## Pending

- **tensegrity_perception** — External package; must be ported to ROS2 in its own repo. Same service names and equivalent message types so planning nodes need minimal changes.
- **bringup_astar** — Optional: add a launch that starts driver + A* planner (equivalent to ROS1 `bringup_astar.launch`).
- **tensegrity_controller** — Package present but has no runnable nodes (no entry_points).
- **End-to-end validation** — Full A*/RL + driver + perception once perception is ROS2.

## How to validate

1. **Build:** `cd ros2_ws && colcon build --symlink-install && source install/setup.bash` (or from repo root: `source setup_ros.sh ros2` after building).
2. **Driver:** `ros2 launch tensegrity_bringup bringup.py` — robot over UDP, state/control/action topics.
3. **Stub planner:** In another terminal (after sourcing): `ros2 run tensegrity_planning astar_planner_node` — runs without crashing; no real planning until perception is connected.
4. **With perception:** When `tensegrity_perception` is ROS2, wire it in and complete A*/RL node logic to use GetPose and publish actions.
