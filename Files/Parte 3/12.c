#include <stdio.h>

int main() {
    FILE *dados = fopen("dados.bin", "wb");
    float valor;

    if (dados == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }


    for (int i = 0; i < 10; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &valor);
        fwrite(&valor, sizeof(float), 1, dados);
    }

    fclose(dados);

    FILE *leitura = fopen("dados.bin", "rb");

    if (leitura == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    float valor_lido;
    while(fread(&valor_lido, sizeof(float), 1, leitura) == 1) {
        printf("Valor lido: %.2f\n", valor_lido);
    };

    fclose(leitura);

    return 0;
}
