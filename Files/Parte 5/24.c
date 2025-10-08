#include <stdio.h>

int main() {
    FILE *file = fopen("texto.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int contagem[26] = {0};
    char c;

    while ((c = fgetc(file)) != EOF) {
       if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
       }
       
       if (c >= 'a' && c <= 'z') {
           contagem[c - 'a']++;
       }
    }

  
    fclose(file);
    
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, contagem[i]);
    }
    return 0;
}
