#include "algoritmos.h"

#define LEFT(i) (2 * (i) + 1)
#define RIGHT(i) (2 * (i) + 2)

static void troca(int *a, int *b, Metricas *m) {
    int t = *a;
    *a = *b;
    *b = t;
    m->qtdTroca++;
}

static void heapFy(int *num, int i, int tamHeap, Metricas *m) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int maior = i;

    if (l < tamHeap) {
        m->qtdComp++;
        if (num[l] > num[maior]) {
            maior = l;
        }
    }

    if (r < tamHeap) {
        m->qtdComp++;
        if (num[r] > num[maior]) {
            maior = r;
        }
    }

    if (maior != i) {
        troca(&num[i], &num[maior], m);
        heapFy(num, maior, tamHeap, m);
    }
}

static void buildHeap(int *num, int n, Metricas *m) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapFy(num, i, n, m);
    }
}

void heapSort(int *num, int n, Metricas *m) {
    int tamHeap = n;
    buildHeap(num, n, m);
    for (int i = n - 1; i >= 1; i--) {
        troca(&num[0], &num[i], m);
        tamHeap--;
        heapFy(num, 0, tamHeap, m);
    }
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define LEFT(i) (2*(i) + 1)
// #define RIGHT(i) (2*(i) + 2)

// int qtdTroca = 0;
// int qtdComp = 0;
// // int tamHeap  = 0; 

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

// void troca(int *a, int *b){
// 	int t = *a;
// 	*a = *b;
// 	*b = t;
// 	qtdTroca++;
// }

// //-----------------------------------------------------------------------------------------------

// void heapFy (int *num, int i){
// 	int l = LEFT (i); //LEFT(i) = 2i
// 	int r = RIGHT (i); //RIGHT(i) = 2i + 1
// 	int m = i;

// 	if(l < tamHeap){
// 		qtdComp++;
// 		if(num[l] > num[m]){
// 			m = l;			
// 		}
// 	}

// 	if(r < tamHeap){
// 		qtdComp++;
//         if(num[r] > num[m]){
//         	m = r;
//         } 
// 	}

// 	if(m != i){
// 		troca (&num[i], &num[m]);
// 		heapFy(num, m);
// 	}
// }

// void buildHeap (int *num, int n){
// 	tamHeap = n;
// 	for (int i = n/2 - 1; i >= 0 ; i--){
// 		heapFy(num, i);
// 	}

// }

// void heapSort (int *num, int n){
// 	buildHeap(num, n);
// 	for (int i = n-1; i >= 1; i--){
// 		troca(&num[0], &num[i]);
// 		tamHeap--;
// 		heapFy(num, 0);
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

//     heapSort(vetor, n);
//     printVetor(vetor, n);
    
//     printf("\nQuantidade de Comparacoes: %d\n", qtdComp);
//     printf("Quantidade de Trocas: %d\n", qtdTroca);

//     free(vetor);

// 	return 0;
// }