#include <stdlib.h>

#include "ast.h"

struct Node *make_node(int type, struct Node *op1, struct Node *op2, int val)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->type = type;
    node->val = val;
    node->op1 = op1;
    node->op2 = op2;

    return node;
}