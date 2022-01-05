#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    Display *d;
    Window w;
    XEvent e;
    XClassHint class;
    char appName[] = "I3blank";
    char className[] = "I3blank";

    int s;

    d = XOpenDisplay(NULL);
    if (d == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 100, 100, 1,
                            BlackPixel(d, s), WhitePixel(d, s));


    class.res_name = appName;
    class.res_class = className;

    XSetClassHint(d, w, &class);

    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapWindow(d, w);

    while (1) {
        XNextEvent(d, &e);
        if (e.type == Expose) {
            XFillRectangle(d, w, DefaultGC(d, s), 20, 20, 10, 10);
        }
        if (e.type == KeyPress)
            if (e.xkey.keycode == 53 || e.xkey.keycode == 104 || e.xkey.keycode == 65) {
                break;
            }
    }

    XCloseDisplay(d);
    return 0;
}