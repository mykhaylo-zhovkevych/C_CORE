#include<stdio.h>
#include<stdlib.h>

/* bitte anpassen */
#define DATEI "datei.txt"

int main(void) {
   FILE *fp;
   int c;

   fp = fopen(DATEI, "r");
   if(fp == NULL) {
      fprintf(stderr, "Konnte %s nicht �ffnen\n", DATEI);
      return EXIT_SUCCESS;
   }
   while(1) {
      while( (c=fgetc(fp)) ) {      /* zeichenweise einlesen */
         if(c == EOF)           /* Ist es EOF? */
            ungetc(c,fp);       /* letztes Zeichen zur�ck */
         else
            fputc(c, stdout);   /* ausgeben */
      }
   }
   /* Wird nie erreicht. */
   fclose(fp);
   return EXIT_SUCCESS;
}
