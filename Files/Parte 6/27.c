#include <stdio.h>

int main() {
    FILE *file = fopen("texto.txt", "r");
    FILE *invertido = fopen("invertido.txt", "w");
    if (file == NULL || invertido == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long tamanho = ftell(file);

    for (long i = tamanho - 1; i >= 0; i--) {
        fseek(file, i, SEEK_SET);
        int c = fgetc(file);
        fputc(c, invertido);
    }

    fclose(file);
    fclose(invertido);
    return 0;
}
