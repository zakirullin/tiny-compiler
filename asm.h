#ifndef ASM_H
#define ASM_H

#include <stdio.h>

#include "asm.h"
#include "sym.h"
#include "codes.h"
#include "gen.h"

void disassemble(byte *code)
{
    byte cur_byte;
    int i = 0;

    while ((cur_byte = code[i++]) != RET) {
        switch (cur_byte) {
            case PUSH: printf("PUSH %i\n", code[i++]); break;
            case READ: cur_byte = code[i++]; printf("READ %s\n",get_sym(cur_byte)->name); break;
            case WRITE: cur_byte = code[i++]; printf("WRITE %s\n", get_sym(cur_byte)->name); break;
            case ADD: puts("ADD POP, POP"); break;
            case SUB: puts("SUB POP, POP"); break;
            case MUL: puts("MUL POP, POP"); break;
            case DIV: puts("DIV POP, POP"); break;
        }
    }
    puts("RET");
}

#endif
