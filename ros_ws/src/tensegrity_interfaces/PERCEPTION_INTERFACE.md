# Perception interface contract

This repo relies on the external **tensegrity_perception** package for vision/tracking. The following contract must be provided (ROS1 or ROS2) so that `tensegrity_planning` and driver integration work.

## Services

### GetPose

- **Name:** `get_pose`
- **Type:** `tensegrity_perception/srv/GetPose`
- **Request:** (empty or as defined in tensegrity_perception)
- **Response:** `success: bool`, `poses: geometry_msgs/Pose[]` (or equivalent: position + orientation per bar/rod)
- **Usage:** Planning nodes call this to obtain current robot pose (COM, principal axis, endcaps) for closed-loop control.

### InitTracker

- **Name:** `init_tracker` (or as defined in tensegrity_perception)
- **Type:** `tensegrity_perception/srv/InitTracker`
- **Usage:** Driver or operator calls this to initialize the tracker (e.g. with initial images or calibration).

### GetBarHeight

- **Name:** `get_bar_height` (or as defined in tensegrity_perception)
- **Type:** `tensegrity_perception/srv/GetBarHeight`
- **Usage:** Optional; used by planning when bar height is needed.

## Notes

- The actual request/response field names and types are defined in the **tensegrity_perception** repository.
- For ROS2 migration, ensure the same service names and logically equivalent message types are used so that `tensegrity_planning` can call these services with minimal changes.
