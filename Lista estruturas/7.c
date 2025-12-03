#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct Pilha {
  char items[MAX];
  int index;
} Pilha;


void inicializarPilha(Pilha *p) {
  p->index = -1;
}

int isEmpty(Pilha *p) {
  if (p->index == -1) return 1;

  return 0;
}

int isFull(Pilha *p) {
  if (p->index == MAX - 1) return 1;

  return 0;
}

int empilhar(Pilha *p, char data) {
  if(isFull(p)) {
    puts("Stack overflow!");
    return 0;
  } 

  p->index++;
  p->items[p->index] = data;
  return 1;
} 
 
int desempilhar(Pilha *p) {
  if (isEmpty(p)) return 0;

  char old_data = p->items[p->index];

  p->index--;
  
  return old_data;
}
  

 

int main(void) {
  
  Pilha p;

  inicializarPilha(&p);

  char string[] = "arara";
  char invertida[sizeof(string)];

  for (int i = 0; i < sizeof(string) - 1; i++) {
    empilhar(&p, string[i]);
  }

  for (int i = 0; i < sizeof(string) - 1; i++) {
    invertida[i] = desempilhar(&p);
  }

  if (!strcmp(string, invertida)) {
    puts("eh palindromo!");
  }



  return 0;
}
