// This file contains functions related to reading files/reading user input.
#include "readFile.h"
#include "workerlib.h"
static FILE *fp; // File stream pointer used for reading data from text file. 

/**
 * function open_file()
 * This function opens the file by given string value(file path). 
 * @param char *fn - String value that represents the file path/location.
 * @return return 0 when successful, otherwise return -1.
 */
int open_file(char *fn){
    fp = fopen(fn,"rt");
    if(fp != NULL) return 0;
    else return -1;
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
    if (scanf("%f", f) != EOF) return 0; // Result was success.
    else return -1; // Result was EOF, failure.
}

/**
 * function get_str_end()
 * This function find the end index of the given string.
 * @param char *s - target string to find its end. 
 * @return int idx - the end index of the string(the position for '\0')
 */
int get_str_end(char *s){
    int idx = 0;
    while(s[idx] != '\0'){// find the end of string
        idx++;
    }
    return idx;
}

/**
* function copy_str()
* This function copy from the source string to the destination string.(Simulate strcpy) 
* @param char *src - the source string to copy.
* @param char *dst - the destination string to be copied.
* @param in end - the index of string end '\0'.  
*/
void copy_str(char* src, char* dst, int end){
    for (int j = 0; j <= end; j++) { // copy until meet '\0'
        dst[j] = src[j];
    }
}

/**
 * function read_string()
 * This function recieve the user input which is String(Actually char[]) type.
 * @param char *s - the pointer of the char variable(Or string type) that will store the user input value.
 * @return return 0 when successful, otherwise return -1.
 */
int read_string(char *s){
    char str[MAX_NAME + 1]; // MAX_NAME(64) + 1 * includes '\0'.
    char fmt_str[20];
    snprintf(fmt_str, sizeof(fmt_str), "%%%ds", MAX_NAME);
    int result = scanf(fmt_str, str); // scanf("%65s", str)
    if (result != EOF){ // Not EOF, but need to check the length
        // check the length
        int str_end = get_str_end(str); // get the end index.

        if (str_end >= MAX_NAME) { // The input has exceeded the maximum length!
            printf("[Warning] The maximum number of characters you can enter is %d!\n", MAX_NAME-1);
            return -1;
        }
        else{ // In case of EOF
            copy_str(str, s, str_end); // copy the string
            return 0;
        }
    }   
    else return -1; // Result was EOF, failure.
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