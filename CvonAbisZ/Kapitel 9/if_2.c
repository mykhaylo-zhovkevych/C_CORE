#include<stdio.h>

int main(void) {
   unsigned int alter;

   printf("Wie alt sind Sie: ");
   scanf("%u", &alter);

   if(alter < 18)  {
      printf("Sie sind noch nicht volljährig\n");
   }
   if(alter > 18)  {
      printf("Sie sind volljährig\n");
   }
   if(alter == 18) {
      printf("Den Führerschein schon bestanden?\n");
   }
   printf("Bye\n");
   return 0;
}
