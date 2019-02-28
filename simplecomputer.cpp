#include "scmemory.h"
#include <malloc.h>
#include <iostream>

using namespace std;

void sc_printMemory()
{
	int *temp = new int;
    for(int i = 0; i < MEMSIZE; i++)
		{
			sc_memoryGet(i, temp);
			cout << *temp << " ";
		}
		cout << endl;
	delete(temp);
}

int main()
{
    sc_memoryInit();
    sc_memorySet(0, 8);
    sc_memorySet(1, 8);
    sc_memorySet(2, 8);
    sc_memorySet(99, 16);
    sc_printMemory();
    sc_memorySave("dimanloh");
    sc_memoryInit();
    sc_memoryLoad("dimanloh");
    sc_printMemory();
    return 0;
}
