#include "algoritmos.h"

static void troca(int *a, int *b, Metricas *m) {
    int t = *a;
    *a = *b;
    *b = t;
    m->qtdTroca++;
}

static int partition(int *num, int p, int r, Metricas *m) {
    // Move o elemento do meio para o fim para evitar Stack Overflow em vetores ordenados de n=100.000
    int meio = p + (r - p) / 2;
    troca(&num[meio], &num[r], m);

    int x = num[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        m->qtdComp++;
        if (num[j] <= x) {
            i = i + 1;
            troca(&num[i], &num[j], m);
        }
    }
    troca(&num[i + 1], &num[r], m);
    return i + 1;
}

void quickSort(int *num, int p, int r, Metricas *m) {
    if (p < r) {
        int q = partition(num, p, r, m);
        quickSort(num, p, q - 1, m);
        quickSort(num, q + 1, r, m);
    }
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int qtdTroca = 0;
// int qtdComp = 0;

// int* criarVetor (int n){
//     int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

//     for(int i = 0; i < n; i++){
//         vetor[i] = rand() % 1000; //atribui valores aleatorios pro vetor de 0 a 999
//     }

//     return vetor;
// }

// void printVetor (int *num, int n){
//      for(int i = 0; i < n; i++){
//         printf(" %d ", num[i]);
//     } 
//     printf("\n");
// }

// //-----------------------------------------------------------------------------------------------

// void troca (int *a, int *b){
// 	int t = *a;
// 	*a = *b;
// 	*b = t;
// 	qtdTroca++;
// }


// //-----------------------------------------------------------------------------------------------
// int partition (int *num, int p, int r){
// 	int x = num[r];
// 	int i = p-1;

// 	for(int j = p; j<r; j++){
// 		qtdComp++;
// 		if(num[j] <= x){
// 			i = i+1;
// 			troca(&num[i], &num[j]);
// 		}
// 	}
// 	troca(&num[i+1], &num[r]);
// 	return i+1;
// }

// //-----------------------------------------------------------------------------------------------
// void quickSort(int *num, int p, int r){
// 	if(p < r){
// 		int q = partition(num, p, r);
// 		quickSort(num, p, q-1);
// 		quickSort(num, q+1, r);	
// 	}	
// }

// //-----------------------------------------------------------------------------------------------

// int main(){
// 	srand(time(NULL)); //pra nao rolar repeticao da execucao anterior
	
// 	int n = 0;
//     printf("Digite tamanho do vetor: ");
//     scanf("%d", &n);
//     int *vetor = criarVetor(n);

//     printf("\n");
//     printVetor(vetor, n);
//     printf("\n");

//     quickSort(vetor, 0, n-1);
//     printVetor(vetor, n);
    
//     printf("\nQuantidade de Comparacoes: %d\n", qtdComp);
//     printf("Quantidade de Trocas: %d\n", qtdTroca);

//     free(vetor);

// 	return 0;
// }