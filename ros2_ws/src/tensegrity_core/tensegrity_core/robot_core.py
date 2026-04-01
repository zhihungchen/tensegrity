#!/usr/bin/env python3
import os
import time
import math
from math import cos, sin
import json
import threading
import xlrd
import numpy as np
from scipy.spatial.transform import Rotation as R
from tensegrity_core.udp_client import UdpClient
from tensegrity_core.command_bus import CommandBus

#from tensegrity_interfaces.msg import Motor, Info, Sensor, Imu, TensegrityStamped

from tensegrity_core.robot_config import RobotConfig
from tensegrity_core.state_snapshot import RobotStateSnapshot
from tensegrity_core.controllers.gait_pid import GaitPidController


class FileError(Exception):
    pass

class S_Q_Pressed(Exception):
    pass

class TensegrityCore:
    def __init__(self, cfg: RobotConfig, udp_client: UdpClient = None):
        
        # --- from config ---#
        self.cfg = cfg

        self.num_sensors = cfg.num_sensors
        self.num_motors = cfg.num_motors
        self.num_imus = cfg.num_imus
        self.num_arduino = cfg.num_arduino
        self.min_length = cfg.min_length

        self.pos = [0] * cfg.num_motors
        self.cap = [0] * cfg.num_sensors
        self.length = [0] * cfg.num_sensors
        self.imu = [[0, 0, 0]] * cfg.num_imus
        self.error = [0] * cfg.num_motors
        self.prev_error = [0] * cfg.num_motors
        self.cum_error = [0] * cfg.num_motors
        self.d_error = [0] * cfg.num_motors
        self.command = [0] * cfg.num_motors
        self.speed = [0] * cfg.num_motors

        self.flip = list(cfg.flip) # flip direction of motors

        self.accelerometer = [[0]*3 for _ in range(3)]
        self.gyroscope = [[0]*3 for _ in range(3)]

        self.encoder_counts = [0]*cfg.num_motors
        self.encoder_length = [0]*cfg.num_motors

        self.RANGE = cfg.RANGE
        self.LEFT_RANGE = cfg.LEFT_RANGE
        self.max_speed = cfg.max_speed
        self.init_speed = cfg.init_speed

        self.tol = cfg.tol
        self.low_tol = cfg.low_tol
        self.P = cfg.P
        self.I = cfg.I
        self.D = cfg.D

        self.gear_ratio = cfg.gear_ratio
        self.winch_diameter = cfg.winch_diameter
        self.encoder_resolution = cfg.encoder_resolution

        # UDP variables
        self.UDP_IP = cfg.UDP_IP  # Listen to all incoming interfaces
        self.UDP_PORT = cfg.UDP_PORT     # Same port used in the Arduino sketch
        print("Running UDP connection with Arduino's: ")
        self.udp_client = udp_client if udp_client is not None else UdpClient(self.UDP_IP, self.UDP_PORT, self.cfg.recv_buf_size)
        #self.addresses = [("172.16.71.78",11311), ("172.16.71.79",11311), ("172.16.71.80",11311)] #[None] * self.num_arduino
        self.addresses = [None] * self.num_arduino
        self.offset = None # Nb of leading end ending 0 preventing errors 

        # Test
        self.record_fp = None


        # --- robot states ---#
        self.num_steps = None
        self.state = None
        self.states = None
        self.control_pub = None
        #self.my_listener = None
        self.keep_going = True
        self.quitting = False
        self.calibration = False
        self.done = None
        self.m = None
        self.b = None
        self.stop_msg = None
        self.which_Arduino = None
        
        # keyboard variables for testing
        self.armed = True      #default: motors OFF

        # --- control / input --- #
        self.bus = CommandBus()
        self.kbd = None
        self._last_sent = None  # optional: avoid spamming identical command

        self.current_motor_speeds = [0] * self.num_motors

        # Background RX: recv -> parse -> latest state (no control policy in this thread).
        self._state_lock = threading.RLock()
        self._rx_stop = threading.Event()
        self._rx_thread = None
        self._rx_started = False
        self._last_udp_debug_t = 0.0

    #----------------------------------------------------------------------#
    def load_states_from_json(self, path):
        try:
            with open(path, 'r') as f:
                data = json.load(f)
                self.states = np.array(data["states"])
                self.num_steps = len(self.states)
                self.state = 0
                self.done = [False] * self.num_motors
                print(f"[INFO] Loaded gait from {path}, total steps: {self.num_steps}")
        except Exception as e:
            print(f"[ERROR] Failed to load gait from {path}: {e}")
            self.states = np.ones((1, self.num_motors))  # fallback
            self.num_steps = 1

    def initialize(
            self,
            *, 
            mode: str = "basic",
            calibration_file: str = None,
            states_path: str = None
        ):

        # ---- control input selection ----
        self.kbd = None

        # containers
        self.inputs = []

        # 1) load states
        if states_path is not None:
            self.load_states_from_json(states_path)

        # 2) load calibration (calibration mode 可能需要)
        if calibration_file is not None:
            self.m, self.b = self.read_calibration_file(calibration_file)

        # 3) select input by mode
        if mode == "basic":
            from tensegrity_core.inputs.keyboard_pynput_basic import PynputBasicKeyboard
            kbd = PynputBasicKeyboard(self.bus)
            kbd.start()
            self.inputs.append(kbd)
            print("[INFO] Mode=basic (pynput / X11)")

        elif mode == "ssh":
            from tensegrity_core.inputs.keyboard_stdin_basic import StdinBasicKeyboard
            kbd = StdinBasicKeyboard(self.bus)
            kbd.start()
            self.inputs.append(kbd)
            print("[INFO] Mode=ssh (stdin)")

        elif mode == "calibration":
            # try pynput first, fallback stdin
            kbd = None
            try:
                from tensegrity_core.inputs.keyboard_pynput_calibration import PynputCalibrationKeyboard
                kbd = PynputCalibrationKeyboard(self.bus)
                kbd.start()
                print("[INFO] Mode=calibration (pynput)")
            except Exception as e:
                print(f"[WARN] pynput calibration unavailable: {e}")

            if kbd is None:
                from tensegrity_core.inputs.keyboard_stdin_basic import StdinBasicKeyboard
                kbd = StdinBasicKeyboard(self.bus)
                kbd.start()
                print("[INFO] Mode=calibration (stdin)")

            self.inputs.append(kbd)

        else:
            raise ValueError(f"Unknown mode: {mode}")


    # ---- rest of init ----
        
        # rospy.init_node('tensegrity_driver', anonymous=True)
        # self.control_pub = rospy.Publisher('control_msg', TensegrityStamped, queue_size=10) ## correct ??

        # package_path = rospkg.RosPack().get_path('tensegrity_driver')
        #self.m = np.array([0.04437, 0.06207, 0.02356, 0.04440, 0.04681, 0.05381, 0.02841, 0.03599, 0.03844])
        #self.b = np.array([15.763, 13.524, 15.708, 10.084, 15.628, 15.208, 16.356, 12.575, 13.506])
        
        """
        # # BEST GAIT
        # quasi-static rolling
        states = np.array([[0.0, 1.0, 0.1, 0.0, 1.0, 1.0], [0.8, 0.1, 1.0, 1.0, 0.1, 1.0], [0.8, 0.1, 0.0, 1.0, 1.0, 0.0], [0.1, 1.0, 1.0, 0.1, 1.0, 1.0], [0.1, 0.0, 1.0, 1.0, 0.0, 1.0],[0.8, 1.0, 0.1, 1.0, 1.0, 0.1]])#6 steps gait
        states = np.array([[0.0, 1.0, 0.1, 0.0, 1.0, 1.0],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0]])#steps gait
        states = np.array([[0.0, 1.0, 1.0, 0.0, 1.0, 0.1],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0]]) # one step and recover
        """
        # self.states = np.array([[1.0, 1.0, 0.1, 1.0, 1.0, 0.1],[0.0, 1.0, 1.0, 0.0, 0.8, 0.1],[1.0, 0.1, 1.0, 1.0, 0.1, 1.0],[1.0, 1.0, 0.0, 0.8, 0.1, 0.0],[0.1, 1.0, 1.0, 0.1, 1.0, 1.0],[1.0, 0.0, 1.0, 0.1, 0.0, 0.8]]) # quasi-static rolling
        #self.states = np.array([[1, 1, 1, 0, 1, 1], [1, 0, 1, 0, 1, 1], [0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1]]) # counterclockwise
        #self.states = np.array([[0, 0, 0, 1, 0, 1], [0, 0, 0, 0, 0, 0.7], [0, 0, 0.7, 0, 1, 1], [1, 1, 1, 1, 1, 1]]) # clockwise 
        #self.states = np.array([[1, 1, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0], [0, 1, 1, 0, 0.8, 0], [1, 1, 1, 1, 1, 1], [1, 0, 1, 0, 0, 0], [1, 0, 0, 0, 0, 0], [1, 1, 0, 0.8, 0, 0], [1, 1, 1, 1, 1, 1], [0, 1, 1, 0, 0, 0], [0, 0, 1, 0, 0, 0], [1, 0, 1, 0, 0, 0.8], [1, 1, 1, 1, 1, 1]]) #clockwise
        # self.states = np.array([[0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1]]) # counterclockwise
        # self.states = np.array([[1,1,1,1,1,1],[0.2,1,1,1,1,1],[1,1,1,1,1,1],[1,0.2,1,1,1,1],[1,1,1,1,1,1],[1,1,0.2,1,1,1],[1,1,1,1,1,1],[1,1,1,0.2,1,1],[1,1,1,1,1,1],[1,1,1,1,0.2,1],[1,1,1,1,1,1],[1,1,1,1,1,0.2]])
        # self.states = np.array([[1.0, 1.0, 0.1, 1.0, 1.0, 0.1],[0.0, 1.0, 1.0, 0.0, 1, 0.1],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],[1.0, 0.1, 1.0, 1.0, 0.1, 1.0],[1.0, 1.0, 0.0, 1.0, 0.1, 0.0],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],[0.1, 1.0, 1.0, 0.1, 1.0, 1.0],[1.0, 0.0, 1.0, 0.1, 0.0, 1.0],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0]]) # quasi-static rolling

        # self.states = np.array([[1.0,1.0,1.0,1.0,1.0,1.0],
        #                    [0.2,1.0,1.0,1.0,1.0,1.0],
        #                    [1.0,1.0,1.0,1.0,1.0,1.0],
        #                    [1.0,0.2,1.0,1.0,1.0,1.0],
        #                    [1.0,1.0,1.0,1.0,1.0,1.0],
        #                    [1.0,1.0,0.2,1.0,1.0,1.0],
        #                    [1.0,1.0,1.0,1.0,1.0,1.0],
        #                    [1.0,1.0,1.0,0.2,1.0,1.0],
        #                    [1.0,1.0,1.0,1.0,1.0,1.0],
        #                    [1.0,1.0,1.0,1.0,0.2,1.0],
        #                    [1.0,1.0,1.0,1.0,1.0,1.0],
        #                    [1.0,1.0,1.0,1.0,1.0,0.2]]) # testing one at a time
    


        # self.states = np.array([[1.0, 1.0, 0.1, 1.0, 1.0, 0.1],[0.0, 1.0, 1.0, 0.0, 1.0, 0.1],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        #                         [1.0, 0.1, 1.0, 1.0, 0.1, 1.0],[1.0, 1.0, 0.0, 1.0, 0.1, 0.0],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        #                         [0.1, 1.0, 1.0, 0.1, 1.0, 1.0],[1.0, 0.0, 1.0, 0.1, 0.0, 1.0],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0]]) # quasi-static rolling with rest states
        

        #self.num_steps = len(self.states)
        #self.state = 0
        self.offset = self.cfg.offset
        #self.done = np.array([False] * self.num_motors)
        self.stop_msg = ' '.join(['0'] * (self.num_motors+2*self.offset))
        #self.init_speed = 70


        # self.states = np.array([[0, 0, 0, 1, 0, 1], [0, 0, 0, 0, 0, 1], [0, 0, 0.7, 0, 1.2, 1], [1, 1, 1, 1, 1, 1], [0, 0, 0, 1, 1, 0], [0, 0, 0, 1, 0, 0], [0.7, 0, 0, 1, 0, 1.2], [1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 1, 1], [0, 0, 0, 0, 1, 0], [0, 0.7, 0, 1.2, 1, 0], [1, 1, 1, 1, 1, 1]]) # cw
        # self.states = np.array([[1, 1, 1, 0, 1, 1], [1, 0, 1, 0, 1, 1], [0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1]]) # ccw

        # single step of cw
        # self.states = np.array([[0, 0, 0, 1, 0, 1], [0, 0, 0, 0, 0, 1], [0, 0, 0.7, 0, 1.2, 1], [1, 1, 1, 1, 1, 1]]) # 1st step
        # self.states = np.array([[0, 0, 0, 1, 1, 0], [0, 0, 0, 1, 0, 0], [0.7, 0, 0, 1, 0, 1.2], [1, 1, 1, 1, 1, 1]]) # 2nd step
        # self.states = np.array([[0, 0, 0, 0, 1, 1], [0, 0, 0, 0, 1, 0], [0, 0.7, 0, 1.2, 1, 0], [1, 1, 1, 1, 1, 1]]) # 3rd step

        # cw345 first step
        # self.states = np.array([[1, 1, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0], [0, 1, 1, 0, 0.7, 0], [1, 1, 1, 1, 1, 1]])
        # all steps
        # self.states = np.array([[1, 1, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0], [0, 1, 1, 0, 0.8, 0], [1, 1, 1, 1, 1, 1], [1, 0, 1, 0, 0, 0], [1, 0, 0, 0, 0, 0], [1, 1, 0, 0.8, 0, 0], [1, 1, 1, 1, 1, 1], [0, 1, 1, 0, 0, 0], [0, 0, 1, 0, 0, 0], [1, 0, 1, 0, 0, 0.8], [1, 1, 1, 1, 1, 1]])

        # crawling cw ABC
        # self.states = np.array([[0,0,0,0.1,0.1,0.1],[0,0,0,1,0.1,1],[0,0,0,1,1,0.1]])
        # DEF
        # self.states = np.array([[0.1,0.1,0.1,0,0,0],[1,1,0.1,0,0,0],[0.1,1,1,0,0,0]])

        # back and forth for demos
        # states = np.array([[1.0, 1.0, 0.1, 1.0, 1.0, 0.1],[0.1, 1.0, 1.0, 0.1, 1.0, 0.1],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        #                    [1.0, 0.1, 1.0, 1.0, 0.1, 1.0],[1.0, 1.0, 0.1, 1.0, 0.1, 0.1],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        #                    [0.1, 1.0, 1.0, 0.1, 1.0, 1.0],[1.0, 0.1, 1.0, 0.1, 0.1, 1.0],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        #                    [1.0, 0.1, 1.0, 1.0, 0.1, 1.0],[0.1, 0.1, 1.0, 0.1, 1.0, 1.0],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        #                    [1.0, 1.0, 0.1, 1.0, 1.0, 0.1],[1.0, 0.1, 0.1, 1.0, 0.1, 1.0],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0],
        #                    [0.1, 1.0, 1.0, 0.1, 1.0, 1.0],[0.1, 1.0, 0.1, 1.0, 1.0, 0.1],[1.0, 1.0, 1.0, 1.0, 1.0, 1.0]]) # quasi-static rolling with rest states
        
        # ---- controller ----

        if self.states is not None:
            self.controller = GaitPidController(
                cfg=self.cfg,
                states=self.states,
                stop_msg=self.stop_msg,
                offset=self.offset
            )



    def read_calibration_file(self, filename):
        try : 
            if filename[-4:] == '.xls':
                # hand calibration excel file
                workbook = xlrd.open_workbook(filename)
                shortsheet = workbook.sheet_by_name('Short Sensors')
                longsheet = workbook.sheet_by_name('Long Sensors')
                m = np.array([float(shortsheet.cell_value(9, col)) for col in range(0, 12, 2)] +
                            [float(longsheet.cell_value(10, col)) for col in range(0, 6, 2)])
                b = np.array([float(shortsheet.cell_value(9, col)) for col in range(1, 13, 2)] +
                            [float(longsheet.cell_value(10, col)) for col in range(1, 7, 2)])
            elif filename[-5:] == '.json':
                # autocalibration JSON file
                data = json.load(open(filename))
                m = np.array(data.get('m'))
                b = np.array(data.get('b'))
            else:
                raise FileError('Invalid calibration file')
            return m, b
        except FileError as ce:
            print("Error occurred:", ce)

    def quat2vec(self, q):
        q0 = float(q[0])
        q1 = float(q[1])
        q2 = float(q[2])
        q3 = float(q[3])
        roll = -math.atan2(2*(q0*q1+q2*q3), 1-2*(q1*q1+q2*q2))#convert quarternion to Euler angle for roll angle
        #convert quarternion to Euler angle for pitch angle
        sinp = 2*(q0*q2-q3*q1)
        #deal with gimlock
        if abs(sinp) >= 1:
            pitch = math.copysign(np.pi/2, sinp)
        else:
            pitch = math.asin(sinp)
        
        #yaw = -math.atan2(2*(q0*q3+q1*q2), 1-2*(q2*q2+q3*q3))-np.pi/2
        #convert quarternion to Euler angle for pitch angle
        yaw = -math.atan2(2*(q0*q3+q1*q2), 1-2*(q2*q2+q3*q3))+np.pi/2

        k=np.array([cos(yaw)*cos(pitch), sin(pitch),sin(yaw)*cos(pitch)])
        r = R.from_rotvec(-np.pi/2 * np.array([0, 1, 0]))
        k = r.apply(k)
        y=np.array([0,1,0])
        s=np.cross(k,y)
        v=np.cross(s,k)
        vrot=v*cos(roll)+np.cross(k,v)*sin(roll)
        return np.cross(k,vrot)

    def send_command(self, input_string, addr, delay_time):
        #self.sock_send.sendto(input_string.encode('utf-8'), addr)
        self.udp_client.send(input_string, addr)
        if delay_time < 0:
            delay_time = 0
        time.sleep(delay_time/1000)

    def _send_stop_to_addrs(self, addrs):
        """Send stop command to each address (caller must not hold _state_lock)."""
        for addr in addrs:
            if addr is not None:
                self.send_command(self.stop_msg, addr, 0)

    def stop_all(self):
        with self._state_lock:
            addrs = list(self.addresses)
        self._send_stop_to_addrs(addrs)

    def start(self):
        """Start one background RX thread: recv -> parse -> update latest state."""
        if self._rx_started:
            return
        self._rx_stop.clear()
        self._rx_thread = threading.Thread(
            target=self._rx_thread_main, name="tensegrity_udp_rx", daemon=True
        )
        self._rx_thread.start()
        self._rx_started = True

    def stop(self):
        """Stop RX thread (closes recv socket so recvfrom unblocks)."""
        if not self._rx_started:
            return
        self._rx_stop.set()
        closer = getattr(self.udp_client, "close_recv", None)
        if callable(closer):
            closer()
        if self._rx_thread is not None:
            self._rx_thread.join(timeout=2.0)
        self._rx_thread = None
        self._rx_started = False

    def _rx_thread_main(self):
        while not self._rx_stop.is_set():
            try:
                received_data, sensor_array, addr = self.udp_client.recv_packet()
            except OSError:
                break
            except Exception:
                if self._rx_stop.is_set():
                    break
                continue
            try:
                to_stop = self._apply_udp_packet(received_data, sensor_array, addr)
                if to_stop:
                    self._send_stop_to_addrs(to_stop)
            except Exception:
                pass

    def _maybe_debug_rx(self, received_data, sensor_array, addr):
        if not self.cfg.debug_udp:
            return
        now = time.monotonic()
        if now - self._last_udp_debug_t < self.cfg.debug_udp_min_interval_s:
            return
        self._last_udp_debug_t = now
        n = len(sensor_array) if sensor_array is not None else 0
        preview = received_data[:120] + ("..." if len(received_data) > 120 else "")
        print(f"[UDP debug] addr={addr} floats={n} data={received_data}")

    def _apply_udp_packet(self, received_data, sensor_array, addr):
        """
        Parse one datagram; update state under lock.
        Returns a list of addresses to send stop to (empty if none). Caller sends without lock.
        """
        stop_targets = []
        with self._state_lock:
            self._maybe_debug_rx(received_data, sensor_array, addr)
            if sensor_array is None:
                return []

            if addr not in self.addresses:
                self.addresses[int(sensor_array[0])] = addr

            if self.record_fp is not None and received_data:
                self.record_fp.write(received_data.strip() + "\n")

            """
            3-bar tensegrity layout (from original read()):
            Rod 0: sensors C,E,I (2,4,8), motors 2,4
            Rod 1: sensors B,D,H (1,3,7), motors 1,3
            Rod 2: sensors A,F,G (0,5,6), motors 0,5
            """
            if len(sensor_array) == 13:
                self.which_Arduino = int(sensor_array[0])
                if self.cfg.debug_udp and (
                    sensor_array[1] == 0.2
                    or sensor_array[2] == 0.2
                    or sensor_array[3] == 0.2
                ):
                    print(
                        "MPR121 or I2C of Arduino "
                        + str(self.which_Arduino)
                        + " wrongly initialized, please reboot Arduino"
                    )

                if int(sensor_array[0]) == 0:
                    self.cap[4] = sensor_array[1]
                    self.cap[2] = sensor_array[2]
                    self.cap[8] = sensor_array[3]
                    self.encoder_counts[4] = sensor_array[6]
                    self.encoder_counts[2] = sensor_array[5]
                if int(sensor_array[0]) == 1:
                    self.cap[3] = sensor_array[1]
                    self.cap[1] = sensor_array[2]
                    self.cap[7] = sensor_array[3]
                    self.encoder_counts[3] = sensor_array[6]
                    self.encoder_counts[1] = sensor_array[5]
                if int(sensor_array[0]) == 2:
                    self.cap[5] = sensor_array[1]
                    self.cap[0] = sensor_array[2]
                    self.cap[6] = sensor_array[3]
                    self.encoder_counts[5] = sensor_array[6]
                    self.encoder_counts[0] = sensor_array[5]

                self.encoder_length = [
                    counts
                    / self.encoder_resolution
                    / self.gear_ratio
                    * np.pi
                    * self.winch_diameter
                    for counts in self.encoder_counts
                ]

                if 0.2 not in self.cap:
                    for i in range(len(self.cap)):
                        self.length[i] = float((self.cap[i] - self.b[i]) / self.m[i])
                    for i in range(self.num_motors):
                        if i < 3:
                            self.pos[i] = float(
                                (self.length[i] - self.min_length) / self.LEFT_RANGE
                            )
                        else:
                            self.pos[i] = float(
                                (self.length[i] - self.min_length) / self.RANGE
                            )

                self.accelerometer[self.which_Arduino][0] = sensor_array[7]
                self.accelerometer[self.which_Arduino][1] = sensor_array[8]
                self.accelerometer[self.which_Arduino][2] = sensor_array[9]
                self.gyroscope[self.which_Arduino][0] = sensor_array[10]
                self.gyroscope[self.which_Arduino][1] = sensor_array[11]
                self.gyroscope[self.which_Arduino][2] = sensor_array[12]

            else:
                if None in self.addresses:
                    for i in range(len(self.addresses)):
                        if self.addresses[i] is None:
                            if self.cfg.debug_udp:
                                print(
                                    "Arduino "
                                    + str(i)
                                    + " wrongly initialized, please reboot Arduino"
                                )
                        else:
                            stop_targets.append(self.addresses[i])
                else:
                    if self.cfg.debug_udp:
                        print("[UDP] unexpected packet length; issuing stop")
                    stop_targets = [a for a in self.addresses if a is not None]

        return stop_targets

    def get_latest_state(self) -> RobotStateSnapshot:
        """Thread-safe copy of latest parsed robot state (for ROS publish / control)."""
        with self._state_lock:
            return RobotStateSnapshot(
                pos=list(self.pos),
                cap=list(self.cap),
                length=list(self.length),
                encoder_counts=list(self.encoder_counts),
                encoder_length=list(self.encoder_length),
                current_motor_speeds=list(self.current_motor_speeds),
                accelerometer=[row[:] for row in self.accelerometer],
                gyroscope=[row[:] for row in self.gyroscope],
                which_Arduino=self.which_Arduino,
                addresses=list(self.addresses),
            )

    def send_motor_speeds(self, speeds):
        """
        Primary TX API: full motor speed vector, broadcast to all known Arduinos.
        """
        if len(speeds) != self.num_motors:
            raise ValueError(
                f"Expected {self.num_motors} motor speeds, got {len(speeds)}"
            )
        with self._state_lock:
            if None in self.addresses:
                raise RuntimeError("Arduino addresses are not fully discovered yet")
            self.current_motor_speeds = [int(s) for s in speeds]
            cmd = self.build_motor_command(self.current_motor_speeds)
            addrs = [a for a in self.addresses if a is not None]
        for addr in addrs:
            self.send_command(cmd, addr, 0)

    def set_gait_state(self, index: int) -> None:
        """Set current gait step (for external/planning control). No ROS dependency."""
        if self.controller is not None:
            self.controller.set_gait_state(index)
        self.state = int(index) % self.num_steps if self.num_steps else 0

    def set_states(self, states) -> None:
        """Replace gait table and reset. Recreates internal controller."""
        self.states = np.array(states, dtype=float)
        self.num_steps = len(self.states)
        self.state = 0
        self.done = [False] * self.num_motors
        if self.controller is not None:
            self.controller.set_states(self.states)
        else:
            self.controller = GaitPidController(
                cfg=self.cfg,
                states=self.states,
                stop_msg=self.stop_msg,
                offset=self.offset
            )

    def _build_jog_msg(self, motor_idx: int, speed: int) -> str:
        msg = self.stop_msg.split()
        msg[self.offset + motor_idx] = str(speed)
        return " ".join(msg)

    def apply_manual_jog(self, intent):
        """
        Old behavior port:
        - selected_motor chooses motor
        - hold f/b => send speed command continuously (or at least once per loop)
        - release => send stop_msg
        """
        motor = intent.selected_motor
        if motor is None:
            return

        # Safety: bounds
        if not (0 <= motor < self.num_motors):
            return

        # If not active, ensure stop (like old on_release)
        if not intent.jog_active or intent.jog_dir == 0:
            if self._last_sent != self.stop_msg:
                self.stop_all()
                self._last_sent = self.stop_msg
            return

        # compute speed like old (respect flip)
        speed = int(self.init_speed) * int(intent.jog_dir) * int(self.flip[motor])
        out = self._build_jog_msg(motor, speed)

        # optional anti-spam: only send when changed
        if out == self._last_sent:
            return
        self._last_sent = out

        with self._state_lock:
            addrs = [a for a in self.addresses if a is not None]
        for addr in addrs:
            self.send_command(out, addr, 0)

    def is_ready(self) -> bool:
        with self._state_lock:
            return None not in self.addresses

    def build_motor_command(self, speeds):
        """
        Build one full command string from a motor speed vector.
        speeds: list of signed values, length = num_motors
        """
        if len(speeds) != self.num_motors:
            raise ValueError(
                f"Expected {self.num_motors} motor speeds, got {len(speeds)}"
            )

        msg = self.stop_msg.split()
        for i in range(self.num_motors):
            speed_i = int(speeds[i])
            msg[self.offset + i] = str(speed_i * int(self.flip[i]))
        return " ".join(msg)

    def motor_to_arduino(self, motor_id: int) -> int:
        mapping = {
            0: 2,
            5: 2,
            1: 1,
            3: 1,
            2: 0,
            4: 0,
        }
        return mapping[motor_id]

    def set_motor_speed(self, motor_id, speed):
        """Update one motor in the speed vector and send via send_motor_speeds."""
        if not (0 <= motor_id < self.num_motors):
            raise IndexError(f"motor_id {motor_id} out of range")
        with self._state_lock:
            speeds = list(self.current_motor_speeds)
        speeds[motor_id] = int(speed)
        self.send_motor_speeds(speeds)

    def read(self):
        """
        Blocking: receive and apply one packet. For CLI `run()` without start().
        Do not use together with start() on the same socket.
        """
        received_data, sensor_array, addr = self.udp_client.recv_packet()
        to_stop = self._apply_udp_packet(received_data, sensor_array, addr)
        if to_stop:
            self._send_stop_to_addrs(to_stop)


    # def compute_command(self) :
    #     command_msg = self.stop_msg.split()
    #     for i in range(self.num_motors):
    #         # two tolerances for shorter and longer commands
    #         if self.states[self.state, i] < 0.5:
    #             tolerance = self.low_tol
    #         else:
    #             tolerance = self.tol

    #         #check if motor reached the target
    #         if self.pos[i] + tolerance > self.states[self.state, i] and self.pos[i] - tolerance < self.states[self.state, i]:
    #             self.done[i] = True
    #             self.command[i] = 0
    #         if not self.done[i]:
    #             self.error[i] = self.pos[i] - self.states[self.state, i]
    #             self.d_error[i] = self.error[i] - self.prev_error[i]
    #             self.cum_error[i] = self.cum_error[i] + self.error[i]
    #             self.prev_error[i] = self.error[i]
    #             #update speed
    #             self.command[i] = max([min([self.P*self.error[i] + self.I*self.cum_error[i] + self.D*self.d_error[i], 1]), -1])
    #             self.speed[i] = self.command[i] * self.max_speed * self.flip[i]
    #             command_msg[i+self.offset] = str(self.speed[i])
                
    #     if all(self.done):
    #         self.state += 1
    #         self.state %= self.num_steps
    #         for i in range(self.num_motors):
    #             self.done[i] = False
    #             self.prev_error[i] = 0
    #             self.cum_error[i] = 0
    #     print('State: ',self.state)
    #     # print(state)
    #     print("Position: ",self.pos)
    #     print("Target: ",self.states[self.state])
    #     # print(pos)
    #     # print(states[state])
    #     print("Done: ",self.done)
    #     print("Length: ",self.length)
    #     print("Capacitance: ",self.cap)
    #     print(' '.join(command_msg))
    #     self.send_command(' '.join(command_msg), self.addresses[self.which_Arduino],0)
    #     #self.send_command(self.stop_msg, self.addresses[self.which_Arduino],0)
    #     print('+++++')

    #     return command_msg

    
    def run(self, calibration_file: str, states_path: str):
        print("Initializing")
        self.initialize(mode = "ssh", calibration_file = calibration_file, states_path = states_path)
        # finishing setup.
        print("Opened connection press s to stop motor and q to quit")
        while not self.quitting :
            try :
                intent = self.bus.snapshot()

                # edge flags -> apply to core state
                if intent.stop:
                    print("[INFO] STOP requested -> stopping motors")
                    self.keep_going = False
                    self.stop_all()

                if intent.armed_toggle:
                    self.armed = not self.armed
                    print("[INFO] Armed:", self.armed)

                if intent.quit:
                    print("[INFO] QUIT requested -> stopping motors and exiting")
                    self.stop_all()
                    self.quitting = True

                self.bus.clear_edge_flags()
 
                self.read()
                # manual jog for calibration
                self.apply_manual_jog(intent)

                # self.sendRosMSG()
                if self.keep_going and None not in self.addresses and self.armed:
                    msg, dbg = self.controller.step(self.pos)     # returns list[str]
                    self.send_command(' '.join(msg), self.addresses[self.which_Arduino], 0)
                    print('debug msg', dbg)

                # else:
                    # set duty cycle as 0 to turn off the motors
                    # for i in qend_command(self.stop_msg, self.addresses[i], 0)
                # if(self.calibration) :
                #     self.sendRosMSG()
                #     for i in range(self.num_sensors) :
                #         print(f"Capacitance {chr(i + 97)}: {self.cap[i]:.2f} \t Length: {self.length[i]:.2f} \n")
            except Exception as e:
                print("\nStopping motors")
                self.keep_going = False
                self.quitting = True
                # set duty cycle as 0 to turn off the motors
                for i in range(len(self.addresses)):
                    self.send_command(self.stop_msg, self.addresses[i], 0)

                print(f"Error type: {type(e).__name__}")
                print(f"Error message: {e}")
            
        
