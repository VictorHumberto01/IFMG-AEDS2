#include <stdio.h>
#include <string.h>

typedef struct Produto {
 char id[20];
 char nome[50];
 float preco;
} Produto;

int main() {

    int escolha = 0;
    int descarte;

    while (escolha != 4) {
        printf("\nDigite a opção desejada:\n");
        puts("1 - Inserir produto");
        puts("2 - Listar produtos");
        puts("3 - Buscar por ID");
        puts("4 - Sair");
        scanf("%d", &escolha);
        getchar();

        if (escolha == 1) {
            FILE *banco = fopen("banco.bin", "ab");
            if (banco == NULL) banco = fopen("banco.bin", "w+b");

            Produto inserir, p;

            puts("Digite o nome do produto: ");
            if (fgets(inserir.nome, sizeof(inserir.nome), stdin) != NULL) {
                inserir.nome[strcspn(inserir.nome, "\n")] = 0;
            }

            puts("Digite o ID do produto: ");
            if (fgets(inserir.id, sizeof(inserir.id), stdin) != NULL) {
                inserir.id[strcspn(inserir.id, "\n")] = 0;
            }

            puts("Digite o preço do produto: ");
            scanf("%f", &inserir.preco);
            getchar();

            int encontrado = 0;

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
            puts("Produto foi inserido com sucesso");
        }

        if (escolha == 2) {
            FILE *banco = fopen("banco.bin", "rb");
            Produto busca;
            if (banco == NULL) {
                puts("Erro ao abrir arquivo");
                return 1;
            }

            while (fread(&busca, sizeof(Produto), 1, banco)) {
                printf("ID: %s, Nome: %s, Preco: %f\n", busca.id, busca.nome, busca.preco);
            }
        }

        if (escolha == 3) {
            FILE *banco = fopen("banco.bin", "rb");
            if (banco == NULL) {
                puts("Erro ao abrir arquivo");
                return 1;
            }

            char id[20];
            Produto p;
            puts("Digite o id a ser buscado:");
            if (fgets(id, sizeof(id), stdin) != NULL) {
                id[strcspn(id, "\n")] = 0;
            }

            int encontrado = 0;

            while (fread(&p, sizeof(Produto), 1, banco)) {
                if (strcmp(p.id, id) == 0) {
                    fseek(banco, -sizeof(Produto), SEEK_CUR);
                    printf("Produto encontrado!\n");
                    printf("ID: %s, Nome: %s, Preco: %f\n", p.id, p.nome, p.preco);
                    encontrado = 1;
                    break;
                }
            }
        } else {
            if (escolha != 4) {
                puts("Opcao invalida!");
            }
        }


    }




    return 0;
}
