#include <stdio.h>

int main (void){
	char c[200]; 
	fgets(c, 200, stdin);
	printf("\n\n%s", c);
	return 0;
}
