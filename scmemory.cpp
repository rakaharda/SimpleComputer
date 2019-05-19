#include "scmemory.h"

using namespace std;

vector<int> memory(MEMSIZE);
bitset<5> flagRegister;
int instructionCounter = 0;
int accumulator = 0;

using namespace std;

int memoryInit()
{
    for(int i = 0; i < MEMSIZE; i++)
        memory[i] = 0;
    return MEMSIZE;
}

int memorySet(int address, int value)
{
    if(address >= MEMSIZE)
        return 0;
    memory[address] = value;
    return 1;
}

int memoryGet(int address, int &value)
{
    if(address >= MEMSIZE)
        return 0;
    value = memory[address];
    return 1;
}

int memoryGet(int address)
{
   if(address >= MEMSIZE)
        return 0;
    return memory[address];
}

int memorySave(string filename)
{
	ofstream file(filename, ios::binary);
	for(int i = 0; i < MEMSIZE; i++)
		file.write((char*)&memory[i], sizeof(int));
	return 1;    
}

int memoryLoad(string filename)
{
    ifstream file(filename, ios::binary);
    if(!file)
        return 0;
    for(int i = 0; i < MEMSIZE; i++)
        file.read((char*)&memory[i], sizeof(int));
    return 1;
}

int regInit()
{
    flagRegister = 0;
    flagRegister[FLAG_INTERRUPT] = 1;
    return 1;
}

int regSet(int reg, int value)
{
    if(reg >= FLAG_REG_SIZE)
        return 0;
    flagRegister[reg] = value;
    return 1;
}

int regGet(int reg, int &value)
{
    if(reg >= FLAG_REG_SIZE)
        return 0;
    value = flagRegister[reg];
    return 1;
}

int regGet(int reg)
{
    if(reg >= FLAG_REG_SIZE)
        return 0;
    return flagRegister[reg];
}


int commandEncode(int command, int operand, int &value)
{
    if(operand > 127 || command > 127)
        return 0;
    bitset<15>temp(0);
    bitset<7> commandBit(command);
    bitset<7> operandBit(operand);
    for(int i = 0; i < 7; i++)
    {
        temp[i] = operandBit[i];
        temp[i + 7] = commandBit[i];
    }
    value = (int)(temp.to_ulong());
    return 1;
}

int commandDecode(int value, int &command, int &operand)
{
    bitset<15> valueBit(value);
    if(valueBit[14])
        return 0;
    bitset<7> commandBit(0);
    bitset<7> operandBit(0);
    for(int i = 0; i < 7; i++)
    {
        commandBit[i] = valueBit[i + 7];
        operandBit[i] = valueBit[i];
    }
    command = (int)commandBit.to_ulong();
    operand = (int)operandBit.to_ulong();
    return 1;
}

int getIC()
{
    return instructionCounter;
}

int getAcc()
{
    return accumulator;
}

int setIC(int value)
{
    if(value < 0 || value > MEMSIZE - 1)
        return 0;
    instructionCounter = value;
    return 1;
}

int setAcc(int value)
{
    accumulator = value;
}

void printMemory()
{
    cout << hex;
    for(auto& i : memory)
        cout << i << ' ';
    cout << dec;
}