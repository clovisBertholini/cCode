#include <stdio.h>
int main(void)
{
    int c;
    int n = 0;
    int b = ' ';
    while ((c = getchar()) != EOF && n <= 100)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && (b != ' ' && b != '\n' && b != '\t'))
            printf("\n");
        else 
            if (c != ' ' && c != '\n' && c != '\t')
                printf("%c", c);
        b = c;
        ++n;
    }
    printf("\n");    
}
