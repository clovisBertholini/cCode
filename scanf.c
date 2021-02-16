#include <stdio.h>

int main(void){
	char string[120];
	unsigned int letters, i;
	printf("your name is: ");
	letters = scanf("%s", string);
	printf("\n\t-> %s\n\t-> %i string was kept by scanf\n", string, letters);
	printf("\n\t\t-> ");
	for (i = 0; string[i] != '\0'; ++i)
		printf("%c", string[i]);
	printf("\n\t\t-> %i characters was read\n", i);
}
