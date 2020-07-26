#include <stdio.h>
#define IN 1 /*Inside a word*/
#define OUT 0 /*Outside a word*/
int main(void)
{
    int c;
    int n = 0;
    int state = OUT;
    int nl = 0;
    int nw = 0;
    int nc = 0;
    while((c = getchar()) != EOF && n <= 100)
    {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT)
        {
            state = IN;
            ++nw;
        }
        ++n;
    }
    printf("%i %i %i\n", nl, nw, nc);
}