if __name__ == "__main__":
    import argparse
    from pathlib import Path

    # robot_core.py: .../tensegrity_core/src/tensegrity_core/robot_core.py
    THIS_FILE = Path(__file__).resolve()
    PKG_ROOT = THIS_FILE.parents[2]  # .../tensegrity_core (calibration/ states/ src/)
    DEFAULT_CALIB  = PKG_ROOT / "calibration" / "calibration_charles.xls"
    DEFAULT_STATES = PKG_ROOT / "states" / "quasi_static.json"

    parser = argparse.ArgumentParser()
    parser.add_argument("--calib",  type=str, default=str(DEFAULT_CALIB),
                        help="calibration file (.xls or .json)")
    parser.add_argument("--states", type=str, default=str(DEFAULT_STATES),
                        help="gait json file that contains {'states': ...}")

    parser.add_argument("--fake", action="store_true",
                    help="use fake UDP client (no hardware)")
    parser.add_argument("--hz", type=float, default=50.0,
                    help="fake UDP rate (Hz)")
    parser.add_argument("--record", type=str, default=None,
                    help="record received UDP packets to file")

    args = parser.parse_args()

    # quick sanity check: 
    if not Path(args.states).exists():
        raise FileNotFoundError(f"States file not found: {args.states}")
    if args.calib and not Path(args.calib).exists():
        raise FileNotFoundError(f"Calibration file not found: {args.calib}")

    cfg = RobotConfig()

    udp = None
    if args.fake:
        from tensegrity_core.fake_udp_client import FakeUdpClient
        udp = FakeUdpClient(
            num_arduino=cfg.num_arduino,
            port=cfg.UDP_PORT,
            hz=args.hz
        )

    core = TensegrityCore(cfg, udp_client=udp)

    # optional recording
    if args.record:
        core.record_fp = open(args.record, "a", buffering=1)

    core.run(args.calib, args.states)

    if core.record_fp:
        core.record_fp.close()


    
