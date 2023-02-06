#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#include "libtinycompiler_export.h"
#include "lex.h"

LIBTINYCOMPILER_EXPORT struct Node *parse(struct Token tok);

#endif