#include<stdio.h>
#include<stdlib.h>

int main(void) {
   FILE *datei;

   /* Bitte Pfad und Dateinamen anpassen */
   datei = fopen("test.txt", "r");
   if(NULL == datei) {
      printf("Konnte Datei \"test.txt\" nicht öffnen!\n");
      return EXIT_FAILURE;
   }
   printf("text.txt wurde erfolgreich geöffnet.\n");
   return EXIT_SUCCESS;
}
