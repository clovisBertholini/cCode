// Dev: Clovis Wanderley Bertholini Sobrinho
// COVID - Acompanhamento dos casos de COVID-19 da PF
// 30 de janeiro de 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaracao de constantes
const int NUM_SERVIDORES = 150;

// definicao das structs
// armazena dados do servidor
struct servidor{ 
	char nome[120];
	char cargo[12];
	char lotacao[40];
	char codArea[3];
	char fone[11];
}; typedef struct servidor Servidor;

// armazena data do relato dos sintomas
struct data{
	char dia[3];
	char mes[3];
	char ano[5];
}; typedef struct data Data;

// armazena relato dos sintomas do servidor
struct relatoDoServidor{
	Data data;
	char relato[255];
}; typedef struct reladoDoServidor RelatoDoServidor;

// prototipos das funcoes
void menuPrincipal();
void criarFicha();
void acrescentarRelato();
void registraFicha(Servidor fichaServidor);

// inicio da funcao main
int main(void){
    menuPrincipal();
    return 0;
} // fim da muncao main

// inicio da funcao menu principal
void menuPrincipal(void){
    char opcao;
    do{
        system("clear");
        printf("\n\tAcompanhamento de Servidores\n");
        printf("\n\t1 <-- Criar ficha do servidor\n");
        printf("\n\t2 <-- Acrescentar relato do servidor\n");
        printf("\n\t3 <-- Sair\n");
        printf("\n\tdigite a opcao desejada: ");
        scanf("%c", &opcao);
        if (opcao == '1'){
            criarFicha();
            break;
        }else if (opcao == '2'){
            acrescentarRelato();
            break;
        }else if (opcao == '3'){
            system("clear");
            exit(0);
        }else{
            system("clear");
            printf("\n\tOpcao invalida! escolha 1, 2 ou 3\n");
            system("sleep 3");
        }
        getchar();
    }while(1);
} // fim da funcao menu principal

// inicio da funcao cria ficha do servidor
void criarFicha(){
    char opcao;
    Servidor fichaServidor;	
    do{
        system("clear");
        printf("\n\tCriar Ficha do Servidor\n");
        printf("\n\tServidor: ");
        scanf("%s", &fichaServidor.nome);
	printf("\n\tCargo: ");
	scanf("%s", &fichaServidor.cargo);
        printf("\n\tFone... ");
	printf("\n\n\tCodigo de Area: ");
	scanf("%s", &fichaServidor.codArea);
	printf("\n\tNumero: ");
	scanf("%s", &fichaServidor.fone);	
	getchar();
	do{
	    system("clear");
	    printf("\n\tServidor: %s", fichaServidor.nome);
	    printf("\n\tCargo: %s", fichaServidor.cargo);
	    printf("\n\tFone: (%s) %s", fichaServidor.codArea, fichaServidor.fone);
	    printf("\n\n\tConfirma os dados digitados S ou N? ");
            scanf("%c", &opcao);
	    if (opcao == 'S' || opcao == 's'){
	        registraFicha(fichaServidor);
		break;
	    }
	    else if (opcao == 'N' || opcao == 'n'){
		break;
	    }
	    else{
		system("clear");
		printf("\n\tEscolha S ou N\n");
	        system("sleep 3");
	    }
	    getchar();
        }while (1);
	getchar();
    }while (1);
} // fim da funcao cria ficha do servidor

// inicio da funcao registra ficha do servidor
void registraFicha(Servidor fichaServidor){
    system("clear");
    printf("\n\tRegistro incluido com sucesso!\n");
    system("sleep 3");
    system("clear");
    getchar();
    menuPrincipal();
} // fim da funcao registra ficha do servidor

// inicio da funcao acrescenta relato do servidor
void acrescentarRelato(){
    system("clear");
    printf("\n\tRelato do Servidor\n");
} // fim da funcao acrecenta relato do servidor
