#include<stdio.h>
#include<stdlib.h>

int wert_global[5];

int main(void) {
   static int wert_static[5];
   int wert_auto[5];
   int i;

   for(i = 0; i < 5; i++)
      printf("%d:\t%10d\t%10d\t%10d\n",
         i, wert_global[i], wert_static[i], wert_auto[i] );
   return EXIT_SUCCESS;
}
