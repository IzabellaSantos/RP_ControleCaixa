#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um produto
typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

// Função para mostrar os produtos disponíveis
void mostrarProdutos(Produto produtos[], int totalProdutos) {
    printf("=== Lista de Produtos ===\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("ID: %d | Nome: %s | Preço: R$ %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
    printf("=========================\n");
}

int main() {
    // Lista de produtos
    Produto produtos[] = {
        {1, "Café Expresso", 5.00},
        {2, "Cappuccino", 7.50},
        {3, "Chocolate Quente", 8.00},
        {4, "Pão de Queijo", 4.00},
        {5, "Sanduíche Natural", 10.00}
    };

    // Número total de produtos
    int totalProdutos = sizeof(produtos) / sizeof(produtos[0]);

    // Chamando a função para mostrar produtos
    mostrarProdutos(produtos, totalProdutos);

    return 0;
}
