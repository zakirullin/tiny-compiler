#include <stdlib.h>
#include <string.h>

#include "sym.h"

struct Table* symbol_table[MAX_SYMBOL_TABLE_SIZE];
int table_size = 0;

struct Table *get_sym(int id)
{
    return symbol_table[id];
}

int add_sym(char *name)
{
    int i;
    for (i = 0; i < table_size; i++) {
        if (strcmp(symbol_table[i]->name, name) == 0)
            return symbol_table[i]->id;
    }

    struct Table *item = malloc(sizeof(struct Table));
    item->id = table_size;
    item->name = name;

    symbol_table[table_size] = item;

    return table_size++; 
}

void set_sym(int id, int val)
{
    symbol_table[id]->val = val;
}

int get_table_size()
{
    return table_size;
}