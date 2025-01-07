#include<stdio.h>
#include<stdlib.h>

int main(void) {
   char string[100];

   printf("Geben Sie ein paar Wörter ein: ");
   scanf("%99s", &string[0]);

   printf("Ihre Eingabe: %s\n",string);
   return EXIT_SUCCESS;
}
