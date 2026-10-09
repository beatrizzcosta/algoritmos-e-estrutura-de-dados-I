#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "raylib.h"

typedef enum { ESPERA, SALTO_EXPONENCIAL, BUSCA_BINARIA, FINALIZADO } EstadoBusca;


typedef union {
    int valor_int;
    float valor_float; 
} Dado;


typedef struct { 
    Dado *dados; 
    int tamanho; 
} VetorDados;


VetorDados carregar_dados(const char *nome_ficheiro) { 
    VetorDados v = {NULL, 0}; 
    FILE *ficheiro = fopen(nome_ficheiro, "r"); 
    if (!ficheiro) {
        printf("Erro ao abrir o arquivo: %s\n", nome_ficheiro);
        return v;
    }

    int temp;
    while (fscanf(ficheiro, "%d", &temp) == 1) {
        v.tamanho++;
    }
    rewind(ficheiro);

    v.dados = (Dado *)malloc(v.tamanho * sizeof(Dado));
    for (int i = 0; i < v.tamanho; i++) {
        fscanf(ficheiro, "%d", &v.dados[i].valor_int);
    }
    fclose(ficheiro);
    return v;
}

int main() { 
    char nome_ficheiro[100];
    Dado procurado;

   
    printf("Digite o nome do arquivo (ex: dados_100_unicos.txt): ");
    scanf("%99s", nome_ficheiro);

    VetorDados v = carregar_dados(nome_ficheiro);
    if (v.tamanho == 0) return 1;

    printf("Arquivo carregado com %d elementos.\n", v.tamanho);
    printf("Digite o numero que deseja procurar (para testar melhor, medio ou pior caso): ");
    scanf("%d", &procurado.valor_int);

   
    const int larguraEcra = 800; 
    const int alturaEcra = 450; 
    InitWindow(larguraEcra, alturaEcra, "Busca Exponencial - Raylib"); 
    SetTargetFPS(60);

    EstadoBusca estado = ESPERA;
    bool pausado = true;

    int salto = 1, esquerda = 0, direita = 0, meio = 0;
    int comparacoes = 0, passos = 0, posicao_encontrada = -1;
    double tempoUltimoPasso = 0;

    
    while (!WindowShouldClose()) {
        
        // Exigência 5: Controlos (iniciar, pausar, continuar, reiniciar, proximo passo)
        if (IsKeyPressed(KEY_R)) {
            estado = ESPERA; pausado = true; salto = 1; esquerda = 0;
            direita = 0; meio = 0; comparacoes = 0; passos = 0; posicao_encontrada = -1;
        }

        if (IsKeyPressed(KEY_SPACE)) pausado = !pausado;

        bool proximo_passo = IsKeyPressed(KEY_RIGHT) || (!pausado && (GetTime() - tempoUltimoPasso) > 0.3);

        if (proximo_passo && estado != FINALIZADO) {
            tempoUltimoPasso = GetTime();
            passos++;

            if (estado == ESPERA) {
                comparacoes++;
                if (v.dados[0].valor_int == procurado.valor_int) {
                    posicao_encontrada = 0;
                    estado = FINALIZADO;
                } else {
                    estado = SALTO_EXPONENCIAL;
                    salto = 1;
                }
            } else if (estado == SALTO_EXPONENCIAL) {
                comparacoes++;
                if (salto < v.tamanho && v.dados[salto].valor_int <= procurado.valor_int) {
                    salto *= 2;
                } else {
                    esquerda = salto / 2;
                    direita = (salto < v.tamanho) ? salto : v.tamanho - 1;
                    estado = BUSCA_BINARIA;
                }
            } else if (estado == BUSCA_BINARIA) {
                if (esquerda <= direita) {
                    meio = esquerda + (direita - esquerda) / 2;
                    comparacoes++;
                    if (v.dados[meio].valor_int == procurado.valor_int) {
                        posicao_encontrada = meio;
                        estado = FINALIZADO;
                    } else {
                        comparacoes++;
                        if (v.dados[meio].valor_int < procurado.valor_int) {
                            esquerda = meio + 1;
                        } else {
                            direita = meio - 1;
                        }
                    }
                } else {
                    estado = FINALIZADO;
                }
            }
        }

       
        BeginDrawing();
        ClearBackground(RAYWHITE);

        int larguraBarra = larguraEcra / v.tamanho;
        for (int i = 0; i < v.tamanho; i++) {
            Color cor = LIGHTGRAY;
            
            if (estado == SALTO_EXPONENCIAL && i <= salto) cor = SKYBLUE;
            if (estado == BUSCA_BINARIA && i >= esquerda && i <= direita) cor = ORANGE;
            if (estado == BUSCA_BINARIA && i == meio) cor = RED;
            if (estado == FINALIZADO && i == posicao_encontrada) cor = GREEN;

            int alturaBarra = v.dados[i].valor_int * 3; 
            if (alturaBarra > alturaEcra - 120) alturaBarra = alturaEcra - 120;
            
            DrawRectangle(i * larguraBarra, alturaEcra - alturaBarra - 30, larguraBarra > 0 ? larguraBarra - 1 : 1, alturaBarra, cor);
        }

                DrawText("Algoritmo: Busca Exponencial", 10, 10, 18, BLACK);
        DrawText(TextFormat("Elementos: %d", v.tamanho), 10, 30, 18, BLACK);
        DrawText(TextFormat("Comparacoes: %d", comparacoes), 10, 50, 18, BLACK);
        DrawText(TextFormat("Passo: %d", passos), 10, 70, 18, BLACK);
        DrawText(TextFormat("Procurando: %d", procurado.valor_int), 10, 90, 18, DARKBLUE);
        
        if (pausado) DrawText("PAUSADO", larguraEcra - 100, 10, 20, RED);

        DrawText("CONTROLOS: [ESPACO] Iniciar/Pausar | [SETA DIR] Passo | [R] Reiniciar", 10, alturaEcra - 20, 14, DARKGRAY);

        EndDrawing();
    }

    free(v.dados);
    CloseWindow();
    return 0;
}