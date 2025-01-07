#include<stdio.h>
#include<stdlib.h>

typedef struct { int wert[3]; } array;

array init_array(void) {
   int i;
   array z;

   for(i = 0; i < sizeof(array) / sizeof(int); i++) {
      printf("Wert %d eingeben: ",i);
      scanf("%d",&z.wert[i]);
   }
   return z;
}

void output_array(array z) {
   int i;

   for(i = 0; i < sizeof(array) / sizeof(int); i++)
      printf("%d\t", z.wert[i]);
   printf("\n");
}

int main(void) {
   array new_array;

   /* Array als Rückgabewert in einer Struktur verschachtelt */
   new_array=init_array();
   /* call-by-value */
   output_array(new_array);
   return EXIT_SUCCESS;
}
