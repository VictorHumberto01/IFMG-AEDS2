#include <stdio.h>

typedef struct {
    int x;
    int y;
} Ponto;


int main() {
    Ponto pontos[2];

    for(int i = 0; i < 2; i++) {
        printf("Digite as coordenadas do ponto %d:\n", i+1);
        printf("X: ");
        scanf("%d", &pontos[i].x);
        printf("Y: ");
        scanf("%d", &pontos[i].y);
    }

    return 0;
}
