#include <stdio.h>

typedef struct Produto {
    char nome[50];
    float preco;
    int quantidade;

} Produto;

int main() {
    FILE *estoque = fopen("estoque.txt", "r");
    if (!estoque) return 1;

    float soma = 0;

    Produto p;


    while (fscanf(estoque, "%s %f %d", p.nome, &p.preco, &p.quantidade) == 3) {
        soma += p.quantidade * p.preco;
    }


    printf("%f", soma);

    fclose(estoque);
    return 0;
}
