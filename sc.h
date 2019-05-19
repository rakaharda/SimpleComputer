#ifndef SCH
#define SCH

#include "scmemory.h"
#include "scterminal.h"
#include "scbigChars.h"
#include "scmyreadkey.h"
#include "scsignal.h"
#include "scprintscreen.h"
#include <bitset>
#include <iostream>
#include <iomanip>
#include <signal.h>

using namespace std;

void printExtendedCharset();
void handleEvents();
void getInput();
void scInit();

#endif 