#include <stdio.h>

// passing the array to the function 
void add_one(int array[], int length);

int main(void) {
    
    int a[] = {2,4,9,1,3,5};
    int x = 3;
    // %p ist placeholder für die Pointer
    // this adress is for the data where it storred 
    printf("a: %p\n", a);
    // a is here just memory adress and wehn i am passing this to the function i am not passing the values but memory adress of array 
    // regular varibales dont behave like that 
    // add_one(a, x); // at this point i am passing the vales and they will not behave that way, as arrays because the arrays will be passed the memory adress and not the values

            // revier
    add_one(a, 6);

    for (int i = 0; i < 6; i++)
        printf("a[%d]=%d\n", i, a[i]);

    return 0;

}
             // revier
void add_one(int array[], int length) {
    // Klammern {} weglassen, wenn nur eine einzelne Anweisung ausgeführt wird  
    printf("array: %p\n", array);
    for (int i = 0; i < length; i++) array[i] += 1;
}


