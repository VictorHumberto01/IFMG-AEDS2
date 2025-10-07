#include <stdio.h>

int main() {
    FILE *texto = fopen("texto.txt", "r");
    char buffer[11];

    fread(buffer, sizeof(char), 10, texto);

    printf("%s\n", buffer);
    rewind(texto);



    fread(buffer, sizeof(char), 10, texto);
    printf("%s\n", buffer);



    fclose(texto);


    return 0;
}
