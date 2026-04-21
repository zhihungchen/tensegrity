# ROS 2 — tensegrity workspace

**Assumptions:** Ubuntu, ROS 2 **Humble** / **Jazzy** / **Iron**, `colcon` + `rosdep`. Robot UDP matches [`RobotConfig`](src/tensegrity_core/tensegrity_core/robot_config.py) (`UDP_IP` / `UDP_PORT`, default `0.0.0.0:2390`).

## Quick Start
This is the fastest way to run the current ROS 2 stack in **simulation mode** with the existing MuJoCo viewer and bridge.

### 1. Build the workspace
```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install --packages-select tensegrity_driver
source install/setup.bash
```

### 2. Run the simulator viewer
Terminal 1:

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws/src/mujoco_simulator_ros2
./scripts/run_udp_simulator_viewer.sh
```

### 3. Run the simulator bridge
Terminal 2:

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run mujoco_simulator_ros2 udp_simulator_bridge_node --ros-args \
  -p use_float64_motor_topic:=true \
  -p motor_speeds_topic:=/sim_motor_speeds
```

### 4. Run the driver in sim mode
Terminal 3:

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run tensegrity_driver robot_driver_direct --ros-args \
  -p backend:=sim \
  -p motor_speeds_topic:=/motor_speeds \
  -p sim_motor_speeds_topic:=/sim_motor_speeds \
  -p sim_control_topic:=/control_msg \
  -p motor_command_json_scan:=false
```

### 5. Publish a test motor command
Terminal 4:

```bash
ros2 topic pub --rate 10 /motor_speeds std_msgs/msg/Float64MultiArray \
  "{data: [10.0, 10.0, 10.0, 10.0, 10.0, 10.0]}"
```

### 6. Verify `/control_msg`
In another terminal:

```bash
ros2 topic echo /control_msg --once
```

If the setup is healthy:
- the MuJoCo viewer moves,
- the bridge keeps publishing `/control_msg`,
- the driver stays in the loop but does **not** publish `/control_msg` in sim mode.

---

## Running Modes

### Real mode (`backend=real`)
Components used:
- `robot_driver_direct` or `tensegrity_driver_node`
- `tensegrity_core`
- `UdpClient`
- real robot hardware / UDP Arduinos

Who publishes `/control_msg`:
- the driver node

Key behavior:
- the driver sends motor vectors through `TensegrityCore.send_motor_speeds(...)`
- telemetry comes from the real UDP path
- this is the path for real hardware or fake UDP regression tests

### Simulation mode (`backend=sim`)
Components used:
- `robot_driver_direct` or `tensegrity_driver_node`
- `udp_simulator_bridge_node`
- `tensegrity_udp_simulator.py` / MuJoCo viewer

Who publishes `/control_msg`:
- `udp_simulator_bridge_node`

Key behavior:
- the driver subscribes to `/motor_speeds`
- the sim backend forwards commands to `/sim_motor_speeds`
- the unchanged simulator bridge converts ROS motor commands to the simulator UDP contract
- the driver does **not** publish a second `/control_msg`

### Real vs sim at a glance
| Mode | Motor output path | `/control_msg` publisher | Fixed external component |
|------|-------------------|--------------------------|--------------------------|
| `backend=real` | Driver -> `TensegrityCore` -> UDP | Driver | real hardware |
| `backend=sim` | Driver -> `udp_simulator_bridge_node` -> UDP -> MuJoCo | Bridge | simulator side |

---

## Architecture

### Driver layer
- [`robot_driver.py`](src/tensegrity_driver/tensegrity_driver/robot_driver.py): gait driver, subscribes to `/action_msg`, publishes `/state_msg`, and dispatches motor vectors through the selected backend.
- [`robot_driver_direct.py`](src/tensegrity_driver/tensegrity_driver/robot_driver_direct.py): direct low-level driver, subscribes to `/motor_speeds`, supports optional JSON motor scripts, and dispatches motor vectors through the selected backend.
- [`motor_control_test.py`](src/tensegrity_driver/tensegrity_driver/motor_control_test.py): test tool for direct-path validation.

### Backend layer
- `backend=real`: wraps [`TensegrityCore`](src/tensegrity_core/tensegrity_core/robot_core.py) and its UDP transport.
- `backend=sim`: adapts the driver to the existing `udp_simulator_bridge_node` ROS interface.
- The backend abstraction exists so driver logic stays shared while the output transport changes.

### Hardware / Simulator layer
- **`TensegrityCore` = real hardware backend**.
- **`udp_simulator_bridge_node` = simulator backend adapter**.
- The MuJoCo simulator side is treated as fixed external functionality and is not redesigned here.

### Conceptual diagram
```text
                 High-level / low-level commands
                           |
        +---------------------------------------------+
        |                 Driver layer                 |
        |  robot_driver_direct   |   tensegrity_driver |
        +---------------------------------------------+
                           |
                    backend:=real|sim
                           |
        +---------------------------------------------+
        |                Backend layer                 |
        |  RealRobotBackend  |   SimBridgeBackend      |
        +---------------------------------------------+
             |                              |
             v                              v
       TensegrityCore                 udp_simulator_bridge_node
             |                              |
             v                              v
      Real robot UDP                 MuJoCo UDP simulator
