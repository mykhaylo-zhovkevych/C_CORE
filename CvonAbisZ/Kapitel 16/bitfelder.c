#include<stdio.h>
#include<stdlib.h>

#define OFF 0
#define ON 1

typedef struct {
   unsigned int Sensor1:1;
   unsigned int Sensor2:1;
   unsigned int Sensor3:1;
   unsigned int Schalter:1;
   unsigned int Ausgabe:4;
} roboter;
roboter Roboter1; // globale Variable vom Typ roboter

char *msg[7] = {
   "Kein Signal an Sensor 1!\n",
   "Kein Signal an Sensor 2!\n",
   "Kein Signal an Sensor 3!\n",
   "Schalter 1 nicht bet�tigt!\n",
   "Notaus bet�tigt!\n",
   "Kein Strom!\n"
};

int main(void) {
   int anzahl;

   do {
       printf("Wie viele Produkte von Pos.A nach Pos.B : ");
       do{ scanf("%d",&anzahl); } while(getchar() != '\n');

       while((anzahl>0) && (anzahl--)) {

          /* Sollte durch echte Schnittstelle ersetzt werden. */
          Roboter1.Sensor1=ON;
          printf("Sensor 1 ist aktiv\n");
          if(Roboter1.Sensor1 == ON)
             printf("Produkt wird aufgenommen und "
                    "zum Flie�band transportiert\n");
          else {

             /* Fehler: Sensor 1 nicht aktiv
              * Fehlermeldung ausgeben */
             Roboter1.Ausgabe = 0;
             printf("%s\n", msg[Roboter1.Ausgabe]);
          }
            /* Sollte durch echte Schnittstelle ersetzt werden. */
             Roboter1.Sensor2=ON;
             printf("Sensor 2 ist aktiv\n");
             if(Roboter1.Sensor2 == ON) {
                printf("Produkt ist auf dem Flie�band\n");
                printf("Bitte >>ENTER<< dr�cken"
                       " f�r den Schalter\n");
                getchar();
                printf("Schalter ist eingeschaltet!\n");
                /* Sollte durch echte Schnittstelle
                 * ersetzt werden. */
                Roboter1.Schalter=ON;
             }
             else {
                Roboter1.Ausgabe=1;
                printf("%s\n",msg[Roboter1.Ausgabe]);
                Roboter1.Ausgabe=3;
                printf("%s\n", msg[Roboter1.Ausgabe]);
             }
             /* Sollte durch echte Schnittstelle
              * ersetzt werden. */
             Roboter1.Sensor3=ON;
             printf("Sensor 3 aktiv\n");
             if(Roboter1.Sensor3 == ON) {
                printf("Produkt am Ziel angekommen!\n");
                printf("Schalter f�r Flie�band auf OFF\n");
                printf("Roboter wieder betriebsbereit\n");
                printf("Weiter mit >>ENTER<<\n");
                getchar();
                Roboter1.Schalter=OFF;
             }
             else {
                Roboter1.Ausgabe = 2;
                printf("%s\n", msg[Roboter1.Ausgabe]);
             }
       }
   } while(anzahl > 0);
   Roboter1.Sensor1=OFF;
   Roboter1.Sensor2=OFF;
   Roboter1.Sensor3=OFF;
   Roboter1.Ausgabe=0;
   printf("%s\n",msg[Roboter1.Ausgabe]);
   return EXIT_SUCCESS;
}
