#include <stdio.h>

int main() {
    FILE *file = fopen("dados.txt", "r");
    if (!file) return 1;

    int numero;
    int soma = 0;

    while (fscanf(file, "%d", &numero) == 1) {
        soma += numero;
    }


    printf("%d", soma);


    fclose(file);
    return 0;
}
