#include "scrun.h"

int CU()
{
    int command, operand;
    if (commandDecode(memoryGet(getIC()), command, operand) == 0)
    {
        regSet(FLAG_INTERRUPT, 1);
        regSet(UNKNOWN_COMMAND, 1);
        return -1;
    }
    switch (command)
    {
    case 0x10: //READ
        gotoXY(1, 23);
        cout << "> ";
        int temp;
        cin >> temp;
        memorySet(operand, temp);
        increaseIC();
        break;
    case 0x11: //WRITE
        gotoXY(1, 24);
        cout << memoryGet(operand);
        increaseIC();
        break;
    case 0x20: //LOAD
        setAcc(memoryGet(operand));
        increaseIC();
        break;
    case 0x21: //STORE
        memorySet(operand, getAcc());
        increaseIC();
        break;
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x66: //ADD SUB DIVIVE MUL SUBC
        ALU(command, operand);
        increaseIC();
        break;
    case 0x40: //JUMP
        setIC(operand);
        break;
    case 0x41: //JNEG
        if (getAcc() < 0)
            setIC(operand);
        else
            increaseIC();
        break;
    case 0x42: //JZ
        if (getAcc() == 0)
            setIC(operand);
        else
            increaseIC();
        break;
    case 0x43: //HALT
        regSet(FLAG_INTERRUPT, 1);
        alarm(0);
        break;
    default:
        regSet(FLAG_INTERRUPT, 1);
        regSet(UNKNOWN_COMMAND, 1);
        return -1;
    }
    return 0;
}

int ALU(int command, int operand)
{
    switch (command)
    {
    case 0x30:  //ADD
        setAcc(getAcc() + memoryGet(operand));
        break;
    case 0x31:  //SUB
        setAcc(getAcc() - memoryGet(operand));
        break;
    case 0x32:  //DIVIDE
        setAcc(getAcc() / memoryGet(operand));
        break;
    case 0x33:  //MUL
        setAcc(getAcc() * memoryGet(operand));
        break;
    case 0x66:  //SUBC 
        setAcc(memoryGet(operand) - getAcc());
        break;
    }
    return 0;
}