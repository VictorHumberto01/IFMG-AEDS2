#include <stdio.h>

#define MAX 50

typedef struct Pilha {
  int data[MAX];
  int index;
} Pilha;

void inicializar(Pilha *p) {
  p->index = -1;
  puts("Inicializada!");
}


int is_empty(Pilha *p) {
  if (p->index == -1) return 1;
  return 0;
}

int is_full(Pilha *p) {
  if (p->index == MAX - 1) return 1;
  return 0;
}


int Empilhar(Pilha *p, int data) {
  if (is_full(p)) return -1;

  p->index++;
  p->data[p->index] = data;
  printf("%d empilhado!\n", data);
  return 1;
}

int Desempilhar(Pilha *p) {
  if (is_empty(p)) {
    puts("Pilha vazia!");
    return -1;
  }

  int old_data = p->data[p->index]; 
  p->index--;

  return old_data;
}

int peek(Pilha *p) {
  if (is_empty(p)) {
    puts("Pilha vazia!");
    return -1;
  }


  return p->data[p->index];
}

int main(void) {
  
  Pilha p;
  inicializar(&p);

  int decimal;

  printf("Digite um número na base 10: ");
  scanf("%d", &decimal);
  
  

  while (decimal > 0) {
    Empilhar(&p, decimal % 2);
    decimal /= 2;
  }

  puts("Numero convertido para binario: ");
  while (!is_empty(&p)) {
    printf("%d", Desempilhar(&p));
  }

  puts("");

  return 0;
}
