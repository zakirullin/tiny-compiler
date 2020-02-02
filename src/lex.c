#include <stdlib.h>
#include <ctype.h>

#include "lex.h"
#include "input.h"
#include "defs.h"
#include "error.h"
#include "sym.h"
#include "ast.h"

bool look_done = false;
struct Token look_tok;

struct Token lex()
{
    int ch = 0;
    struct Token tok;

    // If lookaheaded 
    if (look_done) {
        look_done = false;

        return look_tok;    
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
                do
                    id_name[len++] = (ch = fgetc(get_file()));
                while (isalpha(ch) || isdigit(ch)); 
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
                fatal_error("Lexer: Unexpected symbol");
            }

            ungetc(ch, get_file());
        }
    return tok;
}

struct Token lookahead()
{
    look_tok = lex();
    look_done = true;

    return look_tok;
}