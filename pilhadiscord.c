#include <stdio.h>

#define MAX 5

typedef struct {
  int dados[MAX];
  int indice;
} Pilha;

// [0, 1, 2, 3, 4]

void inicializarPilha(Pilha *p) {
  p->indice = -1;
  puts("Inicializada!");
}

// Empilhar, Desempilhar, peek

int empilhar(Pilha *p, int dado) {
  if (p->indice == MAX - 1) {
    puts("Stack Overflow!");
    return 0;
  }

  p->indice++;
  p->dados[p->indice] = dado;
  return 1;
}

int desempilhar(Pilha *p) {
  if (p->indice == -1) {
    puts("Stack Underflow!");
    return -1;
  }

  int dado_removido = p->dados[p->indice]; // Dado antigo
  
  p->indice--;

  return dado_removido;
}


int peek(Pilha *p) {
  if (p->indice == -1) {
    puts("Stack Underflow!");
    return -1;
  }

  return p->dados[p->indice];
}





int main(void) {

  Pilha p;

  inicializarPilha(&p);

  empilhar(&p, 50);
  empilhar(&p, 20);


  printf("%d\n", peek(&p));

  printf("Removido: %d\n", desempilhar(&p));
  
  printf("%d\n", peek(&p));



  return 0;
}
