#include <_stdio.h>

int main() {
  FILE *exercicio = fopen("exercicio.txt", "w");
  int c = 67;
  fputc(c, exercicio);
  fclose(exercicio);

  return 0;
}
