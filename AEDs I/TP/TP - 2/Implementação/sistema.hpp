#ifndef SISTEMA_H

#define SISTEMA_H
#define MAX_PRODUTOS 10
#define MAX_ENTREGA 7
#define MAX_PRODUTOS_CARDAPIO 10
#define NOME_ARQUIVO "lanchonete.bin"
#define OPCAO_SAIDA 7

#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int codigoPedido = 0;

typedef struct Produto{
    int codigo;
    char nome[100];
    double valor;
};

Produto menu[MAX_PRODUTOS_CARDAPIO]; // Vetor de Structs de Produtos

typedef struct Pedido{
    int codigo;
    int codprodutos[MAX_PRODUTOS];
    int totalprodutos = 0;
    double valorPedido = 0;
    double distancia = 0;
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
//--------------------------------------------TADs--------------------------------------------------------------------------------------------------------------

//TADs de Pilha
void InicializaPilha(Pilha *pilha);                                         // Cria a pilha
bool PilhaVazia(Pilha pilha);                                               // Verifica se a pilha está vazia
bool PilhaCheia(Pilha pilha);                                               // Verifica se a pilha está cheia
void Empilha(Pilha *pilha, Pedido pedido);                                  // Adiciona item no topo
bool Desempilha(Pilha *pilha);                                              // Remove item no topo
void imprimePilha(Pilha pilha);                                             // Imprime a lista
void imprimePedido(Pedido pedido);                                          // Imprime um pedido dentro da lista
Pilha OrdenaPilha(Pilha pilha);                                             // Ordena a pilha em uma lista auxiliar e a retorna
Pedido TopoPilha(Pilha pilha);                                              // Retorna o topo da pilha
int TamanhoPilha(Pilha pilha);                                              // Tamanho da pilha

//TADs de Lista
void CriaListaVazia(ListaSequencial *lista);                                // Cria uma lista vazia
bool VerificaListaVazia(ListaSequencial lista);                             // Retorna TRUE se a lista estiver vazia, FALSE caso contrário
bool VerificaListaCheia(ListaSequencial lista);                             // Retorna TRUE se a lista estiver cheia, FALSE caso contrário
bool inserirLista(ListaSequencial *lista, Pedido pedido);                   // Insere Pedido na lista ListaSequencial
void imprimeLista(ListaSequencial lista);                                   // Imprime a lista
bool RemoveIdLista(ListaSequencial *lista, int id);                         // Remove um Pedido da lista via ID
bool ListaRemove(ListaSequencial *lista, Pedido pedido);                    // Remove um Pedido da lista
int procuraIndice(ListaSequencial lista, Pedido pedido);                    // Retorna o indice do pedido na lista, -1 se não tiver o pedido
int TamanhoLista(ListaSequencial lista);                                    // Retorna o número de itens da lista


//----------------------------------------Funções do Sistema---------------------------------------------------------------------------------------------------

//Arquivo
bool carregaArquivo(ListaSequencial *listaSequencial);                      //Carrega o arquivo
bool salvaArquivo(ListaSequencial *listaSequencial);                        //Salva o arquivo no fim do programa

//Formatação
void formataDecimal();                                                      // Formata os decimais deixando os números com 2 casas decimais depois da virgula

//Produtos
void adicionaCardapio(int codigo, char nome[], double valor);               //Modelo para inserir produtos
void insereProdutos();                                                      //Salvar os produtos no menu na inicialização

//Menu
void Menu();                                                                //Menu com as opções

//Funções exigidas
void incluirPedido(ListaSequencial *listaSequencial);                       // 1° - Incluir pedido na lista
bool verificaCodigoProduto(int codigoProduto);                              // Verificar se existe o código do produto que está sendo inserido no pedido
void insereProdutos(Pedido *pedido);                                        // Cria o Pedido
void criaItemPedido(Pedido *pedido);                                        // Incluir o Produto dentro do pedido criado
void listarPedidos(ListaSequencial listaSequencial);                        // 2° - Lista os pedidos na ordem em foram pedidos
void verCardapio();                                                         // 3° - Mostra o cardápio
void consultarPedido(ListaSequencial listaSequencial);                      // 4° - Consulta um pedido específico com a função imprimePedido
void listaParaPilha(Pilha *pilha, ListaSequencial listaSequencial);         // Realiza a troca de lista para pilha
void imprimirListaEntrega(Pilha *pilha, ListaSequencial listaSequencial);   // 5° - Após a troca de lista para pilha, ele imprime a pilha de entregas
void lancarEntrega(Pilha *pilha, ListaSequencial *listaSequencial);         // 6° - Entrega o pedido que tá no topo, que é o de menor distancia

#endif