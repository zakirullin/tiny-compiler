#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#include "lex.h"

struct Node *parse(struct Token tok);

#endif