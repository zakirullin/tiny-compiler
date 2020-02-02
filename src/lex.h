#ifndef LEX_H
#define LEX_H

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

struct Token lex();
struct Token lookahead();

#endif