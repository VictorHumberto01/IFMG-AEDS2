#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Pilha {
    Node* top;
} Pilha;


void inicializarPilha(Pilha *p) {
    p->top = NULL;
}


int isEmpty(Pilha *p) {
    return p->top == NULL;
}

void empilhar(Pilha *p, int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = p->top;
    p->top = newNode;
    printf("%d empilhado!\n", data);
}


int desempilhar(Pilha *p) {
    if (isEmpty(p)) {
        puts("Stack Underflow!");
        return -1;
    } else {
        Node *temp = p->top;
        p->top = temp->next;
        free(temp);
        puts("Desempilhado!");
        return 1;
    }
}


int peak(Pilha *p) {
    if (isEmpty(p)) {
        puts("Stack vazia!");
        return -1;
    } else {
        return p->top->data;
    }
}

void liberaPilha(Pilha *p) {
    Node *atual = p->top;

    while (atual != NULL) {
        Node *temp = atual;
        atual = atual->next;
        free(temp);
    }

    p->top = NULL;
}

int main(void) {
    Pilha p;
    inicializarPilha(&p);

    printf("Pilha inicializada. Vazia? %s\n", isEmpty(&p) ? "sim" : "nao");

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    printf("Topo atual: %d\n", peak(&p));

    desempilhar(&p);
    printf("Topo apos desempilhar: %d\n", peak(&p));

    desempilhar(&p);
    desempilhar(&p);

    printf("Vazia apos desempilhar tudo? %s\n", isEmpty(&p) ? "sim" : "nao");

    /* tentar desempilhar quando vazia */
    desempilhar(&p);

    liberaPilha(&p);


    return 0;
}
