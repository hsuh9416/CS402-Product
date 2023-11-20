/** 
 * @file statslib.h
 * @brief The header(interface) file for statlib.c
 *
 *  This file is the header file of 'statlib.c' and serves 
 * to link the libraries, such as stdio, stdlib, and math, 
 * required for the overall program.
 *
 * @author Haeun Suh (hsuh7@hawk.iit.edu)
 * @date 19 Nov 2023
 * 
 */
// Header file for "statslib.c"
#ifndef STATLIB_H
#define STATLIB_H

#include <stdio.h>
#include <stdlib.h> // Used for malloc
#include <math.h> // Used for sqrt

// Enum type to specify the type of sum
typedef enum {
    NORMAL, // sum of data x i.e. ∑x
    SQAURE, // sum of sqaured value of data x i.e. ∑(x^2)
    HARMONIC // sum of reciprocal of x i.e. ∑(1/x)
} SUMTYPE;

// Below functions will be externally used.

float* load_data(char *fn, int* size, int* malloc_size);
double get_average(float *arr, int size);
float get_mode(float *arr, int size);
double get_geometric(float *arr, int size);
double get_harmonic(float *arr, int size);
float get_median(float *arr, int size);
double get_stddev(float *arr, int size);

#endif