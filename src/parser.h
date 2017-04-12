#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "error.h"
#include "symbol_table.h"
#include "lexer.h"
#include "node.h"

struct Token tok;

int accept(int type)
{
	if (tok.type == type) {
		tok = next_tok();
		return TRUE;
	} else {
		return FALSE;
	}
}

int accept_two(int type1, int type2)
{
	if (tok.type == type1 && lookahead().type == type2) {
		accept(type1);
		accept(type2);
		return TRUE;
	} else {
		return FALSE;
	}
}

void expect(int type)
{
	if (!accept(type)) {
		fatal_error("parser: syntax error");
    }
}

struct Node* expr();

struct Node* factor()
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
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
		fatal_error("parser: unexpected factor");
	}

	return node; 
}

struct Node* term()
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

struct Node* expr()
{
	struct Node* node = NULL;

	int tok_attr = tok.attr;
	if (accept_two(ID, EQ)) {
		node = (struct Node*)malloc(sizeof(struct Node));
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

struct Node* parse()
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->op1 = expr();
	node->op2 = NULL;

	expect(SEM);

	if (tok.type != EOP) {
		node->type = SEQ_TYPE;
		node->op2 = parse();
	} else {
		node->type = RET_TYPE;
	}

	return node; 
}

#endif
