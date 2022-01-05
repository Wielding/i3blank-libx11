# i3blank-libx11

This app is just a window that will close when you hit enter or space while it is focused.

This is a pure X11 version of [i3blank](https://github.com/Wielding/i3blank) project which uses gtk3.

It's only purpose is as a placeholder if you want to take up a space in an i3 workspace. I have 3 monitors and sometimes
I want to force a window to be a quarter screen due to its ratio so I just fire up an i3blank with a keyboard shortcut
to arrange the tiles the way I want.

If you use compton you can make it invisible by adding the following to your compton.conf

opacity-rule = [ "00:class_g = 'I3blank'" ];

# Dependencies

This requires libx11-dev libs to be present on your system.