#include <stdio.h>
#include <string.h>

int main(void){
	char nome[100];
	printf("Digite seu nome: ");
	fgets(nome, 100, stdin);
	printf("\nSeu nome é: %s\ne o tamanho do seu nome com espaços é: %lu\n", nome, strlen(nome) - 1);
	return 0;
}
