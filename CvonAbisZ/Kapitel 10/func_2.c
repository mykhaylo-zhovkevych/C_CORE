#include<stdio.h>

void hilfe(void); // Vorwärtsdeklarationen sind in C erlaubt

int main(void) {
   hilfe();
   return 0;
}

void hilfe(void) {
   printf("Ich bin die Hilfsfunktion\n");
}
