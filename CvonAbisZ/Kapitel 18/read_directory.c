#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
   DIR *dir;
   struct dirent *dirzeiger;

   if(argc != 2) {
      fprintf(stderr,"Benutzung : %s Directory\n", argv[0]);
      return EXIT_FAILURE;
   }
   /* das Verzeichnis �ffnen */
   if((dir=opendir(argv[1])) == NULL) {
      fprintf(stderr,"Fehler bei opendir ...\n");
      return EXIT_FAILURE;
   }
   /* das komplette Verzeichnis auslesen */
   while((dirzeiger=readdir(dir)) != NULL)
      printf("%s\n",(*dirzeiger).d_name);
   /* Lesezeiger wieder schlie�en */
   if(closedir(dir) == -1)
      printf("Fehler beim Schlie�en von %s\n", argv[1]);
   return EXIT_SUCCESS;
}
