#include <iostream>
#include <windows.h>
#include "lista.hpp"

using namespace std;

void CriaListaVazia(TipoLista *lista)
{
    lista->primeiro = new TipoElemento; //insere um elemento na primeira posição, e esse elemento não tem nada
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
    lista->tamanho = 0;
    cout << "Lista criada com sucesso!";
    Sleep(1500);
}

bool VerificaListaVazia(TipoLista *lista)
{
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(TipoLista *lista)
{
    return lista->tamanho;
}

void InsereListaPrimeiro(TipoLista *lista, TipoItem *item)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    aux->prox = lista->primeiro->prox;
    aux->ant = lista->primeiro;
    lista->primeiro->prox = aux;
    if (lista->primeiro == lista->ultimo)
        lista->ultimo = aux;
    else
        aux->prox->ant = aux;
    lista->tamanho++;
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    aux->prox = NULL;
    aux->ant = lista->ultimo;
    lista->ultimo->prox = aux;
    lista->ultimo = aux;
    lista->tamanho++;
}

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    Apontador aux2 = lista->primeiro->prox;
    while (aux2->item.id != id)
    {
        aux2 = aux2->prox;
    }
    aux->prox = aux2->prox;
    aux->ant = aux2;
    aux2->prox = aux;
    if (aux->prox == NULL)
        lista->ultimo = aux;
    else
        aux->prox->ant = aux;
    lista->tamanho++;
}

void ImprimeLista(TipoLista lista)
{
    if (VerificaListaVazia(&lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;
        aux = aux->prox;
    }
    system("PAUSE");
}

int PesquisaItem(TipoLista *lista, int chave)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != chave){
        aux = aux->prox;
    }
    if (aux != NULL){
        return aux->item.id;
    }
    else{
        return -1;
    }
}

void RemoveListaPrimeiro(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    if (aux->prox != NULL)
    {
        aux->prox->ant = lista->primeiro;
    }
    else
    {
        lista->ultimo = lista->primeiro;
    }
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->ultimo;
    lista->ultimo = aux->ant;
    lista->ultimo->prox = NULL;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != id)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        aux->ant->prox = aux->prox;
        if (aux->prox != NULL)
        {
            aux->prox->ant = aux->ant;
        }
        else
        {
            lista->ultimo = aux->ant;
        }
        delete aux;
        lista->tamanho--;
    }
    else
    {
        cout << "Elemento não encontrado!";
        Sleep(1500);
    }
}

void ImprimeItem(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != id)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;
        Sleep(1500);
    }
    else
    {
        cout << "Elemento não encontrado!";
        Sleep(1500);
    }
}

void adicionaLista(TipoLista *lista, int codigo, char nome[30]){
    lista->primeiro->prox->item.id = codigo;
    strcpy(lista->primeiro->prox->item.nome, nome);
}

void insereLista(TipoLista *lista){
    adicionaLista(lista, 1, "João");
    adicionaLista(lista, 2, "Maria");
    adicionaLista(lista, 3, "Carlos");
    adicionaLista(lista, 4, "Eduardo");
    adicionaLista(lista, 5, "Gabriel");
    adicionaLista(lista, 6, "Marcelo");
    adicionaLista(lista, 7, "Amanda");
    adicionaLista(lista, 8, "Kaicon");
}

void concatenarLista(TipoLista *lista1, TipoLista *lista2, TipoLista *lista3){
    Apontador aux;
    TipoItem item;
    aux = lista1->primeiro->prox;
    while(aux->prox != NULL){
        item = aux->item;
        InsereListaUltimo(lista3, &item);
        aux = aux->prox;
    }
    aux = lista2->primeiro->prox;
    while(aux->prox != NULL){
        item = aux->item;
        InsereListaUltimo(lista3, &item);
        aux = aux->prox;
    }
}

void DividirEmDois(TipoLista *lista3, TipoLista *lista4, TipoLista *lista5){
    Apontador aux;
    TipoItem item;
    int tam = TamanhoLista(lista3);
    for(int i = 0; i < tam/2; i++){
        item = aux->item;
        InsereListaUltimo(lista4, &item);
        aux = aux->prox;
    }

    for(int i = tam/2; i < tam; i++){
        item = aux->item;
        InsereListaUltimo(lista5, &item);
        aux = aux->prox;
    }
}

void ordenarLista(TipoLista *lista){
    Apontador aux, aux2;
    TipoItem item;
    aux = lista->primeiro->prox;
    while(aux != NULL){
        aux2 = aux->prox;
        while(aux != NULL){
            if(aux->item.id > aux->item.id){
                item = aux->item;
                aux->item = aux2->item;
                aux2->item = item;
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }
}

void intercalarLista(TipoLista *lista1, TipoLista *lista2, TipoLista * lista6){
    Apontador aux1, aux2;
    TipoItem item;
    ordenarLista(lista1);
    ordenarLista(lista2);
    aux1 = lista1->primeiro->prox;
    aux2 = lista2->primeiro->prox;
    while(aux1 != NULL && aux2 != NULL){
        if(aux1->item.id < aux2->item.id){
            item = aux1->item;
            InsereListaUltimo(lista6, &item);
            aux1 = aux1->prox;
        }
        else{
            item = aux2->item;
            InsereListaUltimo(lista6, &item);
            aux2 = aux2->prox;
        }
    }
}

void InverteLista(TipoLista *lista, TipoLista *lista7){ //lista toda
    Apontador aux, ult;
    aux = lista->primeiro->prox; //pri recebe a primeira posição
    while (aux != NULL){ //enquanto o primeiro for diferente do ultimo
        InsereListaPrimeiro(lista7, &aux->item);
        aux = aux->prox; //irá percorrer a lista
    }
    Sleep(5000);
}