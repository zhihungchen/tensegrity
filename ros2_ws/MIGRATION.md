# ROS2 migration plan

Single reference for migration status and remaining work.

## Completed

- **tensegrity_interfaces** — All messages (Action, State, TensegrityStamped, etc.) ported to ROS2.
- **tensegrity_core** — Shared logic (robot_core, udp_client, calibration, gait tables); used by driver.
- **tensegrity_driver** — Full driver node: UDP, publishes `control_msg` and `/state_msg`, subscribes to `/action_msg`, applies actions via core.
- **tensegrity_bringup** — Launch file for driver only (`ros2 launch tensegrity_bringup bringup.py`).
- **tensegrity_planning** — Package layout and runnable stub nodes for A* and RL planners.

## Partial / stubs

- **astar_planner_node** — Subscribes to `/state_msg`, publishes `/action_msg`; calls `get_pose` when the service is available (stub polling). Full A* logic still TODO.
- **rl_planner_node** — Same; `get_pose` client wired; full RL logic still TODO.

See [tensegrity_interfaces/PERCEPTION_INTERFACE.md](src/tensegrity_interfaces/PERCEPTION_INTERFACE.md) for the perception service contract (GetPose, InitTracker, etc.).

## Pending

- **tensegrity_perception** — ROS2 package lives in a separate repo/branch (`ros2`). Add it to your `colcon` workspace `src/` next to `tensegrity_interfaces` (see that repo’s `COLCON.md`).
- **bringup_astar** — Optional: add a launch that starts driver + A* planner (equivalent to ROS1 `bringup_astar.launch`).
- **tensegrity_controller** — Package present but has no runnable nodes (no entry_points).
- **End-to-end validation** — Full A*/RL + driver + perception once perception is ROS2.

## How to validate

1. **Build:** `cd ros2_ws && colcon build --symlink-install && source install/setup.bash` (or from repo root: `source setup_ros.sh ros2` after building).
2. **Driver:** `ros2 launch tensegrity_bringup bringup.py` — robot over UDP, state/control/action topics.
3. **Stub planner:** In another terminal (after sourcing): `ros2 run tensegrity_planning astar_planner_node` — runs without crashing; no real planning until perception is connected.
4. **With perception:** Build `tensegrity_perception` in the same workspace, run `tracking_node`, then planners can call `get_pose`. **Trajectory in `control_msg`:** the driver now initializes an empty `Trajectory` so messages are well-formed; COM/planned-path lists stay empty until MPC/controller fills them (perception overlays then stay minimal).

