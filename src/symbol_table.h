#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#include <stdlib.h>

#define MAX_SYMBOL_TABLE_SIZE 100

struct Table_item
{
    int id;
    int val;
    char* name;
};

struct Table_item* symbol_table[MAX_SYMBOL_TABLE_SIZE];
int table_size = 0;

int add_sym(char* name)
{
    int i;
    for (i = 0; i < table_size; i++) {
        if (strcmp(symbol_table[i]->name, name) == 0)
            return symbol_table[i]->id;
    }

    struct Table_item* item = (struct Table_item*)malloc(sizeof(struct Table_item));
    item->id = table_size;
    item->name = name;

    symbol_table[table_size] = item;

    return table_size++; 
}

struct Table_item* get_sym(int id)
{
    return symbol_table[id];
}

void set_sym(int id, int val)
{
    symbol_table[id]->val = val;
}

#endif
