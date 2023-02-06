#ifndef GEN_H
#define GEN_H

#include "libtinycompiler_export.h"
#include "defs.h"
#include "parser.h"

#define MAX_PROGRAM_SIZE 300
#define COMPILE_BOTH compile(node->op1); compile(node->op2) 

LIBTINYCOMPILER_EXPORT void gen(int code);
LIBTINYCOMPILER_EXPORT byte *compile(struct Node *node);

#endif