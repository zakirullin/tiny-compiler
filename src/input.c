#include <unistd.h>
#include <stdlib.h>

#include "input.h"

FILE *file;

void open_file(const char *filename)
{
	if (access(filename, F_OK ) == -1) {
    	printf("The file \"%s\" doesn't exist!\n", filename);

		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");
}

FILE *get_file()
{
	return file;
}

void close_file()
{
	fclose(file);
}