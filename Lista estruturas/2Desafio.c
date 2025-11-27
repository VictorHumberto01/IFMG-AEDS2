#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50


typedef struct {
    int items[MAX];
    int top;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->top = -1;
}

int isEmpty(Pilha *p) {
  if (p->top == -1) return 1;

  return 0;
}

int isFull(Pilha *p) {
  if (p->top == MAX - 1) return 1;

  return 0;
}

int empilhar(Pilha *p, int data) {
  if (isFull(p)) {
    puts("Stack overflow!");
    return -1;
  }


  p->top++;
  p->items[p->top] = data;
  printf("Empilhado: %d\n", data);
  
  return 1;
}

int desempilhar(Pilha *p) {
  if (isEmpty(p)) return -1;

  p->top--;
  puts("Desempilhado!");
  return 0;
}


char peek(Pilha *p) {
  if (isEmpty(p)) return '\0';
  

  return p->items[p->top];

  
}



int main(void) {
    Pilha p;
    inicializaPilha(&p);

    int vetor[] = { 1, 2, 3, 4, 5 };
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int invertido[tamanho];

    for (int i = 0; i < tamanho; i++) {
        empilhar(&p, vetor[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        invertido[i] = peek(&p);
        desempilhar(&p);
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", invertido[i]);
    }
    printf("\n");

    return 0;
}
