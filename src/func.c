#include <stdlib.h>
#include <stdio.h>

#include "func.h"

void *safe_malloc(size_t size)
{
    void *mem = safe_malloc(size);
    if (!mem)
        fatal_error("Out of memory");
    return mem;
}

void fatal_error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}