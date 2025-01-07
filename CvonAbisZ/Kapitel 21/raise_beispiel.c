#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void sigfunc(int sig) {
   if(sig == SIGINT)
      printf("SIGINT wurde ausgeloest\n");
}

int main(void) {
   signal(SIGINT,sigfunc);
   printf("Mit ENTER SIGINT ausloesen\n");
   getchar();
   /* SIGINT auslösen */
   raise(SIGINT);
   return EXIT_SUCCESS;
}
