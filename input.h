#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

#include "input.h"

FILE *file;

void open_file(const char *filename)
{
	file = fopen(filename, "rb");
	if (NULL == file) {
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

#endif