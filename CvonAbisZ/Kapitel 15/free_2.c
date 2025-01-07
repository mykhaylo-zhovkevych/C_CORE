#include<stdio.h>
#include<stdlib.h>

int main(void) {
   int *p = malloc(sizeof(int));

   if(p != NULL) {
         *p=99;
         printf("Allokation erfolgreich ... \n");
   }
   else {
      printf("Kein virtueller RAM mehr verfügbar ... \n");
      return EXIT_FAILURE;
   }
   printf("vor free() *p = %d\n", *p); // 99
   if(p != NULL)
      free(p);
   printf("nach free() *p = %d\n", *p); // evtl. Unsinn
   return EXIT_SUCCESS;
}
