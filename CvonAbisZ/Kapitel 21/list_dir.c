#include<stdio.h>
#include<stdlib.h>
#ifdef __unix__
   #define KOMMANDO system("ls -C")
#else
   #define KOMMANDO system("dir /w")
#endif

int main(void) {
  if( system(NULL) == 0) {
     fprintf(stderr,"Kein Kommandozeilenprozessor vorhanden \n");
     return EXIT_FAILURE;
  }
  else
     KOMMANDO;
  return EXIT_SUCCESS;
}
