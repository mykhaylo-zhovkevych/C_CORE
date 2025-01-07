#include<stdio.h>
#include<stdlib.h>

typedef struct { int wert[3]; } array; // Diese Typendefinition
                                      // reserviert den Speicher
void output_array(array z) {
   int i;

   for(i = 0; i < sizeof(array) / sizeof(int); i++)
      printf("%d\t", z.wert[i]);
   printf("\n");
}

int main(void) {
   array new_array;

   new_array.wert[0] = 10;
   new_array.wert[1] = 20;
   new_array.wert[2] = 30;

   /* call-by-value */
   output_array(new_array);
   return EXIT_SUCCESS;
}
