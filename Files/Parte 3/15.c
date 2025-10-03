#include <stdio.h>

int main() {
    FILE *pessoas = fopen("pessoas.txt", "r");
    char nome[100], sobrenome[100];
    float idade;

    while(fscanf(pessoas, "%s %s %f", nome, sobrenome, &idade) == 3) {
        printf("nome: %s, idade: %s, salario: %.2f\n", nome, sobrenome, idade);
    }

    return 0;
}
