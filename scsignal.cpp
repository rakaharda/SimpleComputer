#include "scsignal.h"

void timer(int sig)
{
    printScreen();
    int temp = getIC();
    (temp < MEMSIZE - 1) ? setIC(temp + 1) : setIC(0);
    alarm(1);
}

void userTimer(int sig)
{
    alarm(0);
    regInit();
    regSet(FLAG_INTERRUPT, 1);
    setIC(0);
}