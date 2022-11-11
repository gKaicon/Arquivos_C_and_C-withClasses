#ifndef LISTA_H
#define LISTA_H


typedef struct TipoItem{
    char placa[7];
    time_t dataInicial;
    time_t dataFinal;
    double precoCobrado;
    int situacao; //1 = tá no estacionamento, 0 = não está no estacionamento
} TipoItem;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento{
    TipoItem item;
    struct TipoElemento* prox;
} TipoElemento;

typedef struct TipoLista{
    Apontador Primeiro;
    Apontador Ultimo;
    int tamanho;
} TipoLista;

bool listaCriada = false;

void CriaListaVazia(TipoLista *lista); //cria uma lista vazia
int VerificaListaVazia(TipoLista *lista); // verifica a existência de uma lista vazia
void InsereListaPrimeiro(TipoLista *lista, TipoItem *item); //inserção na primeira posição da lista
void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id); //inserção após um elemento especificado
void InsereListaUltimo(TipoLista *lista, TipoItem *item); //inserção na última posição da lista
void AtualizaUltimo(TipoLista *lista); //"salva a alteração feita"
void ImprimeLista(TipoLista lista); //imprime a lista
int PesquisaItem(TipoLista *lista, int chave); //pesquisa apenas o item
void ImprimeItem(TipoLista *lista, int id); //imprime um item específico
void RemoveListaPrimeiro(TipoLista *lista); //remove o primeiro da lista
void RemoveListaUltimo(TipoLista *lista); //remove o último da lista
void RemoveItemPorId(TipoLista *lista, int id); //remove pelo id específicado
int TamanhoLista(TipoLista *lista); // tamanho da lista

#endif