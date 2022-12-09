#ifndef LISTA_H
#define LISTA_H

typedef struct TipoItem
{
    int id;
    char nome[30];
} TipoItem;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento
{ // Célula
    TipoItem item;
    Apontador prox;
    Apontador ant;
} TipoElemento;

typedef struct TipoLista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
} TipoLista;

void CriaListaVazia(TipoLista *lista);
bool VerificaListaVazia(TipoLista *lista);
void InsereListaPrimeiro(TipoLista *lista, TipoItem *item);
void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id);
void InsereListaUltimo(TipoLista *lista, TipoItem *item);
void ImprimeLista(TipoLista lista);
int PesquisaItem(TipoLista *lista, int chave);
void ImprimeItem(TipoLista *lista, int id);
void RemoveListaPrimeiro(TipoLista *lista);
void RemoveListaUltimo(TipoLista *lista);
void RemoveItemPorId(TipoLista *lista, int id);
int TamanhoLista(TipoLista *lista);
void insereLista(TipoLista *lista);
void concatenarLista(TipoLista *lista1, TipoLista *lista2, TipoLista *lista3);
void DividirEmDois(TipoLista *lista3, TipoLista *lista4, TipoLista *lista5);
void ordenarLista(TipoLista *lista);
void intercalarLista(TipoLista *lista1, TipoLista *lista2, TipoLista * lista6);
void InverteLista(TipoLista *lista, TipoLista *lista7);

#endif