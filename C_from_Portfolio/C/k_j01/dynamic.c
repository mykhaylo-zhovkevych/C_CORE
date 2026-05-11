#include <stdio.h>
#include <stdlib.h>

int main() {
    char *name;
    int size;

    printf("How many characters do you need?");
    scanf("%d", size);
    name = malloc(size);

    printf("What is your name\n");
    scanf("%s", name);
    printf("Hello %s\n", name);
    free(name);
    return 0;
}