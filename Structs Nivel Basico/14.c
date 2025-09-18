#include <stdio.h>

typedef struct Produto {
    int id;
    int quantidade;
    float preco;
} Produto;

int main() {

    Produto produtos[5];

    for(int i = 0; i < 5; i++) {
        printf("Digite o ID do produto %d: ", i + 1);
        scanf("%d", &produtos[i].id);
        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);
    }


    for (int i = 0; i < 5; i++) {
        if (produtos[i].preco > 50) {
            printf("%d %d %.2f\n", produtos[i].id, produtos[i].quantidade, produtos[i].preco);
        }
    }


    return 0;
}
