"""Quaternion math in MuJoCo order [w, x, y, z] — no PyTorch dependency."""

from __future__ import annotations

import numpy as np


def quat_mul_wxyz(q1: np.ndarray, q2: np.ndarray) -> np.ndarray:
    """Hamilton product q1 * q2; both (..., 4) wxyz."""
    w1, x1, y1, z1 = np.split(q1, 4, axis=-1)
    w2, x2, y2, z2 = np.split(q2, 4, axis=-1)
    w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2
    x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2
    y = w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2
    z = w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2
    return np.concatenate([w, x, y, z], axis=-1)


def rotate_vec_wxyz(q: np.ndarray, v: np.ndarray) -> np.ndarray:
    """
    Apply rotation encoded by unit quaternion q (wxyz) to vectors v.
    Batches (N, 4) with (N, 3), or (1, 4) / (1, 3) broadcast along N.
    """
    q = np.asarray(q, dtype=np.float64)
    v = np.asarray(v, dtype=np.float64)
    if q.ndim == 1:
        q = q.reshape(1, -1)
    if v.ndim == 1:
        v = v.reshape(1, -1)
    nq, nv = q.shape[0], v.shape[0]
    if nq == 1 and nv > 1:
        q = np.repeat(q, nv, axis=0)
    elif nv == 1 and nq > 1:
        v = np.repeat(v, nq, axis=0)
    elif nq != nv:
        raise ValueError(f"rotate_vec_wxyz: batch mismatch q={q.shape} v={v.shape}")

    w = q[:, 0:1]
    r = q[:, 1:4]
    t = 2.0 * np.cross(r, v, axis=1)
    return v + w * t + np.cross(r, t, axis=1)
