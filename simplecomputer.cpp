#include "scmemory.h"
#include "scterminal.h"
#include "scbigChars.h"
#include <bitset>
#include <iostream>
#include <iomanip>

using namespace std;

void printExtendedCharset();
void printScreen();

int main()
{
    clearScreen();
    printScreen();
    gotoXY(1, 13);
    return 0;
}

void printScreen()
{
    //memoryInit();
    Box(1, 1, 61, 12);
    gotoXY(26, 1);
    cout << " Memory ";
    gotoXY(1, 1);
    for(int i = 0; i <= 99; i++)
    {
        if(i % 10 == 0 )
            gotoXY(2, i / 10 + 2);
        int temp;
        memoryGet(i, temp);
        cout << ((temp >= 0) ? '+' : '-') << setfill('0') << setw(4) << hex << temp;
        if(i % 10 != 9)
        {
            cout << ' ';
        }
    }
}
void printExtendedCharset()
{
    char *a = new char;
    for(int i  = 97; i < 126; i++)
    {
        *a = i;
        printf("\n%s =", a);
        printA(a);
    }
}