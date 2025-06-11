#include <windows.h>
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
    int input_valido;

    do {
        id_duplicado = 0;
        input_valido = 1;  

        printf("ID (0-9999): ");
        
        if (scanf("%d", &novo.id) != 1){
            printf("ID INVALIDO! DIGITE UM NUMERO INTEIRO.\n");
            limparBuffer();
            input_valido = 0;
            continue;
        }
        limparBuffer();  
        
        if (novo.id < 0 || novo.id > 9999){
            printf("ID deve estar entre 0 e 9999!\n");
            input_valido = 0;
            continue;
        }
        
        for (int i = 0; i < *tamanho; i++){
            if (itens[i].id == novo.id){
                printf("ERRO: ID %d JA CADASTRADO, DIGITE OUTRO!\n", novo.id);
                id_duplicado = 1;
                input_valido = 0;
                break;
            }
        }

    } while (id_duplicado || !input_valido);

    printf("Nome: ");
    do {
        fgets(novo.nome, sizeof(novo.nome), stdin);
        novo.nome[strcspn(novo.nome, "\n")] = '\0';
        
        if (!validarNome(novo.nome)) {
            printf("Nome deve conter apenas letras e espacos.\n");
            printf("Digite novamente: ");
        }
    } while (!validarNome(novo.nome));

    do {
        printf("Quantidade: ");
        if (scanf("%d", &novo.quantidade) != 1){
            printf("QUANTIDADE INVALIDA! DIGITE UM NUMERO INTEIRO.\n");
            limparBuffer();
            input_valido = 0;
        } else {
            input_valido = 1;
        }
    } while (!input_valido);
    limparBuffer();

    do {
        printf("Preco: ");
        if (scanf("%f", &novo.preco) != 1){
            printf("PRECO INVALIDO! DIGITE UM NUMERO.\n");
            limparBuffer();
            input_valido = 0;
        } else {
            input_valido = 1;
        }
    } while (!input_valido);

    itens[*tamanho] = novo;
    (*tamanho)++;

    limparTela();
    printf("Item adicionado com sucesso!\n");
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
    
    int id, input_valido;
    
    do {
        input_valido = 1;
        printf("Digite o ID do item para editar: ");
        
        if (scanf("%d", &id) != 1){
            printf("ID INVALIDO! DIGITE UM NUMERO!\n");
            limparBuffer();
            input_valido = 0;
            continue;
        }
        limparBuffer();

        limparTela();
        for (int i = 0; i <= 3; i++){
            printf("BUSCANDO");
            for (int j = 0; j < i; j++){
                printf(".");
            }
            Sleep(650);
            limparTela();
        }

        int encontrado = 0;
        for (int i = 0; i < tamanho; i++){
            if (itens[i].id == id){
                encontrado = 1;
                printf("Editando item ID: %d | Nome atual: %s\n", id, itens[i].nome);

                printf("Novo Nome: ");
                do {
                    fgets(itens[i].nome, sizeof(itens[i].nome), stdin);
                    itens[i].nome[strcspn(itens[i].nome, "\n")] = '\0';
                    
                    if (!validarNome(itens[i].nome)){
                        printf("Nome deve conter apenas letras e espacos.\n");
                        printf("Digite novamente: ");
                    }
                } while (!validarNome(itens[i].nome));
                
                do {
                    printf("Nova Quantidade: ");
                    if (scanf("%d", &itens[i].quantidade) != 1){
                        printf("VALOR INVALIDO! DIGITE UM NUMERO.\n");
                        limparBuffer();
                        input_valido = 0;
                    } else if (itens[i].quantidade < 0){
                        printf("QUANTIDADE NAO PODE SER NEGATIVA!\n");
                        input_valido = 0;
                    } else {
                        input_valido = 1;
                    }
                } while (!input_valido);
                
                do {
                    printf("Novo preco: ");
                    if (scanf("%f", &itens[i].preco) != 1){
                        printf("VALOR INVALIDO! DIGITE UM NUMERO.\n");
                        limparBuffer();
                        input_valido = 0;
                    } else if (itens[i].preco <= 0){
                        printf("PRECO DEVE SER MAIOR QUE ZERO!\n");
                        input_valido = 0;
                    } else {
                        input_valido = 1;
                    }
                } while (!input_valido);
                
                printf("EDICAO CONCLUIDA COM SUCESSO!\n");
                pequenaPausa();
                return;
            }
        }
        
        if (!encontrado){
            printf("ITEM COM ID %d NAO FOI ENCONTRADO!\n", id);
            pequenaPausa();
            return;
        }

    } while (!input_valido);
}

void removerItem(Item *itens, int *tamanho){
    if (*tamanho == 0){
        printf("ERRO: NENHUM ITEM CADASTRADO PARA REMOVER!\n");
        pequenaPausa();
        return;
    }
    
    int id, found = 0, input_valido;

    do {
        input_valido = 1;
        printf("Digite o id do item que deseja remover: ");
        
        if (scanf("%d", &id) != 1){
            printf("ID INVALIDO! DIGITE UM NUMERO!\n");
            limparBuffer();
            input_valido = 0;
            continue;
        }
        limparBuffer();

        limparTela();
        for (int i = 0; i <= 3; i++){
            printf("BUSCANDO");
            for (int j = 0; j < i; j++){
                printf(".");
            }
            Sleep(650);
            limparTela();
        }

        for (int i = 0; i < *tamanho; i++){
            if (id == itens[i].id){
                found = 1;
                for (int j = i; j < *tamanho - 1; j++){
                    itens[j] = itens[j + 1];
                }
                (*tamanho)--;
                
                limparTela();
                printf("PRODUTO REMOVIDO COM SUCESSO!\n");
                pequenaPausa();
                return;
            }
        }
        
        if (!found) {
            limparTela();
            printf("ID %d NAO FOI ENCONTRADO...\n", id);
            pequenaPausa();
            return;
        }

    } while (!input_valido);
}

void buscarItem(Item *itens, int tamanho){
    if (tamanho == 0){
        limparTela();
        printf("ERRO: NENHUM ITEM CADASTRADO PARA BUSCAR!\n");
        pequenaPausa();
        return;
    }
    
    int id, found = 0, input_valido;

    do {
        input_valido = 1;
        printf("Digite o id do item que deseja buscar: ");
        
        if (scanf("%d", &id) != 1){
            printf("ID INVALIDO! DIGITE UM NUMERO!\n");
            limparBuffer();
            input_valido = 0;
            continue;
        }
        limparBuffer();

        limparTela();
        for (int i = 0; i <= 3; i++){
            printf("BUSCANDO");
            for (int j = 0; j < i; j++){
                printf(".");
            }
            Sleep(650);
            limparTela();
        }

        for (int i = 0; i < tamanho; i++){
            if (itens[i].id == id){
                found = 1;
                limparTela();
                printf("Item encontrado:\n");
                printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f |\n", itens[i].id, itens[i].nome, itens[i].quantidade, itens[i].preco);
                pequenaPausa();
                return;
            }   
        }
        
        if (!found){
            printf("ID %d NAO ENCONTRADO...\n", id);
            pequenaPausa();
            return;
        }

    } while (!input_valido);
}