//PROGRAMA - AVALIZA��O DIAGN�STICA DE ED1

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Declara��o das fun��es
int adicionar(int num);

//Programa principal
int main (int argc, char *argv[]){
	int opcao;
	bool sair=true;
	int numero;
	
	do{
		system("cls");
		printf ("\t\t\tAVALIACAO DIAGNOSTICA - ED1");
		printf ("\n\t\t1 - Adicionar um novo numero:");
		printf ("\n\t\t2 - Remover um numero existente:");
		printf ("\n\t\t3 - Exibir os numeros fornecidos:");
		printf ("\n\t\t4 - Remover numero de uma posicao especifica:");
		printf ("\n\t\t5 - Verificar numero de ocorrencias de determinado numero:");
		printf ("\n\t\t6 - Exibir os numeros fornecidos em ordem crescente:");
		printf ("\n\t\t7 - Sair: ");
		printf ("\n\t\t\tOpcao: ");
		scanf ("%d",&opcao);
		
		switch(opcao){
			case 1: //Inserir fun��o adicionar numero
				printf("Insira um número positivo: ");
				scanf("%i", &numero);

				if (adicionar(numero))
					printf("Número adicionado");
				else
					printf("Não foi possível adicionar esse número");
				break;
			case 2: //Inserir fun��o remover numero existente
				break;
			case 3: //Inserir fun��o exibir n�meros na ordem que foram inseridos
				break;
			case 4: //Inserir fun��o remover n�mero de uma posi��o especifica.
				break;
			case 5: //Inserir fun��o verificar quantas ocorrencias um determinado n�mero possui
				break;
			case 6: //Inserir fun��o exibir n�meros em ordem crescente
				break;
			case 7: sair=false;
				break;
			default:
				break;
		}
	}while (sair);
	
	return 0;
}

/**
retorna 1 se o número for adicionado ou 0 caso não
*/
int adicionar(int num){
	return 0;
}
