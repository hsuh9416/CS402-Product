// This file contains job list-related manipulation functions.
#include "workerlib.h"

int cur_id = 0; // maximum id number from current Employee list.
int cur_size = 0; // maximum size of current Employee list.

Employee emp_list[MAX_EMP]; // Employee list instance.

/**
 * function equal_to()
 * This function determines whether two strings are the same and returns a result.
 * @param char *x, char *y - Two string(or pointer of char/ array of char) to be compared.
 * @return returns 1 when it was the equal, 0 when it was different.
 */
int equal_to(char *x, char *y){
    int i = 0;
    while(x[i] != 0 && y[i] != 0){
        if(x[i] != y[i]) return 0;
        i++;
    }
    return 1;
}

/**
 * function swap()
 * This function swaps given two entity.
 * @param Employee *a, The employee struct instance that will swap with b.
 * @param Employee *b - The employee struct instance that will swap with a.
 * @return NONE.
 */
void swap(Employee *a, Employee *b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * function sort_employees_by_id()
 * This function sorts the list by employee id in ascending order.
 * @param size Current size of the list.
 * @return NONE.
 */
void sort_employees_by_id(int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (emp_list[i].six_digit_ID > emp_list[i + 1].six_digit_ID) {// If non sorted order found then sort
            swap(&emp_list[i], &emp_list[i + 1]);
        }
    }
}

/**
 * function load_db()
 * This function load data from file to the Employee list =(array of Struct Employee).
 * @param char *fn - the String value(or pointer of char/ array of char) that represents the file name to read.
 * @return returns 1 when successful 0 when failed.
 */
int load_db(char *fn){
    if(open_file(fn) != 0){ // File error
        printf("[Error]Unable to open the file: %s\n", fn);
        return 0;
    }
    
    FILE *fp = get_file();
    Employee emp;

    while(fscanf(fp, "%d %s %s %d",&emp.six_digit_ID, emp.first_name, emp.last_name, &emp.salary) != EOF){ // while input from the file exists
        emp_list[cur_size++] = emp;  // Add the file input
    }
    
    sort_employees_by_id(cur_size); // Sort the file by id in ascending order.
    cur_id = emp_list[cur_size-1].six_digit_ID; // Set maximum current id.
    close_file(); // Close the file have finished reading.

    return 1;
}

/**
 * function print_DB()
 * This function prints the current employee present in the list.
 * @param NONE
 * @return NONE
 */
void print_DB(){
    printf("%20s %20s %-10s %-10s\n", "\t NAME", ""," SALARY", "\t ID"); 
    printf("---------------------------------------------------------------\n");
    for(int i=0; i < cur_size; i++){
        printf("%-20s %-20s %10d %10d\n", 
        emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
    }
    printf("---------------------------------------------------------------\n");
    printf("Number of Employees (%d)\n", cur_size);
}

/**
 * function find_emp_by_ID()
 * This function search the target employee by their id.
 * @param NONE
 * @return NONE
 */
void find_emp_by_ID(){
    Employee emp_info;

    while(1){ // Repeat until get the right input
        printf("Enter a 6 digit employee id: ");  
        if(read_int(&emp_info.six_digit_ID) == EOF || emp_info.six_digit_ID < MIN_ID || emp_info.six_digit_ID > MAX_ID){
            printf("Please enter a 6 digit employee id only!\n");  
            clear_input_buffer();
        }
        else{
            for(int i=0; i < cur_size; i++){
                if(emp_list[i].six_digit_ID == emp_info.six_digit_ID){
                        printf("%20s %20s %-10s %-10s\n", "\t NAME", ""," SALARY", "\t ID"); 
                        printf("---------------------------------------------------------------\n");
                        printf("%-20s %-20s %10d %10d\n", 
                        emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
                        printf("---------------------------------------------------------------\n");
                        return;
                }
            }
            printf("Employee with id %d not found in DB.\n", emp_info.six_digit_ID);
            return;
        }
    }
}

/**
 * function find_emp_by_LN()
 * This function search the target employee by their last name.
 * @param NONE
 * @return NONE
 */
void find_emp_by_LN(){
    Employee emp_info;
    printf("Enter Employee's last name (no extra spaces): ");  
    read_string(emp_info.last_name);
    clear_input_buffer(); // Remove any exceeding characters
    for(int i=0; i < cur_size; i++){
        if(equal_to(emp_list[i].last_name, emp_info.last_name)){
            printf("%20s %20s %-10s %-10s\n", "\t NAME", ""," SALARY", "\t ID"); 
            printf("---------------------------------------------------------------\n");
            printf("%-20s %-20s %10d %10d\n", 
            emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
            printf("---------------------------------------------------------------\n");
            return;
        }
    }
    printf("Employee with last name %s not found in DB\n", emp_info.last_name);
}

/**
 * function add_emp()
 * This function adds the employee by given user input.
 * @param NONE
 * @return NONE
 */
void add_emp(){
    int sel; // 1 for confirm add, 0 for cancel.
    Employee emp_info; // Employee info to be added.

    while(1){
        clear_input_buffer(); // Init buffer
        printf("Enter the first name of the employee: ");  
        if(read_string(emp_info.first_name) == EOF){ // Invalid input
            printf("[Error] Invalid input for the first name. Try Again!\n");
        } 
        else break; // Finish loop when successful.
    }
    
    while(1){
        clear_input_buffer(); // Init buffer
        printf("Enter the last name of the employee: ");  
        if(read_string(emp_info.last_name) == EOF){ // Invalid input
            printf("[Error] Invalid input for the last name. Try Again!\n");
        } 
        else break; // Finish loop when successful.
    }

    while(1){
        clear_input_buffer(); // Init buffer
        printf("Enter employee's salary (%d to %d): ", MIN_SALARY, MAX_SALARY);  
        if(read_int(&emp_info.salary) == EOF){ // Invalid input
            printf("[Error] Invalid input for the salary. Try Again!\n");
        } 
        else if(emp_info.salary < MIN_SALARY || emp_info.salary > MAX_SALARY){
            printf("Salary should be from %d to %d. Try Again!\n", MIN_SALARY, MAX_SALARY);
        }
        else break;
    }

    printf("do you want to add the following employee to the DB?\n");  
    printf("\t\t%s %s, salary: %d\n", emp_info.first_name, emp_info.last_name, emp_info.salary);  
    printf("Enter 1 for yes, 0 or else for no:");
    scanf("%d", &sel);
    
    if(sel == 1){
        if (cur_size >= MAX_EMP) {
            printf("[Error] Employee list is full.\n");
            return;
        }
        emp_info.six_digit_ID = ++cur_id;
        emp_list[cur_size++] = emp_info;
    } 
}