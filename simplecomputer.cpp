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
    gotoXY(1, 12);
    return 0;
}

void printScreen()
{
    memoryInit();
    Box(1, 1, 61, 11);
    gotoXY(26, 1);
    cout << " Memory ";
    gotoXY(1, 2);
    ofstream out("123.txt");
    for(int i = 0; i < 99; i++)
    {
        if(i % 10 == 0 )
            cout << endl;
        int temp;
        memoryGet(i, temp);
        //printf(((temp >= 0) ? "+" : "-"));
        //printf("%04X", temp);
        out << ((temp >= 0) ? '+' : '-') << setfill('0') << setw(4) << hex << temp << endl;
        cout << ((temp >= 0) ? '+' : '-') << setfill('0') << setw(4) << hex << temp;
        if(i % 10 != 9)
            cout << ' ';
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