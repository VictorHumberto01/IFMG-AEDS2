#include <stdio.h>
#include <string.h>

typedef struct Pessoa {
    char nome[50];
    char idade[3];
    char endereco[25];
} Pessoa;

int main() {
    int opcao = 100;

    while (opcao) {
        puts("Digite a opcao");
        puts("0 - sair");
        puts("1 - cadastrar pessoa");
        puts("2 - mostrar pelo nome");

        scanf("%d", &opcao);
        while(getchar() != '\n');

        if (opcao == 1) {
            FILE *pessoa = fopen("pessoa.txt", "a");
            if(!pessoa) return 1;

            Pessoa p;
            printf("Digite o nome: ");
            fgets(p.nome, sizeof(p.nome), stdin);
            for (int i = 0; i < sizeof(p.nome); i++) {
                if (p.nome[i] == '\n') {
                    p.nome[i] = '\0';
                    break;
                }
            }

            printf("Digite a idade: ");
            fgets(p.idade, sizeof(p.idade), stdin);
            for (int i = 0; i < sizeof(p.idade); i++) {
                if (p.idade[i] == '\n') {
                    p.idade[i] = '\0';
                    break;
                }
            }

            while (getchar() != '\n');
            printf("Digite o endereco: ");
            fgets(p.endereco, sizeof(p.endereco), stdin);
            for (int i = 0; i < sizeof(p.endereco); i++) {
                if (p.endereco[i] == '\n') {
                    p.endereco[i] = '\0';
                    break;
                }
            }

            fprintf(pessoa, "%s %s %s\n", p.nome, p.idade, p.endereco);
            fclose(pessoa);
        }

        if (opcao == 2) {
            FILE *pessoa = fopen("pessoa.txt", "r");
            Pessoa busca;
            char nome[50];


            printf("Digite o nome a ser buscado: ");
            fgets(nome, sizeof(nome), stdin);

            for (int j = 0; j < sizeof(nome); j++) {
                if (nome[j] == '\n') {
                    nome[j] = '\0';
                    break;
                }
            }

            while (fscanf(pessoa, "%s %s", busca.nome, busca.idade) == 2) {
                fgets(busca.endereco, sizeof(busca.endereco), pessoa);

                if (strcmp(busca.nome, nome) == 0) {
                    printf("%s %s %s", busca.nome, busca.idade, busca.endereco);
                }


            }





        }
    }

    return 0;
}
