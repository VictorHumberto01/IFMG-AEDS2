#include <string.h>
#include <stdio.h>

int main() {
    FILE *file = fopen("texto.txt", "r+");
    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    char c;
    int i = 0;
    long pos;
    char palavra[100];

    while ((c = fgetc(file)) != EOF) {
        if (c >= 'A' && c <= 'Z') c = c + ('a' - 'A');

        if ((c >= 'a' && c <= 'z')) {
            if (i == 0)
                pos = ftell(file) - 1;
            palavra[i++] = c;
        } else {
            if (i > 0) {
                palavra[i] = '\0';
                if (strcmp(palavra, "casa") == 0) {
                    fseek(file, pos, SEEK_SET);
                    fputs("lar", file);
                    fputc(' ', file);
                }
                i = 0;
            }

            pos = ftell(file);
        }
    }


    fclose(file);
    return 0;
}
