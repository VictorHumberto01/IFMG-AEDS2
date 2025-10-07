#include <stdio.h>

int main() {

    if (remove("final.txt") == 0) {
        puts("Arquivo removido com sucesso");
    } else {
        puts("Erro ao remover arquivo");
    }

    return 0;
}
