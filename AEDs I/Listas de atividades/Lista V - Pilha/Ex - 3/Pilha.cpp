#include <iostream>
#include "Pilha.hpp"

using namespace std;

void FazPilhaVazia(TipoPilha *pilha) {
   pilha->topo = 0;
}

bool VerificaPilhaVazia(TipoPilha *pilha) {
    if (pilha->topo == 0) return true;
    return false;
}

bool VerificaPilhaCheia(TipoPilha *pilha) {
    if (pilha->topo == MAXTAM) return true;
    return false;
}

void Empilha(TipoPilha *pilha, TipoItem item) {
    if (VerificaPilhaCheia(pilha)) {
        cout << "\nPilha cheia\n";
        return;
    } 
    
    pilha->itens[pilha->topo] = item;
    pilha->topo++;
    //cout << "\nItem empilhado com sucesso!\n";
}

void ExibePilha(TipoPilha *pilha) { 
    for (int i=pilha->topo-1; i>=0; i--) {
        cout << "Id: " << pilha->itens[i].id << "\n";
        cout << "\tNome: " << pilha->itens[i].titulo << "\n";
        cout << "\tAutor: " << pilha->itens[i].autor << "\n";
        cout << "\tISBN: " << pilha->itens[i].ISBN << "\n";
        cout << "\tNúmero de Páginas: " << pilha->itens[i].numPG << "\n";
        cout << "\tAno de Lançamento: " << pilha->itens[i].anoLanc << "\n";
    }
}

void Desempilha(TipoPilha *pilha, TipoItem *item) {
    if (VerificaPilhaVazia(pilha)) {
        cout << "\nPilha vazia.\n";
        return;
    }

    pilha->topo--;
    *item = pilha->itens[pilha->topo];
}

int Tamanho(TipoPilha *pilha) {
    return pilha->topo;
}