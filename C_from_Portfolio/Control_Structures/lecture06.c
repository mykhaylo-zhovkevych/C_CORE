// do while loop  
/* Certainly! The do-while loop in C is a post-test loop, 
meaning it evaluates its condition at the end of each iteration. 
This structure guarantees that the loop will execute at least once, regardless of the initial condition. 
It's particularly useful when you want to ensure that the loop body is executed before checking the condition, 
such as when prompting the user for input that needs to be validated. */

#include <stdio.h>

int main(void) {

    int i = 25;

    do {
        printf("i: %d\n", i);
        i++;
    } while (i < 5); // 25 < 5 not true but this will run at least for one time 

    return 0;
}


// here it will check if th ser enters more than 0 if so programm end if not repeat 
int inputvalidation(void) {
    int number = 0;

    do {
        printf("Enter number (>0): ");
        scanf("%d", &number);
        if (number <= 0)
            printf("Number must be >0!\n"); 
            
    } while (number <= 0);

    return 0;
}