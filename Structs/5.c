#include <stdio.h>

typedef struct Produto {
    int id;
    int quantidade;
    float preco;
} Produto;

int main() {
    Produto p;
    float total;

    printf("Digite o ID do produto: ");
    scanf("%d", &p.id);

    printf("Digite a quantidade: ");
    scanf("%d", &p.quantidade);

    printf("Digite o preço: ");
    scanf("%f", &p.preco);

    total = p.quantidade * p.preco;

    printf("\nProduto ID: %d\n", p.id);
    printf("Quantidade: %d\n", p.quantidade);
    printf("Preço: %.2f\n", p.preco);
    printf("Valor total: %.2f\n", total);

    return 0;
}
