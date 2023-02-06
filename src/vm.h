#ifndef VM_H
#define VM_H

#include "libtinycompiler_export.h"
#include "defs.h"

#define POP_BOTH arg2 = pop(); arg1 = pop()

LIBTINYCOMPILER_EXPORT void run(byte *code);

#endif