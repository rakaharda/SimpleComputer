#ifndef SCBIGCHARSH
#define SCBIGCHARSH

#include "sccolors.h"
#include "scterminal.h"
#include <string>
#include <fstream>

#define DRCORNER "j"
#define URCORNER "k"
#define ULCORNER "l"
#define DLCORNER "m"
#define VBORDER  "q"
#define HBORDER  "x"

using namespace std;

int bc_printA(string str);
int bc_box(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
int bc_printBigChar(long big, unsigned x, unsigned y, Color fgColor, Color bgColor);
int bc_setBigCharPos(long *big, unsigned x, unsigned y, bool value);
int bc_getBigCharPos(long *big, unsigned x, unsigned y, bool *value);
int bc_bigCharWrite(string filename, long *big, int count);
int bc_bigCharRead(string filename, long *big, int needCount, int *count);

#endif 