// This file contains functions related to reading files/reading user input.
#include "readFile.h"

static FILE *fp; // File stream pointer used for reading data from text file. 

/**
 * function open_file()
 * This function opens the file by given string value(file path). 
 * @param char *fn - String value that represents the file path/location.
 * @return return -1 when failed, 0 when successful.
 */
int open_file(char *fn){
    fp = fopen(fn,"rt");
    return (fp == NULL) ? -1: 0;
}

/**
 * function read_int()
 * This function recieve the user input which is integer type.
 * @param int *x - the pointer of the integer variable that will store the user input value.
 * @return return -1 when failed, 0 when successful.
 */
int read_int(int *x){
    int result = scanf("%d", x);
    return (result == EOF) ? -1 : 0;
}

/**
 * function read_float()
 * This function recieve the user input which is float type.
 * @param int *f - the pointer of the float variable that will store the user input value.
 * @return return -1 when failed, 0 when successful.
 */
int read_float(float *f){
    int result = scanf("%f", f);
    return (result == EOF) ? -1 : 0;
}

/**
 * function read_string()
 * This function recieve the user input which is String(Actually char[]) type.
 * @param char *s - the pointer of the char variable(Or string type) that will store the user input value.
 * @return return -1 when failed, 0 when successful.
 */
int read_string(char *s){
    int result = scanf("%64s", s); // limited to 64
    return (result == EOF) ? -1 : 0;
}

/**
 * function clear_input_buffer()
 * This function clears current buffer to avoid any unwanted leftover.
 * @param NONE
 * @return NONE
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/**
 * function read_int()
 * This function closes the FILE pointer which has opened.
 * @param int NONE
 * @return return 0 when success, return EOF when failed.
 */
int close_file(){
    return fclose(fp);
}

/**
 * function get_file()
 * This function is accessor of the FILE pointer.
 * @param NONE
 * @return static pointer FILE fp. 
 */
FILE *get_file(){
    return fp;
}

