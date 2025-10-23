#include <stdio.h>

int main() {
    FILE *notas = fopen("notas.txt", "r");
    if (!notas) return 1;

    float notascan = 0;
    float soma = 0;
    int quantidade = 0;
    float media;

    while (fscanf(notas, "%f", &notascan) == 1) {
        quantidade++;
        soma += notascan;
    }


    media = soma / quantidade;
    printf("%f", media);


    return 0;
}
