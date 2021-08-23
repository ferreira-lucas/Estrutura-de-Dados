#include <stdio.h>
#include <string.h>
#include "manut.h"

void inserir(int *vetor[], int valor, int tamanho, int *pn){
    if(*pn == tamanho){
        printf("A lista esta cheia! Item nao adicionado!\n");
    }else{
        //printf("Valor de n: %d\n", n); //DEBUG
        vetor[*pn] = valor;
        *pn = *pn + 1;
        printf("Valor inserido com sucesso!\n");
        //printf("Valor de n: %d\n", *pn); //DEBUG
    }
}

void remover(int *vetor[], int valor, int tamanho, int *pn){
    int aux = 0;
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] == valor){
            aux++;
            for(int j = i; j < tamanho; j++){
                vetor[j] = vetor[j+1];
            }
            *pn = *pn - 1;
        }
    }
    if(aux == 0){
        printf("Nao encontrou nenhum valor! Nada foi deletado, tamanho da lista inalterado!\n");
    }else if(aux = 1){
        printf("Encontrou %d valor! Todos foram excluidos, novo tamanho da lista = %d!\n", aux, *pn);
    }else if(aux > 1){
        printf("Encontrou %d valores! Todos foram excluidos, novo tamanho da lista = %d!\n", aux, *pn);
    }
}

void pesquisar(int *vetor[], int valor, int n){
    int aux = 0;
    for(int i = 0; i < n; i++){
        if(vetor[i] == valor){
            aux = 1;
            printf("Valor encontrado na posicao %d!\n", i);
        }
    }
    if(aux == 0){
        printf("Nao encontrou nenhum valor!\n");
    }
}

void imprimir(int *vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("Valor na posicao %d: %d\n", i, vetor[i]);
    }
}
