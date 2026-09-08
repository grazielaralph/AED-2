#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* criarVetor (int n){
    int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

    for(int i = 0; i < n; i++){
        vetor[i] = rand() % 1000; //atribui valores aleatorios pro vetor de 0 a 999
    }

    return vetor;
}

void printVetor (int *num, int n){
     for(int i = 0; i < n; i++){
        printf(" %d ", num[i]);
    } 
    printf("\n");
}

//-----------------------------------------------------------------------------------------------

void sortByInsert(int *num, int n){
	int qtdComp = 0;
	int qtdTroca = 0;
	int chave = 0;
	int i = 0;

	for(int j = 2; j < n; j++){
		int key = num[j];
		i = j-1;
		while(i < 0 && A[i] > chave){
			num[i+1] = num[i];
			i = i - 1;
			qtdTroca++;
		}
		qtdComp++;
		num[i+1] = chave;
	}

	printf("Quantidade de comparacoes: %d\n", qtdComp);
    printf("Quantidade de trocas: %d\n", qtdTrocas);
}

//-----------------------------------------------------------------------------------------------

int main(){
	srand(time(NULL));

    int n = 0;
    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = criarVetor(n);

    sortByInsert(vetor, n);

    free(vetor);

	return 0;
}