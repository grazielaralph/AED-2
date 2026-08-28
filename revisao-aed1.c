/*funcionario possui 
matricula - numero inteiro e unico
nome - texto com ate 100 caracteres
idade - inteiro
salario - real
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int matricula;
	char nome[100];
	int idade;
	float salario;	
}Funcionario;

Funcionario* criarFuncionario (int matricula, const char* nome, int idade, float salario){
	Funcionario* func = (Funcionario*) malloc(sizeof(Funcionario));
	func->matricula = matricula;
	strcpy(func->nome, nome);
	func->idade = idade;
	func->salario = salario;
	return func;
}

void printFunc (Funcionario* func){
	printf("%s - %d - %d - %2.f\n", func->nome, func->matricula, func->idade, func->salario);
}

//-----------------------------------------------------------------------------------------------------------------

typedef struct{
	Funcionario func;
	struct No *proximo;

}No;

void inserir(No **inicio, Funcionario* func){
	No *ultimo = (No *)malloc(sizeof(No));
	ultimo->func = *func;
	ultimo->proximo = NULL;

	if(*inicio == NULL){
		*inicio = ultimo;
	}else{
			No *atual = *inicio;
			while (atual->proximo != NULL){
				atual = atual->proximo;
			}

			atual->proximo = ultimo;
	}
}

void printFunc(No *inicio){
	No *atual = inicio;

	while (atual != NULL){
		printFunc(&atual->func);
		atual = atual->proximo;
	}
}

int main(){

	Funcionario* f1 = criarFuncionario(12345, "Graziela da Costa Ralph", 20, 15895.8691);
	print(f1);

	
	return 0;
}






