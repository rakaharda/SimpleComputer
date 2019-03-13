#ifndef SCBIGCHARSH
#define SCBIGCHARSH

#include "sccolors.h"
#include "scterminal.h"

#define DRCORNER "j"
#define URCORNER "k"
#define ULCORNER "l"
#define DLCORNER "m"
#define VBORDER  "q"
#define HBORDER  "x"

int bc_printA(char *str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_printBigChar(int *big, int x, int y, Color fgColor, Color bgColor);
int bc_setBigCharPos(int *big, int x, int y, int value);
int bc_getBigCharPos(int *big, int x, int y, int *value);
int bc_bigCharWrite(int fd, int *big, int count);
int bc_bigCharRead(int fd, int *big, int needCount, int *count);

#endif 