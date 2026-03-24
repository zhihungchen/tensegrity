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
| **Driver + perception** (+ optional stub planners) | `ros2 launch tensegrity_bringup pipeline.launch.py` |
| Driver (single node) | `ros2 run tensegrity_driver tensegrity_driver_node` |
| Perception only | `ros2 launch tensegrity_perception tracking.launch.py` |
| A* planner | `ros2 run tensegrity_planning astar_planner_node` |
| RL planner | `ros2 run tensegrity_planning rl_planner_node` |

Put `tensegrity_perception` in `src/` next to the other packages (see `scripts/link_tensegrity_perception.sh` for a sibling checkout). The A* and RL nodes are still planning stubs but poll `get_pose` when the tracker is running.

See [MIGRATION.md](MIGRATION.md) and [tensegrity_interfaces/PERCEPTION_INTERFACE.md](src/tensegrity_interfaces/PERCEPTION_INTERFACE.md).
