#include <stdio.h>
#include <string.h>
#include "manut.h"

void iniciar(nodo *L){
    L->prox = NULL;
}

void inserirInicio(nodo *L, Produto *dado){
    nodo *novo = (nodo *) malloc(sizeof(nodo));

    strcpy(novo->dado.codigoBarras, dado->codigoBarras);
    strcpy(novo->dado.descricao, dado->descricao);
    novo->dado.categoria = dado->categoria;
    novo->dado.preco = dado->preco;

    novo->prox = L->prox;
    L->prox = novo;
}

int estaVazia(nodo *L){
    if(L->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

void excluirItem(nodo *L, char *descricao){
    int aux = 0;
    if(estaVazia(L)){
        printf("\n");
        printf("Lista vazia!\n\n");
        return;
    }

    nodo *noAnterior = L;
    nodo *noAtual = L->prox;
    while(noAtual->prox != NULL){
        if(strcmp(noAtual->dado.descricao, descricao) == 0){
            aux++;
            noAnterior->prox= noAtual->prox;
            free(noAtual);
            printf("\n");
            printf("Item excluído com sucesso!\n");
            return;
        }
        noAnterior = noAtual;
        noAtual = noAtual->prox;
    }
    printf("\n\n");

    if(aux == 0){
        printf("\n");
        printf("Nenhum item encontrado com essa descricao!");
    }
}

void pesquisarItem(nodo *L, char *descricao){
    int aux = 0;
    if(estaVazia(L)){
        printf("\n");
        printf("Lista vazia!\n\n");
        return;
    }

    nodo *no = L->prox;
    while(no != NULL){
        if(strcmp(no->dado.descricao, descricao) == 0){
            aux++;
            printf("\n");
            printf("*****************************\n");
            printf("Codigo: %s\nDescricao: %s\nPreco: R$%.2f\nCategoria: %d\n", no->dado.codigoBarras, no->dado.descricao, no->dado.preco, no->dado.categoria);
        }
        no = no->prox;
    }
    printf("\n\n");

    if(aux == 0){
        printf("\n");
        printf("Nenhum item encontrado com essa descricao!");
    }else if(aux == 1){
        printf("\n");
        printf("Total de 1 item encontrado!\n");
    }else if(aux > 1){
        printf("\n");
        printf("Total de %d item encontrado!\n", aux);
    }
}

void imprimir(nodo *L){
    int aux = 0;
    if(estaVazia(L)){
        printf("\n");
        printf("Lista esta vazia!\n");
        return;
    }

    nodo *no = L->prox;
    while(no != NULL){
        aux++;
        printf("*****************************\n");
        printf("Codigo: %s\nDescricao: %s\nPreco: R$%.2f\nCategoria: %d\n", no->dado.codigoBarras, no->dado.descricao, no->dado.preco, no->dado.categoria);
        no = no->prox;
    }
    printf("\n\n");

    if(aux == 1){
        printf("Total de 1 item encontrado!\n");
    }else if(aux > 1){
        printf("Total de %d itens encontrados!\n", aux);
    }
}
