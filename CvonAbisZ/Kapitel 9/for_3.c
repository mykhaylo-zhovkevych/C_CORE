#include<stdio.h>
#include<time.h>

void delay(long int Millis) {
    long int Now=clock(); // Now=Zeit im Millisekunden beim Aufruf der Schleife (für Windows)
    // Millis*=1000; Auf dem Raspberry Pi ist die Zeit in Mikrosekunden, hier bitte diese Zeile einfügen
    while ((clock()-Now)<Millis) { }
}

int main(void) {
   int sek;
   for(sek = 5; sek > 0; sek--)
   {
      printf("%d Sekunden!\n", sek);
      delay(1000); // Hier eine Sekunde warten
   }
   printf("Die Zeit ist abgelaufen! \n");
   return 0;
}
