#include<stdio.h>

int main(void) {
   /* Deklaration */
   float flaeche, l, b; // Keine Umlaute in Variablennamen!

   printf("Berechnung der Fl�che eines Rechtecks\n");
   /* Werte einlesen */
   printf("L�nge des Rechtecks: ");
   scanf("%f",&l);
   printf("Breite des Rechtecks: ");
   scanf("%f",&b);
   /* Fl�che berechnen */
   flaeche = l * b;
   printf("Fl�che des Rechtecks betr�gt : %f\n",flaeche);
   return 0;
}
