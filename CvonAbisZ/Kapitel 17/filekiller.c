#include<stdio.h>
#include<stdlib.h>

void my_remove(char *rm) {
   unsigned long size,i;
   char C;

   FILE *rem=fopen(rm, "w+b");
   if(rem != NULL)  {
      fseek(rem, 0L, SEEK_END);  /* Stream an das Dateiende   */
      size=ftell(rem);           /* Größe in Bytes ermitteln */
      /* kompletten Inhalt mit Zufallszahlen überschreiben */
      for (i=0; i<size; i++) {
          C=rand()%256; // Zufallszahlen zwischen 0 und 255
          fwrite(&C,1,1,rem); // Immer ein Byte schreiben
      }
      /* damit die Datei gelöscht werden kann, schliessen */
      fclose(rem);
      remove(rm);    /* Jetzt weg damit */
   }
}

int main(void) {
   char datei[] = "test.txt";
   my_remove(datei);
   return EXIT_SUCCESS;
}
