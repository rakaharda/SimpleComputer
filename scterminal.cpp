#include "scterminal.h"

int mt_clrscr ()
{
    printf("\E[H\E[2J");
    return 1;
}

int mt_gotoXY(int row, int column)
{
    printf("\E[%d;%dH", row, column);
    return 1;
}

int mt_getScreenSize(int *rows, int *columns)
{
    struct winsize ws;
    if (!ioctl(1, TIOCGWINSZ, &ws))
    {
        *rows = ws.ws_row;
        *columns = ws.ws_col;
    }
    else
    {
        return 0;
    }
    return 1;
}

int mt_setFgColor(Color color)
{
    printf("\E[%dm", ((int)color)- 10);
    return 1;
}

int mt_setBgColor(Color color)
{
    printf("\E[%dm", (int)color);
    return 1;
}