#include<stdio.h>
#include<stdlib.h>

int main(void) {
   int *ptr;
   ptr = malloc(100);

   if(NULL == ptr) {
      printf("Kein virtueller RAM mehr vorhanden ... !");
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}
