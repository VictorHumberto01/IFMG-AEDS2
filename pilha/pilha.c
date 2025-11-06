#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;


void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

int isFull(Pilha *p) {
    if (p->topo == MAX - 1) return 1;

    return 0;
}

int isEmpty(Pilha *p) {
    if (p->topo == -1) return 1;

    return 0;
}


void Empilhar(Pilha *p, int item) {
    if (isFull(p)) {
        puts("Stack Overflow!");
    } else {

        // -1 + 1 = 0 => [0, 1, 2 ... MAX]
        p->topo++;
        p->itens[p->topo] = item;

        puts("Empilhado!");
    }
}


void Desempilhar(Pilha *p) {
    if (isEmpty(p)) {
        puts("Stack Underflow!");
    } else {
        p->topo--;
        puts("Desempilhado!");
    }
}

void Topo(Pilha *p) {
    if (isEmpty(p)) {
        puts("Stack Underflow!");
    } else {
        printf("Topo: %d", p->itens[p->topo]);
    }
}


int limparPilha(Pilha *p) {
    p->topo = -1;
    return 0;
}

int main() {

    Pilha x;

    inicializaPilha(&x);

    Empilhar(&x, 5);
    Empilhar(&x, 10);
    Empilhar(&x, 15);
    Desempilhar(&x);
    Empilhar(&x, 20);

    Topo(&x);


    limparPilha(&x);




    return 0;
}
