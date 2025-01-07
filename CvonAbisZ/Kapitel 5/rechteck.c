#include<stdio.h>

int main(void) {
   /* Deklaration */
   float flaeche, l, b; // Keine Umlaute in Variablennamen!

   printf("Berechnung der Fläche eines Rechtecks\n");
   /* Werte einlesen */
   printf("Länge des Rechtecks: ");
   scanf("%f",&l);
   printf("Breite des Rechtecks: ");
   scanf("%f",&b);
   /* Fläche berechnen */
   flaeche = l * b;
   printf("Fläche des Rechtecks beträgt : %f\n",flaeche);
   return 0;
}
