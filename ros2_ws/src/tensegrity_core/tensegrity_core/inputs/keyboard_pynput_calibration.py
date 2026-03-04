from tensegrity_core.command_bus import CommandBus

class PynputCalibrationKeyboard:
    """
    q: quit (also stop)
    s: stop motors
    0..5: select motor
    hold f: jog forward (+)
    hold b: jog backward (-)
    release f/b: stop jog
    """
    def __init__(self, bus: CommandBus):
        self.bus = bus
        self.listener = None
        self._keyboard = None
        self._f_down = False
        self._b_down = False

    def start(self):
        from pynput import keyboard
        self._keyboard = keyboard
        self.listener = keyboard.Listener(on_press=self.on_press, on_release=self.on_release)
        self.listener.daemon = True
        self.listener.start()

    def stop(self):
        try:
            if self.listener:
                self.listener.stop()
        except Exception:
            pass

    def on_press(self, key):
        print("[kbd] Key pressed:", key)
        try:
            ch = getattr(key, "char", None)  
            if ch is None:
                return

            if ch == 'q':
                self.bus.request_quit()
                return

            if ch == 's':
                self.bus.request_stop()
                self.bus.clear_level_controls()
                return

            if ch in "012345":
                self.bus.select_motor(int(ch))
                return

            if ch == 'f':
                self._f_down = True
                self.bus.set_jog(direction=+1, active=True)
                return

            if ch == 'b':
                self._b_down = True
                self.bus.set_jog(direction=-1, active=True)
                return

        except Exception as e:
            print("[kbd] on_press exception:", repr(e))


    def on_release(self, key):
        try:
            ch = getattr(key, "char", None)
            if ch is None:
                return

            if ch == 'f':
                self._f_down = False
                if not self._b_down:
                    self.bus.set_jog(direction=0, active=False)
                else:
                    self.bus.set_jog(direction=-1, active=True)

            elif ch == 'b':
                self._b_down = False
                if not self._f_down:
                    self.bus.set_jog(direction=0, active=False)
                else:
                    self.bus.set_jog(direction=+1, active=True)

        except Exception as e:
            print("[kbd] on_release exception:", repr(e))

