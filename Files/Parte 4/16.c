#include <stdio.h>

int main() {
    char quinto, decimo, ultimo;
    FILE *texto = fopen("texto.txt", "r");
    if (texto == NULL) return 1;

    fseek(texto, 4, SEEK_SET);
    fread(&quinto, sizeof(char), 1, texto);
    fseek(texto, 9, SEEK_SET);
    fread(&decimo, sizeof(char), 1, texto);
    fseek(texto, -1, SEEK_END);
    fread(&ultimo, sizeof(char), 1, texto);


    printf("Quinto caractere: %c\n", quinto);
    printf("Decimo caractere: %c\n", decimo);
    printf("Ultimo caractere: %c\n", ultimo);

    return 0;
}
