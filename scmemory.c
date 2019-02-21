#include "scmemory.h"

int sc_memoryInit()
{
    for(int i = 0; i < MEMSIZE; i++)
        sc_memory[i] = 0;
    return MEMSIZE;
}

int sc_memorySet(int address, int value)
{
    if(address > MEMSIZE)
        return 0;
    sc_memory[address] = value;
    return 1;
}

int sc_memoryGet(int address, int *value)
{
    if(address > MEMSIZE)
        return 0;
    *value = sc_memory[address];
    return 1;
}

int sc_memorySave(char *filename)
{
    FILE* f = fopen(filename, "wb");
    if(f == NULL)
        return 0;
    if(fwrite(sc_memory, sizeof(int), MEMSIZE, f) != MEMSIZE)
        return 0;
    return 1;
    
}

int sc_memoryLoad(char *filename)
{
    FILE* f = fopen(filename, "rb");
    if(f == NULL)
        return 0;
    if(fread(sc_memory, sizeof(int), MEMSIZE, f) != MEMSIZE)
        return 0;
    return 1;
}

int sc_regInit()
{
    sc_flag_reg = 0;
    return 1;
}

int sc_regSet(int reg, int value)
{
    if(reg >= FLAG_REG_SIZE)
        return 0;
    if(value == 0)
        sc_flag_reg = sc_flag_reg & (~(1 << (reg - 1)));
    else if (value == 1)
        sc_flag_reg = sc_flag_reg | (1 << (reg - 1));
    else 
        return 0;
    return 1;
}

int sc_regGet(int reg, int *value)
{
    if(reg >= FLAG_REG_SIZE)
        return 0;
    *value = (sc_flag_reg >> (reg - 1)) & 0x1;
    return 1;
}

int sc_commandEncode(int command, int operand, int *value)
{
    if(operand > 127 || command > 127)
        return 0;
    *value = 0;
    int temp;
    temp = command;
    *value = operand;
    temp = temp << 7;
    *value = *value | temp;
    return 1;
}

int sc_commandDecode(int value, int *command, int *operand)
{
    if((value) >> (COMMAND_LENGTH - 1) & 0x1)
        return 0;
    int temp;
    temp = value;
    temp = temp >> 7;
    *command = temp;
    temp = value;
    temp = temp & 0x000000FF;
    temp = temp & (~(1 << 7));
    *operand = temp;
    return 1;
}