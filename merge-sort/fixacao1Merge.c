#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*p -> posicao inicial do subvetor
q -> mediana do vetor
r -> posicao final do subvetor*/


void sortByMerge(int *num, int n, int p, int q, int r){
	
}

void merge(int *num, int n, int p, int q, int r){
	int qtdL = (n/2)+1;
	int qtdR = n/2;
	int *L = (int *) malloc(qtdL * sizeof(int));
	int *R = (int *) malloc(qtdR * sizeof(int));

	L = left(num, n, p, q, r);
	R = right(num, n, p, q, r);
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
	
}

int* left(int *num, int n, int p, int q, int r){
	fim = q-p+1;

	//for(int i = 1; )
	return *L;
}

int* right(int *num, int n, int p, int q, int r){
	return *R;
}

int main(){

	return 0;
}