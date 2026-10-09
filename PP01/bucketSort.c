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

int* bucketSort(int *num, int n, int qtdBalde){
	int *B = (int *) malloc(qtdBalde * sizeof(int));

	for(int i = 0; i < qtdBalde; i++){
		B[i] = NULL; //nao entendi como vou alocar uma lista vazia, vou ter q usar a estrutura de no?
	}

	int k = maiorValor(num, n) / qtdBalde;

	for(int i = 0; i<n; i++){
		indice = (num[i] / qtdBalde) + 1;
		B[indice] = num[i];
	}

	for(int i = 0; i < qtdBalde; i++){
		sortByInsert(&B[i], qtdBalde);
	}

	for (int i = 0; i <= n; i++){
		concatenar();
	}

	return num;
}

//-----------------------------------------------------------------------------------------------

int main(){
	return 0;
}