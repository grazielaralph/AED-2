#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int qtdComp = 0;
int qtdTroca = 0;

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


	/*printf("Vetor L:\n");
	for(int i = 0; i < fim; i++){
		printf("%d ", L[i]);
	}
	printf("\n");*/
	return L;
}

int* right(int *num, int q, int r){
	int fim = r-q;

	int *R = (int *) malloc ((fim + 1) * sizeof(int));

	for(int i = 0; i < fim; i++){
		R[i] = num[q+i+1];
	}

	R[fim] = INT_MAX;

	/*printf("Vetor R:\n");
	for(int i = 0; i < fim; i++){
		printf("%d ", R[i]);
	}
	printf("\n");*/

	return R;
}

void merge(int *num, int p, int q, int r){
	int *L = left(num, p, q); 
	int *R = right(num, q, r);//alocacao dinamica e feita dentro das funcoes left e right
	int i = 0;
	int j = 0;

	for(int k = p; k <= r; k++){
		if (L[i] <= R[j]){ /*se o item do lado esquerdo for menor que o item do lado direito,
		entao a gente adiciona o item do lado esquerdo no vetor*/
			num [k] = L[i];
			i++;
		}else{
			//caso contrario, a gente adiciona o item do lado direito
			num[k] = R[j];
			j++;
		}
	}

	free(L);
	free(R);
	
}

void sortByMerge(int *num, int p, int r){
	if (p < r){ /*se a posicao inicial for menor do que a posicao final, 
	a gente calcula a mediana e divide o vetor no meio*/
		int q = (p+r)/2;
		sortByMerge(num, p, q);
		sortByMerge(num, q+1, r);
		merge(num, p, q, r); //mas por que aciona o merge ?
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