#ifndef FUNCOES_H
#define FUNCOES_H
#include "funcoes.cpp"

void ImprimeJogo(char* jogo[3][3]);
void ImprimeJogoCoo(char* jogo[3][3]);
boolean vitoriaLinha(char* jogo[3][3]);
boolean vitoriaColuna(char*  jogo[3][3]);
boolean diagonalPrincipal(char* jogo[3][3]);
boolean diagonalSecundaria(char* jogo[3][3]);

#endif