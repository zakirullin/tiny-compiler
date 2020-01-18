#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include "defs.h"

#define POP_BOTH arg2 = pop(); arg1 = pop()

void run(byte *obj);

#endif