#include <stdio.h>

typedef struct Retangulo {
    float base;
    float altura;
} Retangulo;

int main() {

    Retangulo retangulos[5];
    float area = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite a base do retângulo %d: ", i + 1);
        scanf("%f", &retangulos[i].base);

        printf("Digite a altura do retângulo %d: ", i + 1);
        scanf("%f", &retangulos[i].altura);

        area += retangulos[i].base * retangulos[i].altura;
    }

    printf("A área total dos retângulos é: %.2f\n", area);


    return 0;
}
