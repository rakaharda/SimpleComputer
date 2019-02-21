#include "scmemory.h"
#include <malloc.h>

int main()
{
    int *value;
    int *command;
    int *operand;
    value = (int*) malloc(sizeof(int));
    command = (int*) malloc(sizeof(int));
    operand = (int*) malloc(sizeof(int));
    sc_commandEncode(10, 10, value);
    sc_commandDecode(*value, command, operand);
    printf ("%x %x %x", 10, *command, *operand);
    return 0;
}