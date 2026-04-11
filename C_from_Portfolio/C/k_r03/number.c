#include <stdio.h>
#include <limits.h>

#define INT_MAX 1000

int main() {
    int num;
    char mode;

    // memory address of the num
    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    else if (num > INT_MAX) {
        printf("Number exceeds maximum integer limit.\n");
        num = INT_MAX;
    }


    printf("Mode (e)ven (o)dd (a)ll: ");
    scanf(" %c", &mode);


    switch (mode)
    {
    case 'e':
        printf("\nEven numbers up to %d:\n", num);
        for (int i = 2; i <= num; i += 2) {
            printf("%d ", i);
        }
        break;
    case 'o':
        printf("\nOdd numbers up to %d:\n", num);
        for (int i = 1; i <= num; i += 2)
            printf("%d ", i);
        break;

    case 'a':
        printf("\nAll numbers up to %d:\n", num);
        for (int i = 1; i <= num; i++)
            printf("%d ", i);
        break;

    default:
        printf("Unknown mode!\n");
        return 1;
    }

    int int_half = num / 2;
    float float_half = (float)num / 2; // cast to float for accurate division

    printf("\n\nInteger half: %d\n", int_half);
    printf("Floating-point half: %.2f\n", float_half);

    int big = INT_MAX;
    printf("\nINT_MAX: %d\n", big);
    printf("INT_MAX + 1 (overflow): %d\n", big + 1);

    // Read Only string pointer
    const char *label = (num % 2 == 0) ? "Even" : "Odd";
    printf("\nThe number %d is %s.\n", num, label);

    // compound expression
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i;
    } 
    printf("Sum of 1..%d = %d\n", num, sum);

    return 0;

}