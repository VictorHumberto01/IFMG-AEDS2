#include <stdio.h>
#include <string.h>

typedef struct contato {
    char nome[50];
    char telefone[12];
    char email[50];
} Contato;

int main() {
    int opcao = 0;
    Contato contato;

    while (opcao != 4) {
        printf("\nDigite a opção desejada:\n");
        puts("1 - Cadastrar contato");
        puts("2 - Excluir contato");
        puts("3 - Listar contatos");
        puts("4 - Sair");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            FILE *agenda = fopen("agenda.txt", "a");
            if (agenda == NULL) {
                puts("Erro ao abrir agenda!");
                return 1;
            }

            puts("Digite o nome do contato");
            scanf("%s", contato.nome);
            puts("Digite o telefone do contato");
            scanf("%s", contato.telefone);
            puts("Digite o email do contato");
            scanf("%s", contato.email);

            fprintf(agenda, "%s;%s;%s\n", contato.nome, contato.telefone, contato.email);
            fclose(agenda);

            puts("Cadastro realizado com sucesso!");
        }

        else if (opcao == 2) {
            FILE *agenda = fopen("agenda.txt", "r");
            FILE *temp = fopen("temp.txt", "w");
            if (agenda == NULL || temp == NULL) {
                puts("Erro ao abrir arquivos!");
                return 1;
            }

            char apagar[50];
            char linha[200];

            puts("Digite o nome do contato a ser apagado:");
            fgets(apagar, sizeof(apagar), stdin);
            apagar[strcspn(apagar, "\n")] = 0;

            while (fgets(linha, sizeof(linha), agenda)) {
                char copia[200];
                strcpy(copia, linha);

                for (int i = 0; copia[i]; i++) {
                    if (copia[i] >= 'A' && copia[i] <= 'Z')
                        copia[i] += ('a' - 'A');
                }

                if (strstr(copia, apagar) == NULL) {
                    fputs(linha, temp);
                }
            }

            fclose(agenda);
            fclose(temp);
            remove("agenda.txt");
            rename("temp.txt", "agenda.txt");
            puts("Contato apagado (se existia).");
        }

        else if (opcao == 3) {
            FILE *agenda = fopen("agenda.txt", "r");
            char linha[200];
            while (fgets(linha, sizeof(linha), agenda)) {
                printf("%s", linha);
            }
        } else {
            if (opcao != 4) {
                puts("Opcao invalida!");
            }
        }


    }

    return 0;
}
