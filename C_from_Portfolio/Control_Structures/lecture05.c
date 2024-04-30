// while loop // 1:09:14 / 5:48:37
#include <stdio.h>

/* int main(void) {
    int i = 0;

    while (i <= 10)
    {
        printf("i: %d\n", i);
        //i = i + 1;

        //shortcuts
        //i += 1; or i ++;
        i ++;
    }

    return 0;
}
 */

/* int main(void) {
    int i = 0;

    int number = 0;
    int total = 0;
    int total_numbers = 0;

    printf("how many numbers:");
    scanf("%d", &total_numbers);

    while (i < total_numbers)
    {
        printf("Enter Numbewr %d: ", i+1); // here the i+1 is like to prevent from showing the 0 
        scanf("%d", &number);
        total = total + number;
        i ++;
    }
    printf("total: %d\n", total);
    printf("averge: %d\n", total/ total_numbers);

    return 0;
}
 */


void printNumbers() {
    int i = 0;
    while (i <= 10) {
        printf("i: %d\n", i);
        i++;
    }
}

void sumAndAverage() {
    int i = 0, number = 0, total = 0, total_numbers = 0;

    printf("How many numbers: ");
    scanf("%d", &total_numbers);

    while (i < total_numbers) {
        printf("Enter Number %d: ", i + 1);
        scanf("%d", &number);
        total += number;
        i++;
    }

    printf("Total: %d\n", total);
    printf("Average: %d\n", total / total_numbers);
}


// this is undefined loop where i used printf methods to debugge the programm 
// using the printf methods can be usefull for debugging purposes 
void findMaximum() {
    int number = 0, max = -1;

    printf("Enter numbers (type -1 to end): ");
    while (number != -1) {
        scanf("%d", &number);
        if (number > max && number != -1)
            max = number;
        printf("Current max: %d\n", max);
    }

    printf("Final max: %d\n", max);
}

int main(void) {
    printNumbers();     // Function to print numbers from 0 to 10
    sumAndAverage();    // Function to compute sum and average of user-input numbers
    findMaximum();      // Function to find the maximum of entered numbers

    return 0;
}
