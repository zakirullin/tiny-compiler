#ifndef FUN_H
#define FUN_H

#include "libtinycompiler_export.h"

LIBTINYCOMPILER_EXPORT void *safe_malloc(size_t size);
LIBTINYCOMPILER_EXPORT void fatal_error(char *msg);

#endif