/*
Funcionario possui:
matricula - numero inteiro e unico (chave da ABB)
nome      - texto com ate 100 caracteres
idade     - inteiro
salario   - real
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[100];
    int idade;
    float salario;
} Funcionario;

typedef struct No {
    Funcionario func;
    struct No *esquerda;
    struct No *direita;
} No;

/* ---------------------------------------------------------------------
   
--------------------------------------------------------------------- */

Funcionario criarFuncionario(int matricula, const char *nome, int idade, float salario) {
    Funcionario f;
    f.matricula = matricula;
    strncpy(f.nome, nome, sizeof(f.nome) - 1);
    f.nome[sizeof(f.nome) - 1] = '\0';
    f.idade = idade;
    f.salario = salario;
    return f;
}

void printFunc(Funcionario *func) {
    printf("%-6d %-30s %3d anos  R$ %.2f\n",
           func->matricula, func->nome, func->idade, func->salario);
}

/* ---------------------------------------------------------------------
--------------------------------------------------------------------- */

No* criarNo(Funcionario func) {
    No *novo = (No *) malloc(sizeof(No));
    novo->func = func;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}


No* inserir(No *raiz, Funcionario func) {
    if (raiz == NULL) {
        return criarNo(func);
    }
    if (func.matricula < raiz->func.matricula) {
        raiz->esquerda = inserir(raiz->esquerda, func);
    } else if (func.matricula > raiz->func.matricula) {
        raiz->direita = inserir(raiz->direita, func);
    } else {
        printf("Matricula %d ja existe! Insercao ignorada.\n", func.matricula);
    }
    return raiz;
}


No* buscar(No *raiz, int matricula) {
    if (raiz == NULL || raiz->func.matricula == matricula) {
        return raiz;
    }
    if (matricula < raiz->func.matricula) {
        return buscar(raiz->esquerda, matricula);
    }
    return buscar(raiz->direita, matricula);
}


void emOrdem(No *raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printFunc(&raiz->func);
    emOrdem(raiz->direita);
}


void preOrdem(No *raiz) {
    if (raiz == NULL) return;
    printFunc(&raiz->func);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void posOrdem(No *raiz) {
    if (raiz == NULL) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printFunc(&raiz->func);
}


int altura(No *raiz) {
    if (raiz == NULL) return -1;
    int he = altura(raiz->esquerda);
    int hd = altura(raiz->direita);
    return 1 + (he > hd ? he : hd);
}


int contarFolhas(No *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL) return 1;
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}


No* menorNo(No *raiz) {
    No *atual = raiz;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}


No* remover(No *raiz, int matricula, int *encontrado) {
    if (raiz == NULL) {
        *encontrado = 0;
        return NULL;
    }

    if (matricula < raiz->func.matricula) {
        raiz->esquerda = remover(raiz->esquerda, matricula, encontrado);
    } else if (matricula > raiz->func.matricula) {
        raiz->direita = remover(raiz->direita, matricula, encontrado);
    } else {
        *encontrado = 1;

        
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }

        
        if (raiz->esquerda == NULL) {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        if (raiz->direita == NULL) {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

       
        No *sucessor = menorNo(raiz->direita);
        raiz->func = sucessor->func;
        int dummy;
        raiz->direita = remover(raiz->direita, sucessor->func.matricula, &dummy);
    }
    return raiz;
}


void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

/* ---------------------------------------------------------------------
--------------------------------------------------------------------- */

No* carregarFuncionariosIniciais(No *raiz) {
    raiz = inserir(raiz, criarFuncionario(105, "Ana Silva", 25, 3500.00f));
    raiz = inserir(raiz, criarFuncionario(102, "Bruno Costa", 30, 5200.50f));
    raiz = inserir(raiz, criarFuncionario(110, "Carla Dias", 22, 2900.00f));
    raiz = inserir(raiz, criarFuncionario(101, "Diego Souza", 40, 6100.00f));
    raiz = inserir(raiz, criarFuncionario(108, "Elis Rocha", 35, 7800.00f));
    raiz = inserir(raiz, criarFuncionario(104, "Felipe Nunes", 28, 4300.00f));
    raiz = inserir(raiz, criarFuncionario(112, "Graziela Ralph", 20, 15895.87f));
    raiz = inserir(raiz, criarFuncionario(107, "Helena Prado", 33, 5000.00f));
    raiz = inserir(raiz, criarFuncionario(103, "Igor Martins", 45, 8900.00f));
    raiz = inserir(raiz, criarFuncionario(109, "Julia Mendes", 27, 4700.00f));
    return raiz;
}

No* cadastrarFuncionario(No *raiz) {
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

    Funcionario f = criarFuncionario(matricula, nome, idade, salario);
    return inserir(raiz, f);
}

/* ---------------------------------------------------------------------
--------------------------------------------------------------------- */

void exibirMenu() {
    printf("\n===== ARVORE BINARIA DE BUSCA - FUNCIONARIOS =====\n");
    printf("1  - Inserir funcionario\n");
    printf("2  - Buscar funcionario por matricula\n");
    printf("3  - Listar em ordem (in-order)\n");
    printf("4  - Listar em pre-ordem\n");
    printf("5  - Listar em pos-ordem\n");
    printf("6  - Calcular altura da arvore\n");
    printf("7  - Contar quantidade de folhas\n");
    printf("8  - Remover funcionario por matricula\n");
    printf("0  - Sair\n");
    printf("Opcao: ");
}

int main() {
    No *raiz = NULL;
    int opcao, matricula;

    raiz = carregarFuncionariosIniciais(raiz);

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                raiz = cadastrarFuncionario(raiz);
                break;

            case 2: {
                printf("Matricula a buscar: ");
                scanf("%d", &matricula);
                No *encontrado = buscar(raiz, matricula);
                if (encontrado != NULL) {
                    printFunc(&encontrado->func);
                } else {
                    printf("Funcionario nao encontrado.\n");
                }
                break;
            }

            case 3:
                printf("\n-- Em ordem (crescente por matricula) --\n");
                emOrdem(raiz);
                break;

            case 4:
                printf("\n-- Pre-ordem --\n");
                preOrdem(raiz);
                break;

            case 5:
                printf("\n-- Pos-ordem --\n");
                posOrdem(raiz);
                break;

            case 6:
                printf("Altura da arvore: %d\n", altura(raiz));
                break;

            case 7:
                printf("Quantidade de folhas: %d\n", contarFolhas(raiz));
                break;

            case 8: {
                printf("Matricula a remover: ");
                scanf("%d", &matricula);
                int encontrado;
                raiz = remover(raiz, matricula, &encontrado);
                if (encontrado) {
                    printf("Removido com sucesso!\n");
                } else {
                    printf("Matricula nao encontrada.\n");
                }
                break;
            }

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    liberarArvore(raiz);
    return 0;
}