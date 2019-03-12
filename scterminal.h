#ifndef SCTERMINALH
#define SCTERMINALH

#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "sccolors.h"

int mt_clrscr ();
int mt_gotoXY(int row, int column);
int mt_getScreenSize(int *rows, int *columns);
int mt_setFgColor(Color color);
int mt_setBgColor(Color color);

#endif