#ifndef STACK_H
#define STACK_H

#include "libtinycompiler_export.h"
#include "defs.h"

struct Stack
{
    int val;
    struct Stack *next;
};

LIBTINYCOMPILER_EXPORT void push(int val);
LIBTINYCOMPILER_EXPORT int pop();
LIBTINYCOMPILER_EXPORT bool empty();

#endif