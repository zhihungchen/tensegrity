# ROS 2 — tensegrity workspace

**Assumptions:** Ubuntu, ROS 2 **Humble** / **Jazzy** / **Iron**, `colcon` + `rosdep`. Robot UDP matches [`RobotConfig`](src/tensegrity_core/tensegrity_core/robot_config.py) (`UDP_IP` / `UDP_PORT`, default `0.0.0.0:2390`).

---

## Architecture

| Layer | Role |
|-------|------|
| **`tensegrity_core`** | UDP sockets, **RX thread** (`TensegrityCore.start()` / `stop()`), parse → **`get_latest_state()`**. **`send_motor_speeds`**, **`stop_all()`**, **`set_motor_speed`**. No ROS, no gait/direct policy. Optional **`debug_udp`** + **`debug_udp_min_interval_s`**. |
| **`tensegrity_driver_node`** ([`robot_driver.py`](src/tensegrity_driver/tensegrity_driver/robot_driver.py)) | Gait PID, **`/action_msg`**, **`/control_msg`**, **`/state_msg`**. Modes **idle** / **gait**; motor vectors only via **`_dispatch_motor_speeds(..., GAIT)`**. Timer does **not** call **`core.read()`**. |
| **`robot_driver_direct`** ([`robot_driver_direct.py`](src/tensegrity_driver/tensegrity_driver/robot_driver_direct.py)) | **`/motor_cmd`**, JSON motor script in a **background thread**. Modes **idle** / **direct** (GAIT enum unused). Vectors only via **`_dispatch_motor_speeds(..., DIRECT)`**. **`core.start()`** on init, **`core.stop()`** on shutdown. |

Default launch ([`bringup.py`](src/tensegrity_bringup/launch/bringup.py)) runs **`tensegrity_driver_node`**, not `robot_driver_direct`.

---

## Workspace layout

```text
ros2_ws/src/
  tensegrity_interfaces/
  tensegrity_core/
  tensegrity_driver/
  tensegrity_planning/
  tensegrity_bringup/
  tensegrity_controller/    # optional
  tensegrity_perception/    # optional; link if used
```

```bash
cd /path/to/tensegrity/ros2_ws
./scripts/link_tensegrity_perception.sh   # optional
```

---

## Dependencies, build, environment

```bash
# once
sudo apt update
sudo apt install -y python3-colcon-common-extensions python3-rosdep ros-humble-desktop
sudo rosdep init    
rosdep update
## cd /path/to/ros2_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install --packages-select tensegrity_driver ## replace with node
source install/setup.bash
```

**Perception (pip, if you use `tensegrity_perception`):**

```bash
pip3 install --user numpy scipy PyYAML opencv-python-headless open3d trimesh pyrender easydict
```

**Every new terminal:**

```bash
source /opt/ros/humble/setup.bash
source /path/to/ros2_ws/install/setup.bash
```

---

## Nodes & executables

| Command | Purpose |
|---------|---------|
| `ros2 run tensegrity_driver tensegrity_driver_node` | Gait driver (same as bringup) |
| `ros2 run tensegrity_driver robot_driver_direct` | Direct + optional JSON scripts |
| `ros2 run tensegrity_driver motor_control_test` | Integration test vs `robot_driver_direct` |

---

## Launch

```bash
ros2 launch tensegrity_bringup bringup.py
```

**Pipeline (driver + perception):**

```bash
ros2 launch tensegrity_bringup pipeline.launch.py
# Optional: launch_astar:=true  launch_rl:=true
# Camera remap example:
#   rgb_topic:=/camera/color/image_raw
#   depth_topic:=/camera/aligned_depth_to_color/image_raw
```

**Perception only** (run a driver separately for `/control_msg`):

```bash
ros2 launch tensegrity_perception tracking.launch.py
```

---

## Direct driver (`robot_driver_direct`)

**Simulation (no hardware):**

```bash
ros2 run tensegrity_driver robot_driver_direct --ros-args \
  -p use_fake_udp:=true -p fake_udp_hz:=50.0
```

**Real UDP:** `-p use_fake_udp:=false`.

| Parameter | Default | Meaning |
|-----------|---------|---------|
| `use_fake_udp` | `false` | Use `FakeUdpClient` instead of real socket |
| `fake_udp_hz` | `50.0` | Fake telemetry rate |
| `motor_command_json_file` | `""` | If set, load this file (skips dir scan) |
| `motor_command_json_scan` | `true` | Look for a script under `motor_command_json_dir` |
| `motor_command_json_dir` | `share/.../motor_scripts` or source `tensegrity_driver/motor_scripts` | Script folder |
| `motor_command_json_basename` | `motor_command.json` | Preferred name; if missing and basename is default, **`motor_command.example.json`** is used |
| `motor_command_json_loop` | `false` | Repeat script after the last segment |

**JSON schema:** root object with **`commands`** (required, non-empty). Each item: a **number** (speed, uses `defaults`) or **`{ "speed", "motor_id"?, "hold_s"? }`**. Optional **`defaults`:** `motor_id`, `hold_s`.

**Disable auto JSON** (e.g. for `motor_control_test`):

```bash
-p motor_command_json_scan:=false
```

---

## Quick test

1. Build + `source install/setup.bash`.
2. **Direct + fake UDP** (default scan loads `motor_command.example.json` if `motor_command.json` is absent):

   ```bash
   ros2 run tensegrity_driver robot_driver_direct --ros-args -p use_fake_udp:=true
   ```

   ```bash
   ros2 topic hz /control_msg
   ```

3. **`motor_control_test`** — terminal A:

   ```bash
   ros2 run tensegrity_driver robot_driver_direct --ros-args \
     -p use_fake_udp:=true -p motor_command_json_scan:=false
   ```

   Terminal B:

   ```bash
   ros2 run tensegrity_driver motor_control_test -- --mode fake --motor-id 2 --sequence 30,0,-30
   ```

   Options: `--help`, `--control-topic`, `--motor-cmd-topic`, `--timeout`, `--tol`, `--step-sleep`. **`--mode real`** only when the driver uses real UDP.

---

## Topics (summary)

| Topic | Type | Producer |
|-------|------|----------|
| `/control_msg` | `tensegrity_interfaces/msg/TensegrityStamped` | Both drivers (`RobotConfig.ros_control_topic`, default `/control_msg`) |
| `/state_msg` | `tensegrity_interfaces/msg/State` | Gait node only |
| `/action_msg` | `tensegrity_interfaces/msg/Action` | Gait node (sub) |
| `/motor_cmd` | `tensegrity_interfaces/msg/MotorCommand` | Direct node (sub) |

**Perception:** `/rgb_images`, `/depth_images` (remap as needed), `/trajectory_images`, services `/init_tracker`, `/get_pose`, `/get_bar_height` — see `tensegrity_perception` and `pipeline.launch.py`.

```bash
ros2 topic list
ros2 topic echo /control_msg --once
ros2 service call /get_pose tensegrity_perception/srv/GetPose "{}"
```

---

## Hardware checklist

1. PC listens on configured UDP; Arduinos match firmware port.
2. After bringup or direct driver: `ros2 topic hz /control_msg` ~50 Hz; echo shows updating motors/sensors.
3. Pipeline: cameras, `init_tracker`, then `get_pose` when the scene is valid.
4. Replace placeholder rod meshes if tracking is poor.
