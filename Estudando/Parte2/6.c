#include <stdio.h>

int main() {
    FILE *file = fopen("duplicado.txt", "w");
    if (file == NULL) return 1;

    char frase[50];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    fputs(frase, file);
    fputs(frase, file);


    fclose(file);


    return 0;
}
