#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>

void fatal_error(char *msg)
{
    printf("%s\n", msg);
    exit(1);
}

#endif
