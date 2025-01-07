#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
   int seite;
   char titel[30];
} index;

int main(void) {
   index lib; // Hier benutzen wir den neu definierten Variablentyp "index"
   lib.seite = 23;
   strcpy(lib.titel, "C-Programmieren");
   printf("%d, %s\n",lib.seite, lib.titel);
   return EXIT_SUCCESS;
}
