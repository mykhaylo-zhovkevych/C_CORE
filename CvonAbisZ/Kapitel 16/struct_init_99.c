#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30

typedef struct { // Ab jetzt benutzen wir immer "typedef struct"
   char vname[MAX];
   char nname[MAX];
   long PLZ;
   char ort[MAX];
   int geburtsjahr;
} adresse; // Oder noch besser: adresse_t

/*Funktion zur Ausgabe des Satzes*/
void ausgabe(adresse a) {
   printf("\n\nSie gaben ein:\n\n");
   printf("Vorname.........:%s\n",   a.vname);
   printf("Nachname........:%s\n",   a.nname);
   printf("Postleitzahl....:%ld\n",a.PLZ);
   printf("Ort.............:%s\n",   a.ort);
   printf("Geburtsjahr.....:%d\n", a.geburtsjahr);
}

int main(void) {
   adresse adressen1 = { // Ist OK, da s�mtliche Elemente angegeben werden
      "Donald",
      "Duck",
       12345,
      "Entenhausen",
      1950
   };

   adresse adressen2; // Diese Struktur wird nicht vollst�ndig initialisiert
   // Vorname und Geburtsjahr enthalten unter Umst�nden Unsinn!
   strcpy(adressen2.ort,"Entenhausen");
   adressen2.PLZ=12345;
   strcpy(adressen2.nname,"Duck");

   adresse adressen3 = { // OK, denn durch das vorige "typedef" wird hier der n�tige Speicher reserviert
       "", // OK, Vorname sp�rter noch �nderbar
       "", // OK, Nachname sp�ter noch �nderbar
      12345,
      "Entenhausen",
       1950
   };

   ausgabe(adressen1);
   ausgabe(adressen2);
   ausgabe(adressen3);
   return EXIT_SUCCESS;
}
