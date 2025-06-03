#include <stdio.h>
#include "../view/modules/func_estoque.h"
#include "../view/modules/prototype_print.h"
#include "../view/modules/utils.h"

#define MAX_ITENS 100

int main(){
    Item estoque[MAX_ITENS];
    int tamanho = 0;
    int opcao;

    do {
        printMenuPrincipal();
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                cadastrarItem(estoque, &tamanho); 
                break;
            case 2:
                listarItens(estoque, tamanho);
                break;
            case 3:
                editarItem(estoque, tamanho);
                break;
            case 4: 
                buscarItem(estoque, tamanho);
                break;
            case 5:
                removerItem(estoque, &tamanho);
                break;
            case 0:
                printf("Saindo...\n"); 
                break;
            default: 
                printf("Opção invalida.\n");
        }

    } while(opcao != 0);

    return 0;
}