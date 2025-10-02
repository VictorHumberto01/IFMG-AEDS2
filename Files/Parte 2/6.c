#include <stdio.h>

int main() {
  FILE *frase = fopen("frase.txt", "w");
  if (frase == NULL) {
      printf("Erro ao abrir o arquivo!\n");
      return 1;
  }
  char buffer[100];

  printf("Digite uma frase: ");
  fgets(buffer, sizeof(buffer), stdin);

  for (int i = 0; buffer[i] != '\0'; i++) {
      fputc(buffer[i], frase);
  }

  fclose(frase);

  return 0;
}
