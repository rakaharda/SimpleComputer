#include "scmemory.h"
#include "scterminal.h"
#include "scbigChars.h"
#include <bitset>
#include <iostream>

using namespace std;

void printExtendedCharset();

int main()
{
    clearScreen();
    //Box(3, 3, 12, 12);
    printBigChar(BIGPLUS, 1, 1);
    printBigChar(BIGMINUS, 1, 10);
    return 0;
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