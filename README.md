# DWM Build
My heavily customized build of dwm, with the following patches applied (in this order):

- **dwm-fullgaps** adds gaps between windows and the bar
- **dwm-pertag** allows the user to have different layouts active on different tags/workspaces
- **dwm-autostart** Allows dwm to read the script ~/.dwm/autostart.sh at startup, to launch programs after dwm itself
- **dwm-systray** Adds a simple sistray at the right edge of the bar
- **dwm-attachaside** Open new windows in the (slave) stack instead of opening it as the master window.
- **dwm-rotatestack** allows dwm to move windows along the stack (top of the stack == master window) using Mod+Shift+j/k
- **dwm-rmaster** enable the user to place the master pane on the right side of the screen instead of left (configurable)
- **dwm-selfrestart** allows dwm to restart itself upon pressing a keybind (only sorta works)
    this patch is not strictly needed for functionality, can be skipped if patching vanilla dwm from scratch
- **dwm-statusallmons** Allows the status bar to bw shown on all monitors, thought the systray will only appear on the the focused monitor
- **dwm-showselmon** Visually shows what monitor is currently being focused, by reversing the colors of the status bar on the unfocused monitors.
- **dwm-tagothermonitor** Adds new keybinds to send/focus windows to a specific tag on other monitors
- **dwm-xrdb** adds support for Xresources/pywal inside dwm

## Installation
- Configure to taste by adjusting settings in config.def.h
- Simply run `make` then `sudo make install`
- run `make clean` before you build again, 
  otherwise you will use config files and binaries from the previous build and your config changes will not take effect

## Further documentation
For information on keybinds look at the man page provided with this build of dwm: `dwm(1)`.
Documentation for other user-accessible options if provided in the source code, consult `config.def.h`.
