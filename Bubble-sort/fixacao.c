#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* criarVetor (int n){
    int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

    for(int i = 0; i < n; i++){
        vetor[i] = rand() % 1000; //atribui valores aleatorios pro vetor de 0 a 9
    }

    return vetor;
}

int* sortByBubble(){
    
}

int main(){
    int n = 0;
    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = criarVetor(n);

    /* for(int i = 0; i < n; i++){
        printf("[%d]: %d\n", i, vetor[i]);
    } */
    return 0;
}