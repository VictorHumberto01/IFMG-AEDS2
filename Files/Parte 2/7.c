#include <stdio.h>

int main() {
    FILE *frase = fopen("frase.txt", "r");
    int c;

    while ((c = fgetc(frase)) != EOF)
        printf("%c", c);

    fclose(frase);

    return 0;
}
