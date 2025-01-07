#include<stdio.h>
#include<stdlib.h>  /* f�r die Bibliotheksfunktion rand() */
#include<time.h> /* F�r clock() */

int main(void) {
   srand(clock());
   int ratezahl, count=0, erraten=0;
   int zufall = (rand()%10)+1; /* Pseudo-Zufallszahl von 1-10 */

   do {
      printf("Zahleingabe bitte (1-10): ");
      scanf("%d", &ratezahl);
      if(ratezahl==zufall) {  /* Zahl richtig geraten ... ? */
         erraten=1;           /* Ja, die Zahl ist richtig   */
         count++;
      }
      else {
         (ratezahl > zufall) ?
            printf("kleiner\n") : printf("gr�sser\n");
         count++;
      }
   } while( (erraten != 1) && (count != 3) );

   if(erraten == 0) {
      printf("Sie haben 3 Chancen vertan ;) \n");
      printf("Die Zahl w�re %d gewesen: \n", zufall);
   }
   else
      printf("Mit %d Versuchen erraten!\n",count);
   return 0;
}
