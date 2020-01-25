#ifndef STACK_H
#define STACK_H

#include "defs.h"

struct Stack
{
    int val;
    struct Stack *next;
};

void push(int val);
int pop();
bool empty();

#endif