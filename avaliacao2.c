//os caracteres especiais nao funcionam corretamente sem codificacao UTF-8
/*
Desenvolver um programa na linguagem C que armazene até 15 números positivos, de modo que desempenhe as seguintes funcionalidades:
1) Adicionar um novo número
2) Remover um número existente
3) Exiba os números na ordem que foram fornecidos
4) Remova um número que está em uma posição informada pelo usuário
5) Verifique quantas vezes um determinado número (informado pelo usuário) foi armazenado

Desafio: uma funcionalidade que exiba os números armazenados em ordem crescente
*/

#include <stdio.h>
#include <stdlib.h>


//adicioa um número ao vetor
int add(int num);
//remove um número do vetor
int remover(int num);
//exibe todos na ordem que foram inseridos
void exibe();
//remove um número em determinada posição
int removerEm(int index);
//Quantidade de ocorrencias de um número
void verificaQtdes();
//x indica onde começa o loop
void realoca(int x);
//conta a quantidade de ocorrencias de um número n
int conta(int n);
//funçao de ordenaçao
void ordena();

//vetor onde serão guardados os números
int numeros[15];
//variável que indica o tamanho do vetor
int size = 0;
/*linhas indicam o número de elementos;
 nas colunas, a primeira indica o número e
 a segunda indica a qtde de ocorrencias*/
int qtdes[15][2];

int main(){

	//os números negativos indicam espaços vazios
	/*
	int i;
	for (i = 0; i < 15; i++)
		numeros[i] = -1;
	*/
	int opt;
	int n;

	do {
		printf("\n\nEscolha uma opção:");
		if (size < 15)
			printf("\n1 - Adicionar um número (restam %i números para serem adicionados)", 15 - size);

		if (size != 0){
			printf("\n2 - Remover um número");
			printf("\n3 - Exibir todos os números");
			printf("\n4 - Remover um número em uma posição específica");
			printf("\n5 - Mostrar quantidade de ocorrencias de um número do vetor");
			printf("\n6 - Mostrar vetor ordenado");
		}
		printf("\n7 - Sair");
		printf("\n: ");
		scanf("%i", &opt);

		printf("\n");

		switch(opt){
			case 1:
				if (size == 15){
					break;
				}

				printf("Digite um número positivo: ");
				scanf("%i", &n);
				if (add(n)){
					printf("Numero adicionado!");
				}
				else {
					printf("Não foi possivel adicionar o número.");
				}
				break;
			case 2:
				if (size == 0){
					break;
				}

				printf("Informe o número para ser removido: ");
				scanf("%i", &n);
				if (!remover(n)) {
					printf("Não foi possível remover esse número!");
				}
				break;
			case 3:
				if (size == 0)
					break;

				printf("\n");
				exibe();
				break;
			case 4:
				if (size == 0){
					break;
				}

				printf("Informe a posição do número: ");
				scanf("%i", &n);
				if (!removerEm(n)){
					printf("Não existe número nessa posição");
				}
				else {
					printf("Numero removido!");
				}
				break;
			case 5:
				if (size == 0)
					break;

				printf("Informe o numero: ");
				scanf("%i", &n);

				printf("O numero %i aparece %i vezes no vetor.", n, conta(n));
				break;
			case 6:
				if (size == 0)
					break;
				//printf("Estamos trabalhando nisso!");
				ordena();
				break;
			case 7:
				printf("Tchau!\n");
				break;
			default:
				printf("Opção inválida!");
				break;
		}

	} while(opt != 7);



	return 0;

}

int add(int num){
	if (num < 0){
		return 0;
	}
	if (size == 15){
		return 0;
	}
	else {
		numeros[size] = num;
		size++;
	}


	return 1;
}

int remover(int num){
	if (num < 0)
		return 0;

	int i;
	int existe = 0;
	for (i = 0; i < size; i++){
		if (numeros[i] == num){
			existe = 1;
			numeros[i] = -1;
			printf("\nNumero removido na posiçao %i", i);
			realoca(i);
			i = 0;
		}
	}

	if (!existe) return 0;

	return 1;
}

void realoca(int x){

	size--;
	if (x != size){
		int i;
		for (i = x; i < size; i++){
			numeros[i] = numeros[i+1];
		}
	}


	return;
}

void exibe(){

	if (size != 0){
		int i;
		printf("{");
		for(i = 0; i < size; i++){
			printf("%i", numeros[i]);

			if(i != size - 1)
				printf(", ");
		}
		printf("}");
	}

	return;
}

int removerEm(int index){

	if (index < 0 || index > (size - 1))
		return 0;

	numeros[index] = -1;
	realoca(index);

	return 1;
}

/*
função criada inicialmente porque não prestei atenção no enunciado do exercicio 5.
Achei que era pra contar quantas vezes cada numero aparece.
Não apaguei ela porque deu trabalho pra fazer.
A função conta() faz o que o exercicio pede.
ps: no Windows está dando erro nessa funçao, mas no Linux(\o/) funciona perfeitamente. o.O
*/
void verificaQtdes(){

	int x, y;
	int existe;
	int sizeQtdes = 0;

	if (size != 0){

		for (x = 0; x < size; x++){
			existe = 0;
			if (sizeQtdes != 0)
			for (y = 0; y < sizeQtdes; y++){
				if (numeros[x] == qtdes[y][0]){
					existe = 1;
					break;
				}

			}

			if (existe){
				qtdes[y][1] = qtdes[y][1] + 1;
			}
			else {
				qtdes[y][0] = numeros[x];
				qtdes[y][1] = 1;
				sizeQtdes++;
			}
		}

		printf("\nNúmeros  | Ocorrencias\n");
		for (x = 0; x < sizeQtdes; x++){
			printf("%i \t | \t %i \n", qtdes[x][0], qtdes[x][1]);
		}

	}

	return;
}

int conta(int n){
	int cont = 0;
	int i;

	for (i = 0; i < size; i++){
		if (numeros[i] == n)
			cont++;
	}

	return cont;
}

void ordena(){
	int x, y;
	int troca;

	for (x = 0; x < size; x++){
		for (y = 0; y < size - 1; y++){
			if (numeros[x] > numeros[y]){
				troca = numeros[x];
				numeros[x] = numeros[y];
				numeros[y] = troca;
			}
		}
	}

	if (size != 0){
		printf("\n{");
		for (x = 0; x < size; x++){
			printf("%i", numeros[x]);
			if (x != size - 1)
				printf(", ");
		}
		printf("}\n");
	}
}
