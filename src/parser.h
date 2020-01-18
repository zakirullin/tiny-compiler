#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "error.h"
#include "symbol_table.h"
#include "lexer.h"
#include "ast.h"

int accept(int type);
int accept_two(int type1, int type2);
void expect(int type);
struct Node *expr();
struct Node *factor();
struct Node *term();
struct Node *parse();

#endif