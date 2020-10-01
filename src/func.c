#include <stdlib.h>
#include <stdio.h>

#include "func.h"

void *safe_malloc(size_t size)
{
    void *const mem = malloc(size);
    if (size != 0 && !mem)
        fatal_error("Out of memory");
    return mem;
}

void fatal_error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}