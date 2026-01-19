import socket
from typing import List, Optional, Tuple


class UdpClient:
    def __init__(self, ip: str, port: int, buffer_size: int = 255) -> None:
        self.buffer_size = buffer_size
        self.sock_receive = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock_send = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock_receive.bind((ip, port))

    def send(self, payload: str, addr: Tuple[str, int]) -> None:
        self.sock_send.sendto(payload.encode('utf-8'), addr)

    def recv_packet(
        self,
    ) -> Tuple[str, Optional[List[float]], Tuple[str, int]]:
        data, addr = self.sock_receive.recvfrom(self.buffer_size)
        received_data = data.decode('utf-8', errors='replace')
        try:
            sensor_values = received_data.split()
            sensor_array = [float(value) for value in sensor_values]
        except ValueError:
            return received_data, None, addr
        return received_data, sensor_array, addr
