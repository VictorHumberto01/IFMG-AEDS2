#include <stdio.h>

int main() {
    FILE *file = fopen("texto.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int contador = 0;
    int maior = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            contador++;
        } else {
            if (contador > maior) {
                maior = contador;
            }
            contador = 0;
        }
    }

    if (contador > maior)
        maior = contador;

    printf("%d\n", maior);

    fclose(file);
    return 0;
}
