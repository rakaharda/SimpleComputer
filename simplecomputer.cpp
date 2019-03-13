#include "scmemory.h"
#include "scterminal.h"
#include "scbigChars.h"

void printExtendedCharset();

int main()
{
    mt_clrscr();
    mt_setBgColor(Color::BLACK);
    mt_setFgColor(Color::DEFAULT);
    bc_box(0, 0, 5, 10);
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