#include <unistd.h>

#include "input.h"
#include "error.h"

FILE *file;

void open_file(const char *filename)
{
	if (access(filename, F_OK ) == -1) {
    	fatal_error("Input: File doesn't exist!");
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