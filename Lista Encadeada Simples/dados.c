#include <stdio.h>
#include <string.h>

typedef struct{
    char codigoBarras[8];
    char descricao[20];
    int categoria;
    float preco;
} Produto;
struct Nodo{
    Produto  dado;
    struct Nodo *prox;
};
typedef struct Nodo nodo;
