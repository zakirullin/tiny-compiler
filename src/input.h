#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

FILE *file;

void open_file(const char *filename)
{
	file = fopen(filename, "rb");
	if (NULL == file) {
		fatal("Input: File doesn't exist!");
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