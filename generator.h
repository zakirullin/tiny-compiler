#ifndef GENERATOR_H
#define GENERATOR_H

#include "symbol_table.h"
#include "node.h"
#include "parser.h"
#include "codes.h"

#define MAX_PROGRAM_SIZE 300
#define COMPILE_BOTH compile(node->op1); compile(node->op2) 
typedef int byte;

byte obj[MAX_PROGRAM_SIZE];
byte* cur = obj;

void gen(int code)
{
	*cur++ = code;
}

void compile(struct Node* node)
{
	if (node == NULL)
		return;

	switch (node->type) {
		case SEQ_TYPE: COMPILE_BOTH; break; 
		case SET_TYPE: compile(node->op2); gen(WRITE); gen(node->op1->val); break; 
		case VAR_TYPE: gen(READ); gen(node->val); break;
		case NUM_TYPE: gen(PUSH); gen(node->val); break; 
		case ADD_TYPE: COMPILE_BOTH; gen(ADD); break;
		case SUB_TYPE: COMPILE_BOTH; gen(SUB); break;
		case MUL_TYPE: COMPILE_BOTH; gen(MUL); break;
		case DIV_TYPE: COMPILE_BOTH; gen(DIV); break;
		case RET_TYPE: COMPILE_BOTH; gen(RET); break;
	}
}

#endif
