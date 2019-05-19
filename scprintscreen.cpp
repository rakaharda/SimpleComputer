#include "scprintscreen.h"

void printScreen()
{
    Box(1, 1, 61, 12);
    Box(1, 13, 46, 22);
    Box(47, 13, 71, 22);
    Box(62, 1, 80, 3);
    Box(62, 4, 80, 6);
    Box(62, 7, 80, 9);
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
    cout << ((getAcc() > -1) ? '+' : '-') << setw(4) << setfill('0') << getAcc();
    gotoXY(70, 4);
    cout << "IC";
    gotoXY(69, 5);
    cout << setw(4) << setfill('0') << getIC();
    gotoXY(69, 7);
    cout << "Flags";
    gotoXY(69, 8);
    cout << regGet(0) << regGet(1) << regGet(2) << regGet(3) << regGet(4);
    gotoXY(26, 1);
    cout << " Memory ";
    gotoXY(1, 1);
    for (int i = 0; i <= 99; i++)
    {
        if (i % 10 == 0)
            gotoXY(2, i / 10 + 2);
        if (i == getIC())
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
    memoryGet(getIC(), currentMemoryValue);
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