#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

/* Zähler Termine */
static int dates = 0;
/* Zähler Adressen */
static int nr = 0;

typedef struct {
    unsigned int stunde;
    unsigned int minute;
    unsigned int sekunde;
} uhrzeit;

typedef struct {
   unsigned int tag;
   unsigned int monat;
   int jahr;
} datum;

typedef struct {
   char vname[MAX];
   char nname[MAX];
   long PLZ;
   char ort[MAX];
   int geburtsjahr;
} adresse_t;
adresse_t adressen[100];

typedef struct {
   datum d;
   uhrzeit z;
   adresse_t a;
} termin_t;
termin_t termine[100];

/* Funktionsprototypen */
void newdate(termin_t *t);
int suche(char *);
void listdate(termin_t *list,int);
void replacedate(termin_t *aendern,int);
void sortdate(termin_t *sort,int);
void Eingabe(adresse_t *neu);
void Ausgabe(adresse_t *adressen);
void Sortadress(adresse_t *adressen);

void newdate(termin_t *t) {
   int auswahl,ret;
   char such_name[MAX];

   printf("Tag.......: ");
   scanf("%u",&t[dates].d.tag);
   printf("Monat.....: ");
   scanf("%u",&t[dates].d.monat);
   printf("Jahr......: ");
   scanf("%d",&t[dates].d.jahr);
   printf("---------------------\n");
   printf("Stunde....: ");
   scanf("%u",&t[dates].z.stunde);
   printf("Minute(n).: ");
   scanf("%u",&t[dates].z.minute);
   printf("---------------------\n");

   printf("\nTermin mit :\n -1- Neuer Adresse\n");
   printf(" -2- Vorhandener Adresse\n");
   printf("Ihre Auswahl : ");
   do {
      scanf("%d",&auswahl);
   } while(getchar()!= '\n');

   if(auswahl == 1) {
      printf("Vorname.....: ");
      fgets(t[dates].a.vname, MAX, stdin);
      printf("Nachname....: ");
      fgets(t[dates].a.nname, MAX, stdin);
      printf("Postleitzahl: ");
      do {
         scanf("%ld",&t[dates].a.PLZ);
      } while(getchar()!= '\n');
      printf("ORT.........: ");
      fgets(t[dates].a.ort, MAX, stdin);
      printf("Geburtsjahr..: ");
      do {
         scanf("%d",&t[dates].a.geburtsjahr);
      } while(getchar()!= '\n');

      /* Neue Adresse kommt auch zum neuen Adresssatz. */
      strcpy(adressen[nr].vname, strtok(t[dates].a.vname, "\n"));
      strcpy(adressen[nr].nname, strtok(t[dates].a.nname, "\n"));
      adressen[nr].PLZ = t[dates].a.PLZ;
      strcpy(adressen[nr].ort, t[dates].a.ort);
      adressen[nr].geburtsjahr=t[dates].a.geburtsjahr;
      dates++;
      nr++;
   }
   else {
      printf("Bitte geben Sie den Nachnamen ein : ");
      fgets(such_name, MAX, stdin);
      ret = suche(strtok(such_name,"\n"));
      if( ret == -1 ) {
         printf("Kein Eintrag vorhanden : %s ???", such_name);
         return;
      }
      strcpy(t[dates].a.vname,adressen[ret].vname);
      strcpy(t[dates].a.nname,adressen[ret].nname);
      t[dates].a.PLZ=adressen[ret].PLZ;
      strcpy(t[dates].a.ort,adressen[ret].ort);
      t[dates].a.geburtsjahr=adressen[ret].geburtsjahr;
      dates++;
   }
}

int suche(char *suchname) {
   int pos, found = 0;

   for(pos = 0; pos <= nr; pos++) {
      if(strcmp(adressen[pos].nname,suchname) == 0) {
         found = 1;
         break;
      }
   }
   if(found)
      return pos;
   else
      return -1;
}

void listdate(termin_t *list, int dates) {
   int i;

   for(i = 0; i < dates; i++) {
      printf("Nr. %d: ", i+1);
      printf("Termin am %02u.%02u.%04d ",
         list[i].d.tag, list[i].d.monat, list[i].d.jahr);
      printf("um %02u.%02u Uhr\n",
         list[i].z.stunde, list[i].z.minute);
      printf("mit %s %s\n\n", list[i].a.vname, list[i].a.nname);
      }
}

