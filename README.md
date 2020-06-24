# DWM Build
My heavily customized build of dwm, with the following patches applied (in this order):

- **dwm-fullgaps** adds gaps between windows and the bar
- **dwm-pertag** allows to have different layouts active on different tags/workspaces
- **dwm-autostart** Allows dwm to read the script ~/.dwm/autostart.sh at startup, to launch programs after dwm itself
- **dwm-systray** Adds a simple sistray at the right edge of the bar
- **dwm-attachaside** Open new windows in the (slave) stack instead of opening it as the master window.
- **dwm-rotatestack** allows dwm to move windows along the stack (top of the stack == master pane) using Mod+Shit+j/k
- **dwm-rmaster** enable the user to place te master pane on the right side of the screen instead of left (configurable)
- **dwm-selfrestart** allows dwm to restart itself upon pressing a keybind (only sorta works)
- **dwm-pywal** a custom patch that allows dwm to pull colors from pywal, for maximum *A E S T H E T I C*
    this patch is not strictly needed for functionality, can be skipped if patching vanilla dwm from scratch

## Installation
- Configure to taste by adjusting settings in config.def.h
- Simply run `make` then `sudo make install`
- run `make clean` before you biuld again, 
  otherwhise you will use config files and binaries from the old build and your config changes will not take effect

## Further documentation
look at the source code lmao, suckless software doesnt have documentation  ¯\_(ツ)_/¯
How dare you want basic information on the software you use, what are you some sort of stupid brainlet? (＃`Д´)

