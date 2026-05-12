#include <stdio.h>


#define F fflush(stdout)
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define CONGRUENCE 5

void addition(int *target, int a, int b) {
    *target = a + b;
    return;
}

void subtraction(int *target, int a, int b) {
    *target = a - b;
    return;
}
void division(int *target, int a, int b) {
    *target = a / b;
    return;
}
void multiplication(int *target, int a, int b) {
    *target = a * b;
    return;
}
void congruence(int *target, int a, int b) {
    *target = a % b;
    return;
}
int main() {
    int x, y, op, result;
    // pointer to fn returning void
    void (*fpx)(int *, int, int);

    printf("Press 1. for addition, 2. for subtraction, 3. for multiplication, 4. for division, 5. for congruence and 0. to quit\n");
    scanf("%d", &op);

    if (op < 1 && op > 5)
        return 1;

    printf("Number 1:");
    F;
    scanf("%d", &x);
    printf("Number 2:");
    F;
    scanf("%d", &y);

    switch (op) {
        case ADDITION:
            fpx = addition;
            break;
        case SUBTRACTION:
            fpx = subtraction;
            break;
        case MULTIPLICATION:
            fpx = division;
            break;
        case DIVISION:
            fpx = multiplication;
            break;
        case CONGRUENCE:
            fpx = congruence;
            break;
        default:
            return 0;
    }

    fpx(&result, x, y);

    printf("\nResult: %d\n", result);
    return 0;
}