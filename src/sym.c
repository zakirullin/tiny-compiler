#include <stdlib.h>
#include <string.h>

#include "sym.h"
#include "func.h"

struct Table* symbol_table[MAX_SYMBOL_TABLE_SIZE];
size_t table_size = 0;

struct Table *get_sym(size_t id)
{
    return symbol_table[id];
}

size_t add_sym(const char *name)
{
    for (size_t i = 0; i < table_size; i++) {
        if (strcmp(symbol_table[i]->name, name) == 0)
            return symbol_table[i]->id;
    }

    struct Table *item = safe_malloc(sizeof(struct Table));
    if (item == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    item->id = table_size;
    item->name = safe_malloc(strlen(name) + 1);
    if (item->name == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(item->name, name);

    symbol_table[table_size] = item;

    return table_size++; 
}

void set_sym(const size_t id, const int val)
{
    symbol_table[id]->val = val;
}

size_t get_table_size()
{
    return table_size;
}
