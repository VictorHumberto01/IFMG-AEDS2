#include <stdio.h>

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;


int main() {

    Data data;

    do {
        printf("Digite o dia: ");
        scanf("%d", &data.dia);
        if(data.dia < 1 || data.dia > 31) {
            printf("Dia invalido!\n");
        }
    } while (data.dia < 1 || data.dia > 31);

    do {
        printf("Digite o mes: ");
        scanf("%d", &data.mes);
        if(data.mes < 1 || data.mes > 12) {
            printf("Mes invalido!\n");
        }
    } while (data.mes < 1 || data.mes > 12);

    do {
        printf("Digite o ano: ");
        scanf("%d", &data.ano);
        if(data.ano < 1) {
            printf("Ano invalido!\n");
        }
    } while (data.ano < 1);

    printf("Data: %d/%d/%d\n", data.dia, data.mes, data.ano);

    return 0;
}
