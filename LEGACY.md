# Legacy and migration notes

## Canonical packages

- **ROS1 (catkin):** `ros_ws/` — build with `catkin_make` or `catkin build`. Source `devel/setup.bash`. See `ros_ws/README.md` for run commands.
- **ROS2 (ament):** `ros2_ws/` — build with `colcon build`. Source `install/setup.bash`. See `ros2_ws/README.md` for run commands and `ros2_ws/MIGRATION.md` for current migration status.

Use the driver and planning nodes from these workspaces rather than the legacy scripts below.

### How to run ROS1 nodes

From the repo root (e.g. `catkin_ws_new`):

1. **Setup:** `source setup_ros.sh` (or `source setup_ros.sh ros1`). This sources the top-level catkin workspace and the nested `ros_ws`, so driver and planning packages are available.
2. **Build** (if needed): `cd src/tensegrity/ros_ws && catkin_make && source devel/setup.bash`
3. **Run driver:** `roslaunch tensegrity_bringup bringup.launch`  
   Or: `rosrun tensegrity_driver tensegrity_driver_node.py`
4. **Run planning** (in another terminal, after sourcing): `rosrun tensegrity_planning astar_planner_node.py` or `rl_planner_node.py`

## Legacy scripts (src/)

The following under `src/` are **legacy** and kept for reference or backward compatibility. Prefer the modular packages when running with ROS.

| Script / folder | Purpose | Replacement |
|-----------------|---------|-------------|
| `run_tensegrity.py`, `run_tensegrity_Astar.py`, `run_tensegrity_RL.py` | Monolithic run + driver + ROS | `tensegrity_driver` + `tensegrity_planning` (ros_ws or ros2_ws) |
| `robot_tensegrity.py` | Full robot + ROS | `tensegrity_driver` (uses `tensegrity_core`) |
| `planner.py`, `RL.py` | Planning nodes | `tensegrity_planning` package |
| `legacy_run_tensegrity*.py`, `legacy_sensor_calibration.py` | Old monolithic scripts | Same as above |
| `sensor_calibration.py`, `manual_control.py` | Calibration / manual control | Use `tensegrity_core` standalone or driver node |

## What to keep

- **calibration/** — calibration data (used by core and driver).
- **onboard/** — firmware and Arduino sketches.
- **msg/** — deprecated for new ROS builds; use `tensegrity_interfaces` in ros_ws/ros2_ws. See `msg/README.md`.

After ROS2 is fully validated in your environment, you may archive or remove the legacy run scripts listed above; keep calibration, onboard, and any offline tools. For current ROS2 migration status and remaining work, see `ros2_ws/MIGRATION.md`.
