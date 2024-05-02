#include <stdio.h>

/* A switch statement allows control to be transferred to different parts of the code based on the value of a variable.
Each possible destination is labeled with a case keyword followed by a constant value and a colon. */


int switches(void);   // Function declaration for switches
int arrays(void);     // Function declaration for arrays

int main(void) {
    switches();     
    arrays();    

    return 0;
}
// |< switch >|
int switches(void) {
    int number = 1;

    switch (number)
    {
    case 0:
        printf("case 0!\n");
        break;
    case 1:
    printf("case 1!\n");
        break;
    default:
        break;
    }

return 0; 
}


// |< arrays >|

/* An array in C is a data structure consisting of a collection of elements, each identified by at least one array index or key. 
Arrays in C are used to store multiple values in a single variable, under a common name. 
The elements in an array are stored in contiguous memory locations,
and each element can be accessed directly using the array name combined with an index. 
Arrays are declared by specifying the type of elements they contain and the number of elements they can hold. 
*/

//
// index: 1  2  3  4  5  6 
//
// grade: 34 21 32 12 45 23
//

int arrays(void) {

    int grade[5];  // Define an array with space for 5 integers

    grade[0] = 234;
    grade[1] = 32;
    grade[2] = 322;
    grade[3] = 432;
    grade[4] = 562;

    // writng the reference of the varaible to the new value
    grade[2] = grade[2] + 5;

    // short way of initializing the array 
    int grade01[5] = {23, 23, 12, 2, 12}; 

    for (int i = 0; i < 5; i++){
        printf("grade[%d] = %d\n", i, grade[i]);

    }
        int total = 0;
        for (int i = 0; i < 5; i++) 
            total += grade[i];
        printf("average: %d\n", total / 5);
    

    /* printf("grade[2] = %d\n", grade[2]);   */
    return 0;  // Return statement added
}



