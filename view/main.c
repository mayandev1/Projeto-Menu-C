#include <stdio.h>
#include "modules/func_estoque.h"
#include "modules/utils.h"
#include "modules/prototype_print.h"

#define MAX_ITENS 100

int main(){
    Item estoque[MAX_ITENS];
    int tamanho = 0;
    int opcao;
    char caminhoArquivo[100];

    do {
        limparTela();
        printMenuPrincipal();
        opcao = lerOpcaoMenu();
        limparTela();

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
            case 6:
                printf("Digite o caminho do arquivo para carregar (ex: estoque.txt): ");
                fgets(caminhoArquivo, sizeof(caminhoArquivo), stdin);
                caminhoArquivo[strcspn(caminhoArquivo, "\n")] = '\0';
                tamanho = carregarEstoqueDeArquivo(estoque, caminhoArquivo);
                pequenaPausa();
                break;
            case 7:
                printf("Digite o caminho do arquivo para salvar (ex: estoque.txt): ");
                fgets(caminhoArquivo, sizeof(caminhoArquivo), stdin);
                caminhoArquivo[strcspn(caminhoArquivo, "\n")] = '\0';
                salvarEstoqueEmArquivo(estoque, tamanho, caminhoArquivo);
                pequenaPausa();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default: 
                printf("Opcao invalida.\n");
                pequenaPausa();
        }

    } while(opcao != 0);

    return 0;
}