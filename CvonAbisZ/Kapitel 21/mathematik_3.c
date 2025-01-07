#include<stdio.h>
#include<stdlib.h>
/* bei Linux den Compiler-Flag -lm mit angeben */
#include<math.h>
#include<fenv.h>
#pragma STDC FENV_ACCESS ON

int main(void) {
   double d1=0, d2=1.0, dges;
   fexcept_t flagp;
   // Exception-Statusflags sichern
   fegetexceptflag(&flagp, FE_ALL_EXCEPT );
   // mit Absicht eine Division durch 0 ausl�sen
   dges = d2 / d1;
   if( fetestexcept( FE_DIVBYZERO ) ) {
      printf("Exception ausgel�st: Divsion durch 0 !\n");
   }
   // Exception-Statusflags wiederherstellen
   fesetexceptflag(&flagp, FE_ALL_EXCEPT);
   // Sollte jetzt nicht mehr ausgef�hrt werden.
   if( fetestexcept( FE_DIVBYZERO ) ) {
      printf("Exception ausgel�st: Divsion durch 0 !\n");
   }
   return EXIT_SUCCESS;
}
