#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "defs.h"
#include "error.h"
#include "sym.h"
#include "lex.h"
#include "ast.h"

struct Token tok;

static bool accept(int type);
static bool accept_two(int type1, int type2);
static void expect(int type);
static struct Node *expr();
static struct Node *factor();
static struct Node *term();

static bool accept(int type)
{
    if (tok.type == type) {
        tok = lex();
        return true;
    } else {
        return false;
    }
}

static bool accept_two(int type1, int type2)
{
    if (tok.type == type1 && lookahead().type == type2) {
        accept(type1);
        accept(type2);
        return true;
    } else {
        return false;
    }
}

static void expect(int type)
{
    if (!accept(type)) {
        fatal_error("Parser: Syntax error");
    }
}

static struct Node *factor()
{
    struct Node* node = malloc(sizeof(struct Node));
    node->op1 = NULL;
    node->op2 = NULL;

    int tok_attr = tok.attr;
    if (accept(ID)) {
        node->type = VAR_TYPE;
        node->val = tok_attr;
    } else if (accept(NUM)) {
        node->type = NUM_TYPE;
        node->val = tok_attr;
    } else if (accept(LBR)) {
        free(node);
        node = expr();
        accept(RBR);    
    } else {
        fatal_error("Parser: Unexpected factor");
    }

    return node; 
}

static struct Node *term()
{
    struct Node* node;
    node = factor();
    
    int tok_attr = tok.attr;
    while (accept(OP2)) {
        node = make_node(tok_attr, node, factor(), 0);

        tok_attr = tok.attr;
    }
    
    return node; 
}

static struct Node *expr()
{
    struct Node* node = NULL;

    int tok_attr = tok.attr;
    if (accept_two(ID, EQ)) {
        node = malloc(sizeof(struct Node));
        node->type = SET_TYPE;
        node->op1 = make_node(VAR_TYPE, 0, 0, tok_attr);
        node->op2 = expr();
    } else {
        node = term(); 

        tok_attr = tok.attr;
        while (accept(OP1)) {
            node = make_node(tok_attr, node, term(), 0);

            tok_attr = tok.attr;
        }   
    }

    return node; 
}

struct Node *produce()
{
    struct Node* node = malloc(sizeof(struct Node));
    node->op1 = expr();
    node->op2 = NULL;

    expect(SEM);

    if (tok.type != EOP) {
        node->type = SEQ_TYPE;
        node->op2 = produce();
    } else {
        node->type = RET_TYPE;
    }

    return node; 
}

struct Node *parse(struct Token start_tok)
{
    tok = start_tok;

    return produce();
}