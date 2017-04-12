#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "generator.h"
#include "virtual_machine.h"
#include "obj_printer.h"

#define SOURCE_ARG 1

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("No source provided!\n");

        return EXIT_FAILURE;
    } else {
        source = fopen(argv[SOURCE_ARG], "r");
    }

	tok = next_tok(source);
	compile(parse());

	fclose(source);

	printf("Generated ASM:\n");
	print_asm();

	printf("Execution result:\n");
	run();

	return EXIT_SUCCESS;
}
