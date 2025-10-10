#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("texto.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char busca[100];
    char palavra[100];

    printf("Digite a palavra a ser buscada: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (int j = 0; busca[j]; j++) {
        if (busca[j] >= 'A' && busca[j] <= 'Z') {
            busca[j] += ('a' - 'A');
        }
    }

    char c;
    int i = 0;

    while ((c = fgetc(file)) != EOF) {
        if (c >= 'A' && c <= 'Z') c = c + ('a' - 'A');

        if (c >= 'a' && c <= 'z') {
            palavra[i++] = c;
        } else {
            palavra[i] = '\0';
            if (strstr(palavra, busca) != NULL) {
                printf("Sua palavra foi encontrada na posição %ld\n", ftell(file));
            }
            i = 0;
        }
    }

    if (i > 0) {
        palavra[i] = '\0';
        if (strstr(palavra, busca) != NULL) {
            printf("%s\n", palavra);
        }
    }

    fclose(file);
    return 0;
}
