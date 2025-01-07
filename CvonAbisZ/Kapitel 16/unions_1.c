#include<stdio.h>
#include<stdlib.h>

typedef struct {
   char a;
   int b;
   double c;
} test1;

typedef union {
   char a;
   int b;
   double c;
} test2;

int main(void) {
   printf("struct benötigt %d Bytes\n", sizeof(test1));
   printf("Union  benötigt %d Bytes\n", sizeof(test2));
   return EXIT_SUCCESS;
}
