#ifndef SCTERMINALH
#define SCTERMINALH

#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "sccolors.h"
#include <bitset>
#include <iostream>

int clearScreen ();
int gotoXY(int row, int column);
int getScreenSize(int *rows, int *columns);
int setFgColor(Color color);
int setBgColor(Color color);

#endif