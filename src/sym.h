#ifndef SYM_TABLE
#define SYM_TABLE

#define MAX_SYMBOL_TABLE_SIZE 100

#include "libtinycompiler_export.h"

struct Table
{
    int id;
    int val;
    char *name;
};

LIBTINYCOMPILER_EXPORT struct Table *get_sym(int id);
LIBTINYCOMPILER_EXPORT int add_sym(char *name);
LIBTINYCOMPILER_EXPORT void set_sym(int id, int val);
LIBTINYCOMPILER_EXPORT int get_table_size();

#endif