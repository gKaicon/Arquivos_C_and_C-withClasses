#include <iostream>
#include <string.h>
#include <windows.h>
#include "listasEncadeada.hpp"

#define MAXTAM 5

using namespace std;

void CriaListaVazia(TipoLista *lista){
    if (!listaCriada){
        lista->primeiro = new TipoElemento;
        lista->ultimo = lista->primeiro;
        lista->ultimo->prox = NULL;
        listaCriada = true;
    }
    else cout << "Lista já existe!";
    Sleep(1500);
}

bool VerificaListaVazia(TipoLista *lista){
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(TipoLista *lista){
    return lista->tamanho;
}

void AtualizaUltimo(TipoLista *lista){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    lista->ultimo = aux;
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item){
    lista->ultimo->prox = new TipoElemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
    id++;
    AtualizaUltimo(lista);
}

void ImprimeLista(TipoLista lista){
    if (VerificaListaVazia(&lista)){
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL){
        cout << "ID: " << aux->item.id << endl;
        cout << "Companhia: " << aux->item.companhia << endl;
        cout << "Parada: " << aux->item.paradas.Nomeparada << endl;
        aux = aux->prox;
    }
    system("pause");
}

bool PesquisaItem(TipoLista *lista, char nome[]){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (strcmp(aux->item.paradas.Nomeparada, nome) == 0) return true;
        aux = aux->prox;
    }
    return false;
}

bool PesquisaItemPorId(TipoLista *lista, int id){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id) return true;
        aux = aux->prox;
    }
    return false;
}

int Atualiza(TipoLista *lista, TipoItem item, char valor[], int campo){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (strcmp(aux->item.companhia, item.companhia) == 0){
            if (campo == 1){
                strcpy(aux->item.companhia, valor);
                return 1;
            }
        }
        aux = aux->prox;
    }
    return 0;
}

/*
int AtualizaParada(TipoLista *lista, TipoItem item, char parada[40]){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (strcmp(aux->item.companhia, item.companhia) == 0){
            //     aux->item.paradas.Nomeparada = parada[40];

            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}
*/


void ImprimeItem(TipoLista *lista, char nome[]){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (strcmp(aux->item.paradas.Nomeparada, nome) == 0){
            // cout << "Nome: " << aux->item.nome << endl;
            cout << "ID: " << aux->item.id << endl;
            cout << "Companhia: " << aux->item.companhia << endl;
            cout << "Quantidade de Cidades na rota: " << aux->item.quantCidades << endl;
            cout << "Nome Cidade: " << aux->item.paradas.Nomeparada << endl;
            //cout << "Hora chegada: " << aux->item.paradas.hora_chegada << endl;
            //cout << "Hora saida: " << aux->item.paradas.hora_saida << endl;
            cout << "Valor Passagem: " << aux->item.paradas.valorPassagem << endl;
            break;
        }
        aux = aux->prox;
    }
}
void ImprimePassagem(TipoLista *lista, char origem[], char destino[]){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        cout << "Nome Compania: " << aux->item.companhia;
        if (aux->item.paradas.Nomeparada == origem){
            cout << aux->item.id << "-" << aux->item.paradas.Nomeparada;
            break;
        }
        if (aux->item.paradas.Nomeparada == destino){
            cout << "-" << aux->item.paradas.Nomeparada << "\n";
            cout << "Parada: " << aux->item.paradas.Nomeparada
                 << endl;
            break;
        }
        aux = aux->prox;
    }
}

void ImprimeItemPorId(TipoLista *lista, int id)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item.id == id)
        {
            cout << "Nome: " << aux->item.companhia << endl;
            cout << "Parada: " << aux->item.paradas.Nomeparada
                 << endl;
            break;
        }
        aux = aux->prox;
    }
}

void RemoveItemPorId(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        return;
    }

    Apontador aux, anterior, x;

    aux = lista->primeiro->prox;

    x = lista->primeiro;

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

//_----------------------------------------------------------------------------------------------------------------

using namespace std;

void LECCriaListaVazia(TipoListaEC *lista)
{
    lista->primeiro = new TipoElementoEC;
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
}

bool LECVerificaListaVazia(TipoListaEC *lista)
{
    return (lista->primeiro == lista->ultimo);
}

