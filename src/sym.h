#ifndef SYM_H
#define SYM_H

#include "defs.h"

#define MAX_SYMBOL_TABLE_SIZE 1024

struct Table {
int id;
char *name;
int val;
};

// Returns the symbol table entry with the given id.
// If the id is out of range, behavior is undefined.
struct Table *get_sym(int id);

// Adds a symbol to the symbol table and returns its id.
// If the symbol already exists in the table, returns its existing id.
// If the symbol table is full, behavior is undefined.
int add_sym(char *name);

// Sets the value of the symbol with the given id.
// If the id is out of range, behavior is undefined.
void set_sym(int id, int val);

// Returns the number of symbols in the symbol table.
int get_table_size();

#endif