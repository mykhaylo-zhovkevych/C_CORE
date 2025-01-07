#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#ifdef __unix__
      #include <unistd.h>
#elif __MSDOS__ || __WIN32__ || _MSC_VER
      #include <io.h>
#endif

int main(void) {
   int fh;

   if((fh=open("adresse.txt", O_RDWR|O_CREAT|O_TRUNC))==-1) {
      perror("Fehler bei open()");
      return EXIT_FAILURE;
   }
   printf("Alles klar, die Datei wurde geöffnet.\n");
   close(fh);
   return EXIT_SUCCESS;
}
