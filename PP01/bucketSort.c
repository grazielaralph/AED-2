#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int qtdTroca = 0;
int qtdComp = 0;

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
} Node;


Node* inserir(Node* head, int valor){
	Node* novo = (Node*)malloc(sizeof(Node));
	novo->valor = valor;
	novo->prox = head;
	return novo;
}

Node* inserirOrdenado(Node* head, int valor){
	Node* novo = (Node*)malloc(sizeof(Node));
	novo->valor = valor;
	novo->prox = NULL;

	if(head == NULL){
		return novo;
	}

	qtdComp++;
	if(head->valor >= valor){
		novo->prox = head;
		for(Node* p = head; p != NULL; p = p->prox){
			qtdTroca++;
		}
		return novo;
	}

	Node* atual = head;
	while(atual->prox != NULL){
		qtdComp++;
		if(atual->prox->valor >= valor){
			break;
		}
		atual = atual->prox;
	}

	novo->prox = atual->prox;
	atual->prox = novo;

	for(Node* p = novo->prox; p != NULL; p = p->prox){
		qtdTroca++;
	}

	return head;
}

Node* insertionSort(Node* head){
	Node* ordenada = NULL;

	while(head != NULL){
		Node* prox = head->prox;
		ordenada = inserirOrdenado(ordenada, head->valor);
		free(head);
		head = prox;
	}

	return ordenada;
}

void concatenar(Node** B, int nBaldes, int A[]){
	int indice = 0;

	for(int i = 0; i < nBaldes; i++){
		Node* atual = B[i];
		while (atual != NULL){
			A[indice++] = atual->valor;
			Node* temp = atual;
			atual = atual->prox;
			free(temp);
		}
	}
}

//-----------------------------------------------------------------------------------------------

int* bucketSort(int *num, int n, int qtdBalde){
	Node** B = (Node**) malloc(qtdBalde * sizeof(Node*));
	
	//vetor de listas vazias
	for(int i = 0; i < qtdBalde; i++){
		B[i] = NULL;
	}

	int k = maiorValor(num, n) / qtdBalde + 1; //tamanho dos baldes

	//distribui os valores nos baldes
	for(int i = 0; i < n; i++){
		int indice = num[i] / k;
		B[indice] = inserir(B[indice], num[i]);

	}

	//ordena cada balde
	for(int i = 0; i < qtdBalde; i++){
		B[i] = insertionSort(B[i]);
	}

	//junta tudo no original
	concatenar(B, qtdBalde, num);

	free(B);
	return num;
	
}

//-----------------------------------------------------------------------------------------------

int main(){

	srand(time(NULL));

	int n = 0;
	int qtdBalde = 5;
    printf("Digite tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = criarVetor(n);

    printf("\n");
    printVetor(vetor, n);
    printf("\n");

   
    int *vetorOrganizado = bucketSort(vetor, n, qtdBalde);
    printVetor(vetorOrganizado, n);
    
    printf("\nQuantidade de Comparacoes: %d\n", qtdComp);
    printf("Quantidade de Trocas: %d\n", qtdTroca);

    free(vetor);

	return 0;
}