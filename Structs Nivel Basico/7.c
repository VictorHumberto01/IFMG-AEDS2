#include <stdio.h>

typedef struct Produto {
    int id;
    int quantidade;
    float preco;
} Produto;

int main() {
    Produto p[3];
    Produto maior;
    for (int i = 0; i < 3; i++) {
        printf("Digite o ID do produto %d: ", i + 1);
        scanf("%d", &p[i].id);
        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &p[i].quantidade);
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%f", &p[i].preco);
    }





    maior.preco = p[0].preco;
    if (p[1].preco > maior.preco) {
        maior = p[1];
    }

    if (p[2].preco > maior.preco) {
        maior = p[2];
    }


    printf("O produto mais caro é o de ID %d, com preço %.2f.\n", maior.id, maior.preco);

    return 0;
}
