
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Carrega os dados gerados pelo programa em C
df = pd.read_csv('resultados.csv')

tamanhos = [1000, 10000, 100000]
ordem_alg = ['Counting Sort', 'Quick Sort', 'Merge Sort', 'Heap Sort', 'Bucket Sort', 'Selection Sort']
ordem_cenarios = ['Ja Ordenado', 'Inversamente Ordenado', 'Aleatorio COM Repeticao', 'Aleatorio SEM Repeticao']

plt.rcParams['font.size'] = 10

# ==============================================================================
# PARTE 1: PAINÉIS CONSOLIDADOS (1x3) -> n=1.000, n=10.000 e n=100.000 LADO A LADO
# ==============================================================================
metricas_info = [
    ('Tempo_ms', 'Tempo de Execução (ms)', 'painel_1_tempo_todos_tamanhos.png', False),
    ('Comparacoes', 'Quantidade de Comparações', 'painel_2_comparacoes_todos_tamanhos.png', True),
    ('Movimentacoes', 'Quantidade de Movimentações', 'painel_3_movimentacoes_todos_tamanhos.png', True)
]

for col_metrica, titulo_y, nome_arquivo, substituir_zero in metricas_info:
    fig, axes = plt.subplots(1, 3, figsize=(20, 6), sharey=True)
    fig.suptitle(f'{titulo_y} por Algoritmo, Cenário e Tamanho de Entrada (Escala Log)', fontsize=14, fontweight='bold')

    for idx, n in enumerate(tamanhos):
        ax = axes[idx]
        df_n = df[df['Tamanho'] == n].copy()
        
        if substituir_zero:
            # Substitui 0 por 1 apenas para visualização na escala logarítmica
            df_n[col_metrica] = df_n[col_metrica].replace(0, 1)

        pivot = df_n.pivot(index='Algoritmo', columns='Cenario', values=col_metrica)
        pivot = pivot.reindex(index=ordem_alg, columns=ordem_cenarios)

        pivot.plot(kind='bar', ax=ax, width=0.8, legend=(idx == 2))
        ax.set_yscale('log')
        ax.set_title(f'Tamanho n = {n:,}'.replace(',', '.'), fontweight='bold', fontsize=12)
        ax.set_xlabel('Algoritmo')
        if idx == 0:
            ax.set_ylabel(f'{titulo_y} (Escala Log)')
        ax.tick_params(axis='x', rotation=25)
        ax.grid(axis='y', linestyle='--', alpha=0.5)

        if idx == 2:
            ax.legend(title='Cenário', bbox_to_anchor=(1.02, 1), loc='upper left')

    plt.tight_layout(rect=[0, 0, 1, 0.94])
    plt.savefig(nome_arquivo, dpi=300)
    plt.close()

# ==============================================================================
# PARTE 2: PAINEL DE LINHAS (2x2) -> ESCALABILIDADE POR CENÁRIO (1.000 a 100.000)
# ==============================================================================
fig, axes = plt.subplots(2, 2, figsize=(15, 10), sharey=True)
fig.suptitle('Escalabilidade do Tempo de Execução (n = 1.000, 10.000 e 100.000) em Cada Cenário', fontsize=14, fontweight='bold')

marcadores = ['o', 's', '^', 'D', 'v', 'P']

for idx, cenario in enumerate(ordem_cenarios):
    ax = axes[idx // 2, idx % 2]
    df_c = df[df['Cenario'] == cenario]
    pivot_c = df_c.pivot(index='Tamanho', columns='Algoritmo', values='Tempo_ms').reindex(columns=ordem_alg)

    for i, alg in enumerate(ordem_alg):
        ax.plot(pivot_c.index.astype(str), pivot_c[alg], marker=marcadores[i], linewidth=2, label=alg)

    ax.set_yscale('log')
    ax.set_title(f'Cenário: {cenario}', fontweight='bold', fontsize=12)
    ax.set_xlabel('Tamanho do Vetor (n)')
    ax.set_ylabel('Tempo (ms) - Escala Log')
    ax.grid(True, linestyle='--', alpha=0.5)
    if idx == 1:
        ax.legend(title='Algoritmo', bbox_to_anchor=(1.02, 1), loc='upper left')

plt.tight_layout(rect=[0, 0, 1, 0.95])
plt.savefig('painel_4_escalabilidade_por_cenario.png', dpi=300)
plt.close()

# ==============================================================================
# PARTE 3: GRÁFICOS INDIVIDUAIS PARA CADA TAMANHO (n = 1.000, 10.000 e 100.000)
# ==============================================================================
for n in tamanhos:
    df_n = df[df['Tamanho'] == n].copy()
    sufixo = f"{n//1000}k"

    # 3.1 Tempo (Log) para o tamanho n
    pivot_t = df_n.pivot(index='Algoritmo', columns='Cenario', values='Tempo_ms').reindex(index=ordem_alg, columns=ordem_cenarios)
    pivot_t.plot(kind='bar', figsize=(12, 6), width=0.8)
    plt.yscale('log')
    plt.title(f'Tempo de Execução por Algoritmo e Cenário (n = {n:,}) - Escala Log'.replace(',', '.'), fontweight='bold')
    plt.ylabel('Tempo (ms) - Escala Logarítmica')
    plt.xlabel('Algoritmo')
    plt.xticks(rotation=15)
    plt.grid(axis='y', linestyle='--', alpha=0.5)
    plt.legend(title='Cenário')
    plt.tight_layout()
    plt.savefig(f'grafico_tempo_{sufixo}_log.png', dpi=300)
    plt.close()

    # 3.2 Comparações (Log) para o tamanho n
    df_comp = df_n.copy()
    df_comp['Comparacoes'] = df_comp['Comparacoes'].replace(0, 1)
    pivot_c = df_comp.pivot(index='Algoritmo', columns='Cenario', values='Comparacoes').reindex(index=ordem_alg, columns=ordem_cenarios)
    pivot_c.plot(kind='bar', figsize=(12, 6), width=0.8)
    plt.yscale('log')
    plt.title(f'Número de Comparações por Algoritmo e Cenário (n = {n:,})'.replace(',', '.'), fontweight='bold')
    plt.ylabel('Quantidade de Comparações (Escala Log)')
    plt.xlabel('Algoritmo')
    plt.xticks(rotation=15)
    plt.grid(axis='y', linestyle='--', alpha=0.5)
    plt.legend(title='Cenário')
    plt.tight_layout()
    plt.savefig(f'grafico_comparacoes_{sufixo}.png', dpi=300)
    plt.close()

    # 3.3 Movimentações (Log) para o tamanho n
    df_mov = df_n.copy()
    df_mov['Movimentacoes'] = df_mov['Movimentacoes'].replace(0, 1)
    pivot_m = df_mov.pivot(index='Algoritmo', columns='Cenario', values='Movimentacoes').reindex(index=ordem_alg, columns=ordem_cenarios)
    pivot_m.plot(kind='bar', figsize=(12, 6), width=0.8)
    plt.yscale('log')
    plt.title(f'Número de Movimentações por Algoritmo e Cenário (n = {n:,})'.replace(',', '.'), fontweight='bold')
    plt.ylabel('Quantidade de Movimentações (Escala Log)')
    plt.xlabel('Algoritmo')
    plt.xticks(rotation=15)
    plt.grid(axis='y', linestyle='--', alpha=0.5)
    plt.legend(title='Cenário')
    plt.tight_layout()
    plt.savefig(f'grafico_movimentacoes_{sufixo}.png', dpi=300)
    plt.close()

print("Todos os painéis e gráficos para n=1.000, n=10.000 e n=100.000 foram gerados com sucesso!")


