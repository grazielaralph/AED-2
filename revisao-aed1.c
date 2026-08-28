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
	printf("%s - %d - %d - %.2f\n", func->nome, func->matricula, func->idade, func->salario);
}

//-----------------------------------------------------------------------------------------------------------------

typedef struct No
{
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

void listarFuncionarios(No *inicio){
	No *atual = inicio;
	while (atual != NULL){
		printFunc(&atual->func);
		atual = atual->proximo;
	}
}

No* searchByMatricula(int matricula, No *inicio){
	No *atual = inicio;
	while (atual != NULL){
		if(atual->func.matricula == matricula){
			return atual;
		}
		atual = atual->proximo;
	}
	return NULL;
}

void removeByMatricula (int matricula, No **inicio){
	No *atual = *inicio;
	No *anterior = NULL;
	while (atual != NULL){
		if(atual->func.matricula == matricula){
			if(anterior == NULL){
				*inicio = atual->proximo;
			}else{
				anterior->proximo = atual->proximo;
			}
			free(atual);
			printf("Removido com sucesso!\n");
			return;
		}
		anterior = atual;
		atual = atual->proximo;
	}
	printf("Matricula nao encontrada.\n");
}

int length(No *inicio){
	int contador = 0;
	No *atual = inicio;
	while(atual != NULL){
		contador++;
		atual = atual->proximo;
	}
	return contador;
}

void searchByMaiorSalario (No* inicio){
	if(inicio == NULL){
		printf("Nao ha funcionarios registrados.\n");
		return;
	}
	No *atual = inicio->proximo;
	No *maior = inicio;
	while (atual != NULL){
		if(atual->func.salario > maior->func.salario){
			maior = atual;
		}
		atual = atual->proximo;
	}
	printFunc(&maior->func);
}

//-----------------------------------------------------------------------------------------------------------------

void cadastrarFuncionario(No **inicio) {
	int matricula, idade;
	char nome[100];
	float salario;

	printf("Matricula: ");
	scanf("%d", &matricula);

	printf("Nome: ");
	scanf(" %[^\n]", nome);

	printf("Idade: ");
	scanf("%d", &idade);

	printf("Salario: ");
	scanf("%f", &salario);

	Funcionario *novo = criarFuncionario(matricula, nome, idade, salario);
	inserir(inicio, novo);
}

int main(){
	No *inicio = NULL;
	int opcao, matricula;

	do {
		printf("\n1-Cadastrar 2-Listar 3-Buscar 4-Remover 5-Quantidade 6-Maior salario 7-Sair\nOpcao: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				cadastrarFuncionario(&inicio);
				break;
			case 2:
				listarFuncionarios(inicio);
				break;
			case 3:
				printf("Matricula a buscar: ");
				scanf("%d", &matricula);
				No *encontrado = searchByMatricula(matricula, inicio);
				if(encontrado != NULL) printFunc(&encontrado->func);
				else printf("Nao encontrado.\n");
				break;
			case 4:
				printf("Matricula a remover: ");
				scanf("%d", &matricula);
				removeByMatricula(matricula, &inicio);
				break;
			case 5:
				printf("Total: %d\n", length(inicio));
				break;
			case 6:
				searchByMaiorSalario(inicio);
				break;
		}
	} while (opcao != 7);
	
	return 0;
}