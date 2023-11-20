// Header file for "statlib.c"
#ifndef STATLIB_H
#define STATLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "readfile.h"

#define INC_SIZE 10

typedef enum {
    NORMAL,
    SQAURE,
    HARMONIC
} SUMTYPE;

void quick_sort(float* arr, int l, int r);
float* load_data(char *fn, int* size, int* malloc_size);
double get_average(float *arr, int size);
float get_mode(float *arr, int size);
float get_harmonic(float *arr, int size);
float get_median(float *arr, int size);
double get_stddev(float *arr, int size);

void save_data(float *arr);

#endif