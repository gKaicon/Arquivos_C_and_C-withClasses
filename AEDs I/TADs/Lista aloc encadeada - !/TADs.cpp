#include <iostream>
#include <windows.h>
#include "lista.hpp"
 
using namespace std;


void menu(){
        cout << "TAD Lista com Vetor \n";
        cout << "1. Criar Lista\n";
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
        lista->Primeiro = new TipoElemento; //primeira posição da LISTA recebe um novo ELEMENTO
        lista->Ultimo = lista->Primeiro; //e o ultimo recebe o primeiro, pois se trata se uma lista vazia
        lista->Ultimo->prox = NULL; //o apontador de struct prox recebe nulo, para que seja possível a próxima inserção
        cout << "Lista criada com sucesso!";
        listaCriada = true; //lista foi criada
    }
    else{
        cout << "Lista já existe!";
    }
    Sleep(1500);//comando de espera em milisegundos
}

int VerificaListaVazia(TipoLista *lista){
    return (lista->Primeiro == lista->Ultimo);
}

int TamanhoLista(TipoLista *lista){
    return lista->tamanho;
}

void AtualizaUltimo(TipoLista *lista){ //faz uma troca dos valores para atualizar o ultimo
    Apontador aux; //apontador auxiliar
    aux = lista->Primeiro->prox; // a primeira posição
    while (aux->prox != NULL){ //enquanto for diferente de null, ele irá percorrer
        aux = aux->prox;
    }
    lista->Ultimo = aux; //quando ele sair do while, o ultimo valor, que fez o while sair, será o último.
}

int InsereListaPrimeiro(TipoLista *lista, TipoItem *item){ //primeira inserção já tendo a lista criada
    Apontador aux;
    aux = lista->Primeiro->prox; 
    lista->Primeiro->prox = new TipoElemento; //primeira posição da LISTA, apontando para a última posição recebe um novo ELEMENTO
    lista->Primeiro->prox->prox = aux; //o próximo depois do anterior, recebe o valor de aux, que era null
    lista->Primeiro->prox->item = *item;
    lista->tamanho++; //incremento da lista
    AtualizaUltimo(lista); //chamada da função anterior
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item){ //insere sempre após o ultimo
    lista->Ultimo->prox = new TipoElemento; //última posição da LISTA, apontando para a última posição recebe um novo ELEMENTO
    lista->Ultimo = lista->Ultimo->prox; // a última posição da LISTA, recebe o apontador da última posição
    lista->Ultimo->prox = NULL; //o apontador da última posição da lista recebe null recebe null
    lista->Ultimo->item = *item;
    lista->tamanho++;
}

//insere em qualquer lugar
void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id)
{
    Apontador aux, pAux, x;
    bool find = false; //achou recebe false
    pAux = lista->Primeiro->prox; //o "ponteiro"
    while (pAux != NULL){// enquanto for diferente de null
        if (pAux->item.chave == id){ //quando a chave for igual ao valor digitado, a inserção será feita após ele
            find = true; //achou recebe true
            x = pAux; //o ponteiro é guardado em x
            aux = x->prox; //aux recebe a poxima posição que foi achada
            x->prox = new TipoElemento; //novo elemento é criado
            x->prox->prox = aux; //no próximo elemento é colocado o que tinha em aux
            x->prox->item = *item; //no proximo elemento recebe o que está em item
            break;
        }
        pAux = pAux->prox; //próxima célula
    }

    if(find){ //se achou, ele atualiza o último, para a inserção ser realizada com sucesso
        cout << "Item inserido com sucesso!";
        AtualizaUltimo(lista);
        lista->tamanho++;
    }
    else{
        cout << "Elemento anterior não encontrado na lista.";
    }
}


void ImprimeLista(TipoLista lista){ //lista toda
    if(VerificaListaVazia(&lista)){ //verifica se o endereço da lista é true
        cout << "Lista Vazia";
        Sleep(1000);
        return ;
    }
    Apontador aux;
    aux = lista.Primeiro->prox; //recebe o apontador de próximo, depois do pirmeiro
    while(aux != NULL){ //enquanto não for nulo, ele imprime
        cout << "ID: " << aux->item.chave << endl;
        cout << "Nome: " << aux->item.nome << endl;
        aux = aux->prox;//aux sendo 'incrementado'
    }
}

void ImprimeItem(TipoLista *lista, int chave){ //elemento da lista
    Apontador aux;
    aux = lista->Primeiro->prox; //ele pega a variavel auxiliar e compara a chave dela, com a chave digitada
    while (aux != NULL){
        if (aux->item.chave == chave){
            cout << "ID: " << aux->item.chave << endl;
            cout << "Nome: " << aux->item.nome << endl;
            break;
        }
        aux = aux->prox;
    }
}

int PesquisaItem(TipoLista *lista, int chave){
    Apontador aux;
    aux = lista->Primeiro->prox;
    while (aux != NULL){
        if (aux->item.chave == chave)return aux->item.chave; //achou a chave
        aux = aux->prox;
    }
    return -1;
}

void RemoveListaPrimeiro(TipoLista *lista){
    if (VerificaListaVazia(lista)) return; //verifica se o endereço da lista é true

    Apontador aux;
    aux = lista->Primeiro->prox;
    lista->Primeiro->prox = aux->prox;
    delete aux; //delete é do LISTA_H
    lista->tamanho--;
}

void RemoveListaUltimo(TipoLista *lista){
    if (VerificaListaVazia(lista)) return;

    Apontador aux, atual;
    atual = lista->Primeiro->prox;
    aux = lista->Ultimo;
    while (atual->prox != lista->Ultimo){// enquanto o valor inicial for diferente do último ele irá seguir em frente e realizar a verificação
        atual = atual->prox;
    }
    atual->prox = NULL; //quando ele sair do while, o "último receberá o valror do primeiro"
    lista->Ultimo = atual; //o último receberá o atual
    delete atual;
    lista->tamanho--;
}

void RemoveItemPorId(TipoLista *lista, int id){
    if (VerificaListaVazia(lista))  return; //verifica se o endereço da lista é true

    Apontador aux, anterior, x;
    x = lista->Primeiro;
    while (x != NULL){
        if (x->prox->item.chave == id){
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}
