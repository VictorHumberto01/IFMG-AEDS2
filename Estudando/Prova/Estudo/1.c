#include <stdio.h>

int main() {
    FILE *notas = fopen("notas.txt", "w");
    if (!notas) return 1;

    int opcao = 0;
    float nota;

    while (!opcao) {
        printf("Opcoes:\n 0 - cadastrar notas\n 1 - sair e salvar");
        printf("\n:");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("digite a nota: ");
            scanf("%f", &nota);
            getchar();

            fprintf(notas, "%f\n", nota);
        }

    }

    fclose(notas);
    return 0;
}
