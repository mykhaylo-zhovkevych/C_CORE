#include <stdio.h>

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i=0; s[i]==' ' || s[i]=='\n' || s[i]=='\t'; i++)
        ; // skip white space. empty body, semicolon only

    sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i++]=='+') ? 1 : -1;
    }
    for (val = 0; s[i] >= '0' && s[i] <= '9'; i++)
        val = 10.0 * val + (s[i] - '0'); //s[i]-'0' converts char to int

    if (s[i] == '.')
        i++;

    for (power = 1; s[i] >= '0' && s[i] <= '9'; i++) {
        val = 10 * val + s[i] - '0';
        power *= 10;
    }
    return (sign * val / power);
}


int main() {
    char s1[] = "  -123.456";
    char s2[] = "  +42.0";
    char s3[] = "   0.5";
    char s4[] = "100";

    printf("atof(s1) = %f\n", atof(s1));
    printf("atof(s2) = %f\n", atof(s2));
    printf("atof(s3) = %f\n", atof(s3));
    printf("atof(s4) = %f\n", atof(s4));
    return 0;
}
