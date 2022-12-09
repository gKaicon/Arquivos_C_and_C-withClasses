#include <iostream>
#include <windows.h>
#include <time.h>
#include "lista.hpp"

using namespace std;

void CriaListaVazia(TipoLista *lista)
{
    lista->primeiro = new TipoElemento; //insere um elemento na primeira posição, e esse elemento não tem nada
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->primeiro->ant = NULL;
    lista->tamanho = 0;
    cout << "Lista criada com sucesso!" << endl;
    //Sleep(1000);
}

bool VerificaListaVazia(TipoLista *lista)
{
    return (lista->primeiro == lista->ultimo);
}

int TamanhoLista(TipoLista *lista)
{
    return lista->tamanho;
}

void InsereListaPrimeiro(TipoLista *lista, TipoItem *item)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    aux->prox = lista->primeiro->prox;
    aux->ant = lista->primeiro;
    lista->primeiro->prox = aux;
    if (lista->primeiro == lista->ultimo)
        lista->ultimo = aux;
    else
        aux->prox->ant = aux;
    lista->tamanho++;
}

void InsereListaUltimo(TipoLista *lista, TipoItem *item)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    aux->prox = NULL;
    aux->ant = lista->ultimo;
    lista->ultimo->prox = aux;
    lista->ultimo = aux;
    lista->tamanho++;
}

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id)
{
    Apontador aux = new TipoElemento;
    aux->item = *item;
    Apontador aux2 = lista->primeiro->prox;
    while (aux2->item.id != id)
    {
        aux2 = aux2->prox;
    }
    aux->prox = aux2->prox;
    aux->ant = aux2;
    aux2->prox = aux;
    if (aux->prox == NULL)
        lista->ultimo = aux;
    else
        aux->prox->ant = aux;
    lista->tamanho++;
}

void ImprimeLista(TipoLista lista)
{
    if (VerificaListaVazia(&lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista.primeiro->prox;
    while (aux != NULL)
    {
        cout << "\tID: " << aux->item.id << endl;
        cout << "\tNome: " << aux->item.nome << endl;
        aux = aux->prox;
    }
    cout << "Tamanho da Lista: " << TamanhoLista(&lista) << endl;
    //system("PAUSE");
}

int PesquisaItem(TipoLista *lista, int chave)
{
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != chave){
        aux = aux->prox;
    }
    if (aux != NULL){
        return aux->item.id;
    }
    else{
        return -1;
    }
}

void RemoveListaPrimeiro(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    if (aux->prox != NULL)
    {
        aux->prox->ant = lista->primeiro;
    }
    else
    {
        lista->ultimo = lista->primeiro;
    }
    delete aux;
    lista->tamanho--;
}

void RemoveListaUltimo(TipoLista *lista)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->ultimo;
    lista->ultimo = aux->ant;
    lista->ultimo->prox = NULL;
    delete aux;
    lista->tamanho--;
}

void RemoveItemPorId(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != id)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        aux->ant->prox = aux->prox;
        if (aux->prox != NULL)
        {
            aux->prox->ant = aux->ant;
        }
        else
        {
            lista->ultimo = aux->ant;
        }
        delete aux;
        lista->tamanho--;
    }
    else
    {
        cout << "Elemento não encontrado!";
        Sleep(1500);
    }
}

void ImprimeItem(TipoLista *lista, int id)
{
    if (VerificaListaVazia(lista))
    {
        cout << "Lista vazia!\n";
        Sleep(1000);
        return;
    }
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL && aux->item.id != id)
    {
        aux = aux->prox;
    }
    if (aux != NULL)
    {
        cout << "ID: " << aux->item.id << endl;
        cout << "Nome: " << aux->item.nome << endl;
        Sleep(1500);
    }
    else
    {
        cout << "Elemento não encontrado!";
        Sleep(1500);
    }
}

