// This file contains employee-related manipulation functions.
#include "workerlib.h"

int cur_id = 0; // A maximum id number from current Employee array.
int cur_size = 0; // A maximum size of current Employee array.

static Employee emp_list[MAX_EMP]; // Employee array instance.

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
 * @param Employee *a - The employee struct instance that will swap with b.
 * @param Employee *b - The employee struct instance that will swap with a.
 * @return NONE.
 */
void swap(Employee *a, Employee *b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * function min_heapify()
 * This function traverse and compare nodes to find minimum, and swap to make minHeap.
 * @param Employee emps - The employ type array to be heapify.
 * @param int size - the size of the array.
 * @param int i - The current index given.
 * @return None.
 */
void min_heapify(Employee emps[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && emps[left].salary < emps[smallest].salary)
        smallest = left;

    if (right < size && emps[right].salary < emps[smallest].salary)
        smallest = right;

    if (smallest != i) {
        swap(&emps[i], &emps[smallest]);
        min_heapify(emps, size, smallest);
    }
}

/**
 * function build_min_heap()
 * This function builds the heap structure by the given array with its size.
 * @param Employee emps - The employ type array to be used to build the heap.
 * @param int size - The size of the array.
 * @return None.
 */
void build_min_heap(Employee emps[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        min_heapify(emps, size, i);
}

/**
 * function partition()
 * This function divides the given Employee array and returns the new partioning index.
 * @param Employee emps - The employ type array to be divided(partioned).
 * @param int l - The leftmost index.
 * @param int r - The rightmost index.
 * @return The partitioning index.
 * @param char orderby - the method to use for sorting. 
 *        'I': six_digit_ID
 *        'S': salary
 */
int partition(Employee emps[], int l, int r, char orderby) {
    
    int pivot == emps[r].six_digit_ID; // default
    if (orderby == 'S') pivot == emps[r].salary;  

    int i = (l - 1);  // Index of smaller element

    for (int j = l; j <= r - 1; j++) {
        if ( ( (orderby == 'I') && (emps[j].six_digit_ID <= pivot) ) 
        || ( (orderby == 'S') && (emps[j].salary >= pivot) )) {
            i++;  // increment index of smaller element
            swap(&emps[i], &emps[j]);
        }
    }

    swap(&emps[i + 1], &emps[r]);

    return (i + 1);
}

/**
 * function quick_sort()
 * The function sorts the given array by quicksort with six_digit_ID as a key.
 * @param Employee emps - The employ type array to be sorted
 * @param int l - the leftmost index.
 * @param int r - The rightmost index.
 * @param char orderby - the method to use for sorting
 */
void quick_sort(Employee emps[], int l, int r, char orderby) {
    if (l < r) {
        int pi = partition(emps, l, r, orderby);

        // Separately sort elements before partition and after partition
        quick_sort(emps, l, pi - 1, orderby);
        quick_sort(emps, pi + 1, r, orderby);
    }
}

/**
 * function load_DB()
 * This function load data from file to the Employee array = (array of Struct Employee).
 * @param char *fn - The String value(or pointer of char/ array of char) that represents the file name to read.
 * @return returns 1 when successful 0 when failed.
 */
int load_DB(char *fn){
    if(open_file(fn) != 0){ // File error
        printf("[Error] Unable to open the file: %s\n", fn);
        return 0;
    }

    int ret;
    FILE *fp = get_file();
    Employee emp;

    while(1){ // ID, First Name, Last Name, Salary
        ret = fscanf(fp, "%d %s %s %d",&emp.six_digit_ID, emp.first_name, emp.last_name, &emp.salary);
        if(ret==EOF) break; // No more data
        emp_list[cur_size++] = emp;  
    }
    
    quick_sort(emp_list, 0, cur_size - 1);// Order by ID ascendant

    cur_id = emp_list[cur_size-1].six_digit_ID; // Set maximum current id.

    close_file(); // Close the file finished its reading.

    return 1;
}

/**
 * function print_emp()
 * This function is shared function to print the given array of employees.
 * @param Employee emps - The array of struct type Employee.
 * @param int size - The size of the given array.
 * @return NONE
 */
void print_emp(Employee emps[], int size){
    printf("%20s %20s %-10s %-10s\n", "\t NAME", ""," SALARY", "\t ID"); 
    printf("---------------------------------------------------------------\n");
    for(int i=0; i < size; i++){
        printf("%-20s %-20s %10d %10d\n", 
        emps[i].first_name, emps[i].last_name, emps[i].salary, emps[i].six_digit_ID); 
    }
    printf("---------------------------------------------------------------\n");
    printf("Number of Employees (%d)\n\n", size);
}

/**
 * function print_DB()
 * This function prints the current employee present in the array.
 * @param NONE
 * @return NONE
 */
void print_DB(){
    print_emp(emp_list, cur_size);
}

/**
 * function find_emp_by_ID()
 * This function searches the target employee by the user given id.
 * @param NONE
 * @return NONE
 */
void find_emp_by_ID(){
    Employee emp_info;

    while(1){ // Repeat until get the right input
        printf("Enter a 6 digit employee id(Range: MIN = %d, MAX = %d): ", MIN_ID, MAX_ID);  
        if(read_int(&emp_info.six_digit_ID) == EOF || emp_info.six_digit_ID < MIN_ID || emp_info.six_digit_ID > MAX_ID){
            printf("Please enter a 6 digit employee id only!\n");  
            clear_input_buffer();
        }
        else break;
    }

    int hasExisted = 0;
    Employee emps[cur_size]; // Won't be larger than the original list!
    for(int i=0; i < cur_size; i++){
        if(emp_list[i].six_digit_ID == emp_info.six_digit_ID){
            emps[0] = emp_list[i];
            hasExisted = 1;
            break; // We actually find just one employee for this!
        }
    }
    
    if (hasExisted) print_emp(emps, 1);
    else printf("Employee with id %d not found in DB\n", emp_info.six_digit_ID);
}

/**
 * function find_emp_by_LN()
 * This function searches the target employee by their last name.
 * @param search_all Integer number corresponding the boolean(0, 1) to:
 *          True(1): Search all employees that have the same last name
 *          False(0): Search only the first employee whose last name has been matched. 
 * @return NONE
 */
void find_emp_by_LN(int search_all){
    Employee emp_info;
    printf("Enter Employee's last name (no extra spaces): ");  
    read_string(emp_info.last_name);
    clear_input_buffer(); // Remove any exceeding characters

    int num = 0;
    Employee emps[MAX_EMP];
    for(int i=0; i < cur_size; i++){
        if(equal_to(emp_list[i].last_name, emp_info.last_name)){
            emps[num] = emp_list[i];
            num++;
            if(!search_all) break;  // We only find just one employee for this!
        }
    }
    
    if (num > 0) print_emp(emps, num);
    else printf("Employee(s) with last name %s not found in DB\n", emp_info.last_name);
}

/**
 * function save_emp()
 * This function adds the new employee to the array by user input.
 * @param int update - Whether the saving employee is for the update(1) or insert(0)
 * @param Employee emp - The employee to be updated (Empty for adding the new employee)
 * @param int index - The index of the employee to be updated (-1 for adding the new employee)
 * @return NONE
 */
void save_emp(int update, int index){
    int sel;
    int flag = 0;
    Employee emp = (update) ? emp_list[index] : emp_list[cur_size+1];
    while(1){
        if(update) printf("Current first name: %s\n", emp.first_name); // Show existing one
        printf("Enter the first name of the employee: ");  
        flag = read_string(emp.first_name);
        if(!flag) break;

        printf("Invalid input for first name. Try Again!\n");
        clear_input_buffer();
    }

    clear_input_buffer();
    
    while(1){
        if(update) printf("Current last name: %s\n", emp.last_name);  // Show existing one
        printf("Enter the last name of the employee: ");  
        flag = read_string(emp.last_name);
        if(!flag) break;
        printf("Invalid input for last name. Try Again!\n");
        clear_input_buffer();
    }

    clear_input_buffer();

    while(1){
        if(update) printf("Current salary: %d\n", emp.salary);
        printf("Enter employee's salary (%d to %d): ", MIN_SALARY, MAX_SALARY);  
        flag = read_int(&emp.salary);
        if(flag || emp.salary < MIN_SALARY || emp.salary > MAX_SALARY){
            printf("Salary should be from %d to %d. Try Again!\n", MIN_SALARY, MAX_SALARY);
            clear_input_buffer();
        }
        else break;
    }

    printf("do you want to %s the following employee to the DB?\n", update ? "add" : "update");  
    printf("\t\t%s %s, salary: %d\n", emp.first_name, emp.last_name, emp.salary);  
    printf("Enter 1 for yes, 0 or else for no:");
    scanf("%d", &sel);
    
    if(sel == 1){
        if (cur_size >= MAX_EMP) {
            printf("Employee list is full.\n");
            return;
        }
        if(update){// For update
            emp_list[index] = emp;
        }
        else{ // For add
            emp.six_digit_ID = ++cur_id;
            emp_list[cur_size++] = emp;
        }

        printf("Employee %s successfully with ID %d\n", update ? "added" : "updated", emp.six_digit_ID);
    } 
    else printf("The process has canceled with no modification.\n");
}

/**
 * function remove_emp()
 * This function removes the existing employee from the array by user input
 * @param NONE
 * @return NONE
 */
void remove_emp(){
    Employee emp_info;
    int index;
    int found = 0;
    while(1){
        printf("Enter a 6 digit employee id to be removed(Range: MIN = %d, MAX = %d): ", MIN_ID, MAX_ID);  
        if(read_int(&emp_info.six_digit_ID) == EOF || emp_info.six_digit_ID < MIN_ID || emp_info.six_digit_ID > MAX_ID){
            printf("Please enter a 6 digit employee id only!\n");  
            clear_input_buffer();
        }
        else break;
    }

    for(int i=0; i < cur_size; i++){
        if(emp_list[i].six_digit_ID == emp_info.six_digit_ID){
            found = 1;
            index = i;
            int sel;
            printf("do you want to revmove the following employee to the DB?\n");  
            printf("\t\t%s %s, salary: %d\n", emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary);  
            printf("Enter 1 for yes, 0 or else for no: ");
            scanf("%d", &sel);
            if(sel) break; // break to proceed.
            else {
                printf("Cancel the removal of the employee.");
                return; // return to end immediately.
            }
        }
    }

    if(found){// If found then 
        for(int i=index; i < cur_size; i++){ // shift left to replace the removed data
            swap(&emp_list[i], &emp_list[i+1]);
        }
        cur_size--;
        printf("Employee %s successfully with ID %d\n", "deleted", emp_info.six_digit_ID);
    }
    else printf("Employee with id %d not found in DB\n", emp_info.six_digit_ID);
}

/**
 * function update_emp()
 * This function updates the existing employee from the array by user input.
 * @param NONE
 * @return NONE
 */
void update_emp(){
    Employee emp_info;
    while(1){
        printf("Enter the six-digit id of the employee to be updated: ");  
        int flag = read_int(&emp_info.six_digit_ID);
        if(flag || emp_info.six_digit_ID < MIN_ID || emp_info.six_digit_ID > MAX_ID){
            printf("Please enter a 6 digit employee id only!");  
            clear_input_buffer();
        }
        else{
            for(int i=0; i < cur_size; i++){
                if(emp_list[i].six_digit_ID == emp_info.six_digit_ID){
                    save_emp(1, i); // update employee with user input
                    return;
                }
            }
            printf("Employee with id %d not found in DB\n", emp_info.six_digit_ID);
            return;
        }
    }
}

/**
 * function print_top_m_sal()
 * This function prints the employees with the highest salaries as many as the user requested number.
 * @param NONE
 * @return NONE
 */
void print_top_m_sal(){
    int m;
    while(1){
        printf("Enter the number of employees with the highest salaries(Current # of Employees: %d): ", cur_size);  
        int flag = read_int(&m);
        if (!flag && m <= cur_size) break;
        printf("Please enter the valid number smaller than the number of current employees!!\n");
        clear_input_buffer();
    }

    Employee top_salary[m];  
    for (int i = 0; i < m; i++) // Copy the values for the m employees only.
        top_salary[i] = emp_list[i];

    build_min_heap(top_salary, m); // Build the heap to sort

    for (int i = m; i < cur_size; i++) {
        if (emp_list[i].salary > top_salary[0].salary) {
            top_salary[0] = emp_list[i]; // replace with the minimum
            min_heapify(top_salary, m, 0); // re-sort
        }
    }
    
    quick_sort(top_salary, 0, m - 1); // sort by id
    print_emp(top_salary, m);

}

/**
 * [This function is optional]
 * function save_DB()
 * This function saves the current array to a file according to the user's selection.
 * @param NONE
 * @return NONE
 */
void save_DB(){
    int sel;
    printf("do you want to save the database?\n");  
    printf("Enter 1 for yes, else for no: ");
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
            }
            fclose(outfile); // Close the file after writing.
            printf("Database saved successfully.\n");
            return;
        }
    } 
    printf("Terminated without saving. Any modifications will not reflect in the future.\n");  
}