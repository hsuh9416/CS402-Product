#include "workerlib.h"

int cur_id = 0;
int cur_size = 0;

static Employee emp_list[MAX_EMP];

Employee get_emp_list(){
    return emp_list[MAX_EMP];
}

int equal_to(char *x, char *y){
    int i = 0;
    while(x[i] != 0 && y[i] != 0){
        if(x[i] != y[i]) return 0;
        i++;
    }
    return 1;
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
    cur_id = emp_list[cur_size-1].six_digit_ID;
    close_file(); // Close the file ended reading.
    
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
    Employee emp_info;

    while(1){
        printf("Enter a 6 digit employee id: ");  
        int flag = read_int(&emp_info.six_digit_ID);
        if(flag || emp_info.six_digit_ID < MIN_ID || emp_info.six_digit_ID > MAX_ID){
            printf("Please enter a 6 digit employee id only! ");  
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

void find_emp_by_LN(){
    char *last_name;
    printf("Enter Employee's last name (no extra spaces): ");  
    read_string(last_name);
    clear_input_buffer(); // Remove any exceeding characters
    int existed = 0;
    for(int i=0; i < cur_size; i++){
        if(equal_to(emp_list[i].last_name, last_name)){
            if(!existed){
                printf("%20s %20s %-10s %-10s\n", "\t NAME", ""," SALARY", "\t ID"); 
                printf("---------------------------------------------------------------\n");
                existed = 1;
            }
                printf("%-20s %-20s %10d %10d\n", 
                emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
        }
    }
    if(existed) printf("---------------------------------------------------------------\n");
    else ("Employee with last name %s not found in DB\n", last_name);
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

int save_db(){
    int sel;
    printf("do you want to save the database?\n");  
    printf("Enter 1 for yes, else for no:");
    scanf("%d", &sel);
 
    if(sel == 1){
        // Attempt to open the file for writing (this will also clear the file if it exists)
        FILE* outfile = fopen("DataBase_Updated.txt", "wt");
        if (outfile == NULL) {
            perror("Error opening file for writing. Saving failed");
            return -1; // Return an error code if file opening failed
        }  
        for(int i = 0; i < cur_size; i++){
            fwrite(&emp_list[i], sizeof(emp_list[i]), 1, outfile);
        }
        fclose(outfile); // Close the file after writing
        printf("Database saved successfully.\n");
        return 1; // Return success code
    } 
    else {
        printf("Terminated without saving. Any modifications will not reflect in the future.\n");  
        return 0; // Return a different code for no save
    }

    return 0;
}