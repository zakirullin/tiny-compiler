#ifndef VM_H
#define VM_H

#include "defs.h"

#define POP_BOTH arg2 = pop(); arg1 = pop()

void run(byte *code);

#endif