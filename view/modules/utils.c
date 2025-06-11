#include "func_estoque.h"
#include "prototype_print.h"
#include "utils.h"

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");  // Linux/MacOS
    #endif
}

void limparBuffer(){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void pequenaPausa(){
    printf("\nPressione ENTER para continuar...");
    
    int key;
    do {
        key = getchar();
    } while (key != '\n' && key != EOF);

    limparBuffer();
}

int lerOpcaoMenu(){
    char input[100];
    int opcao;
    
    while(1){
        printf("Escolha uma opcao: ");
        if (fgets(input, sizeof(input), stdin) == NULL){
            printf("Erro na leitura. Tente novamente.\n");
            continue;
        }
        
        if (sscanf(input, "%d", &opcao) != 1){
            printf("Entrada invalida! Digite apenas numeros de 0 a 5.\n");
            pequenaPausa();
            limparTela();
            printMenuPrincipal();
            continue;
        }
        
        if (opcao < 0 || opcao > 5){
            printf("Opcao invalida! Digite um numero entre 0 e 5.\n");
            pequenaPausa();
            limparTela();
            printMenuPrincipal();
            continue;
        }
        
        return opcao;
    }
}

int validarNome(const char *nome){
    for (int i = 0; nome[i] != '\0'; i++){
        if (!isalpha(nome[i]) && nome[i] != ' '){
            return 0;
        }
    }
    return 1;
}