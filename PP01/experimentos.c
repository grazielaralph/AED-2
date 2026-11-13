#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algoritmos.h"

typedef enum {
    ORDENADO = 0,
    INVERSAMENTE_ORDENADO = 1,
    ALEATORIO_COM_REPETICAO = 2,
    ALEATORIO_SEM_REPETICAO = 3
} TipoCenario;

int* gerarVetorCenario(int n, TipoCenario cenario) {
    int *vetor = (int *) malloc(n * sizeof(int));

    switch (cenario) {
        case ORDENADO:
            for (int i = 0; i < n; i++) vetor[i] = i;
            break;

        case INVERSAMENTE_ORDENADO:
            for (int i = 0; i < n; i++) vetor[i] = n - 1 - i;
            break;

        case ALEATORIO_COM_REPETICAO:
            for (int i = 0; i < n; i++) vetor[i] = rand() % 1000;
            break;

        case ALEATORIO_SEM_REPETICAO:
            for (int i = 0; i < n; i++) vetor[i] = i;
            for (int i = n - 1; i > 0; i--) {
                int j = rand() % (i + 1);
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
            break;
    }
    return vetor;
}

int* copiarVetor(int *origem, int n) {
    int *copia = (int *) malloc(n * sizeof(int));
    memcpy(copia, origem, n * sizeof(int));
    return copia;
}

void executarTeste(const char *nomeAlg, int idAlg, int *vetorBase, int n, const char *nomeCenario, FILE *csv) {
    int *vetor = copiarVetor(vetorBase, n);
    Metricas m = {0, 0, 0.0};

    clock_t inicio = clock();
    switch (idAlg) {
        case 0: sortbySelection(vetor, n, &m); break;
        case 1: sortByMerge(vetor, 0, n - 1, &m); break;
        case 2: quickSort(vetor, 0, n - 1, &m); break;
        case 3: heapSort(vetor, n, &m); break;
        case 4: countingSort(vetor, n, &m); break;
        case 5: bucketSort(vetor, n, 100, &m); break; // 100 baldes
    }
    clock_t fim = clock();

    m.tempo_ms = ((double)(fim - inicio) * 1000.0) / CLOCKS_PER_SEC;

    printf("%-24s | %-8d | %-15s | %-15lld | %-15lld | %-10.3f\n",
           nomeCenario, n, nomeAlg, m.qtdComp, m.qtdTroca, m.tempo_ms);

    if (csv != NULL) {
        fprintf(csv, "%s,%d,%s,%lld,%lld,%.3f\n",
                nomeCenario, n, nomeAlg, m.qtdComp, m.qtdTroca, m.tempo_ms);
    }

    free(vetor);
}

int main() {
    srand(42); // Semente fixa para testes justos e reprodutíveis

    int tamanhos[] = {1000, 10000, 100000};
    const char *nomesCenarios[] = {
        "Ja Ordenado",
        "Inversamente Ordenado",
        "Aleatorio COM Repeticao",
        "Aleatorio SEM Repeticao"
    };
    const char *nomesAlgoritmos[] = {
        "Selection Sort",
        "Merge Sort",
        "Quick Sort",
        "Heap Sort",
        "Counting Sort",
        "Bucket Sort"
    };

    FILE *csv = fopen("resultados.csv", "w");
    if (csv != NULL) {
        fprintf(csv, "Cenario,Tamanho,Algoritmo,Comparacoes,Movimentacoes,Tempo_ms\n");
    }

    printf("%-24s | %-8s | %-15s | %-15s | %-15s | %-10s\n",
           "Cenario", "Tamanho", "Algoritmo", "Comparacoes", "Movimentacoes", "Tempo (ms)");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int t = 0; t < 3; t++) {
        int n = tamanhos[t];
        for (int c = 0; c < 4; c++) {
            int *vetorBase = gerarVetorCenario(n, (TipoCenario)c);

            for (int a = 0; a < 6; a++) {
                executarTeste(nomesAlgoritmos[a], a, vetorBase, n, nomesCenarios[c], csv);
            }
            printf("------------------------------------------------------------------------------------------------------\n");
            free(vetorBase);
        }
    }

    if (csv != NULL) {
        fclose(csv);
        printf("\nArquivo 'resultados.csv' gerado com sucesso!\n");
    }

    return 0;
}