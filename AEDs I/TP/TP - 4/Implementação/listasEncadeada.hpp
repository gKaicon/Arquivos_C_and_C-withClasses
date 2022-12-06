#ifndef LISTA_H
#define LISTA_H

typedef struct TipoLinha //usado na dup/enca circular
{
    unsigned int idCidade;  //idcidade
    char Nomeparada[40];    //nome cidade que parou
    tm hora_chegada;       //horario que chegou na cidade
    tm hora_saida;         //horario que saiu da cidade
    double valorPassagem;      //valor de uma parada para outra

} TipoLinha;

typedef struct TipoItem //usado na encadeada simples
{
    unsigned int id;    //numero linha de onibus
    char companhia[40]; //nome da compania de obinus
    int quantCidades;   //quantidade de cidades na linha
    TipoLinha paradas;  //cidades desta linha
} TipoItem;

typedef struct TipoElemento *Apontador;
typedef struct TipoElementoEC *ApontadorEC;

typedef struct TipoElemento //encadeado simples
{
    TipoItem item;
    Apontador prox; //apontar para o proximo
} TipoElemento;

typedef struct TipoElementoEC //duplamente encadeado circular
{
    TipoLinha item;
    ApontadorEC prox, ant; //apontar para o proximo e o anterior
} TipoElementoEC;

typedef struct TipoListaEC
{
    ApontadorEC primeiro;
    ApontadorEC ultimo;
    int tamanho = 0;
} TipoListaEC;

typedef struct TipoLista
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho = 0;
} TipoLista;

bool listaCriada = false;
int id = 1;

//TDA LISTA ENCADEADA SIMPLES
void CriaListaVazia(TipoLista *lista);
bool VerificaListaVazia(TipoLista *lista);
void InsereListaUltimo(TipoLista *lista, TipoItem *item);
void AtualizaUltimo(TipoLista *lista);
void ImprimeLista(TipoLista lista);
bool PesquisaItem(TipoLista *lista, char nome[]);
bool PesquisaItemPorId(TipoLista *lista, int id);
bool PesquisaItemPorEmail(TipoLista *lista, char email[]);
void ImprimeItem(TipoLista *lista, char nome[]);
void ImprimeItemPorId(TipoLista *lista, int id);
void RemoveListaPrimeiro(TipoLista *lista);
void RemoveListaUltimo(TipoLista *lista);
void RemoveItemPorId(TipoLista *lista, int id);
int TamanhoLista(TipoLista *lista);
int Atualiza(TipoLista *lista, TipoItem item, char nome[], int campo);
int AtualizaParada(TipoLista *lista, TipoItem item, char parada[40]);
void Edicao(TipoLista *lista, TipoItem item);

//TDA LISTA DUPLAMENTE ENCADEADA CIRCULAR LEC
void LECCriaListaVazia(TipoListaEC *lista);
bool LECVerificaListaVazia(TipoListaEC *lista);
void LECInsereListaPrimeiro(TipoListaEC *lista, TipoLinha *item);
void LECInsereListaAposElemento(TipoListaEC *lista, TipoLinha *item, int idEleX);
void LECInsereListaUltimo(TipoListaEC *lista, TipoLinha *item);
void LECRemoveListaPrimeiro(TipoListaEC *lista, TipoLinha *item);
void LECRemoveListaUltimo(TipoListaEC *lista, TipoLinha *item);
void LECRemoveElementoXbyId(TipoListaEC *lista, TipoLinha *item, int idEle);
bool LECPesquisaElementoXbyId(TipoListaEC *lista, TipoLinha *item, int idEle);
bool LECPesquisaElementoXbyTitulo(TipoListaEC *lista, TipoLinha *item, char titulo[]);
void LECImprimeLista(TipoListaEC *lista);
#endif