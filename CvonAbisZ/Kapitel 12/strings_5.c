#include<stdio.h>
#include<stdlib.h>

char undbig[] = {
   "Hund und Katze sind nicht ohne "
   "Grund des Menschen beste Freunde\n"
};

int main(void) {
  int i;

  for(i=0; undbig[i] != '\0'; i++) {
     if(undbig[i-1]==' '&& (undbig[i]=='u' ||undbig[i]=='U')) {
        if(undbig[i+1]=='n'&&undbig[i+2]=='d'&&undbig[i+3]==' '){
           undbig[i] = 'U';
           /* n in Großbuchstaben konvertieren (N) */
           undbig[i+1] -= 32;
           /* d in Großbuchstaben konvertieren  (D) */
           undbig[i+2] -= 32;
        }
      }
   }
   printf("%s", undbig);
   return EXIT_SUCCESS;
}
