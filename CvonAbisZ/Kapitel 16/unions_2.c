#include<stdio.h>
#include<stdlib.h>

typedef union {
   float x;
   int y;
} number;

int main(void) {
   number mixed[3];

   mixed[0].x = 1.123;
   mixed[1].y = 123;
   mixed[2].x = 2.345;
   printf("%.2f\t%d\t%.2f\n",
      mixed[0].x, mixed[1].y, mixed[2].x);
   return EXIT_SUCCESS;
}
