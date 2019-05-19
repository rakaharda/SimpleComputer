#include "sc.h"

void scInit()
{
    cout << "Initializing memory..." << endl;
    memoryInit();
    cout << "Initializing registers..." << endl;
    regInit();
    cout << "Setting signals..." << endl;
    signal(SIGALRM, timer);
    signal(SIGUSR1, userTimer);
    setbuf(stdout, NULL);
}

void handleEvents()
{
    string path;
    Keys key;
    readKey(&key);
    if (regGet(FLAG_INTERRUPT))
        switch (key)
        {
        case KEY_down:
            setIC(getIC() + 10);
            break;
        case KEY_up:
            setIC(getIC() - 10);
            break;
        case KEY_right:
            setIC(getIC() + 1);
            break;
        case KEY_left:
            setIC(getIC() - 1);
            break;
        case KEY_f5:
            setAcc(memoryGet(getIC()));
            break;
        case KEY_l:
            gotoXY(1, 23);
            cout << ">                                    ";
            gotoXY(3, 23);
            cin >> path;
            memoryLoad(path);
            break;
        case KEY_s:
            gotoXY(1, 23);
            cout << ">                                    ";
            gotoXY(3, 23);
            cin >> path;
            memorySave(path);
            break;
        case KEY_enter:
            getInput();
            break;
        case KEY_i:
            memoryInit();
            break;
        case KEY_r:
            regSet(FLAG_INTERRUPT, 0);
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
            regSet(FLAG_INTERRUPT, 1);
            break;
        case KEY_t:
            raise(SIGUSR1);
            break;
        }
}

void getInput()
{
    gotoXY(1, 23);
    cout << ">                                    ";
    gotoXY(3, 23);
    int temp;
    cin >> temp;
    memorySet(getIC(), temp);
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
