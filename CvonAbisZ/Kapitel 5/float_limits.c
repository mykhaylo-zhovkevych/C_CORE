#include<stdio.h>
#include<float.h>
#include<limits.h> //für CHAR_BIT

int main(void) {
   printf("Limits und Eigenschaften von float\n");
   printf("----------------------------------\n");
   printf("Bytes: %d\n", sizeof(float));
   printf("Bit  : %d\n", sizeof(float) * CHAR_BIT );
   printf("Basis-Exponenten-Darstellung: %d\n", FLT_RADIX);
   printf("Anzahl Mantissenstellen   : %d\n", FLT_MANT_DIG);
   printf("Anzahl   Dezimalziffern    : %d\n", FLT_DIG);
   printf("Kl. neg. FLT_RADIX-Exponent: %d\n", FLT_MIN_EXP);
   printf("Kl. neg. Zehnerexponent : %d\n", FLT_MIN_10_EXP);
   printf("Größter FLT_RADIX-Exponent : %d\n", FLT_MAX_EXP);
   printf("Größter Zehnerexponent  : %d\n", FLT_MAX_10_EXP);
   printf("Größter endl. float-Wert   : %f\n", FLT_MAX);
   printf("Kleinster endl. float-Wert : %f\n", FLT_MIN);
   return 0;
}
