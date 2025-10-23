#include <stdio.h>

int main() {
    FILE *file = fopen("numeros.txt", "w");
    if (file == NULL) return 1;


    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) fprintf(file, "%d ", i);
    }

    fclose(file);

    return 0;
}
