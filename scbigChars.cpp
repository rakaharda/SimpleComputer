#include "scbigChars.h"

int bc_printA(string str)
{
    printf("\E(0%s\E(B", str.c_str());
    return 1;
}

int bc_box(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
    if(x1 == 0 || y1 == 0 || x2 == 0 || y2 == 0)
        return 0;
    mt_gotoXY(y1, x1);
    bc_printA(ULCORNER);
    mt_gotoXY(y2, x1);
    bc_printA(URCORNER);
    mt_gotoXY(y1, x2);
    bc_printA(DLCORNER);
    mt_gotoXY(y2, x2);
    bc_printA(DRCORNER);
    for(unsigned i = x1 + 1; i < x2; i++)
    {
        mt_gotoXY(y1, i);
        bc_printA(HBORDER);
        mt_gotoXY(y2, i);
        bc_printA(HBORDER);
    }
    for(unsigned i = y1 + 1; i < y2; i++)
    {
        mt_gotoXY(i, x1);
        bc_printA(VBORDER);
        mt_gotoXY(i, x2);
        bc_printA(VBORDER);
    }
    return 1;
}

int bc_printBigChar(long big, unsigned x, unsigned y, Color fgColor, Color bgColor)
{
    for(int i = 0; i < 64; i++)
        {
            mt_setBgColor(bgColor);
            mt_setFgColor(fgColor);
            int cell = (big >> i) & 0x1;
            mt_gotoXY(i / 8 + y, i % 8 + x);
            if(cell == 0)
                bc_printA(" ");
            else
                bc_printA("a");
            mt_setBgColor(Color::DEFAULT);
            mt_setFgColor(Color::DEFAULT);
        }
    return 1;
}

int bc_setBigCharPos(long *big, unsigned x, unsigned y, bool value)
{
    if(x > 8 || y > 8 || x == 0 || y == 0)
        return 0;
    unsigned shift = (y - 1) * 8 + (x - 1);
    long long1 = 1;
    if(value == false)
        *big = *big & (~(long1 << shift));
    else
        *big = *big | (long1 << shift);
    return 1;
}

int bc_getBigCharPos(long *big, unsigned x, unsigned y, bool *value)
{
    if(x > 8 || y > 8)
        return 0;
    *value = (*big >> (x * 8 + y - 1)) & 0x1;
    return 1;
}

int bc_bigCharWrite(string filename, long *big, int count)
{
    ofstream f(filename);
    for(int i = 0; i < count; i++)
        f << *(big + i);
    return 1;
}

int bc_bigCharRead(string filename, long *big, int needCount, int *count)
{
    ifstream f(filename);
    int i = 0;
    while(f >> *(big + i))
    {
        if(i + 1 == needCount)
            break;
        i++;
    }
    if(i + 1 < needCount)
        *count = 0;
    else 
        *count = needCount;
    return 1;
}
