#include <stdio.h>

// The array decays to a pointer to sensors[0]
// think about like printSensors(&sensors[0], 5);
void printSensors(const int *values, int count) {
    for (int i = 0; i < count; i++) {
        printf("Sebsor %d = %d\n", i, values[i]);
    }
}

double totalPrice(const double *prices, int count) {
    double sum = 0.0;

    for (int j = 0; j < count; j++) {
        sum += prices[j];
    }
    return sum;
}

int main(void) {
    int sensors[5] = {21, 18, 25, 19 ,22 };
    double cart[4] = {12.99, 5.49, 3.00, 7.50};

    printSensors(sensors, 5);

    double total = totalPrice(cart, 4);
    printf("Total: %.2f\n", total);
    return 0;
}