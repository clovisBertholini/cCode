#include <stdio.h>
int main(void)
{
    int c;
    int n = 0;
    while((c = getchar()) != EOF && n <= 10)
    {
        if(c == '\t')
            printf("\\t");
        else if(c == '\b')
            printf("\\b");
        else if(c == '\\')
            printf("\\\\");
        else
            printf("%c", c);
        ++n;
        printf("\n");
    }
}
