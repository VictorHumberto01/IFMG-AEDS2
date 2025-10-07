#include <stdio.h>

int main() {
    FILE *origem = fopen("origem.txt", "r");
    FILE *copia = fopen("copia.txt", "r");
    FILE *final = fopen("final.txt", "w");
    int c;

    if (origem == NULL || copia == NULL || final == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    while ((c = fgetc(origem)) != EOF) {
        fputc(c, final);
    }

    while ((c = fgetc(copia)) != EOF) {
        fputc(c, final);
    }


    fclose(origem);
    fclose(copia);
    fclose(final);

    puts("concatenação realizada com sucesso!");

    return 0;
}
