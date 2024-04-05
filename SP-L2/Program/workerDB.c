// This file contains main function and run function menu()
#include <stdio.h>
#include "readfile.h"
#include "workerlib.h"

/**
 * function menu()
 * This function runs multiple choice options that can manipulate the Employee list.
 * @param None
 * @return return 1 when request quit, else return 0
 */
int menu(){
    int sel;

    printf("Employee DB Menu:\n");
    printf("------------------------------------------------------\n");
    printf("(1) Print the Database\n");
    printf("(2) Lookup by ID\n");
    printf("(3) Lookup by Last Name\n");
    printf("(4) Add an Employee\n");   
    printf("(5) Quit\n");   
    printf("(6) Remove an Employee\n"); 
    printf("(7) Update an employee's information\n"); 
    printf("(8) Print the M employees with the highest salaries\n"); 
    printf("(9) Find all employees with matching last name\n"); 
    printf("------------------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &sel);
    switch (sel)
    {
        case 1:
            print_DB(); // Print the list
            break;
        case 2:
            find_emp_by_ID(); // Search by id
            break;
        case 3:
            find_emp_by_LN(0); // Search by last name(single)
            break;
        case 4:
            save_emp(0, -1); // Add new employee
            break;
        case 5:
            // save_DB(); // Save the list to file
            printf("goodbye!\n");  
            return 1; // Exit.   
        case 6:
            remove_emp(); // Remove the existing employee
            break;  
        case 7:
            update_emp(1); // Update the existing employee
            break;  
        case 8:
            print_top_m_sal(); // Print the M employees with the highest salaries
            break;    
        case 9:
            find_emp_by_LN(1); // Search by last name(multiple)
            break; 
        default:
            printf("Hey, %d is not between 1 and 9, try again...\n", sel); // Recieved invalid input
            break;
    }
    printf("\n");// Line change.
    return 0; // Continue
}

// Main function
int main(int argc, char *argv[])
{
    if(argc < 2 || load_DB(argv[1]) == 0){ // Invalid argument. 
        printf("[Error] No database has been found!");
        return 1;// Terminate.
    }

    while(!menu()){
        // Loop until request quit;
    }

    return 0;// Terminate.
}