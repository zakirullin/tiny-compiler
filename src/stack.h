#ifndef STACK_H
#define STACK_H

struct Stack
{
    int val;
    struct Stack *next;
};

void push(int val);
int pop();
int empty();

#endif