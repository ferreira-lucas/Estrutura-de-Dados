#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "manut.h"

#define tam 5

int vetor[tam], valor;
int n = 0, escolha, loop = 0;
int *pn = &n;


int main(void) {
    setlocale(LC_ALL, "Portuguese_Brasil");
    printf("Nome: Lucas Ferreira Pereira\n");
    do{
        printf("--------------------------\n");
        printf("***Lista Sequencial***\n");
        printf("1 - Inserir valor;\n");
        printf("2 - Deletar valor;\n");
        printf("3 - Pesquisar valor;\n");
        printf("4 - Mostrar toda lista;\n");
        printf("0 - Sair\n");
        printf("Digitar sua escolha: ");
        scanf("%d", &escolha);
        fflush(stdin);//"limpa o teclado"
        switch (escolha){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(vetor, valor, tam, pn);
            break;

            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                remover(vetor, valor, tam, pn);
            break;

            case 3:
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &valor);
                pesquisar(vetor, valor, n);
            break;

            case 4:
                /*for(int i = 0; i < n; i++){
                    printf("Item na posicao %d: %c\n", i, vetor[i]);
                }*/
                imprimir(vetor, n);
                //printf("Valor incluso: %c", vetor[n]);
            break;

            case 0:
                printf("Saindo...");
                loop = 1;
            break;
        }
    }while(loop == 0);
    return 0;
}
