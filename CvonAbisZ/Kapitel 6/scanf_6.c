#include<stdio.h>

int main(void) {
   char a;
   int b, check;

   printf("Bitte Eingabe machen (Zeichen/Zahl): ");
   check = scanf("%c %d",&a, &b);
   printf("check = %d \n",check);
   return 0;
}
