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
   printf("struct ben�tigt %d Bytes\n", sizeof(test1));
   printf("Union  ben�tigt %d Bytes\n", sizeof(test2));
   return EXIT_SUCCESS;
}
