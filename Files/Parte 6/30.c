#include <stdio.h>
#include <string.h>

typedef struct notas {
    char nome[50];
    char conteudo[500];
} Notas;

int main() {
    int opcao = 0;
    Notas nota;

    while (opcao != 4) {
        printf("\nDigite a opção desejada:\n");
        puts("1 - Criar nota");
        puts("2 - Excluir nota");
        puts("3 - Listar notas");
        puts("4 - Sair");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            FILE *notas = fopen("nota.txt", "a");
            if (notas == NULL) {
                puts("Erro ao abrir nota!");
                return 1;
            }

            puts("Digite o nome da nota: ");
            if (fgets(nota.nome, sizeof(nota.nome), stdin) != NULL) {
                nota.nome[strcspn(nota.nome, "\n")] = 0;
            }
            puts("Digite o conteudo: ");
            if (fgets(nota.conteudo, sizeof(nota.conteudo), stdin) != NULL) {
                nota.conteudo[strcspn(nota.conteudo, "\n")] = 0;
            }


            fprintf(notas, "%s;%s\n", nota.nome, nota.conteudo);
            fclose(notas);

            puts("Nota salva com sucesso!");
        }

        else if (opcao == 2) {
            FILE *notas = fopen("nota.txt", "r");
            FILE *temp = fopen("temp.txt", "w");
            if (notas == NULL || temp == NULL) {
                puts("Erro ao abrir arquivos!");
                return 1;
            }

            char apagar[50];
            char linha[200];

            puts("Digite o nome do nota a ser apagado:");
            fgets(apagar, sizeof(apagar), stdin);
            apagar[strcspn(apagar, "\n")] = 0;

            while (fgets(linha, sizeof(linha), notas)) {
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

            fclose(notas);
            fclose(temp);
            remove("nota.txt");
            rename("temp.txt", "nota.txt");
            puts("nota apagado (se existia).");
        }

        else if (opcao == 3) {
            FILE *notas = fopen("nota.txt", "r");
            if (notas == NULL) {
                puts("Nenhuma nota encontrada.");
                continue;
            }

            char linha[600];
            int contador = 1;

            puts("\n==== LISTA DE NOTAS ====\n");

            while (fgets(linha, sizeof(linha), notas)) {
                linha[strcspn(linha, "\n")] = 0;

                char *nome = strtok(linha, ";");
                char *conteudo = strtok(NULL, ";");

                if (nome && conteudo) {
                    printf("Nota %d\n", contador++);
                    printf("Título: %s\n", nome);
                    printf("Conteúdo: %s\n", conteudo);
                    printf("------------------------------\n");
                }
            }

            if (contador == 1)
                puts("Nenhuma nota encontrada.");

            fclose(notas);
        }


    }

    return 0;
}
