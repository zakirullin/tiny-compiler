#include <stdlib.h>

#include "lexer.h"
#include "parser.h"
#include "generator.h"
#include "virtual_machine.h"
#include "obj_printer.h"

int main()
{
	source = fopen("program", "r");

	tok = next_tok(source);
	compile(parse());

	fclose(source);

	printf("Generated ASM:\n");
	print_asm();

	printf("Execution result:\n");
	run();

	return EXIT_SUCCESS;
}
