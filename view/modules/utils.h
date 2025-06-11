#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void limparBuffer();
void limparTela();
void pequenaPausa();
int lerOpcaoMenu(void);
int validarNome(const char *nome);

#endif