#include <stdio.h>

int main() {
    FILE *file = fopen("texto.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int quantidade = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            quantidade++;
        }
    }

    quantidade++;

    printf("%d", quantidade);

    fclose(file);

    return 0;
}
