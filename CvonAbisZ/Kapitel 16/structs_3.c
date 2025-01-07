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

   ausgabe(&adresse); // Hier muss der Address-Of-Operator stehen!
   return EXIT_SUCCESS;
}
