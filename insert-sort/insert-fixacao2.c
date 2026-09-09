#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 5000

int* criarVetor (int n){
    int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

    for(int i = 0; i < n; i++){
        vetor[i] = rand() % 1000; //atribui valores aleatorios pro vetor de 0 a 999
    }

    return vetor;
}


void sortByInsert(int *num, int n){
	int qtdComp = 0;
	int qtdTroca = 0;
	int chave = 0;
	int i = 0;

	for(int j = 1; j < n; j++){
		chave = num[j];
		i = j-1;
		while(i >=0 && qtdComp++, num[i] > chave){
			num[i+1] = num[i];
			i --;
			qtdTroca++;
		}
		num[i+1] = chave;
	}

	printf("Quantidade de comparacoes: %d\n", qtdComp);
    printf("Quantidade de trocas: %d\n", qtdTroca);
}

int main(){
	srand(time(NULL));
	
	int *vetor = criarVetor(n);

	sortByInsert(vetor, n);
    printVetor(vetor, n);

    free(vetor);

	return 0;
}