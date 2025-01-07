#include<stdio.h>
#include<stdlib.h>

int main(void) {
   char str[100];

   printf("Geben Sie ein paar Wörter ein : ");
   fgets(str, 100, stdin);
   printf("Ihre Eingabe: %s\n",str);
   return EXIT_SUCCESS;
}
