#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

void strxcat(int n_strings, ...) {
   va_list zeiger;
   char *quelle, *ziel, *p;

   va_start(zeiger,n_strings);
   /* nun auf den Zielstring */
   ziel = va_arg(zeiger,char *);
   p = ziel;
   /* am Ende vom Zielstring */
   ziel+=strlen(ziel);
   if( (ziel-p) > MAX) {
      printf("!!!Maximale Anzahl an Zeichen ueberschritten!!!\n");
      return;
   }
   while(--n_strings > 0) {
      /* Quelle einlesen */
      quelle = va_arg(zeiger, char *);
      /* jetzt Zeichen f�r Zeichen an ziel */
      while(*quelle) {
         *ziel++ = *quelle++;
         if( (ziel-p) > MAX) {
            printf("!Maximale Anzahl an Zeichen ueberschritten!\n");
            exit(EXIT_FAILURE);
         }
      }
   }
   *ziel = '\0';
}

int main(void) {
   char string[MAX] = "Test : ";
   char string2[] = " Und";

   strxcat(3, string, "hallo " , "welt");
   printf("%s\n",string);

   strxcat(5, string, string2, " noch", " ein", " Test");
   printf("%s\n",string);

   /*Und nun ein Fehler mit Absicht*/
   strxcat(4, string , " Ueberlauf", " von", " MAX");
   printf("%s\n",string);
   return EXIT_SUCCESS;
}
