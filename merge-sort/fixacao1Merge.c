#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

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

//--------------------------------------------------------------------------------------------

/*p -> posicao inicial do subvetor
q -> mediana do vetor
r -> posicao final do subvetor*/

int* left(int *num, int p, int q){
	int fim = q-p+1;

	int *L = (int *) malloc((fim + 1) * sizeof(int)); //alocacao dinamica do vetor

	for(int i = 0; i < fim; i++){
		L[i] = num[p+i];
	}
	L[fim] = INT_MAX;
	return L;
}

int* right(int *num, int q, int r){
	int fim = r-q;

	int *R = (int *) malloc ((fim + 1) * sizeof(int));

	for(int i = 0; i < fim; i++){
		R[i] = num[q+i+1];
	}

	R[fim] = INT_MAX;
	return R;
}

void merge(int *num, int p, int q, int r){
	int *L = left(num, p, q); 
	int *R = right(num, q, r);//alocacao dinamica e feita dentro das funcoes left e right
	int i = 0;
	int j = 0;

	for(int k = p; k <= r; k++){
		if (L[i] <= R[j]){
			num [k] = L[i];
			i++;
		}else{
			num[k] = R[j];
			j++;
		}
	}

	free(L);
	free(R);
	
}

void sortByMerge(int *num, int p, int r){
	if (p < r){
		int q = (p+r)/2;
		sortByMerge(num, p, q);
		sortByMerge(num, q+1, r);
		merge(num, p, q, r);
	}

}


//------------------------------------------------------------------------------------------------------------

int main(){
	srand(time(NULL));

    int n = 0;
    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = criarVetor(n);

    printf("\n");
    printVetor(vetor, n);
    printf("\n");
	
	sortByMerge(vetor, 0, n-1);
    printVetor(vetor, n);

    free(vetor);


	return 0;
}