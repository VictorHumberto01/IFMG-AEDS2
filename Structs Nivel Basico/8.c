#include <stdio.h>

typedef struct {
    int codigo;
    char nome[11];
} Cor;

int main() {
    Cor cores[3];
    Cor menorCodigo;

    for (int i = 0; i < 3; i++) {
        printf("Digite o codigo da cor %d: ", i + 1);
        scanf("%d", &cores[i].codigo);
        printf("Digite o nome da cor %d: ", i + 1);
        scanf("%s", cores[i].nome);
    }

    menorCodigo = cores[0];

    for (int i = 1; i < 3; i++) {
        if (cores[i].codigo < menorCodigo.codigo) {
            menorCodigo = cores[i];
        }
    }

    printf("A cor com menor codigo eh: %d - %s\n", menorCodigo.codigo, menorCodigo.nome);

    return 0;
}
