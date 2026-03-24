#!/usr/bin/env bash
# Link tensegrity_perception into this workspace's src/ (sibling checkout layout).
# Usage (from ros2_ws): ./scripts/link_tensegrity_perception.sh [path_to_tensegrity_perception]
set -euo pipefail
ROS2_WS="$(cd "$(dirname "$0")/.." && pwd)"
SRC="$ROS2_WS/src"
# Default: sibling of tensegrity repo folder under the same parent src/ (e.g. catkin_ws_new/src/tensegrity/ros2_ws -> ../../tensegrity_perception)
TARGET="${1:-$ROS2_WS/../../tensegrity_perception}"
TARGET="$(cd "$TARGET" && pwd)"
ln -sfn "$TARGET" "$SRC/tensegrity_perception"
echo "Linked: $SRC/tensegrity_perception -> $TARGET"
