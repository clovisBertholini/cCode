#include <stdio.h>

/* count digits, white spaces and others */

int main(void){
    int c, i, n, whiteSpaces, others;
    int digits[10];
    whiteSpaces = (others = 0);
    for (i = 0; i < 10; ++i)
        digits[i] = 0;
    n = 0;
    while ((c = getchar()) != EOF && n <= 100){
        if (c >= '0' && c <= '9')
            ++digits[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++whiteSpaces;
        else
            ++others;
        ++n;
    }
    printf("digits ->");
    for (i = 0; i < 10; ++i)
        printf(" %d", digits[i]);
    printf(", white spaces -> %d, others -> %d\n", whiteSpaces, others);
}
