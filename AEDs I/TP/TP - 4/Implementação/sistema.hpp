#include <iostream>
#include <iomanip>
#include <string.h>
#include <windows.h>
#include <listasEncadeada.cpp>

using namespace std;


void Menu();
void Pesquisa();
void Escolher();
void MenuRemocao();
void CabecalhoCadastro();
void CabecalhoRemocaoPorCodigo();
void CabecalhoPesquisaPorCodigo();
void CabecalhoPesquisaPorNome();
void CabecalhoListagemCompleta();
int CadastraRota(TipoLista *lista);
void Edicao(TipoLista *lista, TipoItem item);
