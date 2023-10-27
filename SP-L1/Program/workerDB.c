#include <stdio.h>

#define MAXNAME 64
#define MAXEMP  1024

struct Employee {
    int six_digit_ID;
    char first_name[MAXNAME];
    char last_name[MAXNAME];
    int salary;
};

void print_DB(struct Employee emp[]){}
void find_emp_by_ID(struct Employee emp[],int emp_ID){}
void find_emp_by_LN(struct Employee emp[],char emp_LN[]){}
void Add_emp(struct Employee emp[], struct Employee target){}

int menu(struct Employee emp[]){
    int sel, quit = 0;
    printf("========= MENU =========\n");
    printf("1. Print the Database\n");
    printf("2. Lookup employee by ID\n");
    printf("3. Lookup employee by ID\n");
    printf("4. Add an Employee\n");   
    printf("5. Quit\n");   
    printf("========================\n");
    printf("Select:");
    scanf("%d", &sel);
    switch (sel)
    {
    case 1:
        print_DB(emp);
        break;
    case 2:
        int emp_ID = 273836;
        find_emp_by_ID(emp, emp_ID);
        break;
    case 3:
        char emp_LN[] = "Lamport";
        find_emp_by_LN(emp, emp_LN);
        break;
    case 4:
        struct Employee target = {212121, "Heaun", "Suh", 80000};
        Add_emp(emp, target);
        break;
    case 5:
        printf("[Terminate] Program ends...\n");  
        quit = 1;
        break;         
    default:
        printf("[Warning] Please ENTER the VALID NUMBER from 1 ~ 5!!\n");  
        break;
    }

    return quit;
}

int main(int argc, char *argv[])
{

    FILE* fp = fopen(&argv,"rt");
    if(fp == NULL){
        puts("File Read Failier!");
        return -1; // abnormal termination
    }

    struct Employee emp[MAXEMP];
    int quit = 0;
    while(!quit){
        quit = menu(emp);
    }


    return 0;
}