#include "sc.h"

int main()
{
    scInit();
    memorySet(3, 1234);
    while (true)
    {
        clearScreen();
        printScreen();
        gotoXY(1, 27);
        handleEvents();
    }
    return 0;
}

