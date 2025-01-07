#include<stdio.h>

int main(void) {
   int x;

   printf("Bitte geben Sie eine Zahl ein: ");
   scanf("%d",&x);
   if(x&1)  // Ist das erste Bit gesetzt?
      printf("Dies war eine ungerade Zahl\n");
   else     // Nein, es ist nicht gesetzt.
      printf("Dies war eine gerade Zahl\n");
   return 0;
}
