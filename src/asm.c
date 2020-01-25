#include <stdio.h>

#include "asm.h"
#include "sym.h"
#include "codes.h"
#include "gen.h"

void print_asm(byte *code)
{
    byte cur_byte;
    int i = 0;

    while ((cur_byte = code[i++]) != RET) {
        switch (cur_byte) {
            case PUSH: printf("PUSH %i\n", code[i++]); break; 
            case READ: cur_byte = code[i++]; printf("READ %s\n",get_sym(cur_byte)->name); break;
            case WRITE: cur_byte = code[i++]; printf("WRITE %s\n", get_sym(cur_byte)->name); break;
            case ADD: printf("ADD POP, POP\n"); break;  
            case SUB: printf("SUB POP, POP\n"); break;
            case MUL: printf("MUL POP, POP\n"); break;
            case DIV: printf("DIV POP, POP\n"); break;
        }   
    }
    printf("RET\n");
}
