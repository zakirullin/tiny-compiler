#ifndef AST_H
#define AST_H

#include <stdlib.h>

#include "ast.h"
#include "func.h"

#define SEQ_TYPE 0
#define SET_TYPE 1
#define ADD_TYPE 2
#define SUB_TYPE 3
#define MUL_TYPE 4 
#define DIV_TYPE 5
#define VAR_TYPE 6
#define NUM_TYPE 7
#define RET_TYPE 8

struct Node
{
    int type;
    int val;
    struct Node *op1;
    struct Node *op2;
};

struct Node *make_node(int type, struct Node *op1, struct Node *op2, int val)
{
    struct Node *node = safe_malloc(sizeof(struct Node));
    node->type = type;
    node->val = val;
    node->op1 = op1;
    node->op2 = op2;

    return node;
}

#endif
