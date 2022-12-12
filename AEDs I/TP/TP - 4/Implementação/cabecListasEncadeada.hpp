#ifndef LISTA_E
#define LISTA_E

#include <iostream>
#include <string.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

//Duplamente encadeada
typedef struct TipoItemD{
    int id;
    string nome;
    string saida;
    double valor_passagem;
}TipoLinha;

typedef struct ElementoL* ApontadorL;
typedef struct ElementoL{
    ApontadorL ant; 
    ApontadorL prox;
    TipoItemD item;
}ElementoL;

typedef struct TipoListaD{
    ApontadorL primeiro;
    ApontadorL ultimo;
    int tamanho = 0;
}TipoListaRota;

void criaListaVaziaD(TipoListaRota *lista);
bool listaVaziaD(TipoListaRota *lista);
void insereItemUltimoD(TipoListaRota *lista, TipoLinha item);
void insereItemPrimeiroD(TipoListaRota *lista, TipoLinha item);
ApontadorL localizaItemPorIdD(TipoListaRota *lista ,int id);
void insereItemAposElementoD(TipoListaRota *lista, TipoLinha item, int id);
TipoLinha retiraItemPorIdD(TipoListaRota *lista, int id);
void imprimeItemD(TipoLinha item);
void imprimeListaD(TipoListaRota *lista);
void imprimeListaReversaD(TipoListaRota *lista);

//Encadeada
typedef struct TipoItem{
    string id;
    TipoListaD cidades;
    string companhia;
}TipoRota;

typedef struct Elemento* Apontador;
typedef struct Elemento{
    TipoItem item;
    struct Elemento* prox;
}Elemento;

typedef struct TipoLista{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
}TipoListaLinha;

void CriaListaVazia(TipoListaLinha *lista);
bool verificaListaVazia(TipoListaLinha lista);
void atualizaUltimo(TipoListaLinha *lista);
void insereListaPrimeiro(TipoListaLinha *lista, TipoRota *item);
void insereListaUltimo(TipoListaLinha *lista, TipoRota *item);
void insereListaAposElemento(TipoListaLinha *lista, TipoRota *item, string id);
void imprimeLista(TipoListaLinha *lista);
string pesquisaItem(TipoListaLinha *lista, string id);
void imprimeItem(TipoListaLinha *lista, string id);
void removeListaPrimeiro(TipoListaLinha *lista);
void removeListaUltimo(TipoListaLinha *lista);
void removeItemPorId(TipoListaLinha *lista, string id);

#endif