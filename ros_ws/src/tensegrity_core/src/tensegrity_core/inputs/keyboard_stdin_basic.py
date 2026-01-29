import sys
import threading
import termios
import tty
import select

from tensegrity_core.command_bus import CommandBus


class StdinBasicKeyboard:
    """
    SSH / terminal-friendly keyboard controller.

    Reads single characters from stdin (no Enter needed).

    Controls:
      g : toggle armed
      s : stop motors
      q : quit (stop + exit)
    """

    def __init__(self, bus: CommandBus):
        self.bus = bus
        self._thread = None
        self._stop_event = threading.Event()

    def start(self):
        self._thread = threading.Thread(target=self._loop, daemon=True)
        self._thread.start()

    def stop(self):
        self._stop_event.set()

    def _loop(self):
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)

        try:
            # Put terminal into cbreak mode (read 1 char immediately)
            tty.setcbreak(fd)

            while not self._stop_event.is_set():
                # Non-blocking wait for input
                rlist, _, _ = select.select([sys.stdin], [], [], 0.05)
                if not rlist:
                    continue

                ch = sys.stdin.read(1)

                if ch == 'q':
                    self.bus.request_quit()

                elif ch == 's':
                    self.bus.request_stop()

                elif ch == 'g':
                    self.bus.toggle_armed()

        except Exception:
            # Never crash robot_core from input thread
            pass

        finally:
            # Restore terminal settings
            try:
                termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
            except Exception:
                pass
