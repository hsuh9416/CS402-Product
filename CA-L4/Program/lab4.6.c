#include <stdio.h>

int A(int x, int y){
    if(x == 0) return y + 1;
    else if(y == 0) return A(x - 1, 1);
    else A(x - 1, A(x, y - 1));
}

int main(void){
    int num1, num2;

    while(1){
        printf("Please enter the two non-negative integers! \n");
        scanf("%d %d", &num1, &num2);
        if(num1 >= 0 && num2 >= 0) break;
    }

    printf("A(%d, %d) = %d\n", num1, num2, A(num1, num2));

    return 0;
}