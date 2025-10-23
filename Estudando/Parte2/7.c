#include <stdio.h>

int main() {
    FILE *file = fopen("duplicado.txt", "r");
    if (file == NULL) return 1;


    char c;

    while((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }


    return 0;
}
