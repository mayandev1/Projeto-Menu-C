#ifndef FUNC_ESTOQUE_H
#define FUNC_ESTOQUE_H
#include "utils.h"

typedef struct Item{
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Item;

void cadastrarItem(Item *itens, int *tamanho);
void editarItem(Item *itens, int tamanho);
void removerItem(Item *itens, int *tamanho);
void listarItens(Item *itens, int tamanho);
void buscarItem(Item *itens, int tamanho);

#endif