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

void sortbySelection(int *num, int n){
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

	printVetor(num, n);
    printf("Quantidade de comparacoes: %d\n", qtdComp);
    printf("Quantidade de trocas: %d\n", qtdTroca);
}

//-----------------------------------------------------------------------------------------------
int main(){
	srand(time(NULL)); //pra nao rolar repeticao da execucao anterior
	
	int n = 0;
    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = criarVetor(n);

    sortbySelection(vetor, n);

    free(vetor);
	
	return 0;
}