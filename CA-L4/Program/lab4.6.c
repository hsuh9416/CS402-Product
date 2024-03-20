#include <stdio.h>
/**
 * @brief This function performs the Ackermann operation 
 * using the given parameters and returns the result
 * 
 * @param x - the first non-negative integer
 * @param y - the second non-negative integer
 * @return int - the result integer of Ackermann Function using x and y 
 */
// int cnt = 0; // counter for the function A(x,y) call

int A(int x, int y){
    // cnt++; // counter increate for the function call
    if(x == 0) return y + 1;    // if x = 0 then y+1
    else if(y == 0) return A(x - 1, 1); // else if y = 0 then A(x-1, 1)
    else return A(x - 1, A(x, y - 1)); // else A(x-1, A(x, y-1))
}

// main function
int main(void){
    int num1, num2;

    while(1){
        printf("Please enter the two non-negative integers!\n");
        printf("[Enter]The first non-negative integer: ");
        scanf("%d",&num1);
        printf("[Enter]The second non-negative integer: ");
        scanf("%d",&num2);
        if(num1 >0 && num2 >0) break;
        printf("You have entered a negative integer! Please try again.\n");
    }

    printf("A(%d, %d) = %d\n", num1, num2, A(num1, num2));
    // printf("Total number of calls = %d\n", cnt); // test code for double check with lab 4.7.asm

    return 0;
}