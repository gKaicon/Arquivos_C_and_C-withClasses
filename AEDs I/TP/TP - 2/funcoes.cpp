
#include "Pilha.hpp"


void FazPilhaVazia(Pilha *pilha) {
   pilha->topo = 0;
}

bool VerificaPilhaVazia(Pilha *pilha) {
    if (pilha->topo == 0) return true;
    return false;
}

bool VerificaPilhaCheia(Pilha *pilha) {
    if (pilha->topo == MAXTAM) return true;
    return false;
}

void Empilha(Pilha *pilha, Pedido item) {
    if (VerificaPilhaCheia(pilha)) {
        cout << "\nPilha cheia\n";
        return;
    } 
    pilha->itens[pilha->topo] = item;
    pilha->topo++;

    cout << "\nItem empilhado com sucesso!\n";
}

void ExibePilha(Pilha *pilha) { 
    for (int i = pilha->topo-1; i>=0; i--) {
        cout << "Id: " << pilha->itens[i].id << "\n";
        for(int j = 0 ; j < MAXTAM; j++) cout << "\t Produto: " << pilha->itens[i].produtos[j] << "\n";
        cout << "\tValor do Pedido: R$ " << pilha->itens[i].valor_Pedido << "\n";
        cout << "\tDistância: " << pilha->itens[i].distancia << "\n";
    }
}

void Desempilha(Pilha *pilha, Pedido *item) {
    if (VerificaPilhaVazia(pilha)) {
        cout << "\nPilha vazia.\n";
        return;
    }

    pilha->topo--;
    *item = pilha->itens[pilha->topo];
}

int Tamanho(Pilha *pilha) {
    return pilha->topo;
}