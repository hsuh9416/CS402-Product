// This file contains statistic functions.
#include "statlib.h"

int malloc_size = 20;
int cur_size = 0;

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

void quick_sort(float* arr, int l, int r) {

    if (l < r) {
        int pi = partition(arr, l, r);

        // Separately sort elements before partition and after partition
        quick_sort(arr, l, pi - 1);
        quick_sort(arr, pi + 1, r);
    }
}

/**
 * function load_data()
 * This function load data from file to the pointer of float.
 * @param char *fn - The String value(or pointer of char/ array of char) that represents the file name to read.
 * @param int *size - the pointer of the size of the data array.
 * @param int *malloc_size - the pointer of the size of allocated memory to the array.
 * @return returns array when successful 0 when failed.
 */
float* load_data(char *fn, int* size, int* malloc_size){
    if(open_file(fn) == -1){ // File error
        printf("Error opening file: %s\n", fn);
        return 0;
    }

    int ret;
    FILE *fp = get_file();
    
    float* arr = (float*)malloc(sizeof(float)*(*malloc_size));
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
    close_file(); // Close the file finished its reading.

    return arr;
}

double get_sum(float *arr, float avg, SUMTYPE type, int size){
    double sum = 0.0;
    for(int i=0; i< size; i++){
        float el = (type == HARMONIC) ? 1/arr[i] : (arr[i] - avg);
        sum += (type == SQAURE) ? el*el : el;
    }
    return sum;
}

double get_average(float *arr, int size){
    return get_sum(arr, 0, NORMAL, size)/size;
}

float get_mode(float *arr, int size){
    float mode = arr[0];
    int cur_data = arr[0];
    int max_frequency = 1;
    int current_frequency = 1;

    for(int i = 1; i < size; i++){
        if(arr[i] == arr[i-1]){
            current_frequency++;
        }
        else{
            if(current_frequency > max_frequency){//Update mode
                mode = arr[i-1];
                max_frequency = current_frequency;
                cur_data = arr[i];
                current_frequency = 1;
            }
        }
    }

    return mode;
}

double get_geometric(float *arr, int size){
    double mul = 1;
    for(int i=0; i < size; i++) {
        if (arr[i] <= 0) return 0; // This cannot be calculated
        mul *= arr[i];
    }
    return pow(mul, (double)1/size);
}

double get_harmonic(float *arr, int size){
    return size/get_sum(arr, 0, HARMONIC, size);
}

float get_median(float *arr, int size){
    if (size % 2 != 0) {
        return arr[size/2];
    } else {
        float mid1 = arr[size/2 - 1];
        float mid2 = arr[size/2];
        return (mid1 + mid2) / 2.0;
    }
};

double get_stddev(float *arr, int size){
    return sqrt(get_sum(arr, get_average(arr, size), SQAURE, size)/size);
};

int get_residual(int size){
    return malloc_size - size;
}
void save_data(float *arr){
    free(arr);
};
