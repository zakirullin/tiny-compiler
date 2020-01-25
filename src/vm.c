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

void run(byte *code)
{
    cur_byte = code;

    int arg1;
    int arg2;

    next_op:
    switch (next_byte()) {
        case PUSH: push(next_byte()); goto next_op;
        case READ: push(get_sym(next_byte())->val); goto next_op;
        case WRITE: set_sym(next_byte(), pop()); goto next_op; 
        case ADD: POP_BOTH; push(arg1 + arg2); goto next_op; 
        case SUB: POP_BOTH; push(arg1 - arg2); goto next_op;
        case MUL: POP_BOTH; push(arg1 * arg2); goto next_op;
        case DIV: POP_BOTH; push(arg1 / arg2); goto next_op;
        case RET: 
            for (int i = 0; i < get_table_size(); i++) {
                printf("%s = %i\n", get_sym(i)->name, get_sym(i)->val);
            }

            return;
    }
}