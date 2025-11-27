#include <stdio.h> 
#include <string.h>

#define MAX 50



typedef struct Pilha {
  char string[MAX];
  int index;
} Pilha;


void inicializar(Pilha *p) {
  p->index = -1;
  puts("Inicializada!");
}

int isEmpty(Pilha *p) {
  if (p->index == -1) return 1;

  return 0;
}

int isFull(Pilha *p) {
  if (p->index == MAX - 1) return 1;
  
  return 0;
}


int Empilhar(Pilha *p, char data) {
  if (isFull(p)) {
    puts("Stack Overflow");
    return -1;
  } else {
    p->index++;
    p->string[p->index] = data;
    printf("Empilhado! %c\n", data);
    return 1;
  }
}

int Desempilhar(Pilha *p) {
  if (isEmpty(p)) return -1;

  char data = p->string[p->index];
  p->index--;
  return data;
}

char Peek(Pilha *p) {
  if (isEmpty(p)) return 'e';

  return p->string[p->index];
}




int main(void) {
  char expressao[] = "2 + (3 * [10 / 2]) - { 5 }";
  Pilha Stack;
  inicializar(&Stack);
  int erro = 0;
  
  for (int i = 0; expressao[i] != '\0'; i++) {
    char atual = expressao[i];
    if (atual == '(' || atual == '[' || atual == '{') {
      Empilhar(&Stack, atual);
    } else if (atual == ')' || atual == ']' || atual == '}') {
      if (isEmpty(&Stack)) {
        printf("Erro: Fechamento de %c sem abertura correspondente!\n", atual);
        erro = 1;
        break;
      }

      char topo = Desempilhar(&Stack);

      if ((atual == ')' && topo != '(') ||
        (atual == ']' && topo != '[') ||
        (atual == '}' && topo != '{')) {

        printf("Erro: Esperava fechar '%c', mas encontrou '%c'\n", topo, atual);
        erro = 1;
        break;
      }
    }


  }

  if (erro == 0) {
    if (isEmpty(&Stack)) {
      printf("A expressao esta balanceada! \n");
    } else {
      printf("Erro: Sobraram parenteses abertos na pilha!");
    }
  } 

    

  return 0;
}
