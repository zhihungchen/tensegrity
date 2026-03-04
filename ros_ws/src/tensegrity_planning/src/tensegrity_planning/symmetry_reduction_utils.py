"""
Symmetry reduction for tensegrity gaits: map bottom nodes to gait permutations.
Used by A* / MPC to transform base gaits (roll, cw, ccw) for the current pose.
"""
import numpy as np

symmetry_mapping = {(0,2,5):[0,1,2,3,4,5],(0,3,5):[0,1,2,3,4,5],
		   (1,2,4):[1,2,0,4,5,3],(1,2,5):[1,2,0,4,5,3],
		   (0,3,4):[2,0,1,5,3,4],(1,3,4):[2,0,1,5,3,4]}

reverse_mapping = {(0,2,5):[3,5,4,0,2,1],(0,3,5):[3,5,4,0,2,1],
			(1,2,4):[4,3,5,1,0,2],(1,2,5):[4,3,5,1,0,2],
			(0,3,4):[5,4,3,2,1,0],(1,3,4):[5,4,3,2,1,0]}

next_nodes = {(0,2,5):(1,2,4),(0,3,5):(1,2,4),
			(1,2,4):(0,3,4),(1,2,5):(0,3,4),
			(0,3,4):(0,2,5),(1,3,4):(0,2,5)}

prev_nodes = {(0,2,5):(1,3,4),(0,3,5):(1,3,4),
			  (0,3,4):(1,2,5),(1,3,4):(1,2,5),
			  (1,2,4):(0,3,5),(1,2,5):(0,3,5)}


def transform_gait(gait, bottom_nodes):
	"""gait: N x 6 numpy array. bottom_nodes: 3-tuple of lowest nodes. Returns permuted gait."""
	mapping = symmetry_mapping.get(bottom_nodes)
	if mapping is None:
		return None
	new_gait = np.array([[step[m] for m in mapping] for step in gait])
	return new_gait


def reverse_gait(gait, bottom_nodes):
	"""Reverse gait for backward rolling."""
	mapping = reverse_mapping.get(bottom_nodes)
	if mapping is None:
		return None
	new_gait = np.array([[step[m] for m in mapping] for step in gait])
	return new_gait
