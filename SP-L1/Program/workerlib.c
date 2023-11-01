#include "workerlib.h"

int cur_id = 0;
int cur_size = 0;

static Employee emp_list[MAX_EMP];

int equal_to(char *x, char *y){
    int i = 0;
    while(x[i] != 0 && y[i] != 0){
        if(x[i] != y[i]) return 0;
        i++;
    }
    return 1;
}

// A simple swap function for two Employee structures
void swap(Employee *a, Employee *b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

// A function to perform a bubble sort on an array of Employee structures
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

int load_db(char *fn){
    if(open_file(fn) == -1){
        printf("Error opening file: %s\n", fn);
        return 0;
    }
    Employee emp;
    int ret;
    FILE *fp = get_file();
    while(1){
        ret = fscanf(fp, "%d %s %s %d",&emp.six_digit_ID, emp.first_name, emp.last_name, &emp.salary);
        if(ret==EOF) break;

        emp_list[cur_size++] = emp;  
    }

    sort_employees_by_id(cur_size);
    cur_id = emp_list[cur_size-1].six_digit_ID;
    return 1;
}

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

void find_emp_by_ID(){
    int id;
    while(1){
        clear_input_buffer();
        printf("Enter a 6 digit employee id: ");  
        int flag = read_int(&id);
        if(flag || id < 10000 || id > 99999){
            printf("Please enter a 6 digit employee id only! ");  
        }
        else{
            for(int i=0; i < cur_size; i++){
                if(emp_list[i].six_digit_ID == id){
                        printf("%20s %20s %-10s %-10s\n", "\t NAME", ""," SALARY", "\t ID"); 
                        printf("---------------------------------------------------------------\n");
                        printf("%-20s %-20s %10d %10d\n", 
                        emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
                        printf("---------------------------------------------------------------\n");
                        return;
                }
            }
            printf("Employee with id %d not found in DB\n", id);
            return;
        }
    }

}

void find_emp_by_LN(){
    char *last_name;
    printf("Enter Employee's last name (no extra spaces): ");  
    scanf("%s", last_name);
    for(int i=0; i < cur_size; i++){
        if(equal_to(emp_list[i].last_name, last_name)){
                printf("%20s %20s %-10s %-10s\n", "\t NAME", ""," SALARY", "\t ID"); 
                printf("---------------------------------------------------------------\n");
                printf("%-20s %-20s %10d %10d\n", 
                emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
                printf("---------------------------------------------------------------\n");
                return;
        }
    }
    printf("Employee with last name %s not found in DB\n", last_name);
}

void Add_emp(){
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
    printf("Enter 1 for yes, 0 for no:");
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

int save_db(FILE * fp){
    return 0;
}

Employee get_emp_list(){
    return emp_list[MAX_EMP];
}




