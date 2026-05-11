#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int o_random_f(int max) {
    int x;

    x = rand() % max;

    return x;
}
int main() {
  int random;

    srand(getpid());
    random = o_random_f(10);
    printf ( "%d\n", random);

    random = o_random_f(10);
    printf("%d\n", random);

    return 0;
}