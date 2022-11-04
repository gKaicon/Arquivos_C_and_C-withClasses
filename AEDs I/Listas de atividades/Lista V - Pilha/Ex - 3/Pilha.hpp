#ifndef PILHA_H
#define PILHA_H

#define MAXTAM 20

typedef struct TipoItem {
    int id;
    char titulo[35];
    char autor[35];
    int ISBN;
    int numPG;
    int anoLanc;
} TipoItem;

typedef struct Pilha {
    TipoItem itens[MAXTAM];
    int topo;
} TipoPilha;

void FazPilhaVazia(TipoPilha *pilha);
bool VerificaPilhaVazia(TipoPilha *pilha);
bool VerificaPilhaCheia(TipoPilha *pilha);
void Empilha(TipoPilha *pilha, TipoItem item);
void Desempilha(TipoPilha *pilha, TipoItem *item);
void ExibePilha(TipoPilha *pilha);
int Tamanho(TipoPilha *pilha);

#endif