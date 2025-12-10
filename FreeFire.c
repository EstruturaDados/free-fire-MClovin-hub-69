#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Estrutura que representa um item do inventário
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Funções principais
void inserirItem(Item mochila[], int *qtd);
void removerItem(Item mochila[], int *qtd);
void listarItens(Item mochila[], int qtd);
void buscarItem(Item mochila[], int qtd);

int main() {
    Item mochila[MAX_ITENS];
    int opcao, qtd = 0;

    do {
        printf("\n===== Minha Mochila =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o \n do buffer

        switch(opcao) {
            case 1:
                inserirItem(mochila, &qtd);
                break;
            case 2:
                removerItem(mochila, &qtd);
                break;
            case 3:
                listarItens(mochila, qtd);
                break;
            case 4:
                buscarItem(mochila, qtd);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}

// Função para inserir novo item
void inserirItem(Item mochila[], int *qtd) {
    if (*qtd >= MAX_ITENS) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    printf("Digite o nome do item: ");
    fgets(mochila[*qtd].nome, 30, stdin);
    mochila[*qtd].nome[strcspn(mochila[*qtd].nome, "\n")] = '\0'; // remove \n

    printf("Digite o tipo do item (arma, municao, cura, ferramenta...): ");
    fgets(mochila[*qtd].tipo, 20, stdin);
    mochila[*qtd].tipo[strcspn(mochila[*qtd].tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*qtd].quantidade);
    getchar();

    (*qtd)++;
    printf("Item adicionado com sucesso!\n");

    listarItens(mochila, *qtd);
}

// Função para remover item pelo nome
void removerItem(Item mochila[], int *qtd) {
    char nome[30];
    printf("Digite o nome do item a ser removido: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < *qtd; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < *qtd - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*qtd)--;
            printf("Item removido com sucesso!\n");
            listarItens(mochila, *qtd);
            return;
        }
    }
    printf("Item nao encontrado!\n");
}

// Função para listar todos os itens da mochila
void listarItens(Item mochila[], int qtd) {
    if (qtd == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    printf("\n===== ITENS NA MOCHILA =====\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função para buscar um item pelo nome
void buscarItem(Item mochila[], int qtd) {
    char nome[30];
    printf("Digite o nome do item que deseja buscar: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < qtd; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("Item nao encontrado!\n");
}