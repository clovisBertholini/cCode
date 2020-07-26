#include <stdio.h>
int main(void)
{
    long nc;
    int c;
    for(nc = 0; (c = getchar()) != EOF; ++nc)
        printf("%ld-->%c-->%i\n", nc, c, c);
    printf("%ld\n", nc);
}
