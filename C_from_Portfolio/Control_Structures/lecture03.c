// 43:09 / 5:48:37
#include <stdio.h>

int main (void) {

    int grade = 0;

    printf("Grade: ");
    scanf("%d", &grade);

   /*if (grade >= 50 ) printf("Pass\n"); // this will work upto one statment */

    if (grade >= 50) {
        printf("Pass\n"); 
        printf("Congrats\n"); 
    }
    else printf("Fail\n");
    // if false it will jump out of the block
    printf("if done\n");
    
    /* if (grade >= 90) printf("A\n");
    else if (grade >= 80) printf("B\n");
    else printf("Other\n"); */

    return 0;
}

// 53:50 / 5:48:37