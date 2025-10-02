#include <stdio.h>
#include <string.h>

int main() {
  FILE *frase = fopen("frase.txt", "w");
  if (frase == NULL) {
      printf("Erro ao abrir o arquivo!\n");
      return 1;
  }
  char buffer[100];


  printf("Digite uma frase: ");
  fgets(buffer, sizeof(buffer), stdin);



  while (strcmp(buffer, "fim\n") != 0) {
      fputs(buffer, frase);
      printf("Digite uma frase: ");
      fgets(buffer, sizeof(buffer), stdin);
  }


  fclose(frase);

  return 0;
}
