#include <stdio.h>

// normal function can return only one value directly, but with pointers multiple results can be returned
void calulate(int a, int b, int *sum, int *difference, int *product) {
    *sum = a + b;
    *difference = a - b;
    *product = a * b;
}

int main() {

    int s, d, p;

    calulate(10, 3, &s, &d, &p);

    printf("Sum: %d\n", s);
    printf("Difference: %d\n", d);
    printf("Product: %d\n", p);

    return 0;
}
