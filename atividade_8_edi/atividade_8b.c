#include "raylib.h"
#include "entidade.h"
#include <stdlib.h>
#include <time.h>

#define LARGURA_JANELA  800
#define ALTURA_JANELA   600

int main(void) {
    srand((unsigned int)time(NULL));

    InitWindow(LARGURA_JANELA, ALTURA_JANELA, "Atividade 8b - Reuso do Modulo Entidade");
    SetTargetFPS(60);

    Entidade *jogador = entidadeCriar(ENTIDADE_JOGADOR, (Vector2){ 200.0f, 300.0f });
    Entidade *inimigo = entidadeCriar(ENTIDADE_INIMIGO, (Vector2){ 400.0f, 300.0f });
    Entidade *item = entidadeCriar(ENTIDADE_ITEM, (Vector2){ 600.0f, 300.0f });

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);

            entidadeDesenhar(jogador);
            entidadeDesenhar(inimigo);
            entidadeDesenhar(item);

            DrawText("Reuso de Modulo: Jogador, Inimigo e Item desenhados.", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    free(jogador);
    free(inimigo);
    free(item);

    CloseWindow();
    return 0;
}