#ifndef SCMEMORY_H
#define SCMEMORY_H

#include <stdlib.h>
#include <stdio.h>
#include <fstream>

#define MEMSIZE 100
#define FLAG_REG_SIZE 5
#define MEMORY_OVERFLOW 1
#define DIVIDED_BY_ZERO 2
#define OUT_OF_RANGE 3
#define CLOCK_ERROR 4
#define UNKNOWN_COMMAND 5
#define COMMAND_LENGTH 15

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
int sc_regInit();
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int *value);
int sc_commandEncode(int command, int operand, int *value);
int sc_commandDecode(int value, int *command, int *operand);

#endif
