#include <iostream>
#include <windows.h>
#include "lista.hpp"
 
using namespace std;

#define MAXTAM 5

void menu(){
        cout << "TAD Lista com Vetor \n";
        cout << "1. Troca Item\n";
        cout << "2. Verifica Lista Vazia\n";
        cout << "3. Verifica Lista Cheia\n";
        cout << "4. Insere Item\n";
        cout << "5. Imprime Lista\n";
        cout << "6. Pesquisa Item\n";
        cout << "7. Retira Item\n";
        cout << "0. Sair\n\n";
}

void CriaListaVazia(TipoLista *lista){
    if (!listaCriada){ //se não está criada, ele cria
        lista->tamanho = 0; //usa o ponteiro para apontar para um membro da estrutura
        lista->Primeiro = 0;
        lista->Ultimo = lista->Primeiro;
        cout << "Lista criada com sucesso!";
        listaCriada = true;
    }
    else{
        cout << "Lista já existe!";
    }
    Sleep(1500);//comando de espera em milisegundos
}

int VerificaListaVazia(TipoLista *lista){
    return (lista->Primeiro == lista->Ultimo);
}

int VerificaListaCheia(TipoLista *lista){
    return (lista->Ultimo == MAXTAM);
}

int TamanhoLista(TipoLista *lista){
    return lista->tamanho;
}

int InsereItem(TipoLista *lista, TipoItem item){
    if (lista->Ultimo > MAXTAM){
        cout << "Lista cheia!\n";
        return -1;
    }
    lista->Item[lista->Ultimo].chave = item.chave;
    lista->tamanho++;
    lista->Ultimo++;
    return 1;
}

void ImprimeLista(TipoLista lista){
    if(listaCriada){
        int Aux;
        for (Aux = lista.Primeiro; Aux <= (lista.Ultimo - 1); Aux++){
            cout << "Chave: " << lista.Item[Aux].chave << endl;
        }
    }
    else{
        cout << "Crie a lista primeiramente.";
        Sleep(1000);
    }
}

int PesquisaItem(TipoLista *lista, int chave){
    for (int i = lista->Primeiro; i < lista->Ultimo; i++){
        if (chave == lista->Item[i].chave){
            return i; // Retorna posição do item encontrado
        }
    }
    return -1;
}

void RetiraItem(TipoApontador p, TipoLista *lista, TipoItem *item){
    int Aux;
    if (VerificaListaVazia(lista) || p > lista->Ultimo){
        cout << "Erro: Posição não existe na lista\n";
        return;
    }
    *item = lista->Item[p]; // ?

    for (Aux = p; Aux <= lista->Ultimo; Aux++){
        lista->Item[Aux] = lista->Item[Aux + 1];
    }

    lista->Ultimo--;
    lista->tamanho--;
}

//Questão 1 da Lista
bool TrocaElemento(TipoLista *lista, int i1, int i2){
    TipoItem aux;
    int busca1, busca2;
    busca1 = PesquisaItem(lista, i1);
    busca2 = PesquisaItem(lista, i2);
    if(busca1 == -1)cout << i1 << " não existe na lista";
    if(busca2 == -1)cout << i2 << " não existe na lista";

    if(busca1 != -1 && busca2 != -1){
        aux = lista->Item[busca1];
        lista->Item[busca1] = lista->Item[busca2];
        lista->Item[busca2] = aux;
        cout << "Troca realizada com sucesso\n";
        ImprimeLista(*lista);
        Sleep(4000);
        return true;
    }
    return false;
}