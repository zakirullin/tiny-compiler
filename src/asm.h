#ifndef ASM_H
#define ASM_H

#include <stdio.h>

#include "sym.h"
#include "gen.h"

#define PUSH 0
#define POP 1
#define READ 2
#define WRITE 3
#define ADD 4
#define SUB 5
#define MUL 6
#define DIV 7
#define RET 8

void disassemble(byte *bytecode)
{
    byte cur_opcode;
    int i = 0;

    while ((cur_opcode = bytecode[i++]) != RET) {
        switch (cur_opcode) {
            case PUSH: printf("PUSH %i\n", bytecode[i++]); break;
            case READ: cur_opcode = bytecode[i++]; printf("READ %s\n",get_sym(cur_opcode)->name); break;
            case WRITE: cur_opcode = bytecode[i++]; printf("WRITE %s\n", get_sym(cur_opcode)->name); break;
            case ADD: puts("ADD POP, POP"); break;
            case SUB: puts("SUB POP, POP"); break;
            case MUL: puts("MUL POP, POP"); break;
            case DIV: puts("DIV POP, POP"); break;
        }
    }
    puts("RET");
}

#endif
