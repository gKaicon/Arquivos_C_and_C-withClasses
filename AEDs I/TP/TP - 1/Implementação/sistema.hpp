#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <fstream>
#include <windows.h>
#define fileName "listaDeFuncionarios.bin"
#define OPCAO_SAIDA 8
#define MAX_TAM 5 //tamanho máximo de projetos

using namespace std;

// LISTA SEQUENCIAL
typedef struct Projeto{
    int id;        // codigo do projeto
    char nome[30]; // nome do projeto
    int horas;     // numero de horas trabalhas no projeto
};

typedef struct ListaSequencial{
    Projeto item[MAX_TAM]; //vetor de tamanho máximo de projetos
    int tamanho; //tamanho(que sempre é menor ou igual a 5)
    bool listaSequencialCriada = false; //variavel booleana para criação de listas
};

// LISTA ENCADEADA
typedef struct Funcionario{
    int id;                    //id do funcionário
    char nome[100];            //nome do funcionário
    char endereco[40];         //endereço do funcionário
    int dependentes;           //numero de dependentes do funcionário
    ListaSequencial projetos;  //Lista de Projetos alocados em um campo de funcionário
};

typedef struct Celula *Apontador; //"construtor" da celula

typedef struct Celula{
    Funcionario *item; //funcionario que é colocado dentro da celula
    Apontador prox; //Apontador para a proxima célula
};

typedef struct ListaEncadeada{ //Lista de encadeada
    Apontador primeiro; //apontador da primeira posição
    Apontador ultimo;   //apontador da última posição
    int tamanho = 0;    //tamanho da lista
    bool listaEncadeadaCriada = false; //variavel booleana para indicar se a lsita foi criada ou não
};


// FUNÇÕES DA LISTA SEQUENCIAL
void CriaListaSequencialVazia(ListaSequencial *lista);
bool ListaSequencialEstaVazia(ListaSequencial *lista);
bool ListaSequencialEstaCheia(ListaSequencial *lista);
bool InsereProjeto(ListaSequencial *lista, Projeto projeto);
void ImprimeProjeto(Projeto projeto);
void ImprimeListaSequencial(ListaSequencial *lista);
Projeto *PesquisaProjetoPorID(ListaSequencial *lista, int id);
bool RemoveProjetoPorId(ListaSequencial *lista, int id);
bool RemoveProjeto(ListaSequencial *lista, Projeto projeto);
int IndiceDeProjeto(ListaSequencial *lista, Projeto projeto);
int TamanhoListaSequencial(ListaSequencial *lista);

// FUNÇÕES DA LISTA ENCADEADA
void CriaListaEncadeadaVazia(ListaEncadeada *lista);
bool ListaEncadeadaEstaVazia(ListaEncadeada *lista);
void InsereListaEncadeadaUltimo(ListaEncadeada *lista, Funcionario *funcionario);
void ImprimeFuncionario(Funcionario *funcionario);
Funcionario *PesquisaFuncionario(ListaEncadeada *lista, int id);
void RemoveFuncionario(ListaEncadeada *lista, Funcionario funcionario);
void AtualizaUltimo(ListaEncadeada *lista);
int TamanhoListaEncadeada(ListaEncadeada *lista);

// FUNÇÕES DO SISTEMA 
void menu();
void incluiNovoFuncionario(ListaEncadeada *lista);
Funcionario *criaFuncionario();
void incluiNovosProjetos(ListaEncadeada *lista);
Funcionario *FuncionarioPorID(ListaEncadeada *lista);
void incluiNovoProjeto(Funcionario *funcionario);
void criaProjeto(ListaSequencial *lista, Projeto *projeto);
void excluiProjetos(ListaEncadeada *lista);
void excluiFuncionariosSemProjetos(ListaEncadeada *lista);
void ImprimeListaFunc(ListaEncadeada *lista);
void consultaFuncionario(ListaEncadeada *lista);
int totalHorasSemanais(ListaSequencial lista);
double calculaSalarioBruto(Funcionario *funcionario);
void imprimeContraCheque(ListaEncadeada *lista);


// FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS
bool carregaArquivo(ListaEncadeada *lista);
bool salvaArquivo(ListaEncadeada *lista);


#endif