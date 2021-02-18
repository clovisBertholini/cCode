#include <stdio.h>
int main(void)
{
    int c, i, j;
    int n = 0;
    int b = ' ';
    int numLetters[20];
    for (i = 0; i < 20; ++i)
	    numLetters[i] = 0;
    i = 0;
    while ((c = getchar()) != '\n' && n <= 100)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && (b != ' ' && b != '\n' && b != '\t'))
	{
		printf("\n");
		++i;
	}
        else 
            if (c != ' ' && c != '\n' && c != '\t')
	    {
                printf("%c", c);
		++numLetters[i];
	    }
        b = c;
        ++n;
    }
    printf("\n");    
    n = i + 1;
    for (i = 0; i < n; ++i)
    {
	    for (j = 0; j < numLetters[i]; ++j)
		    printf("#");
	    printf("\n");
    }
    for (j = 20; j > 0; --j) 
    {
	    for (i = 0; i < n; ++i)
    	    {	
	    	if (numLetters[i] >= j)
		        printf("##");
	    	else
		        printf("  ");
		printf(" ");
    	    }
	    printf("\n");
    }
}
