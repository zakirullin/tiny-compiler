#ifndef LEXER_H
#define LEXER_H

#include <stdlib.h>
#include <ctype.h>

#include "defs.h"
#include "error.h"
#include "symbol_table.h"
#include "node.h"

#define EOP -1
#define ID 1
#define NUM 2
#define OP1 3
#define OP2 4
#define LBR 5
#define RBR 6
#define SEM 7
#define EQ 8

#define MAX_LEN 100

struct Token
{
	int type;
	int attr;
};

FILE *source;

int look_done = FALSE;
struct Token look_tok;

struct Token next_tok()
{
	int ch = 0;
	struct Token tok;

	// If lookaheaded 
	if (look_done) {
		look_done = FALSE;

		return look_tok;	
	}

    eat:
    switch (ch = fgetc(source)) {
		case ' ': case '\n': goto eat;
		case EOF: tok.type = EOP; break;
		case '+': tok.type = OP1; tok.attr = ADD_TYPE; break;
		case '-': tok.type = OP1; tok.attr = SUB_TYPE; break;
		case '*': tok.type = OP2; tok.attr = MUL_TYPE; break;
		case '/': tok.type = OP2; tok.attr = DIV_TYPE; break;		
		case '(': tok.type = LBR; break;
		case ')': tok.type = RBR; break;
		case '=': tok.type = EQ; break;
		case ';': tok.type = SEM; break;
		default: 
			// ID
			if (isalpha(ch)) {
				char *id_name = (char*)malloc(MAX_LEN);
				int len = 0;
				id_name[len++] = ch;
				do
					id_name[len++] = (ch = fgetc(source));
				while (isalpha(ch) || isdigit(ch)); 
				id_name[len - 1] = '\0';
			
				tok.type = ID;
				tok.attr = add_sym(id_name); 

			// NUM
			} else if (isdigit(ch)) {
				int val = ch - '0';
				while (isdigit(ch = fgetc(source)))
					val = val * 10 + (ch - '0');

				tok.type = NUM;
				tok.attr = val;
			
			// Error
			} else {
				fatal_error("lexer: unexpected symbol");
			}

			ungetc(ch, source);
		}
	return tok;
}

struct Token lookahead()
{
	look_tok = next_tok();
	look_done = TRUE;

	return look_tok;
}

#endif
