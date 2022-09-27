#ifndef LISTA_ARRANJO_H
#define LISTA_ARRANJO_H
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

#define MAX_TAM 5 //tamanho máximo de projetos

typedef struct Projeto
{
    int id;        // codigo do projeto
    char nome[30]; // nome do projeto
    int horas;     // numero de horas trabalhas no projeto
};

typedef struct ListaSequencial
{
    Projeto item[MAX_TAM]; //vetor de tamanho máximo de projetos
    int tamanho; //tamanho(que sempre é menor ou igual a 5)
    bool listaCriada = false; //variavel booleana para criação de listas
};

void ImprimeProjeto(Projeto projeto);

void CriaListaSequencialVazia(ListaSequencial *lista);         // Cria uma lista vazia
bool ListaSequencialEstaVazia(ListaSequencial *lista);         // Retorna TRUE se a lista estiver vazia, FALSE caso contrário
bool ListaSequencialEstaCheia(ListaSequencial *lista);         // Retorna TRUE se a lista estiver cheia, FALSE caso contrário
bool InsereProjeto(ListaSequencial *lista, Projeto projeto);   // Insere Projeto na lista ListaSequencial
void ImprimeListaSequencial(ListaSequencial *lista);           // Imprime a lista
Projeto *PesquisaProjetoPorID(ListaSequencial *lista, int id); // Pesquisa um Projeto via ID na lista ListaSequencial
bool RemoveProjetoPorId(ListaSequencial *lista, int id);       // Remove um Projeto da lista via ID
bool RemoveProjeto(ListaSequencial *lista, Projeto projeto);   // Remove um Projeto da lista
int IndeceDe(ListaSequencial *lista, Projeto projeto);         // Retorna o indice do projeto na lista, -1 se não tiver o projeto
int TamanhoListaSequencial(ListaSequencial *lista);            // Retorna o número de itens da lista

#endif
