/** 
 * @file statslib.c
 * @headerfile statslib.h
 * @brief Function for statistic calculations.
 *
 *  This file consists of main functions and their auxiliary functions 
 * that meet the requirements of the program.Main functions are linked 
 * from the header file 'statslib.h', and auxiliary files are used only 
 * within the file.
 * 
 * @author Haeun Suh (hsuh7@hawk.iit.edu)
 * @date 19 Nov 2023
 */

#include "statslib.h"

/**
 * Below are the auxiliary functions.
*/

/**
 * function open_file()
 * This function returns the pointer of the file by given string value(file path). 
 * @param char *fn - String value that represents the file path/location.
 * @return return the pointer of FILE when successful.
 */
FILE *open_file(char *fn){
    FILE *fp = fopen(fn,"rt");
    return fp;
}

/**
 * function close_file()
 * This function closes the FILE pointer which has opened.
 * @param FILE *fp - The pointer of FILE.
 * @return return 0 when success, return EOF when failed.
 */
int close_file(FILE *fp){
    return fclose(fp);
}

/**
 * function swap()
 * This function swaps given two float.
 * @param float *a - The float that will swap with b.
 * @param float *b - The float that will swap with a.
 * @return NONE.
 */
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * function partition()
 * This function divides the given array and returns the new partioning index.
 * @param float *arr - The pointer of float type array type.
 * @param int l - The leftmost index.
 * @param int r - The rightmost index.
 * @return The partitioning index.
 */
int partition(float* arr, int l, int r) {
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

/**
 * function quick_sort()
 * The function sorts the given array as ascendant order.
 * @param float *arr - The pointer of float type array type.
 * @param int l - the leftmost index.
 * @param int r - The rightmost index.
 */
void quick_sort(float* arr, int l, int r) {

    if (l < r) {
        int pi = partition(arr, l, r);

        // Separately sort elements before partition and after partition
        quick_sort(arr, l, pi - 1);
        quick_sort(arr, pi + 1, r);
    }
}

/**
 * function get_sum()
 * This function returns the sum of the given array.
 * @param float *arr - The pointer of the float-type array.
 * @param float avg - the avarage value of the given array. (For general sums, set it to a value of 0.)
 * @param SUMTYPE type - the Enum type of summation.
 * @param int size - the size of the given array.
 * @return returns the sum of the given array in double.
 */
double get_sum(float *arr, float avg, SUMTYPE type, int size){
    double sum = 0.0;

    for(int i=0; i< size; i++){
        float el = (type == HARMONIC) ? 1/arr[i] : (arr[i] - avg); // No subtraction of average for harmonic mean.
        sum += (type == SQAURE) ? pow(el,2) : el; // If it is SQAURE mode, sum the squared value of el. 
    }

    return sum;
}

/**
 * Below are the major functions.
*/

/**
 * function load_data()
 * This function load data from file to the pointer of float.
 * @param char *fn - The String value(or pointer of char/ array of char) that represents the file name to read.
 * @param int *size - the pointer of the size of the data array.
 * @param int *malloc_size - the pointer of the size of allocated memory to the array.
 * @return returns the float pointer of array when successful 0 when failed.
 */
float* load_data(char *fn, int* size, int* malloc_size){
    FILE *fp = open_file(fn); // open file
    if(fp == NULL){ // File error
        printf("Error opening file: %s\n", fn);
        return 0;
    }

    float* arr = (float*)malloc(sizeof(float)*(*malloc_size));
    
    int ret;
    int i = 0;
    while(1){
        ret = fscanf(fp, "%f", &arr[(*size)++]);
        if(ret == EOF){
            break;
        }
        if((*size) >= (*malloc_size)){
            float* temp = (float*)malloc(sizeof(float)*(*malloc_size)*2); // Extended array

            for(int j=0; j<(*size); j++) temp[j] = arr[j];// Copy the value
\
            free(arr); // Free old array

            arr = temp; // subtitute
            
            (*malloc_size) *= 2; // Update malloc_size
        }
    }

    (*size)--; // decrease unintentional increment.
    
    close_file(fp); // Close the file finished its reading.

    quick_sort(arr, 0, (*size) - 1); // Sort in advance.
    
    return arr;
}

/**
 * function get_average()
 * This function returns the mean(average) of the given array.
 * @param float *arr - The pointer of the float-type array.
 * @param int size - the size of the given array.
 * @return returns the average of the given array in double data type.
 */
double get_average(float *arr, int size){
    return get_sum(arr, 0, NORMAL, size)/size;
}

/**
 * function get_mode()
 * This function returns the most frequent value from the given array.
 * @param float *arr - The pointer of the float-type array.
 * @param int size - the size of the given array.
 * @return returns the most frequent value from the given array in float data type.
 */
float get_mode(float *arr, int size){
    float mode = arr[0];
    int cur_data = arr[0];
    int max_frequency = 1;
    int current_frequency = 1;

    for(int i = 1; i < size; i++){
        if(arr[i] == arr[i-1]){
            current_frequency++;
        }
        else{ // No more duplicated from cur_data
            if(current_frequency > max_frequency){ //Update mode
                mode = arr[i-1];
                max_frequency = current_frequency;
                cur_data = arr[i];
                current_frequency = 1;
            }
        }
    }

    return mode;
}

/**
 * function get_geometric()
 * This function returns a geometric mean for the given array.
 * @param float *arr - The pointer of the float-type array.
 * @param int size - the size of the given array.
 * @return returns the geometric mean for the given array in double data type.
 */
double get_geometric(float *arr, int size){
    double mul = 1;
    for(int i=0; i < size; i++) {
        if (arr[i] <= 0) return 0; // This cannot be calculated
        mul *= arr[i];
    }
    return pow(mul, (double)1/size);
}

/**
 * function get_harmonic()
 * This function returns a harmonic mean for the given array.
 * @param float *arr - The pointer of the float-type array.
 * @param int size - the size of the given array.
 * @return returns the harmonic mean for the given array in double data type.
 */
double get_harmonic(float *arr, int size){
    return size/get_sum(arr, 0, HARMONIC, size);
}

/**
 * function get_median()
 * This function returns a median value of the given array.
 * @param float *arr - The pointer of the float-type array.
 * @param int size - the size of the given array.
 * @return returns the median value from the given array in float data type.
 */
float get_median(float *arr, int size){
    if (size % 2 != 0) {
        return arr[size/2];
    } else {
        float mid1 = arr[size/2 - 1];
        float mid2 = arr[size/2];
        return (mid1 + mid2) / 2.0;
    }
}

/**
 * function get_stddev()
 * This function returns a standard deviation for the given array.
 * @param float *arr - The pointer of the float-type array.
 * @param int size - the size of the given array.
 * @return returns the standard deviation of the given array in double data type.
 */
double get_stddev(float *arr, int size){
    return sqrt(get_sum(arr, get_average(arr, size), SQAURE, size)/size);
}