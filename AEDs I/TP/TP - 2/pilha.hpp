#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <windows.h>
#define MAXTAM 10
#define MAX_ENTREGA 7

using namespace std;


typedef struct Pedido {
    int id;
    int produtos[MAXTAM];
    double valor_Pedido;
    double distancia;
};

typedef struct Pilha {
    Pedido itens[MAXTAM];
    int topo;
};

void FazPilhaVazia(Pilha *pilha);
bool VerificaPilhaVazia(Pilha *pilha);
bool VerificaPilhaCheia(Pilha *pilha);
void Empilha(Pilha *pilha, Pedido item);
void ExibePilha(Pilha *pilha);
void Desempilha(Pilha *pilha, Pedido *item);
int Tamanho(Pilha *pilha);

#endif