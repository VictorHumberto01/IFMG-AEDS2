#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int indice;
} Lista;

void inicializar_lista(Lista *l) {
    l->indice = -1;
    puts("Lista inicializada!");
}

int inserir_ultimo(Lista *l, int dado) {
    if (l->indice == MAX - 1) {
        puts("Fila cheia!");
        return 0;
    }

    l->dados[l->indice + 1] = dado;
    l->indice++;
    printf("%d adicionado ao fim da lista!\n", dado);
    return 1;
}

int remover_ultimo(Lista *l) {
    if (l->indice == -1) {
        puts("Lista vazia!");
        return -1;
    }

    int removido = l->dados[l->indice];
    l->indice--;
    printf("Removido %d do final\n", removido);
    return removido;
}


// INICIO


int inserir_inicio(Lista *l, int dado) {
    if (l->indice == MAX - 1) {
        puts("Lista cheia!");
        return -1;
    }

    // mover todos para a direita

    for (int i = l->indice; i >= 0; i--) {
        l->dados[i + 1] = l->dados[i];
    }

    l->dados[0] = dado;
    l->indice++;
    printf("%d adicionado ao inicio da lista!\n", dado);

    return 1;
}

int remover_inicio(Lista *l) {
    if (l->indice == -1) {
        puts("Lista vazia!");
        return -1;
    }

    int removido = l->dados[0];


    // mover todos pra esquerda...

    for (int i = 0; i < l->indice; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->indice--;
    printf("Removido %d do inicio\n", removido);
    return removido;
}

// qualquer posicao

int inserir_em(Lista *l, int dado, int posicao) {
    if (l->indice == MAX - 1) {
        puts("Lista cheia!");
        return 0;
    }

    if (posicao < 0 || posicao > l->indice + 1) {
        puts("Indice invalido!");
        return 0;
    }

    // mover todos para a direita a partir da posicao


    for (int i = l->indice; i >= posicao; i--) {
        l->dados[i + 1] = l->dados[i];
    }

    l->indice++;
    l->dados[posicao] = dado;
    printf("%d adicionado na posicao %d\n", dado, posicao);

    return 1;

}

int remover_em(Lista *l, int posicao) {
    if (l->indice == -1) {
        puts("Lista vazia!");
        return 0;
    }

    if (posicao < 0 || posicao > l->indice) {
        puts("indice invalido!");
        return 0;
    }

    int removido = l->dados[posicao];

    // mover todos para a esquerda apos a posicao

    for (int i = posicao; i < l->indice; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->indice--;

    printf("%d removido da posicao %d\n", removido, posicao);

    return removido;
}





int main(void) {





    Lista minhaLista;
    inicializar_lista(&minhaLista);

    printf("--- TESTE 1: INSERÇÕES ---\n");
    // 1. insere_final (O(1))
    inserir_ultimo(&minhaLista, 10); // Lista: [10]
    inserir_ultimo(&minhaLista, 40); // Lista: [10, 40]

    // 2. insere_inicio (O(n))
    inserir_inicio(&minhaLista, 5); // Lista: [5, 10, 40]

    // 3. insere_em (O(n)) - Inserir no meio (índice 2)
    inserir_em(&minhaLista, 20, 2); // Lista: [5, 10, 20, 40]

    // 4. Teste de Capacidade Máxima (MAX=5)
    inserir_em(&minhaLista, 30, 3); // Lista: [5, 10, 20, 30, 40] (Lista Cheia)
    inserir_ultimo(&minhaLista, 99); // Deve falhar (Overflow)

    printf("\n--- TESTE 2: REMOÇÕES ---\n");

    // 1. remove_inicio (O(n))
    remover_inicio(&minhaLista); // Remove 5. Lista: [10, 20, 30, 40]

    // 2. remove_em (O(n)) - Remover do meio (índice 1)
    remover_em(&minhaLista, 1); // Remove 20. Lista: [10, 30, 40]

    // 3. remove_ultimo (O(1))
    remover_ultimo(&minhaLista); // Remove 40. Lista: [10, 30]

    printf("\n--- TESTE 3: Esvaziar Lista ---\n");

    remover_inicio(&minhaLista); // Remove 10. Lista: [30]
    remover_ultimo(&minhaLista); // Remove 30. Lista: []

    remover_inicio(&minhaLista); // Deve falhar (Underflow)

    return 0;
}