void insereLista(TipoLista *lista){
    TipoItem item;
    int n, x;
    for(int i = 0; i < 8; i++){
        srand(time(NULL));
        x = rand()%5;
        item.id = i + x;
        n = rand()%16;
            if(n ==  1){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Eduardo");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  2){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "João");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  3){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "João Emanuell");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  4){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Gabriel Káicon");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  5){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Amanda Soares");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  6){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Marcelo");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  7){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Maria José");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  8){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Maria");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  9){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "José Maria");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  10){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Carlos");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  11){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "João Gabriel");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  12){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Maria Eduarda");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  13){        
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Mário");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  14){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Mickey");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  15){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Carlos Eduardo");
                InsereListaUltimo(lista, &item);
            }
            if(n ==  16){
                Sleep(300);
                srand(time(NULL));
                strcpy(item.nome, "Márcia");
                InsereListaUltimo(lista, &item);
            }
    }
}

void concatenarLista(TipoLista *lista1, TipoLista *lista2, TipoLista *lista3){
    Apontador aux;
    TipoItem item;
    aux = lista1->primeiro->prox;
    while(aux != NULL){
        item = aux->item;
        InsereListaUltimo(lista3, &item);
        aux = aux->prox;
    }
    aux = lista2->primeiro->prox;
    while(aux != NULL){
        item = aux->item;
        InsereListaUltimo(lista3, &item);
        aux = aux->prox;
    }

}

void DividirEmDois(TipoLista *lista3, TipoLista *lista4, TipoLista *lista5){
    Apontador aux;
    TipoItem item;
    aux = lista3->primeiro->prox;
    int tam = TamanhoLista(lista3);
    for(int i = 0; i < tam/2; i++){
        item = aux->item;
        InsereListaUltimo(lista4, &item);
        aux = aux->prox;
    }

    for(int i = tam/2; i < tam; i++){
        item = aux->item;
        InsereListaUltimo(lista5, &item);
        aux = aux->prox;
    }
}

void ordenarLista(TipoLista *lista){
    Apontador aux, aux2;
    TipoItem item;
    aux = lista->primeiro->prox; //pegar o inicio da lista, para percorre-la
    while(aux != NULL){
        aux2 = aux->prox; // pega o segundo valor que será guardado, e depois altera
        while(aux2 != NULL){
            if(aux->item.id > aux2->item.id){ //se o 1° valor for maior que o 2° valor guardado
                item = aux->item; //você vai pegar esse 1° valor, e guardar ele em item
                aux->item = aux2->item; //você vai pegar o menor valor, vai guardar no lugar do maior, que está antes dele
                aux2->item = item; //vai pegar o menor, e guardar o maior valor nele
            }
            aux2 = aux2->prox; //percorre o menor valor, até achar um menor que ele, para entrar no while e fazer as alterações
        }
        aux = aux->prox; //percorre o laço que incrementa o maior, e começa o 2°while de novo
    }
}

void intercalarLista(TipoLista *lista1, TipoLista *lista2, TipoLista * lista6){
    Apontador aux1, aux2;
    TipoItem item;
    ordenarLista(lista1); //ordenar as listas
    ordenarLista(lista2); //ordenar as listas
    aux1 = lista1->primeiro->prox; //cada aux, recebe o inicio de uma lista
    aux2 = lista2->primeiro->prox; 
    while(aux1 != NULL && aux2 != NULL){ //percorre as duas listas, até chegar no fim
        if(aux1->item.id < aux2->item.id){ //se o Id da primeira for menor que o da segunda
            item = aux1->item; //vai guardar esse item
            InsereListaUltimo(lista6, &item); // e vai inserir na lista
            aux1 = aux1->prox; //e incrementar
        }
        else{
            item = aux2->item;
            InsereListaUltimo(lista6, &item);
            aux2 = aux2->prox;
        }
    }
}

void InverteLista(TipoLista *lista, TipoLista *lista7){ //lista toda
    Apontador aux;
    aux = lista->primeiro->prox; //pri recebe a primeira posição
    while (aux != NULL){ //enquanto o primeiro for diferente do ultimo
        InsereListaPrimeiro(lista7, &aux->item);
        aux = aux->prox; //irá percorrer a lista
    }
    Sleep(5000);
}
