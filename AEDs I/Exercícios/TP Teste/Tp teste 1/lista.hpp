#include <iostream>
#include <fstream>
#include <string.h>
//#include <unistd.h>
#include <stdio.h>
#include <windows.h>
#ifndef LISTA_H
#define LISTA_H

using namespace std;

#define MAXTAM 5 //Limitando número máximo da listaSequencial(projetos)
#define INICIO 0 //Iniciando a lista em 0

typedef int TChave;

typedef struct TCelula_str *TApontador;

typedef struct
{
    TChave codigo;
    char nome[41];
    int horas;
} TProjeto;

typedef struct
{
    TProjeto item[MAXTAM]; // Vetor utilizado para armazenar os projetos, definido pela constante MAXTAM
    int primeiro;
    int ultimo;
} TListaSequencial;

// Estrutura para armazenar os dados dos funcionários e a lista que guarda os projetos de cada funcionário
typedef struct
{
    TChave numero;             
    char nome[25];
    char endereco[60];
    int dependentes;
    TListaSequencial projetos;
} TFuncionario;

// Estrutura de células individuais da lista

typedef struct TCelula_str
{
    TFuncionario item; // Ítem da celula
    TApontador prox; // Ponteiro que aponta para a próxima célula
} TCelula;

// Estrutura da lista

typedef struct
{
    TApontador Primeiro; // O primeiro elemento da lista
    TApontador Ultimo; // O último elemento da lista
} TListaEncadeada; 


bool listaCriada = false;
// Funções criadas para o sistema

// Função para impressão do Menu princiapal
void menu();

void CriaListaVaziaEncadeada(TListaEncadeada *listaE);
void InserirEncadeada(TFuncionario fun, TListaEncadeada *listaE);
bool VerificaListaVaziaEncadeada(TListaEncadeada listaE);
int  PesquisaListaEncadeada(TChave cod, TListaEncadeada listaE, TApontador *ptr);

void CriaListaVaziaSequencial(TListaSequencial *listaS);
void InsereSequencial(TProjeto proj, TListaSequencial *listaS);
bool VerificaListaVaziaSequencial(TListaSequencial listaS);
int  PesquisaListaSequencial(TListaSequencial *listaS, TChave cod);

// Funções para a manipulação do dados dos funcionários e seu projetos

void CadastraFuncionario(TListaEncadeada *listaE);                                     
void ConsultaFuncionario(TListaEncadeada *listaE);
void ExcluiFuncionario(TListaEncadeada *listaE);
void DeletaFuncionario(TApontador x, TListaEncadeada *listaE, TFuncionario *fun);
void CadastraProjetos(TListaEncadeada *listaE);
void ExcluiProjetos(TListaEncadeada *listaE);
void ApagaProjeto(TApontador ptr, TListaSequencial *listaS, TChave cod, TProjeto *proj);

// Funções para a realização de cálculo e impressão do contra-cheque

int   CalculaHorasSemanais(TListaSequencial listaS);
float CalculaSalarioBruto(int TotaldeHoras, TApontador x);
void  DadosFuncionario(TChave cod, TListaEncadeada *listaE);
void  ImprimeProjetos(TListaSequencial listaS);
int   QuantProjetos(TListaSequencial listaS);
void ImprimeContraCheque(TListaEncadeada *listaE);



#endif