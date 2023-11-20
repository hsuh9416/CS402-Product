// This file contains main function and run function run_stat()
#include <stdio.h>
#include "readfile.h"
#include "statlib.h"


int run_stat(char* fn){
    int size = 0;
    int malloc_size = 20;
    float* arr = load_data(fn, &size, &malloc_size);
    if(arr == 0) return 1; // read fail!

    quick_sort(arr, 0, size - 1); // sort before use.
    
    printf("Results:\n--------\n");
    printf("Num values:%15d\n", size);
    printf("   average:%15.3f\n", get_average(arr, size));
    printf("      mode:%15.3f\n", get_mode(arr, size));
    printf(" geometric:%15.3f\n", get_geometric(arr, size));
    printf("  harmonic:%15.3f\n", get_harmonic(arr, size));
    printf("    median:%15.3f\n", get_median(arr, size));
    printf("    stddev:%15.3f\n", get_stddev(arr, size));   
    printf("Unused array capacity:  %d", malloc_size - size);

    free(arr); // free the arr
}

// Main function
int main(int argc, char *argv[])
{
    if(argc != 2){ // No argument. Terminate
        printf("No file input found!");
        return 1;
    }

    run_stat(argv[1]);

    return 0;
}