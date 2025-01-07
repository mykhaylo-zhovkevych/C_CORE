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
void ausgabe(adresse_t *struct_ptr) {
   printf("\n\nSie gaben ein:\n\n");
   printf("Vorname.........:%s",struct_ptr->vname);
   printf("Nachname........:%s",struct_ptr->nname);
   printf("Postleitzahl....:%ld\n",struct_ptr->PLZ);
   printf("Ort.............:%s",struct_ptr->ort);
   printf("Geburtsjahr.....:%d\n",struct_ptr->geburtsjahr);
}

adresse_t *eingabe(void) {
   adresse_t *adresse; // Dies ist quasi die "leere Hülle" von "adresse"
   adresse = (adresse_t*)malloc(sizeof(adresse_t)); // Typecasting nötig!
   printf("Vorname : ");
   fgets(adresse->vname, MAX, stdin);
   printf("Nachname : ");
   fgets(adresse->nname, MAX, stdin);
   printf("Postleitzahl : ");
   do {scanf("%ld",&adresse->PLZ);} while(getchar()!= '\n');
   printf("Wohnort : ");
   fgets(adresse->ort, MAX, stdin);
   printf("Geburtsjahr : ");
   do {
      scanf("%d",&adresse->geburtsjahr);
   }while(getchar()!='\n' );
   return adresse; // Der Rückgabetyp ist hier ein neuer Zeiger!
}

int main(void) {
   adresse_t *adresse1, *adresse2; // Hier darf das "*" nicht fehlen!

   adresse1=eingabe();
   adresse2=eingabe();

   ausgabe(adresse1);
   ausgabe(adresse2);
   return EXIT_SUCCESS;
}
