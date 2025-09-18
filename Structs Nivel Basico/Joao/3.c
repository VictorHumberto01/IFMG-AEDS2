#include <stdio.h>

struct retangulo {
   float largura;
   float altura;

};


int main() {

    struct retangulo um;

    printf("\nDigite a altura: ");
    scanf("%f", &um.altura);
    printf("\nDigite a largura: ");
    scanf("%f", &um.largura);

    float area = um.altura * um.largura;

    printf("\nA area do retangulo eh: %.2f", area);

    return 0;
}
