#include <stdio.h>

int main() {

  FILE *dados = fopen("dados.txt", "r");
  char conteudo[100];

  if (dados == NULL) {
    printf("Erro ao abrir (arquivo não existe)");
    return 1;
  }

  fgets(conteudo, sizeof(conteudo), dados);

  printf("%s", conteudo);

  fclose(dados);

  return 0;
}
