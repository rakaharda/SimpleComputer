#include "sc.h"

int main()
{
    scInit();
    //test programm
    int command;
    commandEncode(0x10, 10, command); //READ 10
    memorySet(0, command);
    commandEncode(0x10, 11, command); //READ 11
    memorySet(1, command);
    commandEncode(0x20, 10, command); //LOAD 10
    memorySet(2, command);
    commandEncode(0x30, 11, command); //ADD 11
    memorySet(3, command);
    commandEncode(0x21, 12, command); //STORE 12
    memorySet(4, command);
    commandEncode(0x11, 12, command);
    memorySet(5, command);
    commandEncode(0x43, 0, command); //HALT
    memorySet(6, command);
    //
    clearScreen();
    while (true)
    {
        
        printScreen();
        gotoXY(1, 27);
        handleEvents();
    }
    return 0;
}

