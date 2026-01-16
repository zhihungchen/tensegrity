#!/usr/bin/env python3
from tensegrity_driver.robot_config import RobotConfig
from tensegrity_driver.robot_driver import TensegrityRobot


def main():
    cfg = RobotConfig()
    node = TensegrityRobot(cfg)
    node.run()


if __name__ == '__main__':
    main()