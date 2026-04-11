#include <stdio.h>
#include <string.h>

void zap(char y[]) {
    printf("Y start zap: %s\n", y);
    strcpy(y, "CHANGED");
    printf("Y end zap: %s\n", y);

    //strcpy internally does roughly:
    // while (*src != '\0')
    //     *dest++ = *src++;  // copy byte by byte into the same memory location
    //     *dest = '\0';

}

int main() {
    char x[] = "ORIGINAL";
    printf("X before zap: %s\n", x);
    zap(x); // pass the address of x, not copy
    printf("X after zap: %s\n", x);
    return 0;
}

/*
def zap(y):
    print('Y start zap:', y)
    y = 'CHANGED'
    print('Y end   zap:', y)

x = 'ORIGINAL'
print('X before zap:', x)
zap(x)                   # passes a copy of the reference to 'ORIGINAL'
print('X after  zap:', x)
*/