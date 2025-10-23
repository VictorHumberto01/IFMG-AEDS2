#include <stdio.h>

int main() {
    FILE *file = fopen("numeros.txt", "r");
    if (file == NULL) return 1;

    char c;
    int contador = 0;
    int dentro_numero = 0;

    while ((c = fgetc(file)) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            if (!dentro_numero) {
                contador++;
                dentro_numero = 1;
            }
        } else {
            dentro_numero = 0;
        }
    }


    printf("%d números\n", contador);



    return 0;
}
