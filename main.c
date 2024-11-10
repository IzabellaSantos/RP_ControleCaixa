#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 40
#define QTD_PRODUTOS 10

typedef struct {
    int id;
    char nome[TAMANHO];
    int quantidade;
    float valor;
} Produto;

int menu();
void limparTela();
void cadastrarProduto(Produto produtos[], int *qtdAtualProdutos);
void alterarProduto(Produto produtos[], int qtdAtualProdutos);
void excluirProduto(Produto produtos[], int *qtdAtualProdutos);
void gerarRelatorio(Produto produtos[], int qtdAtualProdutos);
void mostrarProdutos(Produto produtos[], int qtdAtualProdutos);

int main() {
    int escolha = 0, qtdAtualProdutos = 0;
    Produto produtos[QTD_PRODUTOS];
    
    while (escolha != 6) {
        escolha = menu();
        
        limparTela();
        
        switch (escolha) {
            case 1:
                if (qtdAtualProdutos < QTD_PRODUTOS) {
                    cadastrarProduto(produtos, &qtdAtualProdutos);
                } else {
                    printf("Limite de produtos atingido!\n");
                }
                break;
            case 2:
                alterarProduto(produtos, qtdAtualProdutos);
                break;
            case 3:
                excluirProduto(produtos, &qtdAtualProdutos);
                break;
            case 4:
                gerarRelatorio(produtos, qtdAtualProdutos);
                break;
            case 5:
                mostrarProdutos(produtos, qtdAtualProdutos);
                break;
            case 6:
                printf("Caixa finalizado!\n");
                break;
            default:
                printf("Entrada inválida!\n");
        }
    }
    
    return 0;
}

int menu() {
    int escolha = 0;
    
    printf("--------------------------------------------\n");
    printf("| 1. Cadastrar produto                     |\n");
    printf("| 2. Alterar produto                       |\n");
    printf("| 3. Excluir produto                       |\n");
    printf("| 4. Gerar relatorio com todos os produtos |\n");
    printf("| 5. Mostrar itens                         |\n");
    printf("| 6. Sair                                  |\n");
    printf("--------------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    
    return escolha;
}

void limparTela() {
    // Para sistemas Windows use "cls"
    system("clear"); // Para sistemas Unix/Linux use "clear"
}

void cadastrarProduto(Produto produtos[], int *qtdAtualProdutos) {
}

void alterarProduto(Produto produtos[], int qtdAtualProdutos) {
    
}

void excluirProduto(Produto produtos[], int *qtdAtualProdutos) {
    
}

void gerarRelatorio(Produto produtos[], int qtdAtualProdutos) {
    
}

void mostrarProdutos(Produto produtos[], int qtdAtualProdutos) {

}