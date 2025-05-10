#include <stdlib.h>

#include "defs.h"
#include "input.h"
#include "lex.h"
#include "parser.h"
#include "gen.h"
#include "vm.h"
#include "asm.h"

int main(int argc, char **argv)
{
    byte *code;
    if (argc < 2) {
        fatal("No file provided! Usage: compiler <source>");
    }

    open_file(argv[1]);

    code = compile(parse(lex()));

    close_file();

    puts("Generated ASM:");
    print_asm(code);

    puts("Execution result:");
    run(code);

    return EXIT_SUCCESS;
}