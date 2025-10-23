#include <stdio.h>

int main() {
    FILE *file = fopen("arquivo.txt", "r");
    if (file == NULL) {
        puts("Erro ao abrir o arquivo. Programa encerrado com retorno 1");
        return 1;
    }

    return 0;
}
