#include <stdio.h>

int main() {
  FILE *saida;

  saida = fopen("saida.txt", "w");

  fputs("Primeiro arquivo em C", saida);

  fclose(saida);

  return 0;
}
