#ifndef WORKERLIB_H
#define WORKERLIB_H

#include <stdio.h>
#include "readfile.h"

#define MAX_NAME 64
#define MAX_EMP  1024
#define MIN_SALARY 30000
#define MAX_SALARY 150000
#define MIN_ID 100000
#define MAX_ID 999999

typedef struct {
    int six_digit_ID;
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    int salary;
} Employee;

Employee get_emp_list();
int load_db(char *fn);

void print_DB();
void find_emp_by_ID();
void find_emp_by_LN();
void Add_emp();

int save_db();

#endif