#include <stdio.h>
#include <stdlib.h>

// Alocacao dinamica com malloc.
// Retorna um ponteiro para a região de memoria alocada ou NULL

int main() {
  int *x = malloc(sizeof(int));
  if (!x)
    return 1;

  printf("memoria alocada com sucesso!");
  printf("%d\n", *x);

  *x = 50;

  printf("%d", *x);

  free(x);

  return 0;
}
