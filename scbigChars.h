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
int bc_box(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
int bc_printBigChar(long long big, unsigned x, unsigned y, Color fgColor, Color bgColor);
int bc_setBigCharPos(long long *big, unsigned x, unsigned y, bool value);
int bc_getBigCharPos(long long *big, unsigned x, unsigned y, bool *value);
int bc_bigCharWrite(int fd, long long *big, int count);
int bc_bigCharRead(int fd, long long *big, int needCount, int *count);

#endif 