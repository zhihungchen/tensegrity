import numpy as np

class GaitPidController:
    """
    Legacy controller: same logic as original compute_command() but:
    - does NOT send UDP
    - returns (command_msg_list, debug_dict)
    """

    def __init__(self, cfg, states, stop_msg: str, offset: int):
        self.cfg = cfg
        self.states = np.array(states, dtype=float)

        self.num_motors = cfg.num_motors
        self.num_steps = len(self.states)
        self.state = 0

        # keep legacy arrays (same names)
        self.done = [False] * self.num_motors
        self.error = [0] * self.num_motors
        self.prev_error = [0] * self.num_motors
        self.cum_error = [0] * self.num_motors
        self.d_error = [0] * self.num_motors
        self.command = [0] * self.num_motors
        self.speed = [0] * self.num_motors

        # message layout belongs to "driver", but we keep it as input to preserve legacy output format
        self.stop_msg = stop_msg
        self.offset = offset

    def step(self, pos, length=None, cap=None):
        """
        pos: list/np array, len=num_motors (core.pos)
        length/cap: optional, for debug only
        return:
          command_msg_list: list[str] (same as old compute_command returned)
          debug: dict (optional)
        """
        command_msg = self.stop_msg.split()

        for i in range(self.num_motors):
            # two tolerances for shorter and longer commands
            if self.states[self.state, i] < 0.5:
                tolerance = self.cfg.low_tol
            else:
                tolerance = self.cfg.tol

            # check if motor reached the target
            if pos[i] + tolerance > self.states[self.state, i] and pos[i] - tolerance < self.states[self.state, i]:
                self.done[i] = True
                self.command[i] = 0

            if not self.done[i]:
                self.error[i] = pos[i] - self.states[self.state, i]
                self.d_error[i] = self.error[i] - self.prev_error[i]
                self.cum_error[i] = self.cum_error[i] + self.error[i]
                self.prev_error[i] = self.error[i]

                # update speed 
                self.command[i] = max([min([self.cfg.P*self.error[i] + self.cfg.I*self.cum_error[i] + self.cfg.D*self.d_error[i], 1]), -1])
                self.speed[i] = self.command[i] * self.cfg.max_speed * self.cfg.flip[i]
                command_msg[i + self.offset] = str(self.speed[i])

        if all(self.done):
            self.state += 1
            self.state %= self.num_steps
            for i in range(self.num_motors):
                self.done[i] = False
                self.prev_error[i] = 0
                self.cum_error[i] = 0

        debug = {
            "state": self.state,
            "pos": list(pos),
            "target": self.states[self.state].tolist(),
            "done": list(self.done),
            "length": None if length is None else list(length),
            "cap": None if cap is None else list(cap),
            "msg": " ".join(command_msg),
        }
        return command_msg, debug

    def set_gait_state(self, index: int) -> None:
        """Set current gait step index (for external/planning control)."""
        self.state = int(index) % self.num_steps
        for i in range(self.num_motors):
            self.done[i] = False
            self.prev_error[i] = 0
            self.cum_error[i] = 0

    def set_states(self, states) -> None:
        """Replace gait table and reset step index."""
        self.states = np.array(states, dtype=float)
        self.num_steps = len(self.states)
        self.state = 0
        for i in range(self.num_motors):
            self.done[i] = False
            self.prev_error[i] = 0
            self.cum_error[i] = 0
