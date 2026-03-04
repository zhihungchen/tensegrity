# ROS2 workspace

Packages: `tensegrity_interfaces`, `tensegrity_core`, `tensegrity_driver`, `tensegrity_planning`, `tensegrity_controller`, `tensegrity_bringup`. (`tensegrity_controller` is present but has no runnable nodes yet.)

## Build

```bash
source /opt/ros/<distro>/setup.bash
cd /path/to/tensegrity/ros2_ws
colcon build --symlink-install
source install/setup.bash
```

From the repo root (e.g. `catkin_ws_new`), you can use `source setup_ros.sh ros2` after building this workspace; it will source the correct ROS2 distro and `install/setup.bash` if present.

## Run

After sourcing (e.g. `source install/setup.bash` from this directory or `source setup_ros.sh ros2` from repo root):

| What | Command |
|------|---------|
| **Driver** (robot over UDP) | `ros2 launch tensegrity_bringup bringup.py` |
| Driver (single node) | `ros2 run tensegrity_driver tensegrity_driver_node` |
| A* planner | `ros2 run tensegrity_planning astar_planner_node` |
| RL planner | `ros2 run tensegrity_planning rl_planner_node` |

The A* and RL planner nodes are stubs until perception is available; they run and connect to `/state_msg` and `/action_msg` but do not yet perform real planning.

Perception (`tensegrity_perception`) must be migrated to ROS2 separately. See [MIGRATION.md](MIGRATION.md) for migration status and [tensegrity_interfaces/PERCEPTION_INTERFACE.md](src/tensegrity_interfaces/PERCEPTION_INTERFACE.md) for the perception contract.
