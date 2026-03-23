"""Shared helpers for planner nodes calling tensegrity_perception services."""
from tensegrity_perception.srv import GetPose


def attach_get_pose_client(node, period_sec: float = 1.0):
    """Create a GetPose client and a timer that logs pose count when the service responds."""
    client = node.create_client(GetPose, 'get_pose')

    def _on_pose_done(future):
        try:
            resp = future.result()
            if resp.success:
                node.get_logger().info('get_pose: %d rod pose(s)' % len(resp.poses))
            else:
                node.get_logger().debug('get_pose: success=false (tracker not ready?)')
        except Exception as e:
            node.get_logger().debug('get_pose failed: %s' % (e,))

    def _poll():
        if not client.service_is_ready():
            return
        fut = client.call_async(GetPose.Request())
        fut.add_done_callback(_on_pose_done)

    timer = node.create_timer(period_sec, _poll)
    return client, timer
