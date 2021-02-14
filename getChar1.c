#include <stdio.h>

void getString(char *v);

const int TEXTO = 10;

int main(void){
	char texto[TEXTO];
	printf("texto: ");
	getString(texto);
	printf("\n\t-> %s\n", texto);
}

void getString(char *v){
	int count = 0;
	while ((v[count] = getchar()) != '\n' && count < (TEXTO - 2))
		++count;
	v[++count] = '\0';
}
