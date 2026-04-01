import time
import math
from typing import List, Tuple, Optional, Iterable

Addr = Tuple[str, int]


class FakeUdpClient:
    """
    Fake replacement for UdpClient.
    Generates Arduino-like UDP packets.
    """

    def __init__(self, num_arduino: int, port: int, hz: float = 50.0):
        self.num_arduino = num_arduino
        self.port = port
        self.dt = 1.0 / max(hz, 1e-6)
        self.k = 0
        self.t0 = time.time()
        self._recv_closed = False

        self.addresses: List[Addr] = [
            (f"192.168.0.{100+i}", port) for i in range(num_arduino)
        ]

        self.sent_log = []

    def close_recv(self) -> None:
        """Signal RX loop to exit (no real socket)."""
        self._recv_closed = True

    def send(self, payload: str, addr: Addr):
        # 不送 UDP，只記錄
        self.sent_log.append((time.time(), addr, payload))

    def recv_packet(self):
        if self._recv_closed:
            raise OSError("FakeUdpClient recv closed")
        time.sleep(self.dt)
        t = time.time() - self.t0

        arduino_id = self.k % self.num_arduino
        addr = self.addresses[arduino_id]

        # --- fake sensor values (match your real logs) ---
        cap_base = {
            0: (19.1, 17.8, 20.8),
            1: (16.9, 13.7, 22.1),
            2: (18.2, 18.6, 24.7),
        }
        b1, b2, b3 = cap_base.get(arduino_id, (18, 18, 22))

        cap1 = b1 + 0.1 * math.sin(t)
        cap2 = b2 + 0.1 * math.sin(t + 1)
        cap3 = b3 + 0.1 * math.sin(t + 2)

        v4 = 13.7 + 0.03 * math.sin(0.5 * t)

        enc0 = 0.0
        enc1 = 0.0

        ax = 0.3 * math.sin(t)
        ay = 0.3 * math.cos(t)
        az = 0.9

        gx = 0.5 * math.sin(t)
        gy = 0.5 * math.cos(t)
        gz = 0.0

        sensor_array = [
            float(arduino_id),
            cap1, cap2, cap3,
            v4,
            enc0, enc1,
            ax, ay, az,
            gx, gy, gz
        ]

        received_data = " ".join(f"{v:.2f}" for v in sensor_array)

        self.k += 1
        return received_data, sensor_array, addr
