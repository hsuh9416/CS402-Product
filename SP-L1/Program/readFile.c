#include <stdio.h>

static FILE *fp;

int open_file(char *fn){
    fp = fopen(fn,"rt");
    return (fp == NULL) ? -1: 0;
}

int read_int(int *x){
    int result = scanf("%d", &x);
    return (result == EOF) ? -1 : 0;
}

int read_float(float *f){
    int result = scanf("%f", &f);
    return (result == EOF) ? -1 : 0;
}
int read_string(char *s){
    int result = scanf("%s\n", s);
    return (result == EOF) ? -1 : 0;
}

int close_file(){
    return fclose(fp);
}

FILE *get_file(){
    return fp;
}
