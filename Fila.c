#include <stdio.h>

#define MAX 5

// Frente = (frente + 1) % MAX

typedef struct Fila {
    int dados[MAX];
    int frente;
    int tras;
    int quantidade;
} Fila;


void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
    f->quantidade = 0;
    puts("Inicializada!");
}

int enfileirar(Fila *f, int dado) {
    if (f->quantidade == MAX) {
        puts("Fila cheia!");
        return 0;
    }

    f->dados[f->tras] = dado;
    f->tras = (f->tras + 1) % MAX;
    f->quantidade++;
    printf("%d enfileirado!\n", dado);
    return 1;
}


int desenfileirar(Fila *f) {
    if (f->quantidade == 0) {
        puts("Fila vazia!");
        return 0;
    }

    int dado_removido = f->dados[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->quantidade--;
    return dado_removido;

}


int peek(Fila *f) {
    if (f->quantidade == 0) {
        puts("Fila vazia!");
        return -1;
    }

    return f->dados[f->frente];
}


int main(void) {

    Fila f;
    inicializarFila(&f);
    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    printf("Frente da fila: %d\n", peek(&f));
    desenfileirar(&f);
    printf("Frente da fila apos desenfileirar: %d\n", peek(&f));

    return 0;
}
