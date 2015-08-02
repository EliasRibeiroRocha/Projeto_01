//PROGRAMA - AVALIZA��O DIAGN�STICA DE ED1

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Declara��o das fun��es
int validarPosicao(int pos);
int removerPorPosicao (int pos);

//Declara��o das vari�veis globais
int totalNum=0;
int vetNum[15];

//Programa principal
int main (int argc, char *argv[]){
	int opcao;
	bool sair=true;
	
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

//Fun��o para remover por posi��o
int removerPorPosicao (int pos){
	
	if (validarPosicao(pos)){
		vetNum[pos] = -1;
		return 1;
	}
	else
		printf ("\nO valor nao foi removido!");
	return -1;
}

//Fun��o para validar a posi��o
int validarPosicao(int pos){
	
	if (pos >= 0 || pos <= totalNum)
		return 1;
	else
		printf ("\n\nA posicao fornecida e invalida. A posicao deve ser maior igual a 0 ou menor que %d", totalNum);
		
	return 0;
}
