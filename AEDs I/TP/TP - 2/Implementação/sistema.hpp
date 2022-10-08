#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>

using namespace std;

#define NOME_ARQUIVO "lanchonete.bin"
#define OPCAO_SAIDA 7

int codigoPedidoGlobal = 0;

bool carregaArquivo(ListaSequencial *listaSequencial);
void iniciaProdutos();
void adicionaProdutoCardapio(int codigo, char nome[], float valor_produto);
void menu();
void incluirPedido(ListaSequencial *listaSequencial);
void criaPedido(Pedido *pedido);
void insereProdutos(Pedido *pedido);
bool validaCodigoProduto(int codigoProduto);
void listarPedidos(ListaSequencial listaSequencial);
void verCardapio();
void consultarPedido(ListaSequencial listaSequencial);
void imprimirListaEntrega(Pilha *pilha, ListaSequencial listaSequencial);
void listaParaPilha(Pilha *pilha, ListaSequencial listaSequencial);
void lancarEntrega(Pilha *pilha, ListaSequencial *listaSequencial);

#endif