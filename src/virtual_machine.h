#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include <stdio.h>

#include "stack.h"
#include "symbol_table.h"
#include "codes.h"
#include "generator.h"

#define POP_BOTH arg2 = pop(); arg1 = pop()
byte *cur_byte = obj;

byte next_byte()
{
	return *cur_byte++;
}

void run()
{
	int arg1;
	int arg2;
	int i;

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
			for (i = 0; i < table_size; i++) {
				printf("%s = %i\n", get_sym(i)->name, get_sym(i)->val);
            }

			return;
	}
}

#endif
