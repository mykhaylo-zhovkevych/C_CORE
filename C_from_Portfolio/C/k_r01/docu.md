``` c
#include <stdio.h>
int main() {
    char x[] = "Hello"
    int py_len();
    printf("%s %d\n",x,py_len(x));
}
int py_len(self)
    char self[];
{
    int i;
    for (i=0; self[i]; i++);
    return i;
}
main() /*count characters in input*/
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc);
    printf("%.0f\n, nc");
}
main() /*count lines in input*/
{
    int c, nl;
    nl = 0;
    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```


#### string reversal
``` c
#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i = 0;
    // count end
    int j = strlen(s) - 1;

    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char tests[][20] = {
        "hello",
        "abcd",
        "",
        "x"
    }

    for (int i = 0; i < 4; i++) {
        printf("Before: \"%s\" -> ", tests[i]);
        reverse(tests[i]);
        printf("After: \"%s\"\n", tests[i]);
    }
    return 0;
}
```


