#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_arquivo(int tamanho, int com_repeticao) {
    char nome_arquivo[50];
    if (com_repeticao) {
        sprintf(nome_arquivo, "dados_%d_repetidos.txt", tamanho);
    } else {
        sprintf(nome_arquivo, "dados_%d_unicos.txt", tamanho);
    }

    FILE *f = fopen(nome_arquivo, "w");
    if (!f) {
        printf("Erro ao criar %s\n", nome_arquivo);
        return;
    }

    int valor = 2;
    for (int i = 0; i < tamanho; i++) {
        fprintf(f, "%d ", valor);
        if (com_repeticao) {
           
            valor += rand() % 3; 
        } else {
                       valor += (rand() % 5) + 1; 
        }
    }
    fclose(f);
    printf("Gerado: %s\n", nome_arquivo);
}

int main() {
    int tamanhos[] = {10, 100, 500, 1000, 5000, 10000};
    srand(time(NULL));

    printf("Gerando conjuntos de dados exigidos pelo projeto...\n");
    for (int i = 0; i < 6; i++) {
        gerar_arquivo(tamanhos[i], 0); // Ordenados sem repetição
        gerar_arquivo(tamanhos[i], 1); // Ordenados com repetição
    }
    printf("Todos os arquivos foram gerados com sucesso!\n");
    return 0;
}