#include <stdlib.h>

#include "defs.h"
#include "input.h"
#include "lex.h"
#include "parser.h"
#include "gen.h"
#include "vm.h"
#include "asm.h"
#include "error.h"

#define MIN_ARGS 2
#define SOURCE_ARG 1

int main(int argc, char **argv)
{
    if (argc < MIN_ARGS) {
        fatal_error("No file provided! Usage: compiler <source>");
    }

    open_file(argv[SOURCE_ARG]);

    byte *code = compile(parse(lex()));

    close_file();

    printf("Generated ASM:\n");
    print_asm(code);

    printf("Execution result:\n");
    run(code);

    return EXIT_SUCCESS;
}
