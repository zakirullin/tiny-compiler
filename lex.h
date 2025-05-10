#ifndef LEX_H
#define LEX_H

#include <stdlib.h>
#include <ctype.h>

#include "input.h"
#include "defs.h"
#include "sym.h"
#include "ast.h"

#define EOP -1
#define ID 1
#define NUM 2
#define OP1 3
#define OP2 4
#define LBR 5
#define RBR 6
#define SEM 7
#define EQ 8

#define MAX_LEN 20

struct Token
{
    int type;
    int attr;
};

bool looked_ahead = false;
struct Token next_tok;

struct Token lex()
{
    int ch;
    struct Token tok = {0};

    if (looked_ahead) {
        looked_ahead = false;

        return next_tok;
    }

    eat:
    switch (ch = fgetc(get_file())) {
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
                char *id_name = malloc(MAX_LEN);
                int len = 0;
                id_name[len++] = ch;
                do {
                    if (MAX_LEN == len)
                        fatal("Lexer: Variable name is too long");
                    id_name[len++] = (ch = fgetc(get_file()));
                } while (isalpha(ch) || isdigit(ch));
                id_name[len - 1] = '\0';

                tok.type = ID;
                tok.attr = add_sym(id_name);

            // NUM
            } else if (isdigit(ch)) {
                int val = ch - '0';
                while (isdigit(ch = fgetc(get_file())))
                    val = val * 10 + (ch - '0');

                tok.type = NUM;
                tok.attr = val;

            // Error
            } else {
                fatal("Lexer: Unexpected character");
            }

            ungetc(ch, get_file());
        }

    return tok;
}

struct Token lookahead()
{
    next_tok = lex();
    looked_ahead = true;

    return next_tok;
}

#endif