# Lista Duplamente Encadeada em C

Este repositório contém a implementação de uma **Lista Duplamente Encadeada** em linguagem C. O projeto foi desenvolvido como atividade prática para a disciplina de Algoritmos e Estruturas de Dados I.

## 📋 Sobre o Projeto

O objetivo deste código é gerenciar uma estrutura de dados dinâmica bidirecional (lista duplamente encadeada) contendo números inteiros. A implementação gerencia o uso de memória dinamicamente (`malloc` e `free`) e utiliza ponteiros para rastrear o início e o fim da lista, garantindo eficiência nas operações de manipulação nas extremidades.

## ✨ Funcionalidades

O programa conta com um menu interativo no terminal que permite realizar as seguintes operações:

- **Inserção:** No início, no final e em uma posição específica definida pelo usuário.
- **Remoção:** Do início, do final e buscando por um valor específico.
- **Busca:** Verifica se um determinado valor existe na lista.
- **Visualização:** Imprime os elementos da lista em dois sentidos (do início ao fim e do fim ao início) para provar a consistência dos ponteiros `proximo` e `anterior`.
- **Contagem:** Retorna a quantidade total de nós atualmente na estrutura.
- **Prevenção de Memory Leak:** Função de limpeza automática que varre a lista liberando a memória de todos os nós antes de encerrar a execução.

## 🚀 Como Compilar e Executar

### Pré-requisitos

Para compilar o projeto, você precisará de um compilador C instalado no seu sistema. Se estiver usando o Windows, recomendamos o **MSYS2** (MinGW-w64 / GCC). No Linux ou macOS, o `gcc` nativo é suficiente.

### Passo a Passo

1. **Clone o repositório ou baixe o arquivo:**
   Certifique-se de que o arquivo principal de código fonte se chama `lista_dupla.c` e abra o terminal na pasta onde ele está localizado.

2. **Compilação:**
   No terminal, digite o comando abaixo para compilar o código usando o GCC. Isso criará um arquivo executável chamado `lista_dupla.exe` (ou apenas `lista_dupla` em sistemas Unix).
   ```bash
   gcc lista_dupla.c -o lista_dupla.exe
   ```

3. **Execução:**
   Após a compilação bem-sucedida, inicie o programa com o comando:
   ```bash
   ./lista_dupla.exe
   ```

## 💻 Uso do Programa

Ao executar o programa, você verá um menu numérico. Basta digitar o número correspondente à operação que deseja realizar e pressionar `Enter`. 

**Atenção:** 
- Ao escolher a opção **0 (Sair)**, o programa automaticamente limpa todos os nós da memória e encerra a execução. Nunca feche a janela do terminal abruptamente para garantir que a função de liberação de memória seja chamada corretamente.
- Na inserção por posição (opção 3), considere que a posição `1` se refere ao início da lista.

## 🛠️ Tecnologias e Conceitos Aplicados

- Linguagem C Padrão
- Estruturas (`struct`)
- Ponteiros (Ponteiros simples e ponteiros dentro de structs)
- Alocação Dinâmica de Memória (`malloc`, `free`, `sizeof`)
- Lógica de laços de repetição e condicionais