#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Item;

float calcularEstoque(Item *itens, int quantidadeItens) {
    float total = 0;

    for (int i = 0; i < quantidadeItens; i++) {
        total += itens[i].quantidade * itens[i].preco;
    }

    return total;
}

int main() {
    int quantidadeItens;

    printf("=====================================\n");
    printf("   CONTROLE DE ESTOQUE TECNOLOG S.A.\n");
    printf("=====================================\n\n");

    printf("Informe a quantidade de itens: ");
    scanf("%d", &quantidadeItens);

    Item *itens = (Item *)malloc(quantidadeItens * sizeof(Item));

    if (itens == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (int i = 0; i < quantidadeItens; i++) {
        printf("\n--- Item %d ---\n", i + 1);

        printf("Nome do produto: ");
        scanf(" %49[^\n]", itens[i].nome);

        printf("Quantidade em estoque: ");
        scanf("%d", &itens[i].quantidade);

        printf("Preco unitario: ");
        scanf("%f", &itens[i].preco);
    }

    printf("\n\n========== RELATORIO DO ESTOQUE ==========\n");

    for (int i = 0; i < quantidadeItens; i++) {
        float subtotal = itens[i].quantidade * itens[i].preco;

        printf("\nProduto: %s", itens[i].nome);
        printf("\nQuantidade: %d", itens[i].quantidade);
        printf("\nPreco Unitario: R$ %.2f", itens[i].preco);
        printf("\nSubtotal: R$ %.2f\n", subtotal);
    }

    float valorTotal = calcularEstoque(itens, quantidadeItens);

    printf("\n==========================================");
    printf("\nVALOR TOTAL DO ESTOQUE: R$ %.2f", valorTotal);
    printf("\n==========================================\n");

    free(itens);

    return 0;
}
