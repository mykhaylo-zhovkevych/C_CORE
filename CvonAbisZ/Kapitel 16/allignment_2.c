#include<stdio.h>
#include<stdlib.h>

/* L�sst sich dieses Listing nicht �bersetzen,
 * entfernen Sie __attribute__((packed)) und
 * verwenden stattdessen #pragma pack(1).
 * unter Linux funktioniert pragma nicht, sondern nur unter Windows/

/* #pragma pack(1) */
struct speicher {
   char x;
   int z;
} __attribute__ ((packed)); // L�uft nicht auf dem Raspi

int main(void) {
   struct speicher test;

   printf("%u Bytes\n",sizeof(test));
   return EXIT_SUCCESS;
}
