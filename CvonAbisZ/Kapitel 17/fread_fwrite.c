#include<stdio.h>
#include<stdlib.h>

typedef struct {
   char vorname[20];
   char nachname[30];
   char strasse[30];
   char hausnummer[5];
   char plz[7];
   char ort[30];
   char sternzeichen[30];
   char alter[3];
} adresse_t;

adresse_t adresse;

void speichern(void) {
   FILE *save = fopen("adressen.dat","r+b");
   if( NULL == save ) {
      save = fopen("adressen.dat","w+b");
      if( NULL == save ) {
         fprintf(stderr,"Kann \"adressen.dat\" nicht öffnen!\n");
         return;
      }
   }
   /* FILE-Zeiger save auf das Ende der Datei setzen */
   fseek(save, 0, SEEK_END);

   /* Wir schreiben eine Adresse ans Ende von "adressen.dat". */
   if(fwrite(&adresse, sizeof(adresse), 1, save) != 1) {
      fprintf(stderr, "Fehler bei fwrite...!!!\n");
      return;
   }
   /* Wir geben unseren FILE-Zeiger wieder frei. */
   fclose(save);
}

void ausgabe(void) {
   FILE *output = fopen("adressen.dat","r+b");
   if( NULL == output ) {
      fprintf(stderr,"Kann \"adressen.dat\" nicht öffnen!\n");
      return;
   }
   /* Wir lesen alle Adressen aus "adressen.dat". */
   while(fread(&adresse, sizeof(adresse), 1, output) == 1) {
      printf("Vorname...........: %s",adresse.vorname);
      printf("Nachname..........: %s",adresse.nachname);
      printf("Strasse...........: %s",adresse.strasse);
      printf("Hausnummer........: %s",adresse.hausnummer);
      printf("Postleitzahl......: %s",adresse.plz);
      printf("Ort...............: %s",adresse.ort);
      printf("Sternzeichen......: %s",adresse.sternzeichen);
      printf("Alter.............: %s",adresse.alter);
      printf("\n\n");
   }
   fclose(output);
}
void eingabe(void) {
   printf("Vorname...........:");
   fgets(adresse.vorname, sizeof(adresse.vorname), stdin);
   printf("Nachname..........:");
   fgets(adresse.nachname, sizeof(adresse.nachname),stdin);
   printf("Strasse...........:");
   fgets(adresse.strasse, sizeof(adresse.strasse), stdin);
   printf("Hausnummer........:");
   fgets(adresse.hausnummer,sizeof(adresse.hausnummer),stdin);
   printf("Postleitzahl......:");
   fgets(adresse.plz, sizeof(adresse.plz), stdin);
   printf("Ort...............:");
   fgets(adresse.ort, sizeof(adresse.ort), stdin);
   printf("Sternzeichen......:");
   fgets(adresse.sternzeichen,sizeof(adresse.sternzeichen),
      stdin );
   printf("Alter.............:");
   fgets(adresse.alter, sizeof(adresse.alter), stdin);
   speichern();
}

int main(void) {
   int wahl;

   do {
      printf("Was wollen Sie machen:\n\n");
      printf("-1- Neuen Datensatz hinzufuegen\n");
      printf("-2- Alle Datensaetze ausgeben\n");
      printf("-3- Programm beenden\n\n");
      printf("Ihre Auswahl : ");
      do {
         scanf("%d",&wahl);
      } while(getchar() != '\n');
      switch(wahl) {
         case 1 : eingabe();        break;
         case 2 : ausgabe();        break;
         case 3 : printf("...Programm wird beendet\n");
                  break;
         default: printf(">>%d<< ???\n",wahl);
      }
   } while(wahl != 3);
   EXIT_SUCCESS;
}
