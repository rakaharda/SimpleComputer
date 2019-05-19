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
#define MEMORY_OVERFLOW 0
#define DIVIDED_BY_ZERO 1
#define OUT_OF_RANGE 2
#define FLAG_INTERRUPT 3
#define UNKNOWN_COMMAND 4
#define COMMAND_LENGTH 15

int memoryInit();
int memorySet(int address, int value);
int memoryGet(int address, int &value);
int memoryGet(int address);
int memorySave(std::string filename);
int memoryLoad(std::string filename);
int regInit();
int regSet(int reg, int value);
int regGet(int reg, int &value);
int regGet(int reg);
int commandEncode(int command, int operand, int &value);
int commandDecode(int value, int &command, int &operand);
int getIC();
int increaseIC();
int getAcc();
int setIC(int value);
int setAcc(int value);
void printMemory();
#endif