void replacedate(termin_t *aendern, int nt) {
    if(nt <= dates && nt < 20) {
        printf("Bitte neue Terminzeit eingeben!!\n");
        printf("Tag..........: ");
        scanf("%u",&aendern[nt].d.tag);
        printf("Monat........: ");
        scanf("%u",&aendern[nt].d.monat);
        printf("Jahr.........: ");
        scanf("%d",&aendern[nt].d.jahr);
        printf("------------------------\n");
        printf("Stunden......: ");
        scanf("%u",&aendern[nt].z.stunde);
        printf("Minuten......: ");
        scanf("%u",&aendern[nt].z.minute);
      }
    else
       printf("Falsche Eingabe : %d\n", nt);

}

void sortdate(termin_t *sort, int dates) {
   termin_t *temp;
   int i,j;

   temp = (termin_t*)malloc(sizeof(termin_t));
   if(NULL == temp) {
      printf("Konnte keinen Speicher reservieren ...\n");
      return;
   }
   for(i = 0; i < dates; i++) {
      for(j = i + 1; j < dates; j++) {
         if(sort[i].d.jahr > sort[j].d.jahr) {
            *temp=sort[j];
            sort[j]=sort[i];
            sort[i]=*temp;
         }
      }
   }
   printf("... sortiert!!\n");
}

void Eingabe(adresse_t *neu) {
   unsigned int size;

   printf("Vorname : ");
   fgets(neu[nr].vname, MAX, stdin);
   /* newline-Zeichen entfernen */
   size = strlen(neu[nr].vname);
   neu[nr].vname[size-1] = '\0';

   printf("Nachname : ");
   fgets(neu[nr].nname, MAX, stdin);
   /* newline-Zeichen entfernen */
   size = strlen(neu[nr].nname);
   neu[nr].nname[size-1] = '\0';

   printf("Postleitzahl: ");
   do {
      scanf("%ld",&neu[nr].PLZ);
   } while(getchar()!= '\n');
   printf("Wohnort : ");
   fgets(neu[nr].ort, MAX, stdin);
   printf("Geburtsjahr : ");
   do {
      scanf("%d",&neu[nr].geburtsjahr);
   } while(getchar()!= '\n');
   nr++;
}

void Ausgabe(adresse_t *all) {
   int i;

   for(i = 0; i < nr; i++) {
      printf("Vorname.........:%s\n", all[i].vname);
      printf("Nachname........:%s\n", all[i].nname);
      printf("Postleitzahl....:%ld\n", all[i].PLZ);
      printf("Ort.............:%s", all[i].ort);
      printf("Geburtsjahr.....:%d\n\n", all[i].geburtsjahr);
      if( (!(i%2)) && i!=0) {
         // fflush(stdin);
         printf("\n\tWeiter mit <Enter>\n\n");
         getchar();
      }
   }
}

void Sortadress(adresse_t *sort) {
   adresse_t *temp;
   int i,j;

   temp = (adresse_t*)malloc(sizeof(adresse_t));
   if(NULL == temp) {
      printf("Konnte keinen Speicher reservieren ...\n");
      return;
   }
   for(i = 0; i < nr; i++) {
      for(j = i + 1; j < nr; j++) {
         if(strcmp(sort[i].nname, sort[j].nname)>0) {
            *temp=sort[j];
            sort[j]=sort[i];
            sort[i]=*temp;
         }
      }
   }
   printf("... sortiert!!\n");
}

int main(void) {
   int eingabe,aendern;

   do {
      printf("\tTerminverwaltung\n");
      printf("\t----------------\n\n");
      printf("\t-1- Neuer Termin\n");
      printf("\t-2- Termine auflisten\n");
      printf("\t-3- Termin ändern\n");
      printf("\t-4- Termine sortieren\n");
      printf("\t-5- Neue Adresse eingeben\n");
      printf("\t-6- Adressen ausgeben\n");
      printf("\t-7- Adressen sortieren\n");
      printf("\t-8- Programm beenden\n");
      printf("\n\tIhre Auswahl : ");
      scanf("%d",&eingabe);
      /* fflush(stdin); */
      getchar();
      switch(eingabe) {
         case 1  : newdate(termine);            break;
         case 2  : listdate(termine,dates);     break;
         case 3  : listdate(termine,dates);
                  printf("Welchen Termin ändern(Nr.?):");
                  scanf("%d",&aendern);
                  replacedate(termine,--aendern);
                  break;
         case 4  : sortdate(termine,dates);     break;
         case 5  : Eingabe(adressen);          break;
         case 6  : Ausgabe(adressen);          break;
         case 7  : Sortadress(adressen);       break;
         default : break;
      }
   } while(eingabe < 8);
   printf("Bye\n");
   return EXIT_SUCCESS;
}
