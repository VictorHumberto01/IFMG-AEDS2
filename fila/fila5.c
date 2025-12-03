#include <stdio.h>
#include <stdlib.h>


#define MAX 5


typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int quantidade;

} FilaCircular;


void inicializar(FilaCircular *f) {

    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}


int enfileirar(FilaCircular *f, int valor) {
    if (f->quantidade == MAX) {
        puts("Fila cheia!");
        return 0;
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->quantidade++;

    return 1;
}


int desenfileirar(FilaCircular *f) {
    if (f->quantidade == 0) {
       puts("ERRO: Fila vazia! Nada para remover.");

    }
    int itemRemovido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->quantidade--;

    return itemRemovido;
}


int main() {
    FilaCircular fila;


    inicializar(&fila);

    printf("--- Inserindo 10, 20, 30 ---\n");
    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);


    printf("Debug: Inicio: %d | Fim: %d | Qtd: %d\n\n", fila.inicio, fila.fim, fila.quantidade);

    printf("--- Removendo um item ---\n");
    int sai = desenfileirar(&fila);
    printf("Saiu: %d\n", sai);

    printf("Debug: Inicio: %d | Fim: %d | Qtd: %d\n\n", fila.inicio, fila.fim, fila.quantidade);

    return 0;
}
