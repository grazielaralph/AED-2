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

typedef struct Node{
	int valor;
	struct Node* prox;
}

Node* sortByInsert(Node* head, int valor){
	Node* new = (Node*)malloc(sizeof(Node));
	novo->valor = valor;
	novo->prox = NULL;

	if(head == NULL || head->valor >= valor){
		novo->prox = head;
		return new;
	}

	Node* atual = head;
	while(atual->prox != NULL && atual->prox->valor < valor){
		atual = atual->prox;
	}

	novo->prox = atual->prox;
	atual->prox = novo;
	return head;
}

//-----------------------------------------------------------------------------------------------

void concatenar(Node** baldes, int n, float arr[]){
	int indice = 0;
	for(int i = 0; i < n; i++){
		Node* atual = baldes[i];
		while (atual != NULL){
			arr[indice++] = atual->valor;
			Node* temp = atual;
			atual = atual->prox;
			free(temp);
		}
	}
}


int* bucketSort(int *num, int n, int qtdBalde){
	Node** buckets = (Node**)calloc(n, sizeof(Node*));
	int *B = (int *) malloc(qtdBalde * sizeof(int));

	for(int i = 0; i < qtdBalde; i++){
		B[i] = NULL; //nao entendi como vou alocar uma lista vazia, vou ter q usar a estrutura de no?
	}

	int k = maiorValor(num, n) / qtdBalde;

	for(int i = 0; i<n; i++){
		int indice = (num[i] / qtdBalde) + 1;
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