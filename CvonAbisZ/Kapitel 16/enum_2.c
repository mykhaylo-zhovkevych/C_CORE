#include<stdio.h>
#include<stdlib.h>

typedef enum {false,true} bool;

int main(void) {
   int zahl;
   printf("Gib mir eine Zahl (0-9): ");

   if( (scanf("%d",&zahl)) == false )
      printf("Das war keine Zahl!\n");
   else
      printf("Vielen Dank!\n");

   if( (zahl==7) == true)
      printf("Wow, die 7, meine Lieblingszahl\n");
   return EXIT_SUCCESS;
}
