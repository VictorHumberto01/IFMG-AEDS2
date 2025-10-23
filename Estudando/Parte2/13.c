#include <stdio.h>

int main() {
    FILE *file = fopen("pessoas.txt", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    char nome[50];
    int idade;

    while (fscanf(file, " %49[^,], %d", nome, &idade) == 2) {
        if (idade > 30) printf("%s, %d\n", nome, idade);
    }

    fclose(file);
    return 0;
}
