# Atividade 6 - Manipulação de Arquivos (Texto e Binário)

Este projeto é um jogo 2D desenvolvido em C utilizando a biblioteca **raylib**. O principal objetivo desta atividade é demonstrar, na prática, a leitura e escrita de dados em arquivos de texto e binários, bem como o gerenciamento dinâmico de entidades na memória.

## 🚀 Funcionalidades

*   **Gerenciamento Dinâmico de Entidades:** O jogo gerencia Jogador (azul), Inimigos (bordô) e Itens (dourado) alocados dinamicamente através de um vetor de ponteiros e uma estrutura flexível (utilizando `union`).
*   **Mecânicas de Jogo:** Movimentação fluida, sistema de vida e pontuação, e detecção de colisão circular (raio-a-raio).
*   **Arquivos de Texto (`placar.txt`):** Grava a pontuação atual do jogador em formato legível e lê o arquivo ao iniciar para exibir a melhor pontuação (recorde) de todas as partidas.
*   **Arquivos Binários (`save.bin`):** Permite salvar o estado exato do jogo (posição, vida, tipos de todas as entidades) copiando os blocos de memória diretamente para um arquivo binário, permitindo carregar a partida posteriormente.

## 🛠️ Pré-requisitos

*   Compilador C (ex: `gcc`).
*   Biblioteca **raylib** instalada e configurada no sistema.

