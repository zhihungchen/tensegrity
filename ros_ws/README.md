# ROS1 workspace (catkin)

Packages: `tensegrity_interfaces`, `tensegrity_core`, `tensegrity_driver`, `tensegrity_planning`, `tensegrity_bringup`, `tensegrity_controller`.

## Build

From the repo root (e.g. `catkin_ws_new`), source ROS1 then build this workspace. If you get CMake errors about a different source directory (e.g. after cloning or moving the repo), clean and rebuild: `rm -rf build devel` then `catkin_make` again.

```bash
source /opt/ros/noetic/setup.bash   # or melodic
cd /path/to/catkin_ws_new/src/tensegrity/ros_ws
catkin_make
source devel/setup.bash
```

Or use the top-level setup script (it will source this workspace if built):

```bash
cd /path/to/catkin_ws_new
source setup_ros.sh ros1
# Then build the nested ros_ws if not yet built:
cd src/tensegrity/ros_ws && catkin_make && cd -
source setup_ros.sh ros1
```

## Run

After sourcing (e.g. `source setup_ros.sh ros1` or `source devel/setup.bash` from this directory):

| What | Command |
|------|---------|
| **Driver** (robot over UDP) | `roslaunch tensegrity_bringup bringup.launch` |
| **A* (driver + planner)** | `roslaunch tensegrity_bringup bringup_astar.launch` |
| Driver (single node) | `rosrun tensegrity_driver tensegrity_driver_node.py` |
| Calibration node | `rosrun tensegrity_driver tensegrity_driver_cali_node.py` |
| A* planner | `rosrun tensegrity_planning astar_planner_node.py` |
| RL planner | `rosrun tensegrity_planning rl_planner_node.py` |

The driver subscribes to `/action_msg` and publishes `control_msg` and `/state_msg`. It supports both simple action names (roll, cw, ccw) and full A* Action messages (with endcaps, COMs, PAs) and applies transform_gait / range updates. The A* planner subscribes to `/state_msg` and (optionally) perception, and publishes `/action_msg`.

---

## A* stack: how it works (aligned with legacy run_tensegrity_Astar)

The A* configuration replaces the old single-process `run_tensegrity_Astar.py` with a driver + planner split. Behavior is aligned with the previous script.

### Data flow

1. **Driver** (`tensegrity_driver`): Talks to the robot over UDP (sensors, motors). Runs a PID gait controller on a **gait table** (sequence of motor targets). Publishes `control_msg` (TensegrityStamped) and `/state_msg` (State: `prev_action`, `reverse_the_gait`). Subscribes to `/action_msg` (Action).

2. **Planner** (`astar_planner_node`): Subscribes to `/state_msg`. When it receives State (and optionally when a tracking service is up), it treats the robot pose as (x, y, θ) and runs **A\*** in that space to get a path from current pose to a fixed goal. The path is a sequence of **primitives**: roll steps like `"100_100"`, `"120_120"`, or turns `"cw"`, `"ccw"`. It publishes **one** Action per State message: `actions[]` (the planned sequence), `endcaps`, `COMs`, `PAs`.

3. **Driver action handling**: When the driver gets an Action with **endcaps** (6 points), it uses **astar_action_handler** (in `tensegrity_planning`):
   - **bottom3(endcaps)**: which three nodes are on the ground → determines symmetry.
   - **transform_gait(gait, bottom_nodes)**: permutes the canonical gait (roll / cw / ccw) so motor indices match the current bar configuration (using `symmetry_reduction_utils`).
   - **RANGE024 / RANGE135**: for roll primitives like `"100_120"`, cable length ranges are parsed and set on the core (motors 3,4,5 use RANGE024; 0,1,2 use RANGE135).
   - **prev_nodes / next_nodes**: bookkeeping for which bottom nodes come next after a roll step, so the next action uses the correct symmetry.

So: **planner** outputs high-level actions (e.g. `"100_120"`, `"cw"`); **driver** turns them into a concrete gait table and ranges using the current pose (endcaps) and symmetry.

### Primitives and A* search

- **Primitives** come from `new_platform_transformation_table.pkl`: each key like `"100_100__100_100"` gives a rotation and translation (dx, dy, dθ). The planner builds a list `['100_100','120_120',...,'ccw','cw']` and runs **A\*** in (x, y, θ) with those motions, avoiding obstacles and staying inside a boundary.
- **astar.py**: Standard A* with a heap; neighbors are (x + dx, y + dy, θ + dθ) for each primitive. Heuristic is distance (or wave-front). Collision and boundary checks use `util_heuristic` and `close_node`.

### Alignment with old run_tensegrity_Astar

- **Gaits**: Same canonical roll / cw / ccw tables as before; driver applies `transform_gait` and (for roll) `reverse_gait` when `reverse_the_gait` is true.
- **Ranges**: Roll actions `"R135_R024"` set RANGE135 and RANGE024; tolerance 0.35 when range ≥ 130, else 0.15.
- **State**: Driver publishes State (e.g. `prev_action = "RANGE135_RANGE024"` for roll). Planner uses State to know when to replan (e.g. when tracking updates pose) and to send the next action in the sequence.
- **One action per step**: Planner sends the full planned sequence in one message but **pops** the first after publishing; the driver uses only `actions[0]`. So each State message triggers the next primitive in the plan, matching the old “one action per transition” behavior.
