#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "manut.h"

#define tam 5

typedef struct Nodo nodo;

Produto produto;
char *auxChar[20];
nodo *L;

int vetor[tam], valor;
int n = 0, escolha, loop = 0, aux = 0;
int *pn = &n;


int main(void) {
    setlocale(LC_ALL, "Portuguese_Brasil");
    printf("Nome: Lucas Ferreira Pereira\n");
    L = (nodo *) malloc(sizeof(nodo));
    iniciar(L);
    do{
        printf("--------------------------\n");
        printf("***Lista Sequencial***\n");
        printf("1 - Inserir novo item no inicio;\n");
        printf("2 - Deletar item;\n");
        printf("3 - Pesquisar item;\n");
        printf("4 - Mostrar toda lista;\n");
        printf("0 - Sair\n");
        printf("Digitar sua escolha: ");
        scanf("%d", &escolha);
        fflush(stdin);//"limpa o teclado"
        switch (escolha){
            case 1:
                printf("Digite o novo codigo de barras: ");
                scanf("%s", L->dado.codigoBarras);
                fflush(stdin);//"limpa o teclado"
                printf("Digite a descricao do produto: ");
                scanf("%s", L->dado.descricao);
                do{
                    aux = 0;
                    printf("Escolha a categoria do produto:\n");
                    printf("1 - Limpeza;\n");
                    printf("2 - Alimentos;\n");
                    printf("3 - Diversos;\n");
                    scanf("%d", &L->dado.categoria);
                    if(L->dado.categoria != 1 && L->dado.categoria != 2 && L->dado.categoria != 3){
                        printf("Opcao errada, digite novamente!\n");
                    }else{
                        aux = 1;
                    }
                }while(aux == 0);
                printf("Digite o preco do produto: ");
                scanf("%f", &L->dado.preco);
                inserirInicio(L, L);
            break;

            case 2:
                printf("Digite a descricao do item a ser excluido: ");
                scanf("%s", auxChar);
                fflush(stdin);//"limpa o teclado"
                excluirItem(L, auxChar);
            break;

            case 3:
                printf("Digite a descricao do item a ser pesquisado: ");
                scanf("%s", auxChar);
                fflush(stdin);//"limpa o teclado"
                pesquisarItem(L, auxChar);
            break;

            case 4:
                imprimir(L);
            break;

            case 0:
                printf("Saindo...");
                loop = 1;
            break;
        }
    }while(loop == 0);
    return 0;
}
