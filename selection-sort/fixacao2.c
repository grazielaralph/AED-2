#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 5000

int verificaValor(int *vetor, int qtdAtual, int num){
	for(int i = 0; i < qtdAtual; i++){
		if(vetor[i] == num){
			return 1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------

int* criarVetor (int n){
    int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

    for(int i = 0; i < n; i++){
        vetor[i] = rand(); 
    }
    return vetor;
}

int* criarVetorSemRepeticao (int n){
	int numGerado = 0;
	
    int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

    for(int i = 0; i < n; i++){
        do{
        	numGerado = rand();
        }while(verificaValor(vetor, i, numGerado)); //continua executando ate gerar um valor diferente

        vetor[i] = numGerado;
    }

    return vetor;
}

//-----------------------------------------------------------------------------------------------

void sortBySelectionDecresc(int *num, int n){
	int max = 0;
	int aux = 0;
	int qtdTroca = 0;
	int qtdComp = 0;
	int i = 0;

	for(i = 0; i < n-1; i++){
		max = i;

		for(int j = i+1; j < n; j++){
			qtdComp++;
			if(num[j] > num[max]){
				max = j;
			}
		}

		if(max != i){
		aux = num[i];
		num[i] = num[max];
		num[max] = aux;
		qtdTroca++;
		}
	}

	//printVetor(num, n);
    printf("Quantidade de comparacoes: %d\n", qtdComp);
    printf("Quantidade de trocas: %d\n", qtdTroca);
}

void sortBySelection(int *num, int n){
	int min = 0;
	int aux = 0;
	int qtdTroca = 0;
	int qtdComp = 0;
	int i = 0;

	for(i = 0; i < n-1; i++){
		min = i;

		for(int j = i+1; j < n; j++){
			qtdComp++;
			if(num[j] < num[min]){
				min = j;
			}
		}

		if(min != i){
		aux = num[i];
		num[i] = num[min];
		num[min] = aux;
		qtdTroca++;
		}
	}

	//printVetor(num, n);
    printf("Quantidade de comparacoes: %d\n", qtdComp);
    printf("Quantidade de trocas: %d\n", qtdTroca);
}

//-----------------------------------------------------------------------------------------------

int main(){
    srand(time(NULL)); //pra nao rolar repeticao da execucao anterior

	int *vetor1 = criarVetor(TAMANHO); 
	int *vetor2 = criarVetor(TAMANHO);
	int *vetor3 = criarVetorSemRepeticao(TAMANHO);

	printf("Vetor aleatorio com repeticao: \n");
	sortBySelection(vetor1, TAMANHO); //vetor aleatorio com repeticao 
	printf("\n \n");

	printf("Melhor caso - vetor ordenado: \n");
	sortBySelection(vetor1, TAMANHO); //melhor caso - vetor ordenado
    printf("\n \n");
	
	sortBySelectionDecresc(vetor2, TAMANHO);
	printf("Pior caso - vetor ordenado na ordem decrescente: \n");
	sortBySelection(vetor2, TAMANHO); //pior caso - vetor na ordem inversa
	printf("\n \n");

	printf("Vetor aleatorio sem repeticao: \n");
	sortBySelection(vetor3, TAMANHO); //vetor aleatorio sem repeticao
    printf("\n \n");

	free(vetor1);
	free(vetor2);
	free(vetor3);
	return 0;
}