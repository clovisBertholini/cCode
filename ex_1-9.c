#include <stdio.h>
int main(void)
{
    int c, b;
    int n = 0;
    while((c = getchar()) != EOF && n <= 100)
    {
        if(n == 0)
            putchar(c);
        else if(n != 0 && c != b && b == ' ')
            putchar(c);
        else if(n != 0 && b != ' ')
            putchar(c);
        b = c;
        ++n;
    }
}
