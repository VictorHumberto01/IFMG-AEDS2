# Trabalhando com Arquivos em C

Este documento detalha as principais funções e conceitos para manipulação de arquivos na linguagem de programação C.

## A Estrutura `FILE`

Em C, todas as operações de arquivo são realizadas através de um ponteiro para a estrutura `FILE`. Esta estrutura, definida em `<stdio.h>`, contém todas as informações necessárias para controlar um fluxo de dados (stream), como a posição atual no arquivo, ponteiros para seus buffers, e indicadores de erro e fim de arquivo.

```c
#include <stdio.h>

int main() {
    FILE *ponteiro_do_arquivo;
    return 0;
}
```

---

## Funções Principais para Manipulação de Arquivos

### 1. `fopen()` - Abrir um Arquivo

- **Funcionalidade:** Abre um arquivo e associa um fluxo (stream) a ele.
- **Parâmetros:**
    1.  `const char *filename`: Uma string contendo o nome do arquivo a ser aberto (ex: `"meu_arquivo.txt"`).
    2.  `const char *mode`: Uma string que define o modo de acesso ao arquivo (leitura, escrita, etc.).
- **Retorno:**
    -   Se for bem-sucedido, retorna um ponteiro `FILE*` para o arquivo.
    -   Se ocorrer um erro (ex: arquivo não encontrado, permissão negada), retorna `NULL`.
- **Modos de Abertura (`mode`):**
    -   `"r"`: **Leitura (read)**. O arquivo deve existir. O cursor começa no início.
    -   `"w"`: **Escrita (write)**. Cria um novo arquivo para escrita. Se o arquivo já existir, seu conteúdo é **apagado**.
    -   `"a"`: **Anexar (append)**. Abre para escrita no final do arquivo. Se o arquivo não existir, ele é criado.
    -   `"r+"`: **Leitura e Escrita**. O arquivo deve existir. O cursor começa no início.
    -   `"w+"`: **Leitura e Escrita**. Cria um novo arquivo. Se já existir, o conteúdo é **apagado**.
    -   `"a+"`: **Leitura e Anexar**. Abre para leitura e escrita no final do arquivo. Se não existir, é criado.

- **Aplicação:**
```c
FILE *arq = fopen("dados.txt", "w");
if (arq == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return 1; // Encerra o programa indicando erro
}
// ... operações no arquivo ...
```

### 2. `fclose()` - Fechar um Arquivo

- **Funcionalidade:** Fecha um arquivo, desassociando-o do fluxo. Isso garante que todos os dados em buffer sejam gravados no disco e libera os recursos do sistema.
- **Parâmetros:**
    1.  `FILE *stream`: O ponteiro para o arquivo que foi retornado por `fopen()`.
- **Retorno:**
    -   Retorna `0` se o arquivo for fechado com sucesso.
    -   Retorna `EOF` (End Of File) se ocorrer um erro.
- **Aplicação:**
```c
fclose(arq);
```
**Observação:** É uma prática crucial sempre fechar um arquivo após o uso para evitar perda de dados e vazamento de recursos.

### 3. `fprintf()` - Escrever de forma formatada

- **Funcionalidade:** Escreve dados formatados em um arquivo, de forma similar ao `printf`.
- **Parâmetros:**
    1.  `FILE *stream`: O ponteiro para o arquivo.
    2.  `const char *format`: A string de formatação (ex: `"%s %d"`).
    3.  `...`: As variáveis a serem escritas.
- **Retorno:**
    -   O número de caracteres escritos.
    -   Um valor negativo em caso de erro.
- **Aplicação:**
```c
char nome[] = "Maria";
int idade = 30;
fprintf(arq, "Nome: %s, Idade: %d\n", nome, idade);
```

### 4. `fscanf()` - Ler de forma formatada

