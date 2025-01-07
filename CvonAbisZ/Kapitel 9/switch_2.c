#include<stdio.h>

int main(void) {
   int a;
   printf("Bitte eine Zahl von 1-5 eingeben: ");
   scanf("%d", &a);

   switch(a) {
      case 1: printf("Das war eins oder...");
      case 2: printf("...zwei \n");
              break;
      case 3: printf("Das war drei \n");
              break;
      case 4: printf("Das war vier...");
      case 5: printf("...oder fünf \n");
              break;
      }      /* Ende switch */
   return 0;
}
