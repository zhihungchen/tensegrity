#!/usr/bin/env python3
from pathlib import Path
import argparse

from tensegrity_core.robot_config import RobotConfig
from tensegrity_core.robot_core import TensegrityCore
from tensegrity_core.command_bus import CommandBus
from tensegrity_core.inputs.keyboard_pynput_calibration import PynputCalibrationKeyboard


def main():
    # Resolve defaults relative to package root
    THIS_FILE = Path(__file__).resolve()
    # If this file is at: tensegrity_core/scripts/sensor_calibration.py
    PKG_ROOT = THIS_FILE.parents[2]  # .../tensegrity_core

    DEFAULT_CALIB  = PKG_ROOT / "calibration" / "calibration_charles.xls"

    parser = argparse.ArgumentParser(description="Sensor calibration monitor + manual motor jog")
    parser.add_argument("--calib", type=str, default=str(DEFAULT_CALIB),
                        help="calibration file (.xls or .json)")
    parser.add_argument("--fake", action="store_true",
                        help="use fake UDP client (no hardware)")
    parser.add_argument("--hz", type=float, default=50.0,
                        help="fake UDP rate (Hz)")
    parser.add_argument("--print_hz", type=float, default=5.0,
                        help="print rate (Hz)")
    args = parser.parse_args()

    # Sanity checks
    # if not Path(args.states).exists():
    #     raise FileNotFoundError(f"States file not found: {args.states}")
    if args.calib and not Path(args.calib).exists():
        raise FileNotFoundError(f"Calibration file not found: {args.calib}")

    cfg = RobotConfig()

    # Optional fake UDP
    udp = None
    if args.fake:
        from tensegrity_core.fake_udp_client import FakeUdpClient
        udp = FakeUdpClient(num_arduino=cfg.num_arduino, port=cfg.UDP_PORT, hz=args.hz)

    # Core
    core = TensegrityCore(cfg, udp_client=udp)
    core.initialize(mode = "calibration", calibration_file=args.calib)


    print("Sensor calibration monitor running.")
    print("Keys: 0..5 select motor | hold f forward | hold b backward | s stop | q quit")
    print("------------------------------------------------------------")

    try:
        while not core.quitting:
            # Update sensors
            core.read()
               
            if any(addr is not None for addr in core.addresses):
                print("=================")
                for i in range(cfg.num_sensors):
                    print(f"Capacitance {chr(i + 97)}: {core.cap[i]:.2f}\tLength: {core.length[i]:.2f}")
                print("=================")

            # Consume intents
            intent = core.bus.snapshot()

            if intent.stop:
                core.stop_all()
                # if you implemented this, it prevents “stuck jog”
                if hasattr(core.bus, "clear_level_controls"):
                    core.bus.clear_level_controls()

            if intent.quit:
                core.stop_all()
                core.quitting = True
                break

            # Apply manual jog (0..5 + f/b)
            if hasattr(core, "apply_manual_jog"):
                core.apply_manual_jog(intent)

            core.bus.clear_edge_flags()

    finally:
        # Always stop motors on exit
        try:
            core.stop_all()
        except Exception:
            pass

        # Stop keyboard listener
        try:
            if core.kbd:
                core.kbd.stop()
        except Exception:
            pass


if __name__ == "__main__":
    print("Starting sensor calibration monitor...")
    main()
