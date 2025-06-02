# Cooper Black's Wine Launcher
Ultra minimalist way to launch Windows software (.exe) from Linux. Useful for gaming, i guess.

Written in C, for the world to see.

🍷 Wine (the alcoholic drink) is unhealthy in real life.

### Dependencies
Better make sure to hit up `sudo apt install libgtk-3-dev` for the `source-gtk-gnome.c` version. (More versions coming ~~soon~~ later)

![](/Screenshot%20from%202025-06-02%2015-03-51.png)

### Compilation
Easy-peasy, lemon squeezy.

```
gcc `pkg-config --cflags gtk+-3.0` -o OUTPUT SOURCE `pkg-config --libs gtk+-3.0`
```
Ignore errors like this:

![](/Screenshot%20from%202025-06-02%2015-05-03.png)

### Execution
Just find the .exe file and run!

![](/Screenshot%20from%202025-06-02%2015-05-18.png)

Terrible concept, I know. But who cares?
