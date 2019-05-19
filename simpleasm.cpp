#include "scmemory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Not enough arguments! Use: sat in out";
    }
    int errorCount = 0;
    ifstream file(argv[1]);
    string str;
    vector<string> lines;
    memoryInit();
    while (getline(file, str))
    {
        lines.push_back(str);
    }
    for (auto &i : lines)
    {
        istringstream iss(i);
        vector<string> args(istream_iterator<string>{iss},
                            istream_iterator<string>());
        int address = stoi(args[0]);
        if (address > MEMSIZE - 1 || address < 0)
        {
            cout << "Error on line " << &i - &lines[0] + 1 << ": out of range." << endl;
            errorCount++;
        }
        int command = 0;
        if (args[1] == "READ")
            command = 0x10;
        else if (args[1] == "WRITE")
            command = 0x11;
        else if (args[1] == "LOAD")
            command = 0x20;
        else if (args[1] == "STORE")
            command = 0x21;
        else if (args[1] == "ADD")
            command = 0x30;
        else if (args[1] == "SUB")
            command = 0x31;
        else if (args[1] == "DIVIDE")
            command = 0x32;
        else if (args[1] == "MUL")
            command = 0x33;
        else if (args[1] == "SUBC")
            command = 0x66;
        else if (args[1] == "JUMP")
            command = 0x40;
        else if (args[1] == "JNEG")
            command = 0x41;
        else if (args[1] == "JZ")
            command = 0x42;
        else if (args[1] == "HALT")
            command = 0x43;
        else if (args[1] == "=")
            command = 1;
        else
        {
            cout << "Error on line " << &i - &lines[0] + 1 << ": unknown command." << endl;
            errorCount++;
        }
        int operand = 0;
        if (command != 0x43)
        {
            if (args[2].size() > 5)
            {
                cout << "Error on line " << &i - &lines[0] + 1 << ": memory overflow." << endl;
                errorCount++;
            }
            else if (args[2].size() == 5)
            {
                if (args[2][0] > '3')
                {
                    cout << "Error on line " << &i - &lines[0] + 1 << ": memory overflow." << endl;
                    errorCount++;
                }
            }
            else
                operand = stoi(args[2]);
            if (command != 1 && (operand > MEMSIZE - 1 || operand < 0))
            {
                cout << "Error on line " << &i - &lines[0] + 1 << ": memory overflow." << endl;
                errorCount++;
            }
        }
        int encodedCommand;
        if (command == 1)
            memorySet(address, operand);
        else
        {
            commandEncode(command, operand, encodedCommand);
            memorySet(address, encodedCommand);
        }
    }
    if (errorCount == 0)
    {
        memorySave(argv[2]);
        cout << "Translate succesful!";
    }
    else
    {
        cout << "Total number of errors : " << errorCount;
    }
    return 0;
}