#include <stdio.h>
#include "vm.h"
#include "stack.h"
#include "sym.h"
#include "codes.h"

byte *cur_byte;

byte next_byte()
{
    return *cur_byte++;
}

void run(const byte *code)
{
    if (code == NULL) {
        fprintf(stderr, "Error: Byte code is NULL\n");
        return;
    }

    cur_byte = code;

    while (1) {
        byte opcode = next_byte();

        switch (opcode) {
            case PUSH:
                push(next_byte());
                break;
            case READ:
                push(get_sym(next_byte())->val);
                break;
            case WRITE:
                set_sym(next_byte(), pop());
                break; 
            case ADD:
                POP_BOTH;
                push(arg1 + arg2);
                break; 
            case SUB:
                POP_BOTH;
                push(arg1 - arg2);
                break;
            case MUL:
                POP_BOTH;
                push(arg1 * arg2);
                break;
            case DIV:
                POP_BOTH;
                push(arg1 / arg2);
                break;
            case RET:
                for (int i = 0; i < get_table_size(); i++) {
                    printf("%s = %i\n", get_sym(i)->name, get_sym(i)->val);
                }
                return;
            default:
                fprintf(stderr, "Error: Unknown opcode %d\n", opcode);
                return;
        }
    }
}
