#include "scbigChars.h"

int printA(string str)
{
    printf("\E(0%s\E(B", str.c_str());
    return 1;
}

int Box(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
    if(x1 == 0 || y1 == 0 || x2 == 0 || y2 == 0)
        return 0;
    gotoXY(y1, x1);
    printA(ULCORNER);
    gotoXY(y2, x1);
    printA(URCORNER);
    gotoXY(y1, x2);
    printA(DLCORNER);
    gotoXY(y2, x2);
    printA(DRCORNER);
    for(unsigned i = x1 + 1; i < x2; i++)
    {
        gotoXY(y1, i);
        printA(HBORDER);
        gotoXY(y2, i);
        printA(HBORDER);
    }
    for(unsigned i = y1 + 1; i < y2; i++)
    {
        gotoXY(i, x1);
        printA(VBORDER);
        gotoXY(i, x2);
        printA(VBORDER);
    }
    return 1;
}

int printBigChar(long big, unsigned x, unsigned y, Color fgColor, Color bgColor)
{
    bitset<64> b(big);
    for(int i = 0; i < 64; i++)
        {
            setBgColor(bgColor);
            setFgColor(fgColor);
            gotoXY(i % 8 + x, i / 8 + y);
            if(b[63 - i] == 0)
                printA(" ");
            else
                printA("a");
            setBgColor(Color::DEFAULT);
            setFgColor(Color::DEFAULT);
        }
    return 1;
}

int setBigCharPos(long &big, unsigned x, unsigned y, bool value)
{
    if(x > 8 || y > 8 || x == 0 || y == 0)
        return 0;
    unsigned shift = (y - 1) * 8 + (x - 1);
    long long1 = 1;
    bitset<64> b(big);
    b[shift] = value;
    big = b.to_ulong();
    return 1;
}

bool getBigCharPos(long big, unsigned x, unsigned y)
{
    if(x > 8 || y > 8)
        return 0;
    bitset<64> b(big);
    unsigned shift = (y - 1) * 8 + (x - 1);
    return (bool)b[shift];
}

int bigCharWrite(string filename, long &big, int count)
{
    ofstream f(filename);
    bitset<64> b(big);
    for(int i = 0; i < count; i++)
        f << b[i];
    return 1;
}

long bigCharRead(string filename, int needCount, int &count)
{
    ifstream f(filename);
    int i = 0;
    bitset<64> b;
    bool temp;
    while(f >> temp)
    {
        b[i] = temp;
        if(i + 1 == needCount)
            break;
        i++;
    }
    if(i + 1 < needCount)
        count = 0;
    else 
        count = needCount;
    return b.to_ulong();
}
