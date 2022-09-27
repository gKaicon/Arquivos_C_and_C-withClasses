#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "listaSequencial.hpp"

using namespace std;

typedef struct Funcionario
{
    int id;                    //id do funcionário
    char nome[100];            //nome do funcionário
    char endereco[40];         //endereço do funcionário
    int dependentes;           //numero de dependentes do funcionário
    ListaSequencial projetos;  //Lista de Projetos no qual este funcionario está alocado
};

typedef struct Celula *Apontador; //"construtor" da celula

typedef struct Celula
{
    Funcionario *item; //funcionario que é colocado dentro da celula
    Apontador prox; //Apontador para a proxima célula
};

typedef struct ListaEncadeada //Lista de encadeada
{
    Apontador primeiro; //apontador da primeira posição
    Apontador ultimo;   //apontador da última posição
    int tamanho = 0;    //tamanho da lista
    bool foiCriada = false; //variavel booleana para indicar se a lsita foi criada ou não
};

void ImprimeFuncionario(Funcionario *funcionario);

void CriaListaEncadeadaVazia(ListaEncadeada *lista); //sem retorno, apenas cria uma lista vazia com uma celula
bool ListaEncadeadaEstaVazia(ListaEncadeada *lista); //true = lista com celula sem item, e false = lista com uma celula com item
void InsereListaEncadeadaUltimo(ListaEncadeada *lista, Funcionario *funcionario); //sem retorno, apenas inserir no final da lista
Funcionario *PesquisaFuncionario(ListaEncadeada *lista, int id); //retorna um funcionario, de acordo com o id informado
void RemoveFuncionario(ListaEncadeada *lista, Funcionario funcionario); //remover o funcionario, que é passado no parametro
void AtualizaUltimo(ListaEncadeada *lista); //atualiza o apontador ultimo na lista
int TamanhoListaEncadeada(ListaEncadeada *lista); //retorna a quantidade de funcionarios inseridos até o momento

#endif