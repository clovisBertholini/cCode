// Dev: Clovis Wanderley Bertholini Sobrinho
// COVID - Acompanhamento dos casos de COVID-19 da PF
// 30 de janeiro de 2021

#include <stdio.h>
#include <stdlib.h>

void menuPrincipal(void);
void criarFicha();
void acrescentarRelato();

struct servidor{
	char nome[120];
	char cargo[12];
	char lotacao[40];
	char codArea[3];
	char fone[10];
}; typedef struct servidor Servidor;

struct data{
	char dia[3];
	char mes[3];
	char ano[5];
}; typedef struct data Data;

struct relatoDoServidor{
	Data data;
	char relato[255];
}; typedef struct reladoDoServidor RelatoDoServidor;

int main(void){
    menuPrincipal();
    return 0;
}

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
}

void criarFicha(){
    system("clear");
    printf("\n\tCriar Ficha do Servidor\n");
}

void acrescentarRelato(){
    system("clear");
    printf("\n\tRelato do Servidor\n");
}
