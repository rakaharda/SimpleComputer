#ifndef SCMYREADKEYH
#define SCMYREADKEYH

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include "sckeys.h"

int readKey(enum Keys *key);
int myTermSave();
int myTermRestore();
int myTermRegime(int regime, int vtime, int vmin, int echo, int sigint);

#endif 