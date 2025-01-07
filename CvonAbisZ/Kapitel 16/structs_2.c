#include<stdio.h>
#include<stdlib.h>
#define MAX 30

typedef struct {
   char vname[MAX];
   char nname[MAX];
   long PLZ;
   char ort[MAX];
   int geburtsjahr;
} adresse_t;

/* Funktion zur Ausgabe des Satzes */
void ausgabe(adresse_t adresse) {
   printf("\n\nSie gaben ein:\n\n");
   printf("Vorname.........:%s",   adresse.vname);
   printf("Nachname........:%s",   adresse.nname);
   printf("Postleitzahl....:%ld\n",adresse.PLZ);
   printf("Ort.............:%s",   adresse.ort);
   printf("Geburtsjahr.....:%d\n", adresse.geburtsjahr);
}

int main(void) {
   adresse_t adresse;
   printf("Vorname      : ");
   fgets(adresse.vname, MAX, stdin);
   printf("Nachname     : ");
   fgets(adresse.nname, MAX, stdin);
   printf("Postleitzahl : ");
   do {
      scanf("%5ld",&adresse.PLZ);
   } while(getchar()!= '\n');
   printf("Wohnort      : ");
   fgets(adresse.ort, MAX, stdin);
   printf("Geburtsjahr  : ");
   do {
      scanf("%4d",&adresse.geburtsjahr);
   } while(getchar()!='\n' );

   ausgabe(adresse);
   return EXIT_SUCCESS;
}
