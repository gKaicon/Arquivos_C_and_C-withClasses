#ifndef LISTA_H
#define LISTA_H


typedef struct TipoItem{
    int chave;
    char nome[81];
} TipoItem;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento{
    TipoItem item;
    struct TipoElemento* prox;
} TipoElemento;

typedef struct TipoLista{
    Apontador Primeiro;
    Apontador Ultimo;//Apontador para?
    int tamanho;
} TipoLista;

bool listaCriada = false;



void CriaListaVazia(TipoLista *lista);                              // Cria uma lista vazia
int VerificaListaVazia(TipoLista *lista);                           // Retorna TRUE se a lista estiver vazia, FALSE caso contrário
int VerificaListaCheia(TipoLista *lista);                           // Retorna TRUE se a lista estiver cheia, FALSE caso contrário
int InsereItem(TipoLista *lista, TipoItem item);                    // Insere ITEM (chave) na lista TipoLista
//void ImprimeLista(TipoLista lista);                                 // Imprime a lista
//int PesquisaItem(TipoLista *lista, int chave);                      // Pesquisa um ITEM (chave) na lista TipoLista
//void RetiraItem(TipoApontador p, TipoLista *lista, TipoItem *item); // Remove um item da lista pela sua posição
//int TamanhoLista(TipoLista *lista);                                 // Retorna o número de itens da lista

#endif