#include <stdio.h>
#include "readfile.h"


#define MAXNAME 64
#define MAXEMP  1024

int cur_id = 0;
int cur_size = 0;

typedef struct {
    int six_digit_ID;
    char first_name[MAXNAME];
    char last_name[MAXNAME];
    int salary;
} Employee;

Employee emp_list[MAXEMP];

int cmpfunc (Employee a, Employee b) {
   return &a.six_digit_ID - &b.six_digit_ID;
}

void load_db(){

    Employee emp;
    int ret;
    FILE *fp = get_file();
    while(1){
        ret = fscanf(fp, "%d %s %s %d",&emp.six_digit_ID, emp.first_name, emp.last_name, &emp.salary);
        if(ret==EOF) break;
        cur_id = emp.salary;
        emp_list[cur_size++] = emp;  
    }

}

void print_DB(){
    printf("NAME                              SALARY 	     ID\n");   
    printf("---------------------------------------------------------------\n");
    for(int i=0; i < cur_size; i++){
        printf("%s         %s                 %d 	     %d\n", 
        emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
    }
    printf("---------------------------------------------------------------\n");
    printf("Number of Employees (%d)\n", cur_size);
}

void find_emp_by_ID(){
    int id;
    printf("Enter a 6 digit employee id: ");  
    scanf("%d", &id);
    for(int i=0; i < cur_size; i++){
        if(emp_list[i].six_digit_ID == id){
                printf("NAME                              SALARY 	     ID\n");   
                printf("---------------------------------------------------------------\n");
                printf("%s         %s                 %d 	     %d\n", 
                emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
                printf("---------------------------------------------------------------\n");
                return;
        }
    }
    printf("Employee with id %d not found in DB\n", id);
}

void find_emp_by_LN(){
    char *last_name;
    printf("Enter Employee's last name (no extra spaces): ");  
    scanf("%s", last_name);
    for(int i=0; i < cur_size; i++){
        if(equal_to(emp_list[i].last_name, last_name)){
                printf("NAME                              SALARY 	     ID\n");   
                printf("---------------------------------------------------------------\n");
                printf("%s         %s                 %d 	     %d\n", 
                emp_list[i].first_name, emp_list[i].last_name, emp_list[i].salary, emp_list[i].six_digit_ID); 
                printf("---------------------------------------------------------------\n");
                return;
        }
    }
    printf("Employee with last name %s not found in DB\n", last_name);
}

void Add_emp(){
    int sel;
    Employee emp_info;
    printf("Enter the first name of the employee: ");  
    scanf("%s", emp_info.first_name);
    printf("Enter the last name of the employee: ");  
    scanf("%s", emp_info.last_name);
    printf("Enter employee's salary (30000 to 150000): ");  
    scanf("%d", &emp_info.salary);
    printf("do you want to add the following employee to the DB?\n");  
    printf("\t\t%s %s, salary: %d\n", emp_info.first_name, emp_info.last_name, emp_info.salary);  
    printf("Enter 1 for yes, 0 for no:");
    scanf("%d", &sel);
    if(sel == 1){
        emp_info.six_digit_ID = ++cur_id;
        emp_list[cur_size++] = emp_info;
    }
}

int menu(Employee emp_list[]){
    int sel, quit = 0;
    Employee emp_info;
    printf("Employee DB Menu:\n");
    printf("----------------------------------\n");
    printf("(1) Print the Database\n");
    printf("(2) Lookup by ID\n");
    printf("(3) Lookup by Last Name\n");
    printf("(4) Add an Employee\n");   
    printf("(5) Quit\n");   
    printf("----------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &sel);
    switch (sel)
    {
        case 1:
            print_DB();
            break;
        case 2:
            find_emp_by_ID();
            break;
        case 3:
            find_emp_by_LN();
            break;
        case 4:
            Add_emp();
            break;
        case 5:
            printf("goodbye!\n");  
            quit = 1;
            break;         
        default:
            printf("Hey, %d is not between 1 and 5, try again...\n", &sel);  
            break;
    }

    return quit;
}

int save_db(FILE * fp){
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Employee database is missing!");
        return 1;
    }
    if(open_file(argv[1]) == -1){
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    load_db(); // load db

    int quit = 0;
    while(!quit){
        quit = menu(emp_list);
    }

    close_file();

    return 0;
}