#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include "libtinycompiler_export.h"

LIBTINYCOMPILER_EXPORT void open_file(const char *filename);
LIBTINYCOMPILER_EXPORT FILE* get_file();
LIBTINYCOMPILER_EXPORT void close_file();

#endif