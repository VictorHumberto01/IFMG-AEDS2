#include <stdio.h>

int main(){

    //2
    struct date Data = {1, 1, 2000};

    //3
    Retangulo retangulo ;
    float areaRet;
    scanf("%f", &retangulo.largura);
    scanf("%f", &retangulo.altura);
    areaRet = retangulo.base * retangulo.altura;
    printf("%.2f", areaRet);

    //4 
    Triangulo triangulo ;
    float areaTri;
    scanf("%f", &triangulo.base);
    scanf("%f", &triangulo.altura);
    areaTri = triangulo.base * triangulo.altura;
    printf("%.2f", areaTri);

    //5
    Produto p ;
    scanf("%i", &p.id);
    scanf("%i", &p.quantidade);
    scanf("%f", &p.preco);
    float totalProduto = p.quantidade * p.preco;
    printf("%.2f", totalProduto);

    //6
    Aluno alunos[5];
    float soma = 0;
    for(int i = 0; i < 5; i++){
        scanf("%i", &alunos[i].matricula);
        scanf("%f", &alunos[i].nota);
        soma += alunos[i].nota;
    }
    printf("A media das notas é %f", soma / 5);

    return 0;
}

// 1
typedef struct {
    int x;
    int y;
} Ponto;

//2
struct Data{
    int dia;
    int mes;
    int ano;
};

//3
struct Retangulo{
    float largura;
    float altura;
}

//4
struct Triangulo{
    float base;
    float altura;
}

//5
struct Produto{
    int id;
    int quantidade;
    float preco;
}

//6
struct Aluno{
    int matricula;
    float nota;
}




