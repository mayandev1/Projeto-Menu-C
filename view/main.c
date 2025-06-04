#include <stdio.h>
#include "modules/func_estoque.h"
#include "modules/utils.h"
#include "modules/prototype_print.h"

#define MAX_ITENS 100

int main(){
    Item estoque[MAX_ITENS];
    int tamanho = 0;
    int opcao;

    do {
        printMenuPrincipal();
        scanf("%d", &opcao);
        limparTela();

        switch(opcao){
            case 1: 
                cadastrarItem(estoque, &tamanho);
                pequenaPausa(); 
                limparTela();
                break;
            case 2:
                listarItens(estoque, tamanho);
                pequenaPausa();
                limparTela();
                break;
            case 3:
                editarItem(estoque, tamanho);
                pequenaPausa();
                limparTela();
                break;
            case 4: 
                buscarItem(estoque, tamanho);
                pequenaPausa();
                limparTela();
                break;
            case 5:
                removerItem(estoque, &tamanho);
                pequenaPausa();
                limparTela();
                break;
            case 0:
                printf("Saindo...\n"); 
                break;
            default: 
                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);

    return 0;
}