#include "scmemory.h"
#include "scterminal.h"
#include "scbigChars.h"

void printExtendedCharset();

int main()
{
    mt_clrscr();
    bc_box(3, 3, 12, 12);
    long long a = 0;
    //bc_setBigCharPos(&a, 1, 1, true);
    bc_setBigCharPos(&a, 0, 2, true);
    bc_printBigChar(a, 4, 4, Color::GREEN, Color::DEFAULT);
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