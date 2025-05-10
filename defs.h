#ifndef DEFS_H
#define DEFS_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char byte;

void fatal_error(char *msg)
{
    fputs(msg, stderr);
    exit(EXIT_FAILURE);
}

void *safe_malloc(size_t size)
{
    void *const mem = malloc(size);
    if (size != 0 && !mem)
        fatal_error("Out of memory");
    return mem;
}

#endif