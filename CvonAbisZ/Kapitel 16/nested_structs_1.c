#include<stdio.h>
#include<stdlib.h>

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
   datum d;
   uhrzeit z;
} termin_t;

int main(void) {
   termin_t t = { {19, 12, 2004}, {20, 15, 0} };
   printf("Termin am ");
   printf("%u.%u.%d um ", t.d.tag, t.d.monat, t.d.jahr);
   printf("%u.%u.%u0 Uhr \n\n",
      t.z.stunde, t.z.minute, t.z.sekunde);

   printf("Neuen Termin eingeben !!\n\n");
   printf("Tag.............: ");
   scanf("%u",&t.d.tag);
   printf("Monat...........: ");
   scanf("%u",&t.d.monat);
   printf("Jahr............: ");
   scanf("%d",&t.d.jahr);
   printf("\n");
   printf("Stunde..........: ");
   scanf("%u",&t.z.stunde);
   printf("Minuten.........: ");
   scanf("%u",&t.z.minute);
   printf("Sekunden........: ");
   scanf("%u",&t.z.sekunde);
   printf("\n");
   printf("Neuer Termin am ");
   printf("%02u.%02u.%04d um ",t.d.tag, t.d.monat, t.d.jahr);
   printf("%02u.%02u.%02u Uhr \n",
      t.z.stunde, t.z.minute, t.z.sekunde);
   return EXIT_SUCCESS;
}
