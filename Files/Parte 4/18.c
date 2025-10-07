#include <stdio.h>

int main() {
    FILE *origem = fopen("origem.txt", "r");
    FILE *copia = fopen("copia.txt", "w");
    int c;

    if (origem == NULL || copia == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    while ((c = fgetc(origem)) != EOF) {
        fputc(c, copia);
    }


    fclose(origem);
    fclose(copia);


    puts("Copia realizada com sucesso!");

    return 0;
}
