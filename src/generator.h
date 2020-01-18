#ifndef GENERATOR_H
#define GENERATOR_H

#include "defs.h"
#include "parser.h"

#define MAX_PROGRAM_SIZE 300
#define COMPILE_BOTH compile(node->op1); compile(node->op2) 

void gen(int code);
byte *compile(struct Node *node);

#endif