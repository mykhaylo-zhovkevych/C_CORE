#include<stdio.h>
#include<stdlib.h>

typedef enum { Null, Eins, Zwei, Drei, Vier} zahl;

int main(void) {
   zahl x;
   x=Null;
   printf("%d\n",x);

   x=Eins;
   printf("%d\n",x);

   x=Zwei;
   printf("%d\n",x);

   x=Drei;
   printf("%d\n",x);

   x=Vier;
   printf("%d\n",x);
   return EXIT_SUCCESS;
}
