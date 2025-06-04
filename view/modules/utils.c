#include <stdio.h>
#include <stdlib.h>
#include "func_estoque.h"
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
    
    limparBuffer();
    
    int key;
    do {
        key = getchar();
    } while (key != '\n' && key != EOF);
    
    limparBuffer();
}