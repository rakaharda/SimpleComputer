#include "scmemory.h"
#include "scterminal.h"
#include "scbigChars.h"
#include <bitset>
#include <iostream>

using namespace std;

void printExtendedCharset();

int main()
{
    mt_clrscr();
    int command;
    int operand;
    int value;
    commandEncode(10, 11, &value);
    cout << value;
    commandDecode(value, &command, &operand);
    cout << endl << command << " " << operand;
    return 0;
}

void printExtendedCharset()
{
    char *a = new char;
    for(int i  = 97; i < 126; i++)
    {
        *a = i;
        printf("\n%s =", a);
        bc_printA(a);
    }
}