// This file contains functions related to reading files/reading user input.
#include "readFile.h"

FILE *fp; // File stream pointer used for reading data from text file. 

/**
 * function open_file()
 * This function opens the file by given string value(file path). 
 * @param char *fn - String value that represents the file path/location.
 * @return return 0 when successful, otherwise return -1.
 */
int open_file(char *fn){
    fp = fopen(fn,"rt");
    return (fp != NULL) ? 0: -1;
}

/**
 * function read_int()
 * This function recieve the user input which is integer type.
 * @param int *x - the pointer of the integer variable that will store the user input value.
 * @return return 0 when successful, otherwise return -1(invalid input, including float).
 */
int read_int(int *x){
    char inputEnd; // Detect invalid input(such as '.' for float)
    int result = scanf("%d%c", x, &inputEnd);
    if(result == 2 && (inputEnd == '\n' || inputEnd == ' ')) return 0;
    else return -1;
}

/**
 * function read_float()
 * This function recieve the user input which is float type.
 * @param int *f - the pointer of the float variable that will store the user input value.
 * @return return 0 when successful, otherwise return -1.
 */
int read_float(float *f){
    return (scanf("%f", f) != EOF) ? 0 : -1;
}

/**
 * function read_string()
 * This function recieve the user input which is String(Actually char[]) type.
 * @param char *s - the pointer of the char variable(Or string type) that will store the user input value.
 * @return return 0 when successful, otherwise return -1.
 */
int read_string(char *s){
    return (scanf("%64s", s) != EOF) ? 0 : -1; // limited to 64
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
 * function close_file()
 * This function closes the FILE pointer which has opened.
 * @param NONE
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

