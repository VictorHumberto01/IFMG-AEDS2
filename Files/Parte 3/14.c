#include <stdio.h>

typedef struct {
    char nome[50];
    char idade[4];
    float salario;
} Pessoa;

int main() {
    FILE *pessoas = fopen("pessoas.txt", "w");
    if (pessoas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Pessoa p;

    for(int i = 0; i < 5; i++) {
        printf("Digite o nome da pessoa %d: ", i+1);
        scanf("%s", p.nome);
        printf("Digite a idade da pessoa %d: ", i+1);
        scanf("%s", p.idade);
        printf("Digite o salario da pessoa %d: ", i+1);
        scanf("%f", &p.salario);

        fprintf(pessoas, "%s %s %.2f\n", p.nome, p.idade, p.salario);
    }


    fclose(pessoas);
    return 0;
}
