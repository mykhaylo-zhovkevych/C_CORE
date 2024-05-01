#include <stdio.h>

/* int main(void) 
{
    int i = 0;

    // variablescope the i can not be accessed outside the for loop 
    for ( i = 0; i < 10; i++)
    {
        printf("i: %d\n", i);
    }
    
    return 0;
}

 */

/* int main(void) {
    double initial = 0, step = 0, stop = 0;

    do
    {
        printf("Initial (m): ");
        scanf("%lf", &initial);
      
      if(initial < 0 ) printf("Must be >=0"); 
    } while (initial < 0);

    do
    {
        printf("Step (m): ");
        scanf("%lf", &step);
      
      if(step <= 0 ) printf("Must be >0 "); 
    } while (step <= 0);

    do
    {
        printf("stop (m): ");
        scanf("%lf", &stop);
      
      if(stop < 0 ) printf("Must be >=0"); 
    } while (stop < 0);

    printf("\n");
        // initial statment     //conditiion     //update statment
    for (double conv = initial; conv <= stop; conv += step)
    {
        printf("%f %f\n", conv, conv * 3.28084);
    }

    return 0;

} */

#include <stdio.h>

int main(void) {
    double initial = 0, step = 0, stop = 0;
    int result; // To store the return value of scanf

    do {
        printf("Initial (m): ");
        result = scanf("%lf", &initial);
        if (result != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); //  If the input is not numeric (scanf return is not 1), the program clears the input buffer up to the newline character to prepare for the next input attempt. This is done 
        } else if (initial < 0) {
            printf("Must be >=0\n");
        }
    } while (result != 1 || initial < 0);

    do {
        printf("Step (m): ");
        result = scanf("%lf", &step);
        if (result != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else if (step <= 0) {
            printf("Must be >0\n");
        }
    } while (result != 1 || step <= 0);

    do {
        printf("Stop (m): ");
        result = scanf("%lf", &stop);
        if (result != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else if (stop < 0) {
            printf("Must be >=0\n");
        }
    } while (result != 1 || stop < 0);

    printf("\n");
    for (double conv = initial; conv <= stop; conv += step) {
        printf("%f %f\n", conv, conv * 3.28084); // Convert meters to feet
    }

    return 0;
}
