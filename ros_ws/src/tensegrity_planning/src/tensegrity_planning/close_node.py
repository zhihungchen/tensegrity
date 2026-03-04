from scipy.spatial import KDTree

def is_point_within_distance(point, closed_list, distance):
    tree = KDTree(closed_list)
    indices = tree.query_ball_point(point, distance)
    return len(indices) > 0
