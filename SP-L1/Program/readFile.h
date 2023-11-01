#ifndef READFILE_H
#define READFILE_H

int open_file(char *fn);
int read_int(int *x);
int read_float(float *f);
int read_string(char *s);
int close_file();
int equal_to(char *x, char *y);
FILE *get_file();

#endif