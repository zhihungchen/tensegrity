#!/usr/bin/env bash
# Integration test: ros2 topic pub /motor_speeds -> udp_simulator_bridge_node -> MuJoCo UDP sim.
#
# By default opens the interactive MuJoCo viewer (--viewer). For no window (CI/SSH):
#   MUJOCO_TEST_HEADLESS=1 ./test_ros2_pub_bridge_mujoco.sh
#
# Prereqs:
#   - Source ROS 2 and this workspace:  source /opt/ros/humble/setup.bash && source install/setup.bash
#   - pip: mujoco, DISPLAY set for GLFW (viewer mode)
#   - colcon build --packages-select mujoco_simulator_ros2 tensegrity_interfaces
#
# If UDP 2390/2391 are already taken, set e.g.:
#   export MUJOCO_TEST_MOTOR_PORT=2393 MUJOCO_TEST_POSE_PORT=2394
#
# After the test, viewer + sim keep running until:
#   - MUJOCO_TEST_VIEWER_HOLD_S unset + stdin is a TTY: press Enter to stop (default interactive).
#   - MUJOCO_TEST_VIEWER_HOLD_S=<seconds>: sleep that long, then stop (overrides Enter on TTY).
#   - MUJOCO_TEST_VIEWER_HOLD_S=0: stop immediately after checks.
#   - MUJOCO_TEST_AUTO_EXIT=1 + unset HOLD: sleep 20s (no Enter), or use HOLD for duration.
#   - Non-TTY stdin: sleep 45s if HOLD unset (no prompt possible).
# Headless GL: MUJOCO_GL=egl|osmesa (only when MUJOCO_TEST_HEADLESS=1)
set -euo pipefail

# How to run it:
# cd tensegrity/ros2_ws
# source /opt/ros/humble/setup.bash && source install/setup.bash
# ./src/mujoco_simulator_ros2/scripts/test_ros2_pub_bridge_mujoco.sh


if ! command -v ros2 >/dev/null 2>&1; then
  echo "error: ros2 not found. Source /opt/ros/<distro>/setup.bash and install/setup.bash" >&2
  exit 1
fi

PYTHON="${MUJOCO_PYTHON:-python3}"
if ! "$PYTHON" -c "import mujoco" 2>/dev/null; then
  echo "error: MuJoCo Python package not found for $PYTHON" >&2
  exit 1
fi

PKG_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
XML="${PKG_ROOT}/xml_models/3bar_new_platform_all_cables.xml"
UDP_SIM="${PKG_ROOT}/mujoco_simulator/tensegrity_udp_simulator.py"
MOTOR_PORT="${MUJOCO_TEST_MOTOR_PORT:-2390}"
POSE_PORT="${MUJOCO_TEST_POSE_PORT:-2391}"

# Parent of package mujoco_simulator/ so "from mujoco_simulator.*" resolves.
export PYTHONPATH="${PKG_ROOT}:${PYTHONPATH:-}"
# Viewer mode: tensegrity_udp_simulator sets MUJOCO_GL=glfw when --viewer is on argv.
if [[ "${MUJOCO_TEST_HEADLESS:-0}" == "1" ]]; then
  export MUJOCO_GL="${MUJOCO_GL:-egl}"
else
  unset MUJOCO_GL 2>/dev/null || true
fi

if [[ ! -f "$UDP_SIM" ]]; then
  echo "error: missing $UDP_SIM" >&2
  exit 1
fi
if [[ ! -f "$XML" ]]; then
  echo "error: missing XML: $XML" >&2
  exit 1
fi

SIM_PID=""
BRIDGE_PID=""
cleanup() {
  if [[ -n "${BRIDGE_PID}" ]]; then
    kill "${BRIDGE_PID}" 2>/dev/null || true
    wait "${BRIDGE_PID}" 2>/dev/null || true
  fi
  if [[ -n "${SIM_PID}" ]]; then
    kill "${SIM_PID}" 2>/dev/null || true
    wait "${SIM_PID}" 2>/dev/null || true
  fi
}
trap cleanup EXIT INT TERM

