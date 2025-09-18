#include <stdio.h>

typedef struct Aluno {
    int matricula;
    float nota;
} Aluno;

int main() {
    int quantidade;
    int nota;
    int matricula;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quantidade);

    Aluno alunos[quantidade];

    for (int i = 0; i < quantidade; i++) {
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);
    }

    do {
        printf("Digite a matricula do aluno para alterar a nota: ");
        scanf("%d", &matricula);
        printf("Para parar digite a matricula negativa");


        for (int i = 0; i < quantidade; i++) {
            if (alunos[i].matricula == matricula) {
                printf("Digite a nova nota para o aluno %d: ", matricula);
                scanf("%f", &alunos[i].nota);
                break;
            }
        }
    } while (matricula > 0);

    return 0;
}
