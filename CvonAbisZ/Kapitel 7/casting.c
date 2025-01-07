#include<stdio.h>

int main(void) {
   int x = 5, y = 2;
   float z;
   // Implizite Datentypumwandlung
   z = x / y;
   printf("%f\n", z);             // = 2.000000
   // Explizite Datentypumwandlung
   z = (float) x / (float) y;
   printf("%f\n", z);             // = 2.500000
   return 0;
}
