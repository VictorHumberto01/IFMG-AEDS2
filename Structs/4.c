#include <stdio.h>

typedef struct Triangulo {
    float base;
    float altura;
} Triangulo;

int main() {

    Triangulo triangulo;
    float area;

    printf("Digite a base: ");
    scanf("%f", &triangulo.base);

    printf("Digite a altura: ");
    scanf("%f", &triangulo.altura);

    area = triangulo.base * triangulo.altura / 2;

    printf("A área do triângulo é: %.2f\n", area);


    return 0;
}
