#include <stdio.h>
#include "utils.h"

void limparTela(){
    system("cls");
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}