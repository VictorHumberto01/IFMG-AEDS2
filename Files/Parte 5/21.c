#include <stdio.h>

int main() {
    FILE *file = fopen("texto.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int quantidade = 0;
    int dentro_palavra = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            dentro_palavra = 0;
        } else if (!dentro_palavra) {
            dentro_palavra = 1;
            quantidade++;
        }
    }

    printf("%d\n", quantidade);

    fclose(file);
    return 0;
}
