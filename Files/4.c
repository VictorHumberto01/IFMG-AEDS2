#include <stdio.h>

int main() {
  FILE *saida;

  saida = fopen("saida.txt", "w");

  fprintf(saida, "Primeiro arquivo em C");

  fclose(saida);

  return 0;
}
