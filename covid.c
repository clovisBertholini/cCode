// Dev: Clovis Wanderley Bertholini Sobrinho
// COVID - Acompanhamento dos casos de COVID-19 da PF
// 30 de janeiro de 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
}; typedef struct relatoDoServidor RelatoDoServidor;

// prototipos das funcoes
void menuPrincipal();
void criarFicha();
void acrescentarRelato();
void registraFicha(Servidor fichaServidor);
void registraRelato(char nomeArquivo[], RelatoDoServidor sintomas);

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
        scanf("%s", fichaServidor.nome); 
	printf("\n\tCargo: ");
	scanf("%s", fichaServidor.cargo);
        printf("\n\tFone... ");
	printf("\n\n\tCodigo de Area: ");
	scanf("%s", fichaServidor.codArea);
	printf("\n\tNumero: ");
	scanf("%s", fichaServidor.fone);	
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
    FILE *arquivo;
    arquivo = fopen(fichaServidor.nome, "w");
    if (arquivo == NULL){
	printf("Erro na abertura do arquivo, tente novamente!");
	printf("Saindo do programa...");
	exit(1);
    }
    else{
	fprintf(arquivo, "Ficha do Servidor\n");
	fprintf(arquivo, "Servidor: %s\n", fichaServidor.nome);
	fprintf(arquivo, "Cargo: %s\n", fichaServidor.cargo);
	fprintf(arquivo, "Fone: (%s) %s\n", fichaServidor.codArea, fichaServidor.fone);
    }
    fclose(arquivo);
    printf("\n\tRegistro incluido com sucesso!\n");
    system("sleep 3");
    system("clear");
    getchar();
    menuPrincipal();
} // fim da funcao registra ficha do servidor

// inicio da funcao acrescenta relato do servidor
void acrescentarRelato(){
    RelatoDoServidor sintomas;
    char nomeArquivo[120];
    char opcao;
    do{
        system("clear");
        printf("\n\tAcrescentar Relato do Servidor");
        printf("\n\tDigite o nome do servidor: ");
        scanf("%s", nomeArquivo);
        printf("\n\tEntre com a data do relato...");
        printf("\n\tDia: ");
        scanf("%s", sintomas.data.dia);
        printf("\n\tMês: ");
        scanf("%s", sintomas.data.mes);
        printf("\n\tAno: ");
        scanf("%s", sintomas.data.ano);
        printf("\n\tRelato do Servidor: ");
        scanf("%s", sintomas.relato);
	getchar();
	do{
	    printf("\n\tServidor: %s", nomeArquivo);
	    printf("\n\tData: %s/%s/%s", sintomas.data.dia, sintomas.data.mes, sintomas.data.ano);
	    printf("\n\tRelato: %s", sintomas.relato);
	    printf("\n\n\tConfirma a inclusao dos dados acima S/N? ");
	    scanf("%c", &opcao);
	    if (opcao == 'S' || opcao == 's'){
	        registraRelato(nomeArquivo, sintomas);
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
	printf("Deseja cadastrar outro relato para %s S/N? ", nomeArquivo);
	scanf("%s", &opcao);
	do{
	    if (opcao == 'S' || opcao == 's'){
	        continue;
	    }
	    else if (opcao == 'N' || opcao == 'n'){
	        menuPrincipal();
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
} // fim da funcao acrescenta relato do servidor

void registraRelato(char nomeArquivo[], RelatoDoServidor sintomas){
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL){
	    printf("arquivo não encontrado, tente novamente!");
	    printf("Saindo do programa...");
    }
    else{
        fprintf(arquivo, "==========================================================");
	fprintf(arquivo, "\n\tData: %s/%s/%s", sintomas.data.dia, sintomas.data.mes, sintomas.data.ano);
	fprintf(arquivo, "\n\tRelato:");
	fprintf(arquivo, "\n\t%s\n\n", sintomas.relato);
    }
    fclose(arquivo);
} // fim da funcao registra relato do servidor
