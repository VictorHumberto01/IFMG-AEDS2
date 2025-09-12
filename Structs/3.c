#include <stdio.h>

typedef struct Retangulo {
    float base;
    float altura;
} Retangulo;

int main() {

    Retangulo retangulo;
    float area;

    printf("Digite a base: ");
    scanf("%f", &retangulo.base);

    printf("Digite a altura: ");
    scanf("%f", &retangulo.altura);

    area = retangulo.base * retangulo.altura;

    printf("A área do retângulo é: %.2f\n", area);


    return 0;
}
