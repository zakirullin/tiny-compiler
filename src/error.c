#include <stdlib.h>
#include <stdio.h>

#include <error.h>

void fatal_error(char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}