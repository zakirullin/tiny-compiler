#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "error.h"
#include "sym.h"
#include "lexer.h"
#include "ast.h"

struct Node *parse(struct Token tok);

#endif