#include "math_utils.h"
#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b) { return a + b; }
int multiplicar(int a, int b) { return a * b; };
int subtrair(int a, int b) { return a - b; };

float dividir(float a, float b) {
  if (b == 0) {
    fprintf(stderr, "Erro: divisao por zero!");
    exit(EXIT_FAILURE);
  }

  return a / b;
}
