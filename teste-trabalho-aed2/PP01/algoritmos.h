#ifndef ALGORITMOS_H
#define ALGORITMOS_H

typedef struct {
    long long qtdComp;
    long long qtdTroca;
    double tempo_ms;
} Metricas;

void sortbySelection(int *num, int n, Metricas *m);
void sortByMerge(int *num, int p, int r, Metricas *m);
void quickSort(int *num, int p, int r, Metricas *m);
void heapSort(int *num, int n, Metricas *m);
void countingSort(int *num, int n, Metricas *m);
void bucketSort(int *num, int n, int qtdBalde, Metricas *m);

#endif