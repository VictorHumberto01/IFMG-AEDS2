#include <stdio.h>

typedef struct Produto {
    char nome[50];
    float preco;
    int quantidade;

} Produto;

int main() {
    FILE *estoque = fopen("estoque.txt", "w");
    if (!estoque) return 1;

    int quantidade;

    printf("Digite a quantidade de produtos a serem cadastrados: ");
    scanf("%d", &quantidade);

    Produto p[quantidade];

    for (int i = 0; i < quantidade; i++) {
        getchar();
        printf("Digite o nome do produto: ");
        fgets(p[i].nome, sizeof(p[i].nome), stdin);
        for (int j = 0; j < sizeof(p[j].nome); j++) {
            if (p[i].nome[j] == '\n') {
                p[i].nome[j] = '\0';
                break;
            }
        }


        printf("Digite o preço: ");
        scanf("%f", &p[i].preco);
        getchar();

        printf("Digite a quantidade: ");
        scanf("%d", &p[i].quantidade);

        fprintf(estoque, "%s %f %d \n", p[i].nome, p[i].preco, p[i].quantidade);
    }


    fclose(estoque);
    return 0;
}
