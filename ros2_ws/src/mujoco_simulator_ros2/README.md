# mujoco_simulator_ros2

ROS 2 UDP bridge (`udp_simulator_bridge_node`) for the tensegrity MuJoCo simulator, plus vendored `xml_models/`.

## See the MuJoCo viewer (interactive window)

The 3D window is opened by the **Python UDP simulator**, not by the ROS 2 node alone.

**Terminal 1 — simulator + viewer**

From the package source tree:

```bash
cd /path/to/catkin_ws_new/src/tensegrity/ros2_ws/src/mujoco_simulator_ros2
./scripts/run_udp_simulator_viewer.sh
```

Optional: pass another MJCF path as the first argument.

This runs `tensegrity_udp_simulator.py` with `--no-ros --viewer` and uses `xml_models/3bar_new_platform_all_cables.xml` from this package.

**Dependency:** the [MuJoCo Python package](https://pypi.org/project/mujoco/) must be installed for the **`python3` on your PATH**:

```bash
python3 -m pip install --user mujoco
```

For the **browser remote viewer** (`--remote-viewer` on `tensegrity_udp_simulator.py`), also: `pip install aiohttp`. The local GLFW viewer (`--viewer`) does not need it.

If you use **Conda** (or another env) where `mujoco` is installed but system `python3` is different, either activate that env first or run:

```bash
MUJOCO_PYTHON="$CONDA_PREFIX/bin/python" ./scripts/run_udp_simulator_viewer.sh
```

**Terminal 2 — ROS 2 bridge (optional)**

```bash
cd /path/to/tensegrity/ros2_ws
source /opt/ros/humble/setup.bash   # or your distro
source install/setup.bash
ros2 run mujoco_simulator_ros2 udp_simulator_bridge_node
```

Publish motor commands on `control_cmd` (`tensegrity_interfaces/TensegrityStamped`) or set `use_float64_motor_topic` and use `motor_speeds`.

## MuJoCo / MJCF notes

- Default model `3bar_new_platform_all_cables.xml` uses `coordinate="local"` and MJCF flags adjusted for **MuJoCo 3.x** loading. If behavior differs from legacy global-coordinate models, compare with the original in `tensegrity_simulation` and tune as needed.
- Other vendored `.xml` files may still use legacy options; use the default 3-bar model first.

## Launch files

```bash
ros2 launch mujoco_simulator_ros2 udp_simulator_bridge.launch.py
ros2 launch mujoco_simulator_ros2 mujoco_udp_simulator.launch.py \
  simulator_script:=/absolute/path/to/tensegrity_udp_simulator.py
```
