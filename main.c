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
void pausarTela();
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
    limparTela();

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

// Para que usuário leia mensagem de confirmação a cada função antes de retornar ao menu principal e ser apagado por limparTela()
void pausarTela() {
    printf("\nPressione enter para retornar ao menu..\n");
    getchar();getchar();
}

void cadastrarProduto(Produto produtos[], int *qtdAtualProdutos) {
    limparTela();

    FILE *file = fopen("./arquivos/produtos.txt", "a");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de produtos.\n");
        exit(EXIT_FAILURE);
    }

    Produto novoProduto;

    printf("Insira as informaçoes do produto:\n\n");
    getchar();

    printf("Digite o ID do produto: ");
    scanf("%d", &novoProduto.id);
    getchar();

    printf("Digite o nome do produto: ");
    fgets(novoProduto.nome, TAMANHO, stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = '\0';

    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);

    printf("Digite o valor do produto: ");
    scanf("%f", &novoProduto.valor);

    produtos[*qtdAtualProdutos] = novoProduto;
    (*qtdAtualProdutos)++;

    fprintf(file, "#%d\tProduto: %s\t\t\t\tQuantidade: %d\t\tValor: R$: %.2f\n", novoProduto.id, novoProduto.nome, novoProduto.quantidade, novoProduto.valor);

    fclose(file);

    printf("Produto cadastrado com sucesso!\n");
    pausarTela();
}

void alterarProduto(Produto produtos[], int qtdAtualProdutos) {
    
}

void excluirProduto(Produto produtos[], int *qtdAtualProdutos) {
    
}

void gerarRelatorio(Produto produtos[], int qtdAtualProdutos) {
    FILE *file = fopen("./arquivos/relatorioProdutos.txt", "w"); 
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "Relatório de Produtos\n");
    fprintf(file, "Id\t\tNome\t\t\t\tQuantidade\tValor\n");
    for (int i = 0; i < qtdAtualProdutos; i++) {
        fprintf(file, "%d\t\t%s\t\t\t\t%d\t\t%.2f\n", produtos[i].id, produtos[i].nome, produtos[i].quantidade, produtos[i].valor);
    }
    
    fclose(file);

    printf("Relatório gerado com sucesso!\n");
    pausarTela();
}

void mostrarProdutos(Produto produtos[], int qtdAtualProdutos) {

}