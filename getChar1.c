#include <stdio.h>

void getString(char *v, int t);

const int TEXTO = 10;

int main(void){
	char texto[TEXTO];
	printf("texto: ");
	getString(texto, TEXTO);
	printf("\n\t-> %s\n", texto);
}

void getString(char *v, int t){
	int count = 0;
	while ((v[count] = getchar()) != '\n' && count < (t - 2))
		++count;
	v[++count] = '\0';
}
