/** 
 * @maninclude
 * @file basicstats.h
 * @brief Function executes the main and its comprehensive run funtion run_stats()
 *
 *  This file is the introduction of the program and includes the main() function, 
 * which is the execution part. The main function goes through a simple task of 
 * checking arguments at execution time and then calls run_stats() to proceed with 
 * actual program execution.
 *
 *  A program consists of functions in the current file, which is the executable part, 
 * main functions called within the function of the executable part, and auxiliary 
 * functions that assist the main functions.
 * 
 *  The main function and its auxiliary functions are included in a separate file 
 * 'statslib.c', and the main function is defined in 'statslib.h' and is designed 
 * to be called externally. In other words, a function in 'statslib.c' must be defined 
 * in 'statslib.h' to be able to be called externally.
 * 
 *  This program implements statistical functions that meet the requirements defined in 
 * the project 'SP-L3' and is designed to verify validity through the given data file. 
 * The following constraints were added according to the requirements:
 *  1. Make full use of pointer properties without using global variables.
 *  2. Implement a dynamic array using malloc.
 *  3. Except sqrt in the math library, all statistical functions are implemented directly.
 * 
 * @author Haeun Suh (hsuh7@hawk.iit.edu)
 * @date 12 Apr 2024
 * 
 */

#include "statslib.h"

/**
 * function run_stats()
 * This function comprehensively runs the functions that are required regarding the given data file.
 * @param char *fn - The String value(or pointer of char/ array of char) that represents the file name to read.
 * @return returns 1 when error occurred failed. Otherwise return 0.
 */
int run_stats(char* fn){
    int size = 0; // Size of the data
    int malloc_size = 20; // Initial size
    float* arr = load_data(fn, &size, &malloc_size);
    
    if(arr == 0) return 1; // read failure!
    
    printf("Results:\n--------\n");
    printf("Num values:%15d\n", size);
    printf("   average:%15.3f\n", get_average(arr, size));
    printf("      mode:%15.3f\n", get_mode(arr, size));
    printf(" geometric:%15.3f\n", get_geometric(arr, size));
    printf("  harmonic:%15.3f\n", get_harmonic(arr, size));
    printf("    median:%15.3f\n", get_median(arr, size));
    printf("    stddev:%15.3f\n", get_stddev(arr, size));   
    printf("Unused array capacity:  %d\n", malloc_size - size);
    
    free(arr); // free the arr

    return 0; // Successfully terminated.
}

// Main function
int main(int argc, char *argv[])
{
    if(argc != 2){ // No argument. Terminate
        printf("No file input found!");
        return 1;
    }

    return run_stats(argv[1]);
}