#include <stdio.h>
#include <string.h>

typedef struct Produto {
    char id[20];
    char nome[50];
    float preco;
} Produto;

int main() {
    int escolha = 0;

    while (escolha != 4) {
        printf("\nDigite a opção desejada:\n");
        puts("1 - Inserir produto");
        puts("2 - Listar produtos");
        puts("3 - Buscar por ID");
        puts("4 - Sair");
        scanf("%d", &escolha);
        getchar();

        if (escolha == 1) {
            FILE *banco = fopen("banco.bin", "r+b");
            if (banco == NULL) banco = fopen("banco.bin", "w+b");

            Produto inserir, p;

            puts("Digite o nome do produto: ");
            fgets(inserir.nome, sizeof(inserir.nome), stdin);
            inserir.nome[strcspn(inserir.nome, "\n")] = 0;

            puts("Digite o ID do produto: ");
            fgets(inserir.id, sizeof(inserir.id), stdin);
            inserir.id[strcspn(inserir.id, "\n")] = 0;

            puts("Digite o preço do produto: ");
            scanf("%f", &inserir.preco);
            getchar();

            int encontrado = 0;
            rewind(banco);

            while (fread(&p, sizeof(Produto), 1, banco)) {
                if (strcmp(p.id, inserir.id) == 0) {
                    fseek(banco, -sizeof(Produto), SEEK_CUR);
                    fwrite(&inserir, sizeof(Produto), 1, banco);
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                fwrite(&inserir, sizeof(Produto), 1, banco);
            }

            fclose(banco);
            puts("Produto foi inserido com sucesso!");
        }

        else if (escolha == 2) {
            FILE *banco = fopen("banco.bin", "rb");
            if (banco == NULL) {
                puts("Nenhum produto cadastrado ainda.");
                continue;
            }

            Produto busca;
            while (fread(&busca, sizeof(Produto), 1, banco)) {
                printf("ID: %s, Nome: %s, Preço: %.2f\n",
                       busca.id, busca.nome, busca.preco);
            }
            fclose(banco);
        }

        else if (escolha == 3) {
            FILE *banco = fopen("banco.bin", "rb");
            if (banco == NULL) {
                puts("Nenhum produto cadastrado ainda.");
                continue;
            }

            char id[20];
            Produto p;

            puts("Digite o ID a ser buscado:");
            fgets(id, sizeof(id), stdin);
            id[strcspn(id, "\n")] = 0;

            int encontrado = 0;
            while (fread(&p, sizeof(Produto), 1, banco)) {
                if (strcmp(p.id, id) == 0) {
                    printf("Produto encontrado!\n");
                    printf("ID: %s, Nome: %s, Preço: %.2f\n",
                           p.id, p.nome, p.preco);
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) puts("Produto não encontrado.");

            fclose(banco);
        }

        else if (escolha != 4) {
            puts("Opção inválida!");
        }
    }

    return 0;
}
