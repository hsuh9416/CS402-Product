// This file contains job list-related manipulation functions.
#include "workerlib.h"

int cur_id = 0; // maximum id number from current Employee list.
int cur_size = 0; // maximum size of current Employee list.

static Employee emp_list[MAX_EMP]; // Employee list instance.

/**
 * function get_emp_list()
 * This function is accessor of the employee list. 
 * @param NONE
 * @return Array of Employee.
 */
Employee get_emp_list(){
    return emp_list[MAX_EMP];
}

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
 * This function order the list by its id.
 * @param size Current size of the list.
 * @return NONE.
 */
void sort_employees_by_id(int size) {
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (emp_list[i].six_digit_ID > emp_list[i + 1].six_digit_ID) {
                swap(&emp_list[i], &emp_list[i + 1]);
                swapped = 1;
            }
        }
        size--; // Decrease the size because the last element is already in place
    } while (swapped);
}

/**
 * function load_db()
 * This function load data from file to the Employee list =(array of Struct Employee).
 * @param char *fn - the String value(or pointer of char/ array of char) that represents the file name to read.
 * @return returns 1 when successful 0 when failed.
 */
int load_db(char *fn){
    if(open_file(fn) == -1){ // File error
        printf("Error opening file: %s\n", fn);
        return 0;
    }
    Employee emp;
    int ret;
    FILE *fp = get_file();
    while(1){ // ID, First Name, Last Name, Salary
        ret = fscanf(fp, "%d %s %s %d",&emp.six_digit_ID, emp.first_name, emp.last_name, &emp.salary);
        if(ret==EOF) break; // No more data
        emp_list[cur_size++] = emp;  
    }
    
    sort_employees_by_id(cur_size); // sort the file

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
        int flag = read_int(&emp_info.six_digit_ID);
        if(flag || emp_info.six_digit_ID < MIN_ID || emp_info.six_digit_ID > MAX_ID){
            printf("Please enter a 6 digit employee id only!");  
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
            printf("Employee with id %d not found in DB\n", emp_info.six_digit_ID);
            return;
        }
    }
}

/**
 * function find_emp_by_LN()
 * This function search the target employee by their last name.
 * @param search_all Integer number corresponding the boolean(0, 1) to:
 *          True(1): Search all employees that have the same last name
 *          False(0): Search only the first employee whose last name has been matched. 
 * @return NONE
 */
void find_emp_by_LN(int search_all){
    Employee emp_info;
    printf("Enter Employee's last name (no extra spaces): ");  
    read_string(emp_info.last_name);
    int flag = 0;
    clear_input_buffer(); // Remove any exceeding characters
    for(int i=0; i < cur_size; i++){
        if(equal_to(emp_list[i].last_name, emp_info.last_name)){
            printf("%20s %20s %-10s %-10s\n", "\t NAME", ""," SALARY", "\t ID"); 
            printf("---------------------------------------------------------------\n");
            printf("%-20s %-20s %10d %10d\n", 
            emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
            if(!search_all){
                printf("---------------------------------------------------------------\n");
                return;
            }
            if(!flag) flag = 1; // At least one employee existed.
        }
    }
    (flag) ? printf("---------------------------------------------------------------\n") 
    : printf("Employee with last name %s not found in DB\n", emp_info.last_name);
}

/**
 * function add_emp()
 * This function adds the new employee to the list by user input.
 * @param NONE
 * @return NONE
 */
void add_emp(){
    int sel;
    int flag = 0;

    Employee emp_info;

    while(1){
        printf("Enter the first name of the employee: ");  
        flag = read_string(emp_info.first_name);
        if(!flag) break;

        printf("Invalid input for first name. Try Again!\n");
        clear_input_buffer();
    }

    clear_input_buffer();
    
    while(1){
        printf("Enter the last name of the employee: ");  
        flag = read_string(emp_info.last_name);
        if(!flag) break;
        printf("Invalid input for last name. Try Again!\n");
        clear_input_buffer();
    }

    clear_input_buffer();

    while(1){
        printf("Enter employee's salary (%d to %d): ", MIN_SALARY, MAX_SALARY);  
        flag = read_int(&emp_info.salary);
        if(flag || emp_info.salary < MIN_SALARY || emp_info.salary > MAX_SALARY){
            printf("Salary should be from %d to %d. Try Again!\n", MIN_SALARY, MAX_SALARY);
            clear_input_buffer();
        }
        else break;
    }

    printf("do you want to add the following employee to the DB?\n");  
    printf("\t\t%s %s, salary: %d\n", emp_info.first_name, emp_info.last_name, emp_info.salary);  
    printf("Enter 1 for yes, 0 or else for no:");
    scanf("%d", &sel);
    
    if(sel == 1){
        if (cur_size >= MAX_EMP) {
            printf("Employee list is full.\n");
            return;
        }
        emp_info.six_digit_ID = ++cur_id;
        emp_list[cur_size++] = emp_info;
        printf("Employee added successfully with ID %d\n", emp_info.six_digit_ID);
    } 
    else printf("The process has canceled with no modification.\n");
}

/**
 * function remove_emp()
 * This function removes the existing employee by user input
 * @param NONE
 * @return NONE
 */
void remove_emp(){

}

/**
 * function update_emp()
 * This function removes the existing employee from the list by user input.
 * @param NONE
 * @return NONE
 */
void update_emp(){

}

/**
 * function print_top_m_sal()
 * This function prints the employees with the highest salaries as many as the user requested number.
 * @param NONE
 * @return NONE
 */
void print_top_m_sal(){

}

/**
 * function save_db()
 * This function saves the current list to a file according to the user's selection.
 * @param NONE
 * @return NONE
 */
void save_db(){
    int sel;
    printf("do you want to save the database?\n");  
    printf("Enter 1 for yes, else for no:");
    scanf("%d", &sel);
 
    if(sel == 1){
        // Attempt to open the file for writing (this will also clear the file if it exists)
        FILE* outfile = fopen("DataBase_Updated.txt", "wt");
        if (outfile == NULL) {
            printf("Error opening file for writing. Saving failed.\n");
            fclose(outfile); // Just in case.
        }
        else{
            for(int i = 0; i < cur_size; i++){
                fprintf(outfile, "%d %s %s %d\n",
                    emp_list[i].six_digit_ID, emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary);
                // fwrite((void*)&emp_list[i], sizeof(Employee), 1, outfile);
            }
            fclose(outfile); // Close the file after writing
            printf("Database saved successfully.\n");
            return;
        }
    } 
    printf("Terminated without saving. Any modifications will not reflect in the future.\n");  
}