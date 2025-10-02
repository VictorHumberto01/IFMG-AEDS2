#include <stdio.h>

int main() {
    FILE *texto = fopen("texto.txt", "r");
    int quantidade = 0;
    int c;

    if (texto == NULL) {
        printf("Erro ao abrir o arquivo \n");
        return 1;
    }

    while ((c = fgetc(texto)) != EOF) {
        quantidade++;
    }

    fclose(texto);
    printf("%d", quantidade);
    return 0;
}
