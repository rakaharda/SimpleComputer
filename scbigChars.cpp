#include "scbigChars.h"

int bc_printA(char *str)
{
    printf("\E(0%s\E(B", str);
    return 1;
}

int bc_box(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
    mt_gotoXY(x1, y1);
    bc_printA(ULCORNER);
    mt_gotoXY(x1, y2);
    bc_printA(URCORNER);
    mt_gotoXY(x2, y1);
    bc_printA(DLCORNER);
    mt_gotoXY(x2, y2);
    bc_printA(DRCORNER);
    for(unsigned i = x1 + 1; i < x2; i++)
    {
        mt_gotoXY(i, y1);
        bc_printA(HBORDER);
        mt_gotoXY(i, y2);
        bc_printA(HBORDER);
    }
    for(unsigned i = y1 + 1; i < y2; i++)
    {
        mt_gotoXY(x1, i);
        bc_printA(VBORDER);
        mt_gotoXY(x2, i);
        bc_printA(VBORDER);
    }
    return 1;
}

int bc_printBigChar(long long big, unsigned x, unsigned y, Color fgColor, Color bgColor)
{
    for(int i = 0; i < 64; i++)
        {
            mt_setBgColor(bgColor);
            mt_setFgColor(fgColor);
            int cell = (big >> i) & 0x1;
            mt_gotoXY(i % 8 + x, i / 8 + y);
            if(cell == 0)
                bc_printA(" ");
            else
                bc_printA("a");
            mt_setBgColor(Color::DEFAULT);
            mt_setFgColor(Color::DEFAULT);
        }
    return 1;
}

int bc_setBigCharPos(long long *big, unsigned x, unsigned y, bool value)
{
    if(x > 7 || y > 7)
        return 0;
    if(value == false)
        *big &= (~(1 << (x * 8 + y)));
    else
        *big |= (1 << (x * 8 + y));
    return 1;
}

int bc_getBigCharPos(long long *big, unsigned x, unsigned y, bool *value)
{
    if(x > 8 || y > 8)
        return 0;
    *value = (*big >> (x * 8 + y - 1)) & 0x1;
    return 1;
}

int bc_bigCharWrite(int fd, long long *big, int count)
{
    
    return 1;
}

int bc_bigCharRead(int fd, long long *big, int needCount, int *count)
{
    
    return 1;
}
