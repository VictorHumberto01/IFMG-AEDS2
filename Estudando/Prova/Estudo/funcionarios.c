#include <string.h>
#include <stdio.h>

typedef struct funcionario {
    char id[50];
    char nome[50];
    char cargo[50];
    float salario;

} funcionario;

int main() {
    int opcao = 1;

    while(opcao) {
        printf("digite a opção desejada: \n");
        puts("0 - Sair");
        puts("1 - cadastrar funcionario");
        puts("2 - listar por cargo");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            FILE *funcionarios = fopen("funcionarios.txt", "a");
            if (!funcionarios) return 1;

            funcionario f;

            printf("Digite o nome do funcionario: ");
            fgets(f.nome, sizeof(f.nome), stdin);
            for (int i = 0; i < sizeof(f.nome); i++) {
                if (f.nome[i] == '\n') {
                    f.nome[i] = '\0';
                    break;
                }
            }

            printf("Digite o id: ");
            fgets(f.id, sizeof(f.id), stdin);
            for (int i = 0; i < sizeof(f.id); i++) {
                if (f.id[i] == '\n') {
                    f.id[i] = '\0';
                    break;
                }
            }

            printf("Digite o cargo: ");
            fgets(f.cargo, sizeof(f.cargo), stdin);
            for (int i = 0; i < sizeof(f.cargo); i++) {
                if (f.cargo[i] == '\n') {
                    f.cargo[i] = '\0';
                    break;
                }
            }

            printf("Digite o salario: ");
            scanf("%f", &f.salario);
            getchar();

            fprintf(funcionarios, "%s %s %s %f\n", f.nome, f.id, f.cargo, f.salario);
            fclose(funcionarios);
        }

        if (opcao == 2) {
            FILE *funcionarios = fopen("funcionarios.txt", "r");
            if (!funcionarios) return 1;

            funcionario f;
            char cargobusca[50];

            printf("Digite o cargo a ser buscado: ");
            fgets(cargobusca, sizeof(cargobusca), stdin);
            for (int i = 0; i < sizeof(cargobusca); i++) {
                if (cargobusca[i] == '\n') {
                    cargobusca[i] = '\0';
                    break;
                }
            }

            printf("%s encontrado: \n", cargobusca);

            while (fscanf(funcionarios, "%s %s %s %f", f.nome, f.id, f.cargo, &f.salario) == 4) {
                if (strcmp(f.cargo, cargobusca) == 0) {
                    printf("%s, %s, %s, %f\n", f.nome, f.id, f.cargo, f.salario);
                }
            }

            fclose(funcionarios);
        }
    }

    return 0;
}
