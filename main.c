#include <stdlib.h>

#include "defs.h"
#include "input.h"
#include "lex.h"
#include "parser.h"
#include "gen.h"
#include "vm.h"
#include "asm.h"

#define MIN_ARGS 2
#define SOURCE_ARG 1

int main(int argc, char **argv)
{
    byte *code;
    if (argc < MIN_ARGS) {
        fatal("No file provided! Usage: compiler <source>");
    }

    open_file(argv[SOURCE_ARG]);

    code = compile(parse(lex()));

    close_file();

    puts("Generated ASM:");
    print_asm(code);

    puts("Execution result:");
    run(code);

    return EXIT_SUCCESS;
}
