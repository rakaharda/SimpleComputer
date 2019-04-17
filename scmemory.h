#ifndef SCMEMORY_H
#define SCMEMORY_H

#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>

#define MEMSIZE 100
#define FLAG_REG_SIZE 5
#define MEMORY_OVERFLOW 1
#define DIVIDED_BY_ZERO 2
#define OUT_OF_RANGE 3
#define CLOCK_ERROR 4
#define UNKNOWN_COMMAND 5
#define COMMAND_LENGTH 15

int memoryInit();
int memorySet(int address, int value);
int memoryGet(int address, int &value);
int memorySave(std::string filename);
int memoryLoad(std::string filename);
int regInit();
int regSet(int reg, int value);
int regGet(int reg, int *value);
int commandEncode(int command, int operand, int *value);
int commandDecode(int value, int *command, int *operand);
void printMemory();
#endif
