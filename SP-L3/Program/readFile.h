// Header file for "readFile.c"
#ifndef READFILE_H
#define READFILE_H

#include <stdio.h>

int open_file(char *fn);
int read_int(int *x);
int read_float(float *f);
int read_string(char *s);
void clear_input_buffer();
int close_file();
FILE *get_file();

#endif