#include <stdio.h>
#include <string.h>
#include "func_estoque.h"
#include "utils.h"

void cadastrarItem(Item *itens, int *tamanho){
    Item novo;
    printf("ID: ");
    scanf("%d", &novo.id);
    limparBuffer();

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);  

    printf("Preco: ");
    scanf("%f", &novo.preco);

    itens[*tamanho] = novo;
    (*tamanho)++;

    printf("Item Adicionado!");
}

void listarItens(Item *itens, int tamanho){
    printf("======== LISTA DE ITENS CADASTRADOS ========\n");
    for (int i = 0; i < tamanho; i++){
        printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f |\n", itens[i].id, itens[i].nome, itens[i].quantidade, itens[i].preco);
    }
}

void editarItens(Item *itens, int tamanho){
    int id;
    printf("Digite o ID do item para editar: ");
    scanf("%d", &id);

    for (int i = 0; i < tamanho; i++){
        if (itens[i].id == id){
            printf("Novo Nome: ");
            fgets(itens[i].nome, sizeof(itens[i].nome), stdin);
            itens[i].nome[strcspn(itens[i].nome, "\n")] = '\0';
            limparBuffer();

            printf("Nova Quantidade: ");
            scanf("%d", &itens[i].quantidade);

            printf("Novo Preco: ");
            scanf("%f", &itens[i].quantidade);

            printf("EDICAO CONCLUIDA COM SUCESSO!\n");
            return;
        }
    }
    
    printf("ITEM COM ID %d NAO FOI ENCONTRADO!\n", id);
}

void removerItem(Item *itens, int *tamanho){
    int id, found = 0;

    printf("Digite o id do item que deseja remover: ");
    scanf("%d", &id);
    for (int i = 0; i < tamanho; i++){
        if (id == itens[i].id){
            found = 1;

            for (int j = i; j < *tamanho - 1; j++){
                itens[j] = itens[j - 1];
            }
            (*tamanho)++;

            printf("PRODUTO REMOVIDO COM SUCESSO...\n");
            break;
        }
    }
    
    if (!found){
        printf("ID %d NAO FOI ENCONTRADO..\n", id);
    }
}

void buscarItem(Item *itens, int tamanho){
    int id, found = 0;
    
    printf("Digite o id do item que deseja buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < tamanho; i++){
        if (itens[i].id == id){
            found = 1;

            printf("Item encontrado:\n");
            printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f |\n", itens[i].id, itens[i].nome, itens[i].quantidade, itens[i].preco);
            
        }   
    }
    
    if (!found){
        printf("ID %d NAO ENCONTRADO...\n", id);
    }
}