#ifndef SCBIGCHARSH
#define SCBIGCHARSH

#include "sccolors.h"
#include "scterminal.h"
#include <string>
#include <fstream>
#include <bitset>

#define DRCORNER "j"
#define URCORNER "k"
#define ULCORNER "l"
#define DLCORNER "m"
#define VBORDER  "q"
#define HBORDER  "x"
#define BIG1 0xC3C6CCC0C0C0C0C
#define BIG2 0x3CC3C3030C30C0FF
#define BIG3 0x3CC3030C0303C33C
#define BIG4 0x3363C3C3FF030303
#define BIG5 0xFFC0C03C0303C33C
#define BIG6 0x3CC3C0FCC3C3C33C
#define BIG7 0xFF03060C183060C0
#define BIG8 0x3CC3C33CC3C3C33C
#define BIG9 0x3CC3C3C33F03C33C
#define BIG0 0x3CC3C3C3C3C3C33C
#define BIGPLUS 0x3C3CFFFF3C3C00//0x3C3C3CFFFF3C3C3C
#define BIGMINUS 0xFFFF000000
#define BIGSPACE 0x0
using namespace std;

int printA(string str);
int Box(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
int printBigChar(long big, unsigned x, unsigned y, Color fgColor = DEFAULT, Color bgColor = DEFAULT);
int setBigCharPos(long &big, unsigned x, unsigned y, bool value);
bool getBigCharPos(long big, unsigned x, unsigned y);
int bigCharWrite(string filename, long big, int count);
long bigCharRead(string filename, int needCount, int &count);

#endif 