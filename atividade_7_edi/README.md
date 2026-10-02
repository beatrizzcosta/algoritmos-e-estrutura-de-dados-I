# Atividade 7 - Complexidade de Algoritmos: Busca e Ordenação

Este projeto é uma aplicação visual interativa desenvolvida em C com a biblioteca **raylib**. O objetivo é demonstrar, na prática, o custo computacional de diferentes algoritmos de busca e ordenação através da contagem de operações (comparações e trocas) e da medição do tempo de execução em milissegundos[cite: 1, 2, 3].

O programa desenha um vetor dinâmico de placares como barras verticais, permitindo enxergar visualmente o efeito da ordenação[cite: 1].

## 🚀 Funcionalidades e Algoritmos

*   **Busca Sequencial $O(n)$:** Funciona em qualquer vetor (ordenado ou não), verificando posição por posição[cite: 2].
*   **Busca Binária $O(\log n)$:** Mais eficiente, descartando metade dos elementos a cada passo, mas exige que o vetor esteja previamente ordenado[cite: 2, 3].
*   **Bubble Sort $O(n^2)$:** Ordenação percorrendo o vetor repetidamente e trocando elementos vizinhos fora de ordem[cite: 2].
*   **Insertion Sort $O(n^2)$:** Ordenação que insere cada elemento na sua posição correta deslocando os anteriores[cite: 3].
*   **Métricas de Desempenho:** Contagem de comparações, trocas e medição do tempo real de execução em milissegundos usando `GetTime()`[cite: 2, 3].

## 🛠️ Pré-requisitos

Para compilar e executar este projeto, você precisará de:
*   Compilador C (como o `gcc`).
*   Biblioteca **raylib** instalada e configurada no seu sistema.

## ⚙️ Como Compilar

No Linux (com a raylib instalada), abra o terminal na pasta do arquivo e execute o comando abaixo:

```bash
gcc atividade7.c -o atividade7 -lraylib -lm -lpthread -ldl -lrt -lX11