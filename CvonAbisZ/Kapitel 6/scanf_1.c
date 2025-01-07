#include <stdio.h>

int main (void) {
   int i;               /* ein ganzzahliger Datentyp */
   printf("Bitte geben Sie eine Zahl ein : ");
   scanf("%d",&i);      /* i einlesen (bitte das & nicht vergessen!) */
   printf("Die Zahl, die Sie eingegeben haben, war %d\n",i);
   return 0;
}
