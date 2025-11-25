#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50


typedef struct {
    char items[MAX];
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

int empilhar(Pilha *p, char data) {
  if (isFull(p)) {
    puts("Stack overflow!");
    return -1;
  }


  p->top++;
  p->items[p->top] = data;
  printf("Empilhado: %c\n", data);
  
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

  char texto[] = "casa";
  char invertido[sizeof(texto)];

  for (int i = 0; texto[i] != '\0'; i++) {
    empilhar(&p, texto[i]);
  }

   
  for (int i = 0; texto[i] != '\0'; i++) {
    invertido[i] = peek(&p);
    desempilhar(&p);
  }

  printf("%s\n", invertido);


  return 0;
}


