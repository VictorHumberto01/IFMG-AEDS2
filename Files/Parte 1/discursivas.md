# Questão 1

### **A)** 
Os arquivos de texto são escritos em ASCII 2 fazendo com que sejam compativeis com editores de texto, porém sejam maiores em tamanho já que caracteres ocupam mais espaço. Usam as funções fprintf, fscanf, fgets, fputs. Os binários são escritos com dados na forma bruta, ocupam menos espaço e são mais rápidos de gravar e ler. Mais adequados para estruturas de dados complexas e grandes volumes de dados. Usam fwrite, fread.

### **B)** 
Os arquivos permitem que dados sejam persistentes ou seja, sejam lembrados entre sessões.

# Questão 2

A leitura sequencial percorre o arquivo do inicio ao fim, passo a passo. É mais lenta já que é necessário percorrer todos os dados até que se chegue no objetivo. 

**Exemplo:**

```
#include <stdio.h>

int main() {
    FILE *arq = fopen("dados.txt", "r");
    char linha[100];

    while (fgets(linha, sizeof(linha), arq)) {
        printf("%s", linha);
    }

    fclose(arq);
    return 0;
}
```
A leitura randômica permite que o programa pule partes dos dados e vá direto à posição desejada. Isso pode ser feito usando o fseek().

```
#include <stdio.h>

int main() {
    FILE *arq = fopen("dados.txt", "r");
    char buffer[20];

    fseek(arq, 10, SEEK_SET); // Vai para o 10º byte do arquivo
    fread(buffer, sizeof(char), 10, arq);
    buffer[10] = '\0';

    printf("Leitura randômica: %s\n", buffer);

    fclose(arq);
    return 0;
}
```

# Questão 3

Modos de abertura de arquivos em C (`fopen`)

1. **"r"**  
   - Abre um arquivo para **leitura**.  
   - O arquivo **deve existir**, caso contrário `fopen` retorna `NULL`.

2. **"w"**  
   - Abre um arquivo para **escrita**.  
   - Se o arquivo já existir, seu conteúdo é **apagado**.  
   - Se não existir, um novo arquivo é criado.

3. **"a"**  
   - Abre um arquivo para **acréscimo (append)**.  
   - Os dados sempre serão gravados **no final do arquivo**.  
   - Se não existir, é criado.

4. **"r+"**  
   - Abre um arquivo para **leitura e escrita**.  
   - O arquivo deve existir.  
   - Permite alterar dados já existentes sem apagar o conteúdo.

5. **"w+"**  
   - Abre um arquivo para **leitura e escrita**.  
   - Se o arquivo já existir, seu conteúdo é **apagado**.  
   - Se não existir, é criado.
