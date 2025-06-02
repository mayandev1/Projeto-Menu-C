#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct Item{
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Item;

void cadastrarItem(Item *item);
void editarItem(Item *item);
void removerItem(Item *item);
void listarItens(Item *item);

#endif