SIM_EXTRA_ARGS=()
if [[ "${MUJOCO_TEST_HEADLESS:-0}" == "1" ]]; then
  SIM_EXTRA_ARGS+=(--no-viz)
  echo "Starting MuJoCo UDP sim (headless) on UDP ${MOTOR_PORT}/${POSE_PORT}..."
else
  echo "Starting MuJoCo UDP sim + viewer on UDP ${MOTOR_PORT}/${POSE_PORT}..."
  echo "(Keep this terminal open until you press Enter at the end, or the viewer/sim will be stopped.)"
  SIM_EXTRA_ARGS+=(--viewer)
fi
"$PYTHON" "$UDP_SIM" "$XML" --no-ros --port "${MOTOR_PORT}" --pose-port "${POSE_PORT}" "${SIM_EXTRA_ARGS[@]}" &
SIM_PID=$!
sleep 5
if ! kill -0 "${SIM_PID}" 2>/dev/null; then
  echo "error: simulator exited. Ports ${MOTOR_PORT}/${POSE_PORT} may be in use; try MUJOCO_TEST_MOTOR_PORT/MUJOCO_TEST_POSE_PORT." >&2
  exit 1
fi

echo "Starting udp_simulator_bridge_node (motor_speeds -> sim)..."
ros2 run mujoco_simulator_ros2 udp_simulator_bridge_node --ros-args \
  -p use_float64_motor_topic:=true \
  -p command_port:="${MOTOR_PORT}" &
BRIDGE_PID=$!
sleep 2

echo "Publishing /motor_speeds @ 20 Hz while viewer runs (~6s of motion)..."
timeout 6 ros2 topic pub --rate 20 /motor_speeds std_msgs/msg/Float64MultiArray \
  "{data: [15.0, 15.0, 15.0, 15.0, 15.0, 15.0]}" || true
sleep 0.5

echo "Sample /control_msg (expect motors[].speed == 15):"
if ! timeout 6 ros2 topic echo /control_msg --once | grep -q "speed: 15.0"; then
  echo "error: did not observe motors with speed 15.0 on /control_msg" >&2
  exit 1
fi

echo "OK — ROS2 pub → bridge → MuJoCo path verified."
ros2 topic pub --once /motor_speeds std_msgs/msg/Float64MultiArray \
  "{data: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]}" >/dev/null 2>&1 || true

if [[ "${MUJOCO_TEST_HEADLESS:-0}" != "1" ]]; then
  echo ""
  echo "MuJoCo viewer should stay open. You can publish more commands in another terminal, e.g.:"
  echo "  ros2 topic pub --rate 10 /motor_speeds std_msgs/msg/Float64MultiArray \\"
  echo "    '{data: [10.0, 10.0, 10.0, 10.0, 10.0, 10.0]}'"
  echo ""

  if [[ -n "${MUJOCO_TEST_VIEWER_HOLD_S+x}" ]]; then
    if [[ "${MUJOCO_TEST_VIEWER_HOLD_S}" == "0" ]]; then
      echo "MUJOCO_TEST_VIEWER_HOLD_S=0 — stopping sim + bridge now."
    else
      echo "Keeping sim + viewer ${MUJOCO_TEST_VIEWER_HOLD_S}s (MUJOCO_TEST_VIEWER_HOLD_S)."
      sleep "${MUJOCO_TEST_VIEWER_HOLD_S}"
    fi
  elif [[ -t 0 ]] && [[ "${MUJOCO_TEST_AUTO_EXIT:-0}" != "1" ]]; then
    echo "Press Enter here to stop the simulator and bridge (keep this terminal open)."
    read -r _
  else
    _hold=45
    [[ "${MUJOCO_TEST_AUTO_EXIT:-0}" == "1" ]] && _hold=20
    echo "Keeping sim + viewer ${_hold}s (no TTY or MUJOCO_TEST_AUTO_EXIT=1). Set MUJOCO_TEST_VIEWER_HOLD_S to force a duration."
    sleep "${_hold}"
  fi
fi
