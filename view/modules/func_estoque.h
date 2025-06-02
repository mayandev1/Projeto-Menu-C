#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct Item{
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Item;

void cadastrarItem(Item *itens, int *tamanho);
void editarItens(Item *itens, int tamanho);
void removerItens(Item *itens, int *tamanho);
void listarItens(Item *itens, int tamanho);

#endif