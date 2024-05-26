// Dynamically allocated memory (malloc, calloc, realloc, free)

#include <stdio.h>
#include <stdlib.h>
// stack memory
// variable   address   value
// a          12        5
// b          13        6
// c          14        8
// d          15        10
// e[0]       16        0
// e[1]       17        1
// ...
// e[9]       25        5
// f          26        9

int main(void) {

    // generaly wehn i declared varible the existing in the stack memory will occure
    int f = 5;
    int b = 6;

    int *a;
    // creates heap space for 5 integers
    // calloc test zero as in te defaut at this is more time consumig overall but at least i know what will be there
    // the malloc will set some random values it it is not changed
    //a = malloc(sizeof(int) * 5); 
    a = calloc(5, sizeof(int));
    // the malloc will return the memory addresse where that block of space will return a pointer 
    // after that i need make the dynamically allocated array

    // all what happening here is i got this block of memory and i have pointer to it and i am accessing with array notation 
    a[0] = 1;
    a[1] = 5;
    a[2] = 7;
    a[3] = 9;
    a[4] = 11;
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    // reason for using the allocated memory is that ii memory can be extended and changed, for Extendable Memory: realloc

    free(a);

/*  Why free is Important

    Preventing Memory Leaks:
    When you allocate memory dynamically using malloc or calloc, the memory is taken from the heap. If you do not release this memory using free, it will remain allocated even after the program has finished using it. This leads to memory leaks, where the program consumes more and more memory over time, which can eventually exhaust the available memory, causing the program or the system to run out of memory.

    Efficient Memory Management:
    Properly freeing memory helps in managing the system's memory efficiently. By releasing memory that is no longer needed, you make it available for other processes and parts of your program. This is crucial in long-running programs or those that use large amounts of memory dynamically.

    Avoiding Undefined Behavior:
    Not freeing dynamically allocated memory can lead to undefined behavior. If you lose the pointer to the allocated memory (for instance, by reassigning it or going out of scope), you can no longer free that memory, and it remains allocated, resulting in a memory leak.

    Good Programming Practice:
    Using free is part of good programming practices in C. It ensures that your program is clean and that resources are properly managed. This is particularly important in larger and more complex programs where managing resources efficiently can significantly affect performance and stability. 
*/

    // EXAMPLE APPLICATION THAT RECEIVES NUMBERS AND EXPANDS ITS INPUT CAPACITY IF NECESSARY AND RETURNS THE TOTAL NUMBER FOR ALL INPUTS
    int *numbers;
    int size = 2;
    numbers = malloc(sizeof(int) * size);
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int input = 0, counterOfNumbers = 0;

    do {
    
        // better way of doing it with the temporary pointer 
        /* if (counterOfNumbers == size) {
            size += 2;
            int *temp = realloc(numbers, sizeof(int) * size);
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(numbers);
                return 1;
            }
            numbers = temp;
        } */

        // If the array is full, expand it
        if (counterOfNumbers == size) {
            size += 2;
            numbers = realloc(numbers, sizeof(int) * size);
            printf("Realloc for %d ints\n", size);
            
        }

        printf("Enter a number (-1 to quit): ");
        scanf("%d", &input);

        if (input != -1) {
            numbers[counterOfNumbers] = input;
            counterOfNumbers++;
        }
    } while (input != -1);

    int total = 0;
    for (int i = 0; i < counterOfNumbers; i++) {
        total += numbers[i];
    }

    if (counterOfNumbers > 0) {
        float average = (float) total / counterOfNumbers;
        printf("Average: %.2f\n", average);
    } else {
        printf("No numbers were entered.\n");
    }

    free(numbers);

    return 0;
}

void func() {

    int c = 8;
    int d = 10;
    int e[10];
    int f = 9;

    // this will not work:
    // int e[11];
    // to make it possibel this is where the dynamical memory allocation come in 
    //  dynamical memory allocation will exist at the heap 

}
