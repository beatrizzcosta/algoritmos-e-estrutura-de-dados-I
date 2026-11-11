#include <stdio.h>
#include <stdlib.h>

// Estrutura do Nó
typedef struct No {
    int dado;
    struct No *anterior;
    struct No *proximo;
} No;

// Estrutura da Lista
typedef struct Lista {
    No *inicio;
    No *fim;
} Lista;

// 1. Inicializar lista
void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

// 2. Inserir elemento no inicio
void inserirInicio(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = lista->inicio;

    if (lista->inicio != NULL) {
        lista->inicio->anterior = novo; // O antigo primeiro aponta para o novo
    }
    lista->inicio = novo; // O novo nó vira o início

    if (lista->fim == NULL) {
        lista->fim = novo; // Se a lista estava vazia, o novo também é o fim
    }
}

// 3. Inserir elemento no final
void inserirFinal(Lista *lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;
    novo->anterior = lista->fim;

    if (lista->fim != NULL) {
        lista->fim->proximo = novo; // O antigo último aponta para o novo
    }
    lista->fim = novo; // O novo nó vira o fim

    if (lista->inicio == NULL) {
        lista->inicio = novo; // Se a lista estava vazia, o novo também é o início
    }
}

// 4. Inserir em uma posicao específica (considerando 1 como a primeira)
void inserirPosicao(Lista *lista, int valor, int posicao) {
    if (posicao <= 1) {
        inserirInicio(lista, valor);
        return;
    }

    No *atual = lista->inicio;
    int cont = 1;

    // Navega até o nó anterior à posição desejada
    while (atual != NULL && cont < posicao - 1) {
        atual = atual->proximo;
        cont++;
    }

    // Se a posição for maior que o tamanho da lista, insere no final
    if (atual == NULL || atual == lista->fim) {
        inserirFinal(lista, valor);
        return;
    }

    // Cria o novo nó e ajusta os 4 ponteiros no meio da lista
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    
    novo->proximo = atual->proximo;
    novo->anterior = atual;
    
    atual->proximo->anterior = novo;
    atual->proximo = novo;
}

// 5. Remover do inicio
void removerInicio(Lista *lista) {
    if (lista->inicio == NULL) return; // Lista já está vazia

    No *temp = lista->inicio;
    lista->inicio = temp->proximo;

    if (lista->inicio != NULL) {
        lista->inicio->anterior = NULL;
    } else {
        lista->fim = NULL; // A lista ficou vazia após remover o único elemento
    }

    free(temp);
}

// 6. Remover do final
void removerFinal(Lista *lista) {
    if (lista->fim == NULL) return; // Lista já está vazia

    No *temp = lista->fim;
    lista->fim = temp->anterior;

    if (lista->fim != NULL) {
        lista->fim->proximo = NULL;
    } else {
        lista->inicio = NULL; // A lista ficou vazia
    }

    free(temp);
}

// 7. Remover um valor específico
void removerValor(Lista *lista, int valor) {
    No *atual = lista->inicio;

    // Procura o valor
    while (atual != NULL && atual->dado != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Valor %d nao encontrado na lista.\n", valor);
        return;
    }

    // Se for o primeiro ou o último, reaproveita as funções que já fizemos
    if (atual == lista->inicio) {
        removerInicio(lista);
        return;
    }
    if (atual == lista->fim) {
        removerFinal(lista);
        return;
    }

    // Se estiver no meio, conecta o anterior com o próximo
    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;
    free(atual);
    printf("Valor %d removido com sucesso.\n", valor);
}

// 8. Buscar um valor
void buscar(Lista *lista, int valor) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dado == valor) {
            printf("Valor %d encontrado na lista!\n", valor);
            return;
        }
        atual = atual->proximo;
    }
    printf("Valor %d nao encontrado.\n", valor);
}

// 9. Imprimir do inicio ao final
void imprimirDireto(Lista *lista) {
    No *atual = lista->inicio;
    printf("Lista (Inicio -> Fim): NULL ");
    while (atual != NULL) {
        printf("<- %d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// 9. Imprimir do final ao inicio
void imprimirInverso(Lista *lista) {
    No *atual = lista->fim;
    printf("Lista (Fim -> Inicio): NULL ");
    while (atual != NULL) {
        printf("<- %d -> ", atual->dado);
        atual = atual->anterior;
    }
    printf("NULL\n");
}

// 10. Contar elementos
int contarElementos(Lista *lista) {
    int cont = 0;
    No *atual = lista->inicio;
    while (atual != NULL) {
        cont++;
        atual = atual->proximo;
    }
    return cont;
}

// 11. Liberar memoria
void liberarLista(Lista *lista) {
    while (lista->inicio != NULL) {
        removerInicio(lista);
    }
    printf("Memoria liberada e lista vazia.\n");
}

// ---------------- MAIN / MENU ----------------
int main() {
    Lista lista;
    inicializar(&lista);
    int opcao, valor, pos;

    do {
        printf("\n--- MENU LISTA DUPLAMENTE ENCADEADA ---\n");
        printf("1. Inserir no Inicio\n");
        printf("2. Inserir no Final\n");
        printf("3. Inserir em Posicao\n");
        printf("4. Remover do Inicio\n");
        printf("5. Remover do Final\n");
        printf("6. Remover Valor Especifico\n");
        printf("7. Buscar Valor\n");
        printf("8. Mostrar Lista (Direto e Inverso)\n");
        printf("9. Contar Elementos\n");
        printf("0. Sair e Liberar Memoria\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirFinal(&lista, valor);
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Digite a posicao: ");
                scanf("%d", &pos);
                inserirPosicao(&lista, valor, pos);
                break;
            case 4:
                removerInicio(&lista);
                break;
            case 5:
                removerFinal(&lista);
                break;
            case 6:
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);
                removerValor(&lista, valor);
                break;
            case 7:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                buscar(&lista, valor);
                break;
            case 8:
                imprimirDireto(&lista);
                imprimirInverso(&lista);
                break;
            case 9:
                printf("Total de elementos: %d\n", contarElementos(&lista));
                break;
            case 0:
                liberarLista(&lista);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}