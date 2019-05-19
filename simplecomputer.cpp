#include "scmemory.h"
#include "scterminal.h"
#include "scbigChars.h"
#include "scmyreadkey.h"
#include <bitset>
#include <iostream>
#include <iomanip>
#include <signal.h>

int instructionCounter = 1;
int accumulator = 0;
bool FLAG_INTERRUPT = true;

using namespace std;

void printExtendedCharset();
void printScreen();
void handleEvents();
void getInput();
void timer(int sig);
void userTimer(int sig);

int main()
{
    signal(SIGALRM, timer);
    signal(SIGUSR1, userTimer);
    memorySet(3, 1234);
    setbuf(stdout, NULL);
    while (true)
    {
        clearScreen();
        printScreen();
        gotoXY(1, 27);
        handleEvents();
    }
    return 0;
}

void handleEvents()
{
    Keys key;
    readKey(&key);
    if (FLAG_INTERRUPT)
        switch (key)
        {
        case KEY_down:
            if (instructionCounter < MEMSIZE - 10)
                instructionCounter += 10;
            break;
        case KEY_up:
            if (instructionCounter > 10)
                instructionCounter -= 10;
            break;
        case KEY_right:
            if (instructionCounter < MEMSIZE - 1)
                instructionCounter++;
            break;
        case KEY_left:
            if (instructionCounter > 0)
                instructionCounter--;
            break;
        case KEY_f5:
            memoryGet(instructionCounter, accumulator);
            break;
        case KEY_l:
            memoryLoad("memdump");
            break;
        case KEY_s:
            memorySave("memdump");
            break;
        case KEY_enter:
            getInput();
            break;
        case KEY_i:
            memoryInit();
            break;
        case KEY_r:
            FLAG_INTERRUPT = false;
            raise(SIGALRM);
            break;
        case KEY_t:
            raise(SIGUSR1);
            break;
        }
    else
        switch (key)
        {
        case KEY_r:
            alarm(0);
            FLAG_INTERRUPT = true;
            break;
        case KEY_t:
            raise(SIGUSR1);
            break;
        }
}

void getInput()
{
    gotoXY(1, 23);
    cout << "> ";
    int temp;
    cin >> temp;
    memorySet(instructionCounter, temp);
}

void printScreen()
{
    Box(1, 1, 61, 12);
    Box(1, 13, 46, 22);
    Box(47, 13, 71, 22);
    Box(62, 1, 80, 3);
    Box(62, 4, 80, 6);
    gotoXY(52, 13);
    cout << " Keys ";
    gotoXY(48, 14);
    cout << "l - load";
    gotoXY(48, 15);
    cout << "s - save";
    gotoXY(48, 16);
    cout << "r - run";
    gotoXY(48, 17);
    cout << "t - step";
    gotoXY(48, 18);
    cout << "i - reset";
    gotoXY(48, 19);
    cout << "F5 - accumulator";
    gotoXY(48, 20);
    cout << "F6 - instructionCounter";
    gotoXY(66, 1);
    cout << "Accumulator";
    gotoXY(68, 2);
    cout << ((accumulator > -1) ? '+' : '-') << setw(4) << setfill('0') << accumulator;
    gotoXY(62, 4);
    cout << "InstructionCounter";
    gotoXY(68, 5);
    cout << setw(4) << setfill('0') << instructionCounter;
    gotoXY(26, 1);
    cout << " Memory ";
    gotoXY(1, 1);
    for (int i = 0; i <= 99; i++)
    {
        if (i % 10 == 0)
            gotoXY(2, i / 10 + 2);
        if (i == instructionCounter)
            setBgColor(Color::RED);
        int temp;
        memoryGet(i, temp);
        cout << ((temp >= 0) ? '+' : '-') << setfill('0') << setw(4) << temp;
        if (i % 10 != 9)
        {
            cout << ' ';
        }
        setBgColor(Color::BLACK);
    }
    int currentMemoryValue;
    memoryGet(instructionCounter, currentMemoryValue);
    printBigChar((currentMemoryValue >= 0) ? BIGPLUS : BIGMINUS, 2, 14);
    int margin = 7;
    for (int i = 4; i >= 1; i--)
    {
        margin--;
        int temp = currentMemoryValue % 10;
        currentMemoryValue /= 10;
        long bigChar;
        switch (temp)
        {
        case 0:
            bigChar = BIG0;
            break;
        case 1:
            bigChar = BIG1;
            break;
        case 2:
            bigChar = BIG2;
            break;
        case 3:
            bigChar = BIG3;
            break;
        case 4:
            bigChar = BIG4;
            break;
        case 5:
            bigChar = BIG5;
            break;
        case 6:
            bigChar = BIG6;
            break;
        case 7:
            bigChar = BIG7;
            break;
        case 8:
            bigChar = BIG8;
            break;
        case 9:
            bigChar = BIG9;
            break;
        }
        printBigChar(bigChar, i * 8 + margin, 14);
    }
}
void printExtendedCharset()
{
    char *a = new char;
    for (int i = 97; i < 126; i++)
    {
        *a = i;
        printf("\n%s =", a);
        printA(a);
    }
}

void timer(int sig)
{
    printScreen();
    (instructionCounter < MEMSIZE - 1) ? instructionCounter++ : instructionCounter = 0;
    alarm(1);
}

void userTimer(int sig)
{
    alarm(0);
    regInit();
    FLAG_INTERRUPT = true;
    instructionCounter = 0;
}