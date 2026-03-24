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

- **tensegrity_controller** — Package present but has no runnable nodes (no entry_points).
- **Planner logic** — `astar_planner_node` / `rl_planner_node` still stubs for full A*/RL; they already poll `get_pose` when perception is up.

## Perception integration (done)

- **tensegrity_perception** — Build in the same colcon workspace (see `scripts/link_tensegrity_perception.sh` or clone under `ros2_ws/src/`; `COLCON.md` in the perception repo).
- **pipeline.launch.py** — `ros2 launch tensegrity_bringup pipeline.launch.py` starts driver + `tracking_node` (optional planners via `launch_astar:=true` / `launch_rl:=true`).
- **Topics** — Driver and perception use absolute **`/control_msg`** so both nodes resolve the same topic regardless of node name.

## How to validate

1. **Build:** `cd ros2_ws && colcon build --symlink-install && source install/setup.bash` (or from repo root: `source setup_ros.sh ros2` after building).
2. **Driver:** `ros2 launch tensegrity_bringup bringup.py` — robot over UDP, state/control/action topics.
3. **Stub planner:** In another terminal (after sourcing): `ros2 run tensegrity_planning astar_planner_node` — runs without crashing; no real planning until perception is connected.
4. **With perception:** Link or clone `tensegrity_perception` under `ros2_ws/src/`, build with `colcon build --symlink-install --packages-up-to tensegrity_bringup`, then `ros2 launch tensegrity_bringup pipeline.launch.py` (after publishing RGB-D on `/rgb_images` and `/depth_images`, or remap). Call `init_tracker` once with seed images and cable lengths before expecting `get_pose` to succeed. **Trajectory in `control_msg`:** the driver publishes an empty `Trajectory`; COM lists stay empty until filled; tracking still uses cable `sensors`.

