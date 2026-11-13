import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Carrega os dados gerados pelo programa em C
df = pd.read_csv('resultados.csv')

plt.rcParams['figure.figsize'] = (12, 6)
plt.rcParams['font.size'] = 10

# 1. Gráfico de Tempo de Execução para n = 100.000 (Escala Logarítmica para ver todos)
df_100k = df[df['Tamanho'] == 100000]
pivot_tempo = df_100k.pivot(index='Algoritmo', columns='Cenario', values='Tempo_ms')
ordem_alg = ['Counting Sort', 'Quick Sort', 'Merge Sort', 'Heap Sort', 'Bucket Sort', 'Selection Sort']
pivot_tempo = pivot_tempo.reindex(ordem_alg)

ax = pivot_tempo.plot(kind='bar', width=0.8)
plt.yscale('log')
plt.title('Tempo de Execução por Algoritmo e Cenário (n = 100.000) - Escala Log', fontweight='bold')
plt.ylabel('Tempo (ms) - Escala Logarítmica')
plt.xlabel('Algoritmo')
plt.xticks(rotation=15)
plt.grid(axis='y', linestyle='--', alpha=0.5)
plt.legend(title='Cenário')
plt.tight_layout()
plt.savefig('grafico_1_tempo_100k_log.png', dpi=300)
plt.close()

# 2. Gráfico de Tempo de Execução sem o Selection Sort e Bucket Sort (Escala Linear n = 100.000)
alg_rapidos = ['Counting Sort', 'Quick Sort', 'Merge Sort', 'Heap Sort']
pivot_rapidos = pivot_tempo.reindex(alg_rapidos)

ax = pivot_rapidos.plot(kind='bar', width=0.75)
plt.title('Comparação Direta dos Algoritmos Mais Rápidos (n = 100.000)', fontweight='bold')
plt.ylabel('Tempo de Execução (ms)')
plt.xlabel('Algoritmo')
plt.xticks(rotation=0)
plt.grid(axis='y', linestyle='--', alpha=0.5)
plt.legend(title='Cenário')
plt.tight_layout()
plt.savefig('grafico_2_tempo_rapidos_100k.png', dpi=300)
plt.close()

# 3. Gráfico de Comparações (n = 100.000) - Escala Logarítmica
pivot_comp = df_100k.pivot(index='Algoritmo', columns='Cenario', values='Comparacoes').reindex(ordem_alg)
ax = pivot_comp.plot(kind='bar', width=0.8)
plt.yscale('log')
plt.title('Número de Comparações por Algoritmo e Cenário (n = 100.000)', fontweight='bold')
plt.ylabel('Quantidade de Comparações (Escala Log)')
plt.xlabel('Algoritmo')
plt.xticks(rotation=15)
plt.grid(axis='y', linestyle='--', alpha=0.5)
plt.legend(title='Cenário')
plt.tight_layout()
plt.savefig('grafico_3_comparacoes_100k.png', dpi=300)
plt.close()

# 4. Gráfico de Movimentações (n = 100.000) - Escala Logarítmica
pivot_mov = df_100k.pivot(index='Algoritmo', columns='Cenario', values='Movimentacoes').reindex(ordem_alg)
ax = pivot_mov.plot(kind='bar', width=0.8)
plt.yscale('log')
plt.title('Número de Movimentações por Algoritmo e Cenário (n = 100.000)', fontweight='bold')
plt.ylabel('Quantidade de Movimentações (Escala Log)')
plt.xlabel('Algoritmo')
plt.xticks(rotation=15)
plt.grid(axis='y', linestyle='--', alpha=0.5)
plt.legend(title='Cenário')
plt.tight_layout()
plt.savefig('grafico_4_movimentacoes_100k.png', dpi=300)
plt.close()

print("Gráficos gerados com sucesso na pasta PP01!")
