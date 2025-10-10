#include <stdio.h>

typedef struct {
    int idade;
    char nome[50];
} Pessoa;

int main() {
    Pessoa p[3];

    for (int i = 0; i < 3; i++) {
        puts("Digite o nome: ");
        scanf("%s", p[i].nome);
        puts("digite a idade: ");
        scanf("%d", &p[i].idade);
    }


    for (int i = 0; i < 3; i++) {
        printf("Nome: %s, Idade: %d\n", p[i].nome, p[i].idade);
    }

    return 0;
}
