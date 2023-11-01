#include <stdio.h>
#include "readfile.h"
#include "workerlib.h"

int menu(){
    int sel, quit = 0;

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


int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Employee database is missing!");
        return 1;
    }

    if(load_db(argv[1]) == 0) return 1; // load db

    int quit = 0;
    while(!quit){
        quit = menu();
    }

    close_file();

    return 0;
}