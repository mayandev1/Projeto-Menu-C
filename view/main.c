#include <stdio.h>
#include "../view/modules/func_estoque.h"
#include "../view/modules/prototype_print.h"
#include "../view/modules/utils.h"

#define MAX_ITENS 100

int main(){
    Item estoque[MAX_ITENS];
    int tamanho = 0;
    int opcao;

    do{
        printf("==== MENU ESTOQUE ====\n");
        printf("1. Cadastrar Item\n");
        printf("2. Listar Itens\n");
        printf("3. Editar Item\n");
        printf("4. Remover Item\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: cadastrarItem(estoque, *tamanho); break;
            case 2: listarItens(estoque, tamanho); break;
            case 3: editarItem(estoque, tamanho); break;
            case 4: removerItem(estoque, *tamanho); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while(opcao != 0);

    return 0;
}