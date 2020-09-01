#include "input.h"
#include "error.h"

FILE *file;

void open_file(const char *filename)
{
	file = fopen(filename, "rb");
	if (file == NULL) {
		fatal_error("Input: File doesn't exist!");
	}
}

FILE *get_file()
{
	return file;
}

void close_file()
{
	fclose(file);
}