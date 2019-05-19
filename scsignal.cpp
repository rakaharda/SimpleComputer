#include "scsignal.h"

void timer(int sig)
{
    if(!regGet(FLAG_INTERRUPT))
    {
        printScreen();
        CU();
        alarm(1);
    }
    else
    {
        alarm(0);
        printScreen();
    }
    
}

void userTimer(int sig)
{
    alarm(0);
    regSet(FLAG_INTERRUPT, 1);
    CU();
}