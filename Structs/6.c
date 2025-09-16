#include <stdio.h>

typedef struct Aluno {
    int matricula;
    float nota;
} Aluno;

int main() {
    Aluno alunos[5];
    float soma = 0;

    for (int i = 0; i < 5; i++) {
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);
        soma += alunos[i].nota;
    }

    printf("A media das notas é %f", soma / 5);

    return 0;
}
