#!/usr/bin/env python3
import time
import argparse
from pathlib import Path

from tensegrity_core.robot_core import TensegrityCore
from tensegrity_core.robot_config import RobotConfig


def build_all_motor_command(core: TensegrityCore, speed: int) -> str:
    """
    Build one command string that drives all motors at the same signed speed.
    Applies core.flip so physical direction stays consistent.
    """
    msg = core.stop_msg.split()
    for i in range(core.num_motors):
        msg[core.offset + i] = str(int(speed) * int(core.flip[i]))
    return " ".join(msg)


def wait_for_addresses(core: TensegrityCore, timeout_sec: float) -> bool:
    """
    Wait until all Arduino addresses are discovered from incoming UDP packets.
    Returns True if all addresses are found before timeout.
    """
    start = time.time()
    while time.time() - start < timeout_sec:
        core.read()
        if None not in core.addresses:
            return True
    return False


def parse_manual_addresses(addr_list):
    """
    Parse address strings like:
        172.16.71.74:2390 172.16.71.76:2390 172.16.71.78:2390
    into:
        [("172.16.71.74", 2390), ...]
    """
    parsed = []
    for item in addr_list:
        ip, port = item.split(":")
        parsed.append((ip, int(port)))
    return parsed


def main():
    parser = argparse.ArgumentParser(
        description="Send all motors forward, then backward, then stop."
    )
    parser.add_argument(
        "--speed",
        type=int,
        default=30,
        help="Motor speed magnitude (start small for safety).",
    )
    parser.add_argument(
        "--forward-seconds",
        type=float,
        default=1.0,
        help="Duration to run forward.",
    )
    parser.add_argument(
        "--backward-seconds",
        type=float,
        default=1.0,
        help="Duration to run backward.",
    )
    parser.add_argument(
        "--discover-timeout",
        type=float,
        default=5.0,
        help="Seconds to wait for Arduino address discovery.",
    )
    parser.add_argument(
        "--mode",
        type=str,
        default="basic",
        choices=["basic", "ssh", "calibration"],
        help="initialize(...) input mode. ssh is safest for terminal use.",
    )
    parser.add_argument(
        "--calib",
        type=str,
        default=None,
        help="Optional calibration file path. Not needed for this pre-test.",
    )
    parser.add_argument(
        "--states",
        type=str,
        default=None,
        help="Optional gait states path. Not needed for this pre-test.",
    )
    parser.add_argument(
        "--addresses",
        nargs="*",
        default=None,
        help='Optional manual addresses like "172.16.71.74:2390" "172.16.71.76:2390".',
    )

    args = parser.parse_args()

    cfg = RobotConfig()
    core = TensegrityCore(cfg)

    calib_path = str(Path(args.calib).resolve()) if args.calib else None
    states_path = str(Path(args.states).resolve()) if args.states else None

    print("[INFO] Initializing core...")
    core.initialize(
        mode=args.mode,
        calibration_file=calib_path,
        states_path=states_path,
    )

    # Optional manual address override
    if args.addresses:
        manual_addresses = parse_manual_addresses(args.addresses)
        for i in range(min(len(manual_addresses), core.num_arduino)):
            core.addresses[i] = manual_addresses[i]

    # If some addresses are still unknown, discover them from incoming packets
    if None in core.addresses:
        print("[INFO] Waiting for Arduino address discovery...")
        ok = wait_for_addresses(core, args.discover_timeout)
        if not ok:
            print("[ERROR] Could not discover all Arduino addresses.")
            print("[INFO] Current addresses:", core.addresses)
            core.stop_all()
            return

    print("[INFO] Ready. Arduino addresses:", core.addresses)

    forward_cmd = build_all_motor_command(core, args.speed)
    backward_cmd = build_all_motor_command(core, -args.speed)

    try:
        print("[INFO] Sending FORWARD:", forward_cmd)
        for addr in core.addresses:
            if addr is not None:
                core.send_command(forward_cmd, addr, 0)
        time.sleep(args.forward_seconds)

        print("[INFO] Sending BACKWARD:", backward_cmd)
        for addr in core.addresses:
            if addr is not None:
                core.send_command(backward_cmd, addr, 0)
        time.sleep(args.backward_seconds)

    finally:
        print("[INFO] Sending STOP")
        core.stop_all()


if __name__ == "__main__":
    main()