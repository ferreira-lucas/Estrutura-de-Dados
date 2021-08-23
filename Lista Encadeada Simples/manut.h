#ifndef MANUT_H_INCLUDED
#define MANUT_H_INCLUDED

typedef struct{
    char codigoBarras[9];
    char descricao[20];
    int categoria;
    float preco;
} Produto;

struct Nodo{
    Produto dado;
    struct Nodo *prox;
};

typedef struct Nodo nodo;

void iniciar(nodo *L);

void inserirInicio(nodo *L, Produto *dado);

int estaVazia(nodo *L);

void excluirItem(nodo *L, char *descricao);

void pesquisarItem(nodo *L, char *descricao);

void imprimir(nodo *L);

#endif // MANUT_H_INCLUDED
