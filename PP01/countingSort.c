#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int qtdTroca = 0;
//int qtdComp = 0; //nao e possivel calcular a quantidade de comparacoes, pois o counting e baseado em contagem e nao em comparacao


int* criarVetor (int n){
    int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

    for(int i = 0; i < n; i++){
        vetor[i] = rand() % 1000; //atribui valores aleatorios pro vetor de 0 a 10
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

int maiorValor(int *num, int n){ //encontrando o maior valor dentro do vetor
	int maiorN = num[0];

	for(int i = 0; i < n; i++){
		if(num[i] > maiorN){
			maiorN = num[i]; 
		}
	}

	return maiorN;
}

//-----------------------------------------------------------------------------------------------

int* countingSort (int *num, int n, int k){
	
	int *C = (int *)calloc(k + 1, sizeof(int)); //aloca o vetor dinamicamente e inicializa todas as posicoes com zero
	int *B = (int *)malloc(n * sizeof(int));
	
	
	for (int j = 0; j < n; j++){
		C[num[j]] = C[num[j]] + 1;
	}
	
	for (int i = 1; i <= k; i++){
		C[i] = C[i] + C[i-1];
	}
	
	for (int j = n-1; j >= 0; j--){
		B[C[num[j]] - 1] = num[j];
		qtdTroca++;
		C[num[j]]--;
	}
	
	free(C);
	return B;
}

//-----------------------------------------------------------------------------------------------


int main(){
	srand(time(NULL)); //pra nao rolar repeticao da execucao anterior
	
	int n = 0;
    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = criarVetor(n);

    printf("\n");
    printVetor(vetor, n);
    printf("\n");

    int k = maiorValor(vetor, n); //maior valor dentro do vetor
	
    int *vetorOrganizado = countingSort(vetor, n, k);
    printVetor(vetorOrganizado, n);
    
    //printf("\nQuantidade de Comparacoes: %d\n", qtdComp);
    printf("Quantidade de Trocas: %d\n", qtdTroca);

    free(vetor);
    free(vetorOrganizado);

	return 0;
}