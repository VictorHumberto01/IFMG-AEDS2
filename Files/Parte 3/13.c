#include <stdio.h>

typedef struct aluno {
    char nome[50];
    char matricula[10];
    float media;
} Aluno;

int main() {
    FILE *alunos = fopen("alunos.bin", "wb");
    Aluno aluno;

    for (int i = 0; i < 3; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", aluno.nome);
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%s", aluno.matricula);
        printf("Digite a media do aluno %d: ", i + 1);
        scanf("%f", &aluno.media);
        fwrite(&aluno, sizeof(Aluno), 1, alunos);
    }

    fclose(alunos);

    FILE *alunos2 = fopen("alunos.bin", "rb");

    while (fread(&aluno, sizeof(Aluno), 1, alunos2) == 1) {
        printf("\nNome: %s\n", aluno.nome);
        printf("Matricula: %s\n", aluno.matricula);
        printf("Media: %.2f\n", aluno.media);
    }

    fclose(alunos2);

    return 0;
}
