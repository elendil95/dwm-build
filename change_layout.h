#ifndef _CHANGE_LAYOUT_H_
#define _CHANGE_LAYOUT_H_

#include <string.h>
#include <stdlib.h>
#include <X11/XKBlib.h>

#define LEN(x) (sizeof (x) / sizeof *(x))

static int valid_layout_or_variant(char *sym) {
	size_t i;
	/* invalid symbols from xkb rules config */
	static const char *invalid[] = { "evdev", "inet", "pc", "base" };

	for (i = 0; i < LEN(invalid); i++)
		if (!strcmp(sym, invalid[i]))
            return 0;

	return 1;
}

static char* get_layout() {
    Display *dpy;
	XkbDescRec *desc;
	XkbStateRec state;
	char *symbols, *tok, *layout;
	int grp;
	
    layout = NULL;

	dpy = XOpenDisplay(NULL);
	desc = XkbAllocKeyboard();
	XkbGetNames(dpy, XkbSymbolsNameMask, desc);
	XkbGetState(dpy, XkbUseCoreKbd, &state);
	symbols = XGetAtomName(dpy, desc->names->symbols);

	layout = NULL;
	tok = strtok(symbols, "+:");
	for (grp = 0; tok && grp <= state.group; tok = strtok(NULL, "+:")) {
		if (!valid_layout_or_variant(tok)) {
			continue;
		} else if (strlen(tok) == 1 && tok[0] >= '0' && tok[0] <= '9') {
			/* ignore :2, :3, :4 (additional layout groups) */
			continue;
		}
		layout = tok;
		grp++;
	}

	return layout;
}

static void change_layout() {
  char* curr_layout = get_layout(), command[13] = "setxkbmap ";
  int i = 0;
  for (; i < LEN(kblayouts); ++i)
    if (!strcmp(curr_layout, kblayouts[i]))
      break;
  
  if (i == LEN(kblayouts) - 1)
    i = 0;
  else
    ++i;
  system(strcat(command, kblayouts[i]));
}
#endif // _CHANGE_LAYOUT_H_

