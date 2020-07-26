#include <stdio.h>
int main(void)
{
    int nl = 0;
    int sp = 0;
    int tb = 0;
    int n = 0;
    int c;
    while ((c = getchar()) != EOF && n <= 100)
    {
        if(c == ' ') 
            ++sp;
        if(c == '\t')
            ++tb;
        if(c == '\n')
            ++nl;
        ++n;
    }
    printf("nl: %i - sp: %i - tb: %i\n", nl, sp, tb);
}
