#include <stdio.h>

int main() {
    int c, i;
    int nwhite = 0, nother = 0;
    int ndigit[10] = {0};

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0']; // c - '0' converts character digit to array index
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);

    printf("\nwhite space = %d, other = %d\n", nwhite, nother);

    return 0;
}