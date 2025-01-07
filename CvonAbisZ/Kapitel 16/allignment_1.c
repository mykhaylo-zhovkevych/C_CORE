#include<stdio.h>
#include<stdlib.h>

typedef struct {
   char x;
   int z;
} speicher;

int main(void) {
   speicher test;

   printf("%u Bytes\n",sizeof(test));
   return EXIT_SUCCESS;
}
