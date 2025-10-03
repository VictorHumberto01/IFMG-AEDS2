#include <stdio.h>

int main() {
    FILE *arquivo = fopen("numeros.txt", "w");
    int numero;

    for (int i = 0; i < 10; i++) {
        puts("Digite um número:");
        scanf("%d", &numero);
        fprintf(arquivo, "%d\n", numero);
    }

    fclose(arquivo);

    arquivo = fopen("numeros.txt", "r");
    while (fscanf(arquivo, "%d", &numero) == 1) {
        printf("Número lido: %d\n", numero);
    }

    fclose(arquivo);
    return 0;
}
