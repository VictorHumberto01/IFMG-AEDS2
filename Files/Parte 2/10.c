#include <stdio.h>

int main() {
    FILE *frase = fopen("frase.txt", "r");
    char buffer[256];

    if (frase == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }


    while (fgets(buffer, sizeof(buffer), frase) != NULL) {
        printf("%s", buffer);
    }


    fclose(frase);
    return 0;
}
