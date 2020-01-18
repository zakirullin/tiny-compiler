#include <stdlib.h>

#include "defs.h"
#include "input.h"
#include "parser.h"
#include "generator.h"
#include "virtual_machine.h"
#include "asm.h"

#define MIN_ARGS 2
#define SOURCE_ARG 1

int main(int argc, char **argv)
{
    if (argc < MIN_ARGS) {
        printf("No source provided!\n");
        printf("Usage: compiler source\n");

        return EXIT_FAILURE;
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
