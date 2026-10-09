# Busca Exponencial - Visualização em Raylib

Este repositório contém a implementação e a visualização gráfica do algoritmo de Busca Exponencial em linguagem C. O projeto foi desenvolvido como requisito de avaliação para a disciplina de Algoritmos e Estrutura de Dados I.

## Funcionalidades

* Implementação do algoritmo de Busca Exponencial do zero, sem funções predefinidas.
* Leitura de conjuntos de dados a partir de ficheiros de texto.
* Visualização gráfica interativa do funcionamento do algoritmo utilizando a biblioteca Raylib.
* Exibição de estatísticas em tempo real, incluindo o número de comparações e o passo atual.

## Dependências

Para compilar e executar este projeto, especialmente em ambiente Windows, é necessário possuir:
* **MSYS2** (ambiente UCRT64 ou MINGW64)
* Compilador **GCC**
* Biblioteca **Raylib**

## Como Compilar e Executar

Siga os passos abaixo no terminal do MSYS2 para rodar o projeto:

1. Navegar até a pasta do projeto

cd /c/Users/alexi/Desktop/projeto_edi

2. Gerar os arquivos de dados (Testes)
Antes de rodar a busca, compile e execute o gerador para criar os arquivos de texto necessários para os experimentos:

gcc gerador.c -o gerador.exe

./gerador.exe

3. Compilar o programa principal
Com os arquivos de dados criados, compile o código-fonte da interface visual:

gcc projeto.c -o busca_exponencial.exe -lraylib -lgdi32 -lwinmm

4. Executar o programa
Inicie a aplicação com o comando abaixo:


./busca_exponencial.exe

O terminal solicitará o nome do arquivo que você deseja ler (ex: dados_1000_repetidos.txt) e o número que você quer buscar na lista. Após informar os dados, a interface gráfica do Raylib se abrirá.

Controles da Interface Gráfica
[ESPAÇO]: Iniciar ou pausar a animação da busca.

[SETA DIREITA]: Executar o próximo passo da busca de forma manual.

[R]: Reiniciar o algoritmo desde o estado inicial.