void LECInsereListaPrimeiro(TipoListaEC *lista, TipoLinha *item)
{
    ApontadorEC aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = new TipoElementoEC;
    lista->primeiro->prox->prox = aux;
    lista->primeiro->prox->item = *item;
    aux->ant = lista->primeiro->prox;
    lista->primeiro->prox->ant = lista->primeiro;
    lista->ultimo->prox = lista->primeiro;//circular
    lista->ultimo->prox->ant = lista->ultimo->prox;//circular
}

void LECInsereListaAposElemento(TipoListaEC *lista, TipoLinha *item, int idEleX)
{
    ApontadorEC aux, x, itemAnterior;
    x = lista->primeiro; // Célula cabeça

    while (x->prox != NULL)
    {
        if (x->prox->item.idCidade == idEleX)
        {
            itemAnterior = x->prox;
            break;
        }
        x = x->prox;
    }

    aux = itemAnterior->prox;
    itemAnterior->prox = new TipoElementoEC;
    itemAnterior->prox->item = *item;
    itemAnterior->prox->prox = aux;
    aux->ant = itemAnterior->prox;
    aux->ant->ant = itemAnterior;
}

void LECInsereListaUltimo(TipoListaEC *lista, TipoLinha *item)
{
    ApontadorEC aux;
    aux = lista->ultimo;
    lista->ultimo->prox = new TipoElementoEC;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = *item;
    lista->ultimo->prox = NULL;
    lista->ultimo->ant = aux;
    lista->ultimo->prox = lista->primeiro;//circular
   lista->ultimo->prox->ant = lista->ultimo->prox;//circular
}

void LECRemoveListaPrimeiro(TipoListaEC *lista, TipoLinha *item)
{
    ApontadorEC aux;

    if (LECVerificaListaVazia(lista))
    {
        return;
    }
    *item = lista->primeiro->prox->item;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    lista->primeiro->prox->ant = lista->primeiro;
    free(aux);
}

void LECRemoveListaUltimo(TipoListaEC *lista, TipoLinha *item)
{
    ApontadorEC aux, anterior, x;

    if (LECVerificaListaVazia(lista))
    {
        return;
    }

    x = lista->primeiro;
    while (x != NULL)
    {
        if (x->prox == lista->ultimo)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }

    aux = lista->ultimo;
    lista->ultimo = anterior;
    *item = aux->item;
    lista->ultimo->prox = NULL;
    free(aux);
}

void LECRemoveElementoXbyId(TipoListaEC *lista, TipoLinha *item, int idEle)
{
    ApontadorEC aux, anterior, x;

    if (LECVerificaListaVazia(lista))
    {
        return;
    }

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.idCidade == idEle)
        {
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    *item = aux->item;
    free(aux);
}

bool LECPesquisaElementoXbyId(TipoListaEC *lista, TipoLinha *item, int idEle)
{
    ApontadorEC x;

    if (LECVerificaListaVazia(lista))
    {
        return false;
    }

    x = lista->primeiro;

    while (x != NULL)
    {
        if (x->prox->item.idCidade == idEle)
        {
            *item = x->prox->item;
            return true;
        }
        x = x->prox;
    }
    return false;
}

bool LECPesquisaElementoXbyNome(TipoListaEC *lista, TipoLinha *item, char nome[])
{
    ApontadorEC x;

    if (LECVerificaListaVazia(lista))
    {
        return false;
    }

    x = lista->primeiro;

    while (x != NULL)
    {
        if (strcmpi(x->prox->item.Nomeparada, nome) == 0)
        {
            *item = x->prox->item;
            return true;
        }
        x = x->prox;
    }
    return false;
}

void LECImprimeLista(TipoListaEC *lista)
{
    ApontadorEC x;

    x = lista->primeiro->prox;

    while (x != NULL)
    {
        cout << "Código: " << x->item.idCidade << endl;
        cout << "Nome Parada: " << x->item.Nomeparada << endl;
        //cout << "Hora Chegada: " << x->item.hora_chegada << endl;
        //cout << "Hora Saida: " << x->item.hora_saida << endl;
        cout << "Valor Passagem: " << x->item.valorPassagem << endl
             << endl;
        x = x->prox;
    }
}