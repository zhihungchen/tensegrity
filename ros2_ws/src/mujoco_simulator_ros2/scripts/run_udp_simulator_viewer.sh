#!/usr/bin/env bash
# Run MuJoCo UDP simulator with interactive viewer + --no-ros.
# Uses vendored mujoco_simulator under this package. Requires: pip package "mujoco".
#
# If you see "No module named 'mujoco'", the `python3` on your PATH is not the one where
# MuJoCo is installed. Fix one of:
#   python3 -m pip install --user mujoco
#   MUJOCO_PYTHON=/path/to/python ./scripts/run_udp_simulator_viewer.sh
#
# Errno 98 "Address already in use" — UDP ports 2390 (motors) and 2391 (pose) are
# already bound. Only one tensegrity_udp_simulator (or launch-spawned sim) per machine.
#   Inspect:  ss -ulnp | grep -E '2390|2391'
#             sudo lsof -i UDP:2390 -i UDP:2391
#   Fix:     stop the other process, or use another motor port and match the bridge:
#             ./run_udp_simulator_viewer.sh /path/to/model.xml --port 2393
set -euo pipefail
PYTHON="${MUJOCO_PYTHON:-python3}"
PKG_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
XML="${1:-${PKG_ROOT}/xml_models/3bar_new_platform_all_cables.xml}"
UDP_SIM="${PKG_ROOT}/mujoco_simulator/tensegrity_udp_simulator.py"
export PYTHONPATH="${PKG_ROOT}:${PYTHONPATH:-}"
if ! "$PYTHON" -c "import mujoco" 2>/dev/null; then
  echo "error: MuJoCo Python package not found for: $PYTHON ($(command -v "$PYTHON" 2>/dev/null || true))" >&2
  echo "  Install:  $PYTHON -m pip install --user mujoco" >&2
  echo "  Or set MUJOCO_PYTHON to a Python that already has mujoco (e.g. conda env)." >&2
  exit 1
fi
if [[ ! -f "$UDP_SIM" ]]; then
  echo "error: missing $UDP_SIM (expected vendored mujoco_simulator in this package)" >&2
  exit 1
fi
if [[ ! -f "$XML" ]]; then
  echo "error: missing XML: $XML" >&2
  exit 1
fi
exec "$PYTHON" "$UDP_SIM" "$XML" --no-ros --viewer "${@:2}"
