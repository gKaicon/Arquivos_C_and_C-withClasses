#include <iostream>
#include <windows.h>
#include "TADs.hpp"
 
using namespace std;

#define MAXTAM 5

void menu(){
    cout << "CADASTRO\n\n";
    cout << "1. Projeto";
    cout << "2. Funcionario";
    cout << "0. Sair";
}

void menuProjeto(){
  //  cout << "1.1 Cria Lista sequencial de projeto";
  //  cout << "1.2 Verifica se a lista está vazia";
  //  cout << "1.3 Verifica se a lista está cheia";
    cout << "1.4 Incluir na lista projeto";
    cout << "1.5 Listar projetos";
    cout << "1.6 Pesquisar projeto por id";
    cout << "1.7 Retirar projeto";
}
void menuFuncionario(){
  //  cout << "2.1 Cria lista dinâmica de funcionário";
  //  cout << "2.2 Verifica se a lista está Vazia";
    cout << "2.3 Incluir funcionário";
    cout << "    2.3.1 Incluir projeto ao funcionário";
    cout << "    2.3.2 Excluir funcionário sem projeto";
    cout << "    2.3.3 Excluir projeto do funcionário";
    cout << "2.5 Listar funcionários";
    cout << "2.6 Quantidade de funcionários";
    cout << "2.7 Imprimir todos os Contra-Cheque";
}

void criaListaProj(ListaSequencialProjeto *lista){
    if(!listaProjectCriada){
        lista->tamanho = 0;
        lista->primeiro = 0; //usa o ponteiro para apontar para um membro da estrutura
        lista->ultimo = lista->primeiro;
        cout << "Lista de projetos criada com sucesso!";
        listaProjectCriada = true;
    }
    else cout << "Lista já existe";
    Sleep(2000);
}

bool verificalistaVaziaProj(ListaSequencialProjeto *lista){
    return (lista->primeiro == lista->ultimo);
}
bool verificaListaCheiaProj(ListaSequencialProjeto *lista){
    return (lista->ultimo == MAXTAM);
}

bool incluirNaListaProjeto(ListaSequencialProjeto *lista, Projeto item){
    if (lista->ultimo > MAXTAM){
        cout << "Turma cheia!\n";
        return false;
    }
    else{
        lista->itemProjeto[lista->ultimo].codigo = item.codigo;
        strcpy(lista->itemProjeto[lista->ultimo].nome, item.nome);
        lista->itemProjeto[lista->ultimo].horas = item.horas;
        lista->tamanho++;
        lista->ultimo++;
        return true;
    }
}
void listaDeProjetos(ListaSequencialProjeto *lista){
    
}
void pesquisaProjeto(ListaSequencialProjeto *lista){
    
}
void retiraProjeto(ListaSequencialProjeto *lista){

}