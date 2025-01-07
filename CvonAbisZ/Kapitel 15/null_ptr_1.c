#include<stdio.h>
#include<stdlib.h>

int main(void) {
   char *ptr1 = NULL;
   char *ptr2 = 0;

   if(ptr1 == NULL){
      printf("ptr1 ist ein Nullzeiger.\n");
   }
   if(ptr2 == 0) {
      printf("ptr2 ist ein Nullzeiger.\n");
   }
   return EXIT_SUCCESS;
}
