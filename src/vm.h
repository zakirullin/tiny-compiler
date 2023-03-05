#ifndef VM_H
#define VM_H

#include "libtinycompiler_export.h"
#include "defs.h"

/**
 * Runs the bytecode in the specified code buffer.
 *
 * @param code The byte code to execute. This buffer must remain valid throughout
 *        the execution of the function and must contain a sequence of bytecode
 *        instructions. If the buffer is NULL or empty, the function has no effect.
 */
LIBTINYCOMPILER_EXPORT void run(const byte *code);

#endif