# ROS 2 notes (tensegrity + tensegrity_perception)

Assumptions: Ubuntu with ROS 2 **Humble** (or **Jazzy** / **Iron**), `colcon` and `rosdep` installed, robot reachable over UDP with the same IP/port as `tensegrity_core.RobotConfig`.

## 1. Workspace layout

Clone or place both repositories so `tensegrity_perception` sits next to the other ROS 2 packages:

```text
ros2_ws/src/
  tensegrity_interfaces/
  tensegrity_core/
  tensegrity_driver/
  tensegrity_planning/
  tensegrity_bringup/
  tensegrity_controller/   # optional; no nodes
  tensegrity_perception/   # from branch ros2
```

If you use the `tensegrity` repo’s nested `ros2_ws` and keep `tensegrity_perception` beside it (e.g. under the same parent `src/` as `tensegrity`), link it in:

```bash
cd /path/to/tensegrity/ros2_ws
./scripts/link_tensegrity_perception.sh /path/to/tensegrity_perception
# or with default relative path to ../../../tensegrity_perception from this layout:
./scripts/link_tensegrity_perception.sh
```

## 2. System dependencies (ROS + build tools)

```bash
sudo apt update
sudo apt install -y python3-colcon-common-extensions python3-rosdep ros-humble-desktop
# Replace humble with jazzy/iron if needed.
sudo rosdep init   # skip if already done
rosdep update
```

## 3. rosdep for workspace packages

From `ros2_ws`:

```bash
source /opt/ros/humble/setup.bash
cd /path/to/ros2_ws
rosdep install --from-paths src --ignore-src -r -y
```

## 4. Python packages (perception)

Not all perception libraries are satisfied by `rosdep`; use pip in a venv or user site (match the Python version ROS uses):

```bash
pip3 install --user numpy scipy PyYAML opencv-python-headless open3d trimesh pyrender easydict
```

If GPU/pyrender causes issues, install the versions pinned in `tensegrity_perception/environment.yml` where possible.

## 5. Build

```bash
source /opt/ros/humble/setup.bash
cd /path/to/ros2_ws
colcon build --symlink-install --packages-up-to tensegrity_bringup
source install/setup.bash
```

Partial rebuild examples:

```bash
colcon build --symlink-install --packages-select tensegrity_perception
colcon build --symlink-install --packages-select tensegrity_driver tensegrity_bringup
```

## 6. Source (every new terminal)

```bash
source /opt/ros/humble/setup.bash
source /path/to/ros2_ws/install/setup.bash
```

From a monorepo that contains `setup_ros.sh` (if paths match):

```bash
source /path/to/catkin_ws_new/setup_ros.sh ros2
```

## 7. Run / launch

**Driver only (robot UDP):**

```bash
ros2 launch tensegrity_bringup bringup.py
```

**Driver + perception** (expects RGB-D on `/rgb_images` and `/depth_images` unless remapped):

```bash
ros2 launch tensegrity_bringup pipeline.launch.py
```

**Remap camera topics (RealSense-style example):**

```bash
ros2 launch tensegrity_bringup pipeline.launch.py \
  rgb_topic:=/camera/color/image_raw \
  depth_topic:=/camera/aligned_depth_to_color/image_raw
```

**Optional stub planners** (still poll `get_pose`; no full A*/RL yet):

```bash
ros2 launch tensegrity_bringup pipeline.launch.py launch_astar:=true
# or
ros2 launch tensegrity_bringup pipeline.launch.py launch_rl:=true
```

**Perception node alone** (driver must publish `/control_msg` in another terminal):

```bash
ros2 launch tensegrity_perception tracking.launch.py
```

## 8. Topics / services inspection

```bash
ros2 topic list
ros2 topic echo /control_msg --once
ros2 topic echo /state_msg --once
ros2 topic hz /control_msg
ros2 service list | grep -E 'pose|tracker|bar'
ros2 interface show tensegrity_perception/srv/GetPose
ros2 interface show tensegrity_perception/srv/InitTracker
```

**Call `get_pose`** (after successful `init_tracker`):

```bash
ros2 service call /get_pose tensegrity_perception/srv/GetPose "{}"
```

`init_tracker` requires images and arrays; use a small Python script or a one-off node in the lab, or call from your own tooling with `ros2 interface proto` to build the request.

## 9. Topic contract (quick)

| Direction | Topic | Type |
|-----------|--------|------|
| Driver → perception | `/control_msg` | `tensegrity_interfaces/msg/TensegrityStamped` |
| Camera → perception | `/rgb_images`, `/depth_images` (remap as needed) | `sensor_msgs/msg/Image` |
| Perception → viz | `/trajectory_images` (remap via `trajectory_topic`) | `sensor_msgs/msg/Image` |
| Driver → planners | `/state_msg` | `tensegrity_interfaces/msg/State` |
| Planners → driver | `/action_msg` | `tensegrity_interfaces/msg/Action` |

Services: `/init_tracker`, `/get_pose`, `/get_bar_height` (`tensegrity_perception`).

## 10. Hardware verification (short)

1. **Network:** Ping the robot or verify the PC listens on `RobotConfig.UDP_IP` / `UDP_PORT` (default `0.0.0.0:2390`) and Arduinos match the sketch.
2. **Driver only:** Launch `bringup.py`, confirm `ros2 topic hz /control_msg` is ~50 Hz and `ros2 topic echo /control_msg` shows updating `motors` / `sensors`.
3. **Camera:** With the RGB-D driver running, confirm `ros2 topic hz` on your color and depth topics; remapped names should match `pipeline.launch.py` arguments.
4. **Pipeline:** Launch `pipeline.launch.py` with remaps; confirm no fatal errors from `tracking_service` (meshes load). Initialize the tracker (`init_tracker`) with a synchronized snapshot; then `ros2 service call /get_pose ...` returns `success: true` and a non-empty `poses` when the scene is valid.
5. **Planners (optional):** With `launch_astar:=true`, watch logs for `get_pose: N rod pose(s)` when the tracker is ready.

Replace the placeholder rod mesh (`mesh/rod_strut_placeholder.obj`) with your calibrated strut model if tracking quality is poor.
