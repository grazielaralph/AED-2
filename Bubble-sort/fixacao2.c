#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 5000

int verificaValor(int *vetor, int qtdAtual, int num){
	for(int i = 0; i < qtdAtual; i++){
		if(vetor[i] == num){
			return 1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------

int* criarVetor (int n){
    int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

    for(int i = 0; i < n; i++){
        vetor[i] = rand(); 
    }
    return vetor;
}

int* criarVetorSemRepeticao (int n){
	int numGerado = 0;
	
    int *vetor = (int *) malloc(n * sizeof(int)); //alocacao dinamica

    for(int i = 0; i < n; i++){
        do{
        	numGerado = rand();
        }while(verificaValor(vetor, i, numGerado)); //continua executando ate gerar um valor diferente

        vetor[i] = numGerado;
    }

    return vetor;
}

//-----------------------------------------------------------------------------------------------

void sortByBubbleCresc(int *num, int n){
    int qtdComp = 0; //qtd de comparacoes
    int qtdTrocas = 0; //quantidade de trocas
    int aux = 0;

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            qtdComp++;
            if (num[j] > num[j+1]){
                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
                qtdTrocas++; //incrementa a troca
            }
        }
    }

    //printVetor(num, n);
    printf("Quantidade de comparacoes: %d\n", qtdComp);
    printf("Quantidade de trocas: %d\n", qtdTrocas);
}

void sortByBubbleDecresc(int *num, int n){
    int qtdComp = 0; //qtd de comparacoes
    int qtdTrocas = 0; //quantidade de trocas
    int aux = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            qtdComp++;
            //faz a comparacao inversa
            if (num[j] < num[j+1]){
                aux = num[j+1];
                num[j+1] = num[j];
                num[j] = aux;
                qtdTrocas++; //incrementa a troca
            }
        }
    }

    /*printVetor(num, n);
    printf("Quantidade de comparacoes: %d\n", qtdComp);
    printf("Quantidade de trocas: %d\n", qtdTrocas);*/
}
//-----------------------------------------------------------------------------------------------

int main(){
    srand(time(NULL)); //pra nao rolar repeticao da execucao anterior

	int *vetor1 = criarVetor(TAMANHO); 
	int *vetor2 = criarVetor(TAMANHO);
	int *vetor3 = criarVetorSemRepeticao(TAMANHO);

	printf("Vetor aleatorio com repeticao: \n");
	sortByBubbleCresc(vetor1, TAMANHO); //vetor aleatorio com repeticao 
	printf("\n \n");

	printf("Melhor caso - vetor ordenado: \n");
	sortByBubbleCresc(vetor1, TAMANHO); //melhor caso - vetor ordenado
    printf("\n \n");
	
	sortByBubbleDecresc(vetor2, TAMANHO);
	printf("Pior caso - vetor ordenado na ordem decrescente: \n");
	sortByBubbleCresc(vetor2, TAMANHO); //pior caso - vetor na ordem inversa
	printf("\n \n");

	printf("Vetor aleatorio sem repeticao: \n");
	sortByBubbleCresc(vetor3, TAMANHO); //vetor aleatorio sem repeticao
    printf("\n \n");

	free(vetor1);
	free(vetor2);
	free(vetor3);
	return 0;
}