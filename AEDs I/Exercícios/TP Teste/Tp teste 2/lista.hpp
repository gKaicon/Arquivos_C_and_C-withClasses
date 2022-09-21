#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#ifndef LISTA_H
#define LISTA_H

#define MAXTAM 3

using namespace std;

// Cadastro de Funcionário
int codFun=0;
int codProj=0;



typedef int TChave;

typedef struct TCelula_str *TApontador;

typedef struct {
    TChave codProjeto;
    char nomeProjeto[41];
    int numHoras;
} TProjeto;

typedef struct {
    TChave codFuncionario;
    char nomeFuncionario[41];
    int numDependentes;
    char endereco[41];
    int projetos;
    TProjeto codProjeto[6];
} TFuncionario;

typedef struct TCelula_str {
    TFuncionario Item;
    TApontador prox;
} TCelula;

typedef struct {
    TApontador Primeiro;
    TApontador Ultimo;
} TListaEncadeada;
 

bool listaCriada = false;
void menu();
//TADS: Criar Lista Vazia, Inserir item na lista, Retirar item da lista, Pesquisar item na lista
void CriaListaVazia(TListaEncadeada *lista);
void Insere(TFuncionario f, TListaEncadeada *lista);
void InsereProjeto(TFuncionario f, TListaEncadeada *lista);
int Pesquisa(TChave cod, TListaEncadeada lista, TApontador *p);
void CadastraFuncionario(TListaEncadeada *lista);
void CadastraProjeto(TListaEncadeada *lista);
void ConsultaFuncionario(TListaEncadeada *lista);
void ExcluiFuncionario(TListaEncadeada *lista);
void ListaCheque(TListaEncadeada *lista);
void ExcluiProjeto(TListaEncadeada *lista);
void Logo(int escolha);
void Exclui1Funcionario(TListaEncadeada *lista);
int Listagem(TListaEncadeada *lista);
void CadastraFuncionarioI(char nomef[40],char ender[40],int codf,int dep,int proj,TListaEncadeada *lista);
void CadastraProjetoI(int codf,int codp,int htrab,char nomep[40],int contu,TListaEncadeada *lista);
void IniciacaoFunNom(char ch);
void IniciacaoFunEnd(char ch);
void IniciacaoFunProj(int conty, int it,TListaEncadeada *lista);
void IniciacaoCharProj(char ch, TListaEncadeada *lista);
void Salvar(TListaEncadeada *lista);
int ListagemP (int cod, TListaEncadeada *lista);
void ListaCheque1(TListaEncadeada *lista);
void InsereProjetoI(int contu, TFuncionario f, TListaEncadeada *lista);





#endif