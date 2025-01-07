#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(void) {
   int_least8_t i8;
   int_least32_t i32;
   int_least64_t i64;
   // beispielsweise Linux: -128 und 127
   printf("int_least8_t/Max. : %d; Min : %d\n",
       INT_LEAST8_MAX, INT_LEAST8_MIN);
   // beispielsweise Linux: -2147483648 und 2147483647
   printf("int_least32_t/Max.: %d; Min : %d\n",
      INT_LEAST32_MAX, INT_LEAST32_MIN);
   // beispielsweise Linux: -9223372036854775808 und
   // 9223372036854775807
   printf("int_least64_t/Max.: %lld; Min: %lld\n",
      INT_LEAST64_MAX, INT_LEAST64_MIN);
   return 0;
}
