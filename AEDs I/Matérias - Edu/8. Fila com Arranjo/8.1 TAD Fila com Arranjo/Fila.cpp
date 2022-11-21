#include <iostream>
#include "Fila.hpp"

using namespace std;

void FazFilaVazia(TipoFila *fila)
{
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFila *fila)
{
    if (fila->tamanho == 0)
        return true;

    return false;
}

bool VerificaFilaCheia(TipoFila *fila)
{
    if (fila->tamanho == MAXTAM)
        return true;

    return false;
}

void Enfileira(TipoFila *fila, TipoItem item)
{
    if (VerificaFilaCheia(fila))
    {
        cout << "\nFila Cheia.\n";
        return;
    }
    fila->fim++;
    fila->itens[fila->fim] = item;
    fila->tamanho++;
    cout << "Valor enfileirado: " << item.id << endl;
}

void Desenfileira(TipoFila *fila, TipoItem *item)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia.\n";
        return;
    }
    *item = fila->itens[fila->inicio];
    fila->inicio++;
    fila->tamanho--;
}

void ExibeFila(TipoFila *fila)
{
    if (VerificaFilaVazia(fila))
    {
        cout << "Fila vazia.\n";
        return;
    }

    cout << "Fila: ";
    for (int i = fila->inicio; i <= fila->fim; i++)
    {
        cout << fila->itens[i].id << " ";
    }
    cout << endl;
}

int Tamanho(TipoFila *fila)
{
    return fila->tamanho;
}