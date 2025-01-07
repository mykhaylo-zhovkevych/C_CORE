#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF 255

int main(void) {
   size_t len;
   char *str = NULL;
   char puffer[BUF];

   printf("Ein dynamisches char-Array f�r Strings\n");
   printf("Eingabe machen : ");
   fgets(puffer, BUF, stdin);
   str = malloc(strlen(puffer)+1);
   if(NULL == str) {
      printf("Kein virtueller RAM mehr vorhanden ... !");
      return EXIT_FAILURE;
   }
   strcpy(str, puffer);
   printf("Weitere Eingabe oder beenden mit \"END\"\n>");
   /* Endlossschleife */
   while(1) {
      fgets(puffer, BUF, stdin);
      /* Abbruchbedingung */
      if(strcmp(puffer,"end\n")==0 || strcmp(puffer,"END\n")==0)
         break;
       /* aktuelle L�nge von str z�hlen f�r realloc */
       len = strlen(str);
       /* neuen Speicher f�r str anfordern */
       str = realloc(str,strlen(puffer)+len+1);
       if(NULL == str) {
          printf("Kein virtueller RAM mehr vorhanden ... !");
          return EXIT_FAILURE;
       }
       /* Hinten anh�ngen */
       strcat(str, puffer);
   }
   printf("Ihre Eingabe lautete: \n");
   printf("%s", str);
   free(str);
   return EXIT_SUCCESS;
}
