#include "scmemory.h"
#include "scterminal.h"

int main()
{
    mt_clrscr();
    mt_setBgColor(Color::BLACK);
    mt_setFgColor(Color::DEFAULT);
    unsigned long long x;
    x = x | 0xFFFFFFFFFFFFFFFFFFFFFFFF;
    printf("%lli", x);
    return 0;
}