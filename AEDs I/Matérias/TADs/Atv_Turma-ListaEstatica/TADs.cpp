#include <iostream>
#include <windows.h>
#include <string.h>
#include "lista.hpp"
 
using namespace std;

#define MAXTAM 5

void menu(){
        cout << "TAD Lista com Vetor \n";
        cout << "1. Cria turma\n";
        cout << "2. Verifica se a turma está vazia\n";
        cout << "3. Verifica se a turma está cheia de alunos\n";
        cout << "4. Cadastra aluno\n";
        cout << "5. Imprime turma\n";
        cout << "6. Pesquisa aluno\n";
        cout << "7. Retira aluno\n";
        cout << "0. Sair\n\n";
}

void CriaTurmaVazia(TipoListaTurma *lista){
    if (!listaCriada){ //se não está criada, ele cria
        lista->tamanho = 0; //usa o ponteiro para apontar para um membro da estrutura
        lista->Primeiro = 0;
        lista->Ultimo = lista->Primeiro;
        cout << "Turma criada com sucesso!";
        listaCriada = true;
    }
    else{
        cout << "Turma já existe!";
    }
    Sleep(1500);//comando de espera em milisegundos
}

int VerificaListaVazia(TipoListaTurma *lista){
    return (lista->Primeiro == lista->Ultimo);
}

int VerificaListaCheia(TipoListaTurma *lista){
    return (lista->Ultimo == MAXTAM);
}

int TamanhoLista(TipoListaTurma *lista){
    return lista->tamanho;
}

int InsereItem(TipoListaTurma *lista, TipoItemAluno item){
    if (lista->Ultimo >= MAXTAM){
        cout << "Turma cheia!\n";
        return -1;
    }
    else{
        lista->Item[lista->Ultimo].matricula = item.matricula;
        strcpy(lista->Item[lista->Ultimo].nome, item.nome);
        lista->Item[lista->Ultimo].turma = item.turma;
        lista->Item[lista->Ultimo].n1 = item.n1;
        lista->Item[lista->Ultimo].n2 = item.n2;
        lista->Item[lista->Ultimo].n3 = item.n3;
        lista->tamanho++;
        lista->Ultimo++;
        return 1;
    }
}

void ImprimeLista(TipoListaTurma lista){
    if(listaCriada){
        int Aux;
        for (Aux = lista.Primeiro; Aux <= (lista.Ultimo - 1); Aux++){
            cout << "Matricula: " << lista.Item[Aux].matricula << endl;
            cout << "Nome: " << lista.Item[Aux].nome << endl;
            cout << "Turma: " << lista.Item[Aux].turma << endl;
            cout << "Nota 1: " << lista.Item[Aux].n1 << endl;
            cout << "Nota 2: " << lista.Item[Aux].n2 << endl;
            cout << "Nota 3: " << lista.Item[Aux].n3 << endl;
            cout << "\n";
        }
    }
    else{
        cout << "Crie a Turma primeiramente.";
        Sleep(1000);
    }
}

int PesquisaItem(TipoListaTurma *lista, int matricula){
    for (int i = lista->Primeiro; i < lista->Ultimo; i++){
        if (matricula == lista->Item[i].matricula){
            return i; // Retorna posição do item encontrado
        }
    }
    return -1;
}

void RetiraItem(TipoApontador p, TipoListaTurma *lista, TipoItemAluno *item){
    int Aux;
    if (VerificaListaVazia(lista) || p > lista->Ultimo){
        cout << "Erro: Posição não existe na turma\n";
        return;
    }
    *item = lista->Item[p]; // ?

    for (Aux = p; Aux <= lista->Ultimo; Aux++){
        lista->Item[Aux] = lista->Item[Aux + 1];
    }

    lista->Ultimo--;
    lista->tamanho--;
}