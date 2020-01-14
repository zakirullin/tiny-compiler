#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct Stack_item 
{
    int val;
    struct Stack_item* next;
};

struct Stack_item* head = NULL;

void push(int val)
{
    struct Stack_item* item = malloc(sizeof(struct Stack_item));
    item->val = val;
    item->next = head;
    head = item;
}

int pop()
{
    int val = head->val;

    struct Stack_item* tmp = head;
    head = head->next;
    free(tmp);

    return val;
}

int empty()
{
    return head == NULL;
}

#endif
