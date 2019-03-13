#include "scbigChars.h"

int bc_printA(char *str)
{
    printf("\E(0%s\E(B", str);
    return 1;
}

int bc_box(int x1, int y1, int x2, int y2)
{
    mt_gotoXY(x1, y1);
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
        {
            if(i == x1 && j == y1)
                bc_printA(ULCORNER);
            else if(i == x1 && j == y2)
                bc_printA(URCORNER);
            else if(i == x2 && j == y1)
                bc_printA(DLCORNER);
            else if(i == x2 && j == y2)
                bc_printA(DRCORNER);
            else if (i == x1 || i == x2)
                bc_printA(VBORDER);
            else if (j == y1 || j == y2)
                bc_printA(HBORDER);
            else
                printf(" ");
            if(j == y2)
                printf("\n");
        }
    return 1;
}

int bc_printBigChar(int *big, int x, int y, Color fgColor, Color bgColor)
{
    
    return 1;
}

int bc_setBigCharPos(int *big, int x, int y, int value)
{
    
    return 1;
}

int bc_getBigCharPos(int *big, int x, int y, int *value)
{
    
    return 1;
}

int bc_bigCharWrite(int fd, int *big, int count)
{
    
    return 1;
}

int bc_bigCharRead(int fd, int *big, int needCount, int *count)
{
    
    return 1;
}
