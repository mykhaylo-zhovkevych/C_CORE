#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

typedef struct {
   char vname[MAX];
   char nname[MAX];
   long PLZ;
   char ort[MAX];
   int geburtsjahr;
} adresse_t;

int cmp_structs(adresse_t *str1, adresse_t *str2) {
   /* Vorname gleich und */
   if(strcmp(str1->vname, str2->vname) == 0 &&
      /* Nachname gleich und */
      strcmp(str1->nname, str2->nname) == 0 &&
      /* Postleitzahl gleich und */
      (str1->PLZ-str2->PLZ) == 0 &&
      /* Wohnort gleich und */
      strcmp(str1->ort, str2->ort) == 0 &&
      /* geburtsjahr gleich */
      (str1->geburtsjahr-str2->geburtsjahr) == 0)
         return 0;    /* Beide Strukturen gleich */
   else
      return 1;       /* Strukturen nicht gleich */
}

int main(void) {
   // Die nächsten zwei Zeilen funktionieren leider nicht überall
   adresse_t adresse1={"John","Leroy",1234,"New York",1980 };
   adresse_t adresse2={"John","Leroy",1234,"New York",1980 };

   if(cmp_structs(&adresse1, &adresse2) == 0)
      printf("Beide Strukturen sind gleich.\n");
   else
      printf("Die Strukturen weisen Unterschiede auf.\n");
   return EXIT_SUCCESS;
}
