# Atividade 8 - Módulos em C: Separação e Reuso de Código

Este projeto demonstra como organizar um programa em linguagem C separando-o em múltiplos arquivos (módulos) utilizando a biblioteca **raylib**[cite: 4]. O objetivo principal é isolar a lógica das entidades do jogo em um módulo independente, permitindo a compilação separada e o reuso do código por diferentes programas[cite: 4, 6].

## 📁 Estrutura do Projeto

O projeto foi refatorado e dividido nos seguintes arquivos:

*   **`entidade.h` (Interface):** Arquivo de cabeçalho que contém as declarações dos tipos (`enum`, `union`, `struct`) e os protótipos das funções do módulo de entidades[cite: 4, 5].
*   **`entidade.c` (Implementação):** Contém o código real (a lógica) de cada função declarada no cabeçalho, como criação, colisão, desenho e aplicação de dano, além da verificação se a entidade está viva[cite: 5, 6].
*   **`atividade8.c` (Programa Principal):** O jogo principal que inclui `entidade.h` e utiliza a interface pública do módulo para gerenciar o jogador, os inimigos e os itens[cite: 5, 6].
*   **`atividade8b.c` (Reuso do Módulo):** Um programa secundário e simples, que demonstra o principal benefício da modularização: reutilizar o mesmo módulo (`entidade.h` e `entidade.c`) sem precisar copiar nenhuma linha de código do módulo original.

## 🛠️ Pré-requisitos

*   Compilador C (como o `gcc`).
*   Biblioteca **raylib** instalada e configurada no seu sistema.

