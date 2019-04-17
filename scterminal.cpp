#include "scterminal.h"

using namespace std;

int clearScreen ()
{
    cout << "\E[H\E[2J";
    return 1;
}

int gotoXY(int column, int row)
{
    printf("\E[%d;%dH", row, column);
    //cout << "\E[" << row << ';' << column << 'H';
    return 1;
}

int getScreenSize(int *rows, int *columns)
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

int setFgColor(Color color)
{
    cout << "\E[" << (int)color - 10 <<'m';
    return 1;
}

int setBgColor(Color color)
{
    cout << "\E[" << (int)color << 'm';
    return 1;
}