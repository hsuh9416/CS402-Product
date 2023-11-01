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

int equal_to(char *x, char *y){
    int i = 0;
    while(x[i] != 0 && y[i] != 0){
        if(x[i] != y[i]) return 0;
        i++;
    }
    return 1;
}

FILE *get_file(){
    return fp;
}

