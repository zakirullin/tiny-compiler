#include "input.h"

FILE *file;

void open_file(const char *filename)
{
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