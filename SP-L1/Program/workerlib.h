// Header file for "workerlib.c"
#ifndef WORKERLIB_H
#define WORKERLIB_H

#include <stdio.h>
#include "readFile.h"

#define MAX_NAME 64 // Maximum length of character for the name values.
#define MAX_EMP  1024 // Maximum size of Employee list.
#define MIN_SALARY 30000 // Minimum salary for each employee.
#define MAX_SALARY 150000 // Maximum salary for each employee.
#define MIN_ID 100000 // Minimum id number for each employee.
#define MAX_ID 999999 // Maximum id number for each employee.

// This stcuct represents the properties of each Employee.
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

void save_db();

#endif