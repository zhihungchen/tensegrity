# tensegrity_core/inputs/keyboard_pynput_basic.py
from tensegrity_core.command_bus import CommandBus

class PynputBasicKeyboard:
    """
    q: quit (and stop)
    s: stop motors
    g: toggle armed

    NOTE:
    - Do NOT import pynput at module import time.
    - Import it lazily in start() so SSH (no X11) won't crash robot_core.
    """
    def __init__(self, bus: CommandBus):
        self.bus = bus
        self.listener = None
        self._keyboard = None  # pynput.keyboard module (lazy)

    def start(self):
        from pynput import keyboard  # <-- lazy import
        self._keyboard = keyboard
        self.listener = keyboard.Listener(on_press=self.on_press)
        self.listener.daemon = True
        self.listener.start()

    def stop(self):
        try:
            if self.listener:
                self.listener.stop()
        except Exception:
            pass

    def on_press(self, key):
        try:
            keyboard = self._keyboard
            if key == keyboard.KeyCode.from_char('q'):
                self.bus.request_quit()
            elif key == keyboard.KeyCode.from_char('s'):
                self.bus.request_stop()
            elif key == keyboard.KeyCode.from_char('g'):
                self.bus.toggle_armed()
        except Exception:
            pass
