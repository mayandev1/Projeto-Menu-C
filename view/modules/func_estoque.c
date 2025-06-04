#include <stdio.h>
#include <string.h>
#include <time.h>
#include "func_estoque.h"
#include "utils.h"

#define MAX_ITENS 100

void cadastrarItem(Item *itens, int *tamanho){
    
    if (*tamanho >= MAX_ITENS){
        printf("ERRO: ESTOQUE CHEIO!\n");
        pequenaPausa();
        return;
    }
    
    Item novo;
    int id_duplicado;

    do {

        id_duplicado = 0;

        printf("ID (0-9999): ");
        if (scanf("%d", &novo.id) != 1){
            printf("ID INVALIDO! DIGITE UM NUMERO.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();
    
        if (novo.id < 0 || novo.id > 9999){
            printf("ID deve estar entre 0 e 9999!\n");
            continue;   
        }
        
        for (int i = 0; i < *tamanho; i++){
            if (itens[i].id == novo.id){
                printf("ERRO: ID %d JA CADASTRADO, DIGITE OUTRO!\n", novo.id);
                id_duplicado = 1;
                break;
            }
        }

    } while (id_duplicado);
        
    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);  

    printf("Preco: ");
    scanf("%f", &novo.preco);

    itens[*tamanho] = novo;
    (*tamanho)++;

    limparTela();
    printf("\nItem adicionado com sucesso!\n");
    printf("ID: %d | Nome: %s\n", novo.id, novo.nome);
    pequenaPausa();
}

void listarItens(Item *itens, int tamanho){
    if (tamanho == 0){
        printf("ERRO: NENHUM ITEM CADASTRADO PARA LISTAR!\n");
        pequenaPausa();
        return;
    }

    printf("======== LISTA DE ITENS CADASTRADOS ========\n");
    for (int i = 0; i < tamanho; i++){
        printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f |\n", itens[i].id, itens[i].nome, itens[i].quantidade, itens[i].preco);
    }
    pequenaPausa();
}

void editarItem(Item *itens, int tamanho){

    if (tamanho == 0){
        printf("ERRO: NENHUM ITEM CADASTRADO PARA EDITAR!\n");
        pequenaPausa();
        return;
    }
    
    int id;
    printf("Digite o ID do item para editar: ");

    if (scanf("%d", &id) != 1){
        printf("ID INVALIDO! DIGITE UM NUMERO!\n");
        limparBuffer();
        pequenaPausa();
        return;
    }
    limparBuffer();

    for (int i = 0; i < tamanho; i++){
        if (itens[i].id == id){
            printf("\nEditando item ID: %d | Nome atual: %s\n", id, itens[i].nome);

            printf("Novo Nome: ");
            fgets(itens[i].nome, sizeof(itens[i].nome), stdin);
            itens[i].nome[strcspn(itens[i].nome, "\n")] = '\0';
            
            do {
                printf("Nova Quantidade: ");
                if (scanf("%d", &itens[i].quantidade) != 1){
                    printf("VALOR INVALIDO! DIGITE UM NUMERO.\n");
                    limparBuffer();
                    continue;
                }
                
            } while (itens[i].quantidade < 0);
            
            do {
                printf("Novo preco: ");
                if (scanf("%f", &itens[i].preco) != 1){
                    printf("VALOR INVALIDO! DIGITE UM NUMERO.\n");
                    limparBuffer();
                    continue;
               }
                
            } while (itens[i].preco <= 0);
            limparBuffer();
            
            printf("EDICAO CONCLUIDA COM SUCESSO!\n");
            pequenaPausa();
            return;
        }
    }
    
    printf("ITEM COM ID %d NAO FOI ENCONTRADO!\n", id);
    pequenaPausa();
}

void removerItem(Item *itens, int *tamanho){
    if (*tamanho == 0){
        printf("ERRO: NENHUM ITEM CADASTRADO PARA REMOVER!\n");
        pequenaPausa();
        return;
    }
    
    int id, found = 0;

    printf("Digite o id do item que deseja remover: ");
    scanf("%d", &id);
    for (int i = 0; i < *tamanho; i++){
        if (id == itens[i].id){
            found = 1;

            for (int j = i; j < *tamanho - 1; j++){
                itens[j] = itens[j - 1];
            }
            (*tamanho)++;
            
            limparTela();
            printf("PRODUTO REMOVIDO COM SUCESSO...\n");
            pequenaPausa();
            break;
        }
    }
    
    if (!found){
        limparTela();
        printf("ID %d NAO FOI ENCONTRADO..\n", id);
        pequenaPausa();

    }
}

void buscarItem(Item *itens, int tamanho){
    if (tamanho == 0){
        limparTela();
        printf("ERRO: NENHUM ITEM CADASTRADO PARA BUSCAR!\n");
        pequenaPausa();
        return;
    }
    
    int id, found = 0;
    
    printf("Digite o id do item que deseja buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < tamanho; i++){
        if (itens[i].id == id){
            found = 1;

            limparTela();
            printf("Item encontrado:\n");
            printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f |\n", itens[i].id, itens[i].nome, itens[i].quantidade, itens[i].preco);
            pequenaPausa();
        }   
    }
    
    if (!found){
        printf("ID %d NAO ENCONTRADO...\n", id);
        pequenaPausa();

    }
}