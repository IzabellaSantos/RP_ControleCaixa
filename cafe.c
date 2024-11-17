#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

void excluirProduto(Produto produtos[], int *totalProdutos, int id) {
    int encontrado = 0;

    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i].id == id) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < *totalProdutos - 1; j++) {
            produtos[j] = produtos[j + 1];
        }

        (*totalProdutos)--;
        printf("Produto com ID %d foi excluído com sucesso!\n", id);
    } else {
        printf("Produto com ID %d não encontrado!\n", id);
    }
}

void mostrarProdutos(Produto produtos[], int totalProdutos) {
    printf("=== Lista de Produtos ===\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("ID: %d | Nome: %s | Preço: R$ %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
    printf("=========================\n");
}

int main() {
    Produto produtos[] = {
        {1, "Café Expresso", 5.00},
        {2, "Cappuccino", 7.50},
        {3, "Chocolate Quente", 8.00},
        {4, "Pão de Queijo", 4.00},
        {5, "Sanduíche Natural", 10.00}
    };

    int totalProdutos = sizeof(produtos) / sizeof(produtos[0]);

    mostrarProdutos(produtos, totalProdutos);

    int idProdutoExcluir = 3;
    excluirProduto(produtos, &
