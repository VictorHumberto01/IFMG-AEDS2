#include <stdio.h>

typedef struct Aluno {
    int matricula;
    float nota;
} Aluno;

int main() {
    Aluno alunos[3];

    for (int i = 0; i < 3; i++) {
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);
    }





    return 0;
}
