#include <stdio.h>
#include <string.h>

typedef struct Pessoa {
    char nome[50];
    char idade[4];
    char cidade[50];
} Pessoa;

int main() {
    FILE *file = fopen("pessoas.txt", "w");
    if (!file) {
        puts("Erro ao abrir o arquivo");
        return 1;
    }

    Pessoa pessoa;
    int c;

    for (int i = 0; i < 3; i++) {
        printf("Digite o nome: ");
        fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
        pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

        printf("Digite a idade: ");
        fgets(pessoa.idade, sizeof(pessoa.idade), stdin);
        pessoa.idade[strcspn(pessoa.idade, "\n")] = '\0';

        printf("Digite a cidade: ");
        fgets(pessoa.cidade, sizeof(pessoa.cidade), stdin);
        pessoa.cidade[strcspn(pessoa.cidade, "\n")] = '\0';

        fwrite(&pessoa, sizeof(pessoa), 1, file);
    }

    fclose(file);
    return 0;
}
