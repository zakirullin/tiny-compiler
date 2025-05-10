#ifndef DEFS_H
#define DEFS_H

#include <stdbool.h>
#include <stdio.h>

typedef unsigned char byte;

void fatal(char *msg)
{
    fputs(msg, stderr);
    exit(EXIT_FAILURE);
}

#endif