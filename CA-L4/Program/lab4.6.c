#include <stdio.h>
/**
 * @brief This function performs the Ackermann operation 
 * using the given parameters and returns the result.
 * 
 * @param x - The first non-negative integer
 * @param y - The second non-negative integer
 * @return int - The result of the Ackermann function using x and y
 */
int A(int x, int y){
    if(x == 0) return y + 1;    // if x = 0 then y+1
    else if(y == 0) return A(x - 1, 1); // else if y = 0 then A(x-1, 1)
    else A(x - 1, A(x, y - 1)); // else A(x-1, A(x, y-1))
}

// main function
int main(void){
    int num1, num2;

    printf("Please enter the two non-negative integers!\n");
    
    while(1){ // Repeat until the desired integer is received
        printf("[Enter]The first non-negative integer: ");
        scanf("%d",&num1);
        if(num1 >= 0) break; // No negative numbers are allowed
        printf("You have entered a negative integer! Please try again.\n");
    }

    while(1){ // Repeat until the desired integer is received
        printf("[Enter]The second non-negative integer: ");
        scanf("%d",&num2);
        if(num2 >= 0) break; // No negative numbers are allowed.
        printf("You have entered a negative integer! Please try again.\n");
    }

    printf("A(%d, %d) = %d\n", num1, num2, A(num1, num2));

    return 0;
}