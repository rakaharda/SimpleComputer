#ifndef SCSIGNALH
#define SCSIGNALH

#include <unistd.h>
#include <signal.h>
#include "scmemory.h"
#include "scprintscreen.h"
#include "scrun.h"

void timer(int sig);
void userTimer(int sig);

#endif