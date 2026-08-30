#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* criarVetor (int n){
    srand(time(NULL)); //pra nao rolar repeticao da execucao anterior

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

void sortByBubble(int *num, int n){
    int qtdComp = 0; //qtd de comparacoes
    int qtdTrocas = 0; //quantidade de trocas
    int aux = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            qtdComp++;
            if (num[j] > num[j+1]){
                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
                qtdTrocas++; //incrementa a troca
            }
        }
    }

    printVetor(num, n);
    printf("Quantidade de comparacoes: %d\n", qtdComp);
    printf("Quantidade de trocas: %d\n", qtdTrocas);
}

//-----------------------------------------------------------------------------------------------

int main(){
    int n = 0;
    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = criarVetor(n);

    sortByBubble(vetor, n);

    free(vetor);

    return 0;
}