- **Funcionalidade:** Lê dados formatados de um arquivo, de forma similar ao `scanf`.
- **Parâmetros:**
    1.  `FILE *stream`: O ponteiro para o arquivo.
    2.  `const char *format`: A string de formatação (ex: `"%s %d"`).
    3.  `...`: Os ponteiros para as variáveis onde os dados serão armazenados.
- **Retorno:**
    -   O número de itens lidos com sucesso.
    -   `EOF` se o final do arquivo for alcançado antes de qualquer leitura.
- **Aplicação:**
```c
char nome[50];
int idade;
fscanf(arq, "%s %d", nome, &idade);
```

### 5. `fputc()` - Escrever um caractere

- **Funcionalidade:** Escreve um único caractere em um arquivo.
- **Parâmetros:**
    1.  `int character`: O caractere a ser escrito (passado como `int`).
    2.  `FILE *stream`: O ponteiro para o arquivo.
- **Retorno:**
    -   O caractere escrito.
    -   `EOF` em caso de erro.
- **Aplicação:**
```c
fputc('A', arq);
```

### 6. `fgetc()` - Ler um caractere

- **Funcionalidade:** Lê um único caractere de um arquivo.
- **Parâmetros:**
    1.  `FILE *stream`: O ponteiro para o arquivo.
- **Retorno:**
    -   O caractere lido (como um `int`).
    -   `EOF` se o final do arquivo for alcançado ou se ocorrer um erro.
- **Aplicação:**
```c
int caractere = fgetc(arq);
while (caractere != EOF) {
    printf("%c", caractere);
    caractere = fgetc(arq);
}
```

### 7. `fgets()` - Ler uma string (linha)

- **Funcionalidade:** Lê uma linha inteira de um arquivo, até encontrar uma quebra de linha (`\n`), o final do arquivo, ou até o limite de caracteres ser atingido.
- **Parâmetros:**
    1.  `char *str`: Ponteiro para o buffer onde a string será armazenada.
    2.  `int n`: O número máximo de caracteres a serem lidos (incluindo o caractere nulo `\0`).
    3.  `FILE *stream`: O ponteiro para o arquivo.
- **Retorno:**
    -   Um ponteiro para `str` se a leitura for bem-sucedida.
    -   `NULL` se o final do arquivo for alcançado ou se ocorrer um erro.
- **Aplicação:**
```c
char linha[100];
while (fgets(linha, 100, arq) != NULL) {
    printf("%s", linha);
}
```

---

## Exemplo Completo

O programa a seguir cria um arquivo chamado `log.txt`, escreve algumas informações nele, fecha-o, e depois o abre novamente para ler e exibir seu conteúdo na tela.

```c
#include <stdio.h>
#include <stdlib.h> // Para exit()

int main() {
    FILE *arquivo;
    char nome[50];
    int idade;

    // --- Bloco de Escrita ---
    arquivo = fopen("log.txt", "w"); // Abre em modo de escrita

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        exit(1);
    }

    printf("Arquivo log.txt criado com sucesso.\n");

    // Escrevendo dados formatados
    fprintf(arquivo, "Log de Usuários\n");
    fprintf(arquivo, "===============\n");
    fprintf(arquivo, "Joao 25\n");
    fprintf(arquivo, "Ana 32\n");

    fclose(arquivo); // Fecha o arquivo
    printf("Dados escritos e arquivo fechado.\n\n");


    // --- Bloco de Leitura ---
    arquivo = fopen("log.txt", "r"); // Abre em modo de leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

    printf("Conteúdo do arquivo log.txt:\n");
    
    char linha[100];
    // Lê e imprime o cabeçalho
    fgets(linha, 100, arquivo);
    printf("%s", linha);
    fgets(linha, 100, arquivo);
    printf("%s", linha);

    // Lê os dados de cada usuário
    while (fscanf(arquivo, "%s %d", nome, &idade) != EOF) {
        printf("Usuário: %s, Idade: %d\n", nome, idade);
    }

    fclose(arquivo); // Fecha o arquivo novamente

    return 0;
}
```