#define MAX_PRODUTOS 10
#define MAX_ENTREGA 7
#define MAX_PRODUTOS_CARDAPIO 10

#include <iostream>
#include <windows.h>


using namespace std;

typedef struct Produto{
    int codigo;
    char nome[100];
    float valor_produto;
};

Produto menu[MAX_PRODUTOS_CARDAPIO];

typedef struct Pedido{
    int codigo;
    int produtos[MAX_PRODUTOS];
    int total_produtos = 0;
    float valor_pedido = 0;
    float distancia = 0;
};

typedef struct Pilha{
    Pedido pedidos[MAX_ENTREGA];
    int topo;
};

typedef struct ListaSequencial{
    Pedido pedidos[MAX_ENTREGA];
    int tamanho;
    bool listaCriada = false;
};


void Lista_Inicializa(ListaSequencial *lista);               // Cria uma lista vazia
bool Lista_Vazia(ListaSequencial lista);                    // Retorna TRUE se a lista estiver vazia, FALSE caso contrário
bool Lista_Cheia(ListaSequencial lista);                    // Retorna TRUE se a lista estiver cheia, FALSE caso contrário
bool Lista_Insere(ListaSequencial *lista, Pedido pedido);    // Insere Pedido na lista ListaSequencial
void Lista_Imprime(ListaSequencial lista);                  // Imprime a lista
bool Lista_Remove_Id(ListaSequencial *lista, int id);        // Remove um Pedido da lista via ID
bool Lista_Remove(ListaSequencial *lista, Pedido pedido);    // Remove um Pedido da lista
int IndeceDe(ListaSequencial lista, Pedido pedido);         // Retorna o indice do pedido na lista, -1 se não tiver o pedido
int Lista_Tamanho(ListaSequencial lista);                   // Retorna o número de itens da lista






void InicializaPilha(Pilha *pilha);
bool PilhaVazia(Pilha pilha);
bool PilhaCheia(Pilha pilha);
void Empilha(Pilha *pilha, Pedido pedido);
bool Desempilha(Pilha *pilha);
void imprimePilha(Pilha pilha, bool imprimirProdutos);
void imprimePedido(Pedido pedido, bool imprimirProdutos);
Pilha OrdenaPilha(Pilha pilha);
Pedido TopoPilha(Pilha pilha);
int TamanhoPilha(Pilha pilha);