#include <iostream>
#include <windows.h>
#include "lista.hpp"
 
using namespace std;


void menu(){
        cout << "TAD Lista com Vetor \n";
        cout << "1. Criar Lista\n";
        cout << "2. Verifica Lista Vazia\n";
        cout << "3. Verifica Lista Cheia\n";
        cout << "4. Insere Item\n";
        cout << "5. Imprime Lista\n";
        cout << "6. Pesquisa Item\n";
        cout << "7. Retira Item\n";
        cout << "0. Sair\n\n";
}

void CriaListaVazia(TipoLista *lista){
    if (!listaCriada){ //se não está criada, ele cria
        lista->Primeiro = new TipoElemento;
        lista->Ultimo = lista->Primeiro;
        lista->Ultimo->prox = NULL;
        cout << "Lista criada com sucesso!";
        listaCriada = true;
    }
    else{
        cout << "Lista já existe!";
    }
    Sleep(1500);//comando de espera em milisegundos
}

int VerificaListaVazia(TipoLista *lista){
    return (lista->Primeiro == lista->Ultimo);
}
/*
int VerificaListaCheia(TipoLista *lista){
    return (lista->Primeiro == lista->Ultimo);
}
*/
int TamanhoLista(TipoLista *lista){
    return lista->tamanho;
}

void AtualizaUltimo(TipoLista *lista){
    Apontador aux;
    aux = lista->Primeiro->prox;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    lista->Ultimo = aux;
}

int InsereListaPrimeiro(TipoLista *lista, TipoItem *item){ //primeira inserção já tendo a lista criada
    Apontador aux;
    aux = lista->Primeiro->prox;
    lista->Primeiro->prox = new TipoElemento;
    lista->Primeiro->prox->prox = aux;
    lista->Primeiro->prox->item = *item;
    lista->tamanho++;
    AtualizaUltimo(lista);
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item){ //insere sempre após o ultimo
    lista->Ultimo->prox = new TipoElemento;
    lista->Ultimo = lista->Ultimo->prox;
    lista->Ultimo->prox = NULL;
    lista->Ultimo->item = *item;
    lista->Ultimo->prox = NULL;
    lista->tamanho++;
}

//insere em qualquer lugar

void ImprimeLista(TipoLista lista){ //lista toda
    if(VerificaListaVazia(&lista)){
        cout << "Lista Vazia";
        Sleep(1000);
        return ;
    }
    Apontador aux;
    aux = lista.Primeiro->prox; 
    while(aux != NULL){
        cout << "ID: " << aux->item.chave << endl;
        cout << "Nome: " << aux->item.nome << endl;
        aux = aux->prox;
    }
}

void ImprimeItem(TipoLista *lista, int chave){
    Apontador aux;
    aux = lista->Primeiro->prox;
    while (aux != NULL){
        if (aux->item.chave == chave){
            cout << "ID: " << aux->item.chave << endl;
            cout << "Nome: " << aux->item.nome << endl;
            break;
        }
        aux = aux->prox;
    }
}

int PesquisaItem(TipoLista *lista, int chave){
    Apontador aux;
    aux = lista->Primeiro->prox;
    while (aux != NULL){
        if (aux->item.chave == chave)return aux->item.chave;
        aux = aux->prox;
    }
    return -1;
}

void RemoveListaPrimeiro(TipoLista *lista){
    if (VerificaListaVazia(lista)) return;

    Apontador aux;
    aux = lista->Primeiro->prox;
    lista->Primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(TipoLista *lista){
    if (VerificaListaVazia(lista)) return;

    Apontador aux, atual;
    atual = lista->Primeiro->prox;
    aux = lista->Ultimo;
    while (atual->prox != lista->Ultimo)
    {
        atual = atual->prox;
    }
    atual->prox = NULL;
    lista->Ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(TipoLista *lista, int id){
    if (VerificaListaVazia(lista))  return;

    Apontador aux, anterior, x;

    x = lista->Primeiro;

    while (x != NULL)
    {
        if (x->prox->item.id == id)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}