```

### Existing technical notes
| Layer | Role |
|-------|------|
| **`tensegrity_core`** | UDP sockets, **RX thread** (`TensegrityCore.start()` / `stop()`), parse -> **`get_latest_state()`**. **`send_motor_speeds`**, **`stop_all()`**, **`set_motor_speed`**. No ROS, no gait/direct policy. Optional **`debug_udp`** + **`debug_udp_min_interval_s`**. |
| **`tensegrity_driver_node`** ([`robot_driver.py`](src/tensegrity_driver/tensegrity_driver/robot_driver.py)) | Gait PID, **`/action_msg`**, **`/control_msg`**, **`/state_msg`**. Modes **idle** / **gait**; motor vectors only via **`_dispatch_motor_speeds(..., GAIT)`**. Timer does **not** call **`core.read()`**. |
| **`robot_driver_direct`** ([`robot_driver_direct.py`](src/tensegrity_driver/tensegrity_driver/robot_driver_direct.py)) | **`/motor_speeds`**, JSON motor script in a **background thread**. Modes **idle** / **direct** (GAIT enum unused). Vectors only via **`_dispatch_motor_speeds(..., DIRECT)`**. Real backend uses **`core.start()`** / **`core.stop()`**. |

Default launch ([`bringup.py`](src/tensegrity_bringup/launch/bringup.py)) runs **`tensegrity_driver_node`**, not `robot_driver_direct`.

---

## Topic Interfaces

### `/motor_speeds`
- Type: `std_msgs/msg/Float64MultiArray`
- Publishers:
  - direct test tools
  - manual `ros2 topic pub`
- Subscribers:
  - `robot_driver_direct` in both backends
- Purpose:
  - canonical low-level motor command vector on the driver side

### `/sim_motor_speeds`
- Type: `std_msgs/msg/Float64MultiArray`
- Publishers:
  - sim backend inside the driver
- Subscribers:
  - `udp_simulator_bridge_node` when `use_float64_motor_topic:=true`
- Purpose:
  - bridge-facing simulator command topic

### `/control_msg`
- Type: `tensegrity_interfaces/msg/TensegrityStamped`
- Publishers:
  - real mode: driver node
  - sim mode: `udp_simulator_bridge_node`
- Subscribers:
  - perception / monitoring / debug tools
  - sim backend telemetry consumer
- Purpose:
  - low-level telemetry / observed control state

**Important:** only **one** node should publish `/control_msg` at a time.

### `/state_msg`
- Type: `tensegrity_interfaces/msg/State`
- Publishers:
  - `tensegrity_driver_node`
- Subscribers:
  - planner nodes
- Purpose:
  - planner-facing gait state

### `/action_msg`
- Type: `tensegrity_interfaces/msg/Action`
- Publishers:
  - planners
- Subscribers:
  - `tensegrity_driver_node`
- Purpose:
  - high-level gait / planning command input

### Topic summary
| Topic | Type | Publisher(s) | Subscriber(s) | Purpose |
|-------|------|--------------|---------------|---------|
| `/motor_speeds` | `std_msgs/msg/Float64MultiArray` | direct tests/tools | direct driver | driver-side low-level motor command |
| `/sim_motor_speeds` | `std_msgs/msg/Float64MultiArray` | sim backend | simulator bridge | bridge-facing motor command |
| `/control_msg` | `tensegrity_interfaces/msg/TensegrityStamped` | real: driver, sim: bridge | monitoring/perception/tools | telemetry |
| `/state_msg` | `tensegrity_interfaces/msg/State` | gait driver | planners | gait state |
| `/action_msg` | `tensegrity_interfaces/msg/Action` | planners | gait driver | high-level action input |

---

## Simulator Mode

### Why `/motor_speeds` and `/sim_motor_speeds` are different
In simulation mode, the driver needs its own input topic and the bridge needs its own input topic.

Flow:
```text
/motor_speeds -> driver (backend=sim) -> /sim_motor_speeds -> udp_simulator_bridge_node
```

This separation keeps the driver in the loop while still adapting to the simulator’s existing interface.

### Important warning
Do **not** set `/motor_speeds` and `/sim_motor_speeds` to the same topic.

If they are the same, the driver would subscribe to a topic and then publish back onto that same topic, which can create an infinite command loop.

### Viewer note
The 3D window is opened by the **Python UDP simulator**, not by the ROS 2 bridge alone.

Run the viewer from:

```bash
cd /path/to/catkin_ws_new/src/tensegrity/ros2_ws/src/mujoco_simulator_ros2
./scripts/run_udp_simulator_viewer.sh
```

Optional:
- pass another MJCF path as the first argument
- set `MUJOCO_PYTHON=/path/to/python` if MuJoCo is installed in a different Python

Bridge only:

```bash
cd /path/to/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run mujoco_simulator_ros2 udp_simulator_bridge_node
```

---

## Dependencies, Build, Environment

```bash
# once
sudo apt update
sudo apt install -y python3-colcon-common-extensions python3-rosdep ros-humble-desktop
sudo rosdep init
rosdep update

# in ros2_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install --packages-select tensegrity_driver
source install/setup.bash
```

**Every new terminal:**

```bash
source /opt/ros/humble/setup.bash
source /path/to/ros2_ws/install/setup.bash
```

**MuJoCo dependency** for the viewer:

```bash
python3 -m pip install --user mujoco
```

For the browser remote viewer (`--remote-viewer` on `tensegrity_udp_simulator.py`), also:

```bash
pip install aiohttp
```

---

## Workspace Layout

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

Optional perception link:

```bash
cd /path/to/tensegrity/ros2_ws
./scripts/link_tensegrity_perception.sh
```

---

## Nodes and Launch

### Executables
| Command | Purpose |
|---------|---------|
| `ros2 run tensegrity_driver tensegrity_driver_node` | Gait driver (same as bringup) |
| `ros2 run tensegrity_driver robot_driver_direct` | Direct driver + optional JSON scripts |
| `ros2 run tensegrity_driver motor_control_test` | Integration test vs `robot_driver_direct` |

### Launch files
Default bringup:

```bash
ros2 launch tensegrity_bringup bringup.py
```

Pipeline (driver + perception):

```bash
ros2 launch tensegrity_bringup pipeline.launch.py
# Optional: launch_astar:=true  launch_rl:=true
# Camera remap example:
#   rgb_topic:=/camera/color/image_raw
#   depth_topic:=/camera/aligned_depth_to_color/image_raw
```

Perception only (run a driver separately for `/control_msg`):

```bash
ros2 launch tensegrity_perception tracking.launch.py
```

MuJoCo launch files:

```bash
ros2 launch mujoco_simulator_ros2 udp_simulator_bridge.launch.py
ros2 launch mujoco_simulator_ros2 mujoco_udp_simulator.launch.py \
  simulator_script:=/absolute/path/to/tensegrity_udp_simulator.py
```

---

## Testing

### Real backend test
This validates the direct path with `backend:=real` and fake UDP.

Terminal A:

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run tensegrity_driver robot_driver_direct --ros-args \
  -p backend:=real \
  -p use_fake_udp:=true \
  -p motor_command_json_scan:=false
```

Terminal B:

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run tensegrity_driver motor_control_test -- \
  --mode fake \
  --motor-id 2 \
  --sequence 30,0,-30
```

Optional checks:

```bash
ros2 topic hz /control_msg
ros2 topic echo /control_msg --once
```

`motor_control_test` options:
- `--help`
- `--control-topic`
- `--motor-speeds-topic`
- `--timeout`
- `--tol`
- `--step-sleep`
- `--mode real` only when the driver uses real UDP

### Simulator backend test
This validates the direct path with `backend:=sim` and the unchanged MuJoCo bridge.

Terminal A: simulator + viewer

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws/src/mujoco_simulator_ros2
./scripts/run_udp_simulator_viewer.sh
```

Terminal B: bridge

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run mujoco_simulator_ros2 udp_simulator_bridge_node --ros-args \
  -p use_float64_motor_topic:=true \
  -p motor_speeds_topic:=/sim_motor_speeds
```

Terminal C: direct driver in sim mode

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run tensegrity_driver robot_driver_direct --ros-args \
  -p backend:=sim \
  -p motor_speeds_topic:=/motor_speeds \
  -p sim_motor_speeds_topic:=/sim_motor_speeds \
  -p sim_control_topic:=/control_msg \
  -p motor_command_json_scan:=false
```

Terminal D: test command

```bash
cd /home/andrew/Desktop/catkin_ws_new/src/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash
source install/setup.bash
ros2 run tensegrity_driver motor_control_test -- \
  --mode fake \
  --motor-id 2 \
  --sequence 25,0,-25 \
  --motor-speeds-topic /motor_speeds \
  --control-topic /control_msg
```

Manual publish alternative:

```bash
ros2 topic pub --rate 10 /motor_speeds std_msgs/msg/Float64MultiArray \
  "{data: [10.0, 10.0, 10.0, 10.0, 10.0, 10.0]}"
```

Verification:

```bash
ros2 topic echo /control_msg --once
```

---

## Advanced Configuration

### Direct driver parameters
`robot_driver_direct` supports `backend:=real|sim`.

**Real backend** (`TensegrityCore` + UDP / fake UDP state):

```bash
ros2 run tensegrity_driver robot_driver_direct --ros-args \
  -p backend:=real \
  -p use_fake_udp:=true \
  -p fake_udp_hz:=50.0
```

**Sim backend**:

```bash
ros2 run tensegrity_driver robot_driver_direct --ros-args \
  -p backend:=sim \
  -p motor_speeds_topic:=/motor_speeds \
  -p sim_motor_speeds_topic:=/sim_motor_speeds \
  -p sim_control_topic:=/control_msg \
  -p motor_command_json_scan:=false
```

Matching bridge:

```bash
ros2 run mujoco_simulator_ros2 udp_simulator_bridge_node --ros-args \
  -p use_float64_motor_topic:=true \
  -p motor_speeds_topic:=/sim_motor_speeds
```

### Parameter reference
| Parameter | Default | Meaning |
|-----------|---------|---------|
| `backend` | `real` | Backend selection: `real` or `sim` |
| `motor_speeds_topic` | `/motor_speeds` | Driver-side low-level command topic (`Float64MultiArray`) |
| `sim_motor_speeds_topic` | `/sim_motor_speeds` | Bridge-facing motor topic used only in `backend:=sim` |
| `sim_control_topic` | `/control_msg` | Telemetry topic consumed from the bridge in `backend:=sim` |
| `use_fake_udp` | `false` | Use `FakeUdpClient` instead of real socket |
| `fake_udp_hz` | `50.0` | Fake telemetry rate |
| `motor_command_json_file` | `""` | If set, load this file (skips dir scan) |
| `motor_command_json_scan` | `true` | Look for a script under `motor_command_json_dir` |
| `motor_command_json_dir` | `share/.../motor_scripts` or source `tensegrity_driver/motor_scripts` | Script folder |
| `motor_command_json_basename` | `motor_command.json` | Preferred name; if missing and basename is default, **`motor_command.example.json`** is used |
| `motor_command_json_loop` | `false` | Repeat script after the last segment |

### JSON motor scripts
JSON schema:
- root object with **`commands`** (required, non-empty)
- each item is either:
  - a number (speed, uses `defaults`)
  - or `{ "speed", "motor_id"?, "hold_s"? }`
- optional `defaults`:
  - `motor_id`
  - `hold_s`

Disable auto JSON scanning:

```bash
-p motor_command_json_scan:=false
```

---

## Perception Setup

If you use `tensegrity_perception`, install the Python dependencies:

```bash
pip3 install --user numpy scipy PyYAML opencv-python-headless open3d trimesh pyrender easydict
```

Perception topics and services include:
- `/rgb_images`
- `/depth_images`
- `/trajectory_images`
- `/init_tracker`
- `/get_pose`
- `/get_bar_height`

Useful checks:

```bash
ros2 topic list
ros2 topic echo /control_msg --once
ros2 service call /get_pose tensegrity_perception/srv/GetPose "{}"
```

---

## Hardware Notes

1. PC listens on configured UDP; Arduinos match firmware port.
2. After bringup or direct driver: `ros2 topic hz /control_msg` should be around 50 Hz and the echo should show updating motors and sensors.
3. For the pipeline: start cameras, initialize tracking, then call `get_pose` when the scene is valid.
4. Replace placeholder rod meshes if tracking is poor.

---

## MuJoCo / MJCF Notes

- Default model `3bar_new_platform_all_cables.xml` uses `coordinate="local"` and MJCF flags adjusted for **MuJoCo 3.x** loading.
- If behavior differs from legacy global-coordinate models, compare with the original in `tensegrity_simulation` and tune as needed.
- Other vendored `.xml` files may still use legacy options; use the default 3-bar model first.

---

## Design Note

Backend abstraction was introduced so the **driver logic stays shared** while the output transport changes.

Why this design:
- the direct and gait drivers should not duplicate control logic
- `TensegrityCore` is the real hardware backend and should remain the hardware-oriented path
- `udp_simulator_bridge_node` is the simulator backend adapter and is treated as fixed external functionality
- the simulator side is owned separately, so the safer integration is to adapt the driver to the simulator’s existing interfaces rather than modifying simulator code

In short:
- the driver chooses **what** motor speeds to send
- the backend decides **how** those speeds reach the target system
