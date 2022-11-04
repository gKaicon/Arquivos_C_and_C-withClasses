#include <iostream>
#include <windows.h>
#include "TADs-lista.hpp"
 
using namespace std;

void menu(){

    cout << " --------------------------------\n";
    cout << "          Lista Encadeada        \n";
    cout << " --------------------------------\n";
    cout << " 1. Concatena 1ª com 2ª lista - Lista 3\n";
    cout << " 2. Verifica Lista Vazia\n";
    cout << " 3. Insere Item no início da lista\n";
    cout << " 4. Insere Item no final da lista\n";
    cout << " 5. Insere Item após um elemento X\n";
    cout << " 6. Imprime Lista\n";
    cout << " 7. Pesquisa Item\n";
    cout << " 8. Remove Item do início da lista\n";
    cout << " 9. Remove Item do final da lista\n";
    cout << "10. Remove Item por ID\n";
    cout << "11. Inverte Lista - Lista 5\n";
    cout << "12. Concatena Alternadamente - Lista 4\n";
    cout << "13. Tamanho da Lista\n";
    cout << " 0. Sair\n\n";
}

void CriaListaVazia(TipoLista *lista){
    listaCriada = false;
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
    lista->Ultimo = aux; //quando ele sair do while, o ultimo valor que fez sair do while, será o último.
}

void InsereListaPrimeiro(TipoLista *lista, TipoItem *item){ //primeira inserção já tendo a lista criada
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

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, int id){ //insere em qualquer lugar
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
        Sleep(2000);
        return ;
    }
    Apontador aux;
    aux = lista.Primeiro->prox; //recebe o apontador de próximo, depois do pirmeiro
    while(aux != NULL){ //enquanto não for nulo, ele imprime
        cout << "Nome: " << aux->item.nome << "\t";
        cout << "ID: " << aux->item.chave << "\n";
        aux = aux->prox;//aux sendo 'incrementado'
    }
    Sleep(3000);
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
    x = lista->Primeiro; //guarda no x o primeiro lugar da lista
    while (x != NULL){
        if (x->prox->item.chave == id){ //quando for encontrado
            anterior = x; //anterior vai receber ele
            break;
        }
        x = x->prox; //incremento do while
    }
    aux = anterior->prox; //quando sair do while, o aux vai receber o último valor(último porque estou apontando para o próximo depois do antepenúltimo)
    anterior->prox = aux->prox; 
    delete aux; //deleta o auxiliar
    lista->tamanho--; //diminuindo a lista
}

//Questão 2
void Concatena(TipoLista *lista1, TipoLista *lista2, TipoLista *lista3){
    Apontador p;
    p = lista1->Primeiro->prox;
    while(p !=NULL){
        InsereListaUltimo(lista3, &p->item);
        p = p->prox;
    }
    p = lista2->Primeiro->prox;
    while(p !=NULL){
        InsereListaUltimo(lista3, &p->item);
        p = p->prox;
    }
}

//Questão 3
void ConcatenaAlternado(TipoLista *lista1, TipoLista *lista2, TipoLista *lista4){
    Apontador p1, p2;
    p1 = lista1->Primeiro->prox;
    p2 = lista2->Primeiro->prox;
    while(p1 !=NULL || p2!=NULL){
        InsereListaUltimo(lista4, &p1->item);
        InsereListaUltimo(lista4, &p2->item);
        p1 = p1->prox;
        p2 = p2->prox;
    }
}

//Questão 4
void InverteLista(TipoLista *lista){ //lista toda
    if(VerificaListaVazia(lista)){ //verifica se o endereço da lista é true
        cout << "Lista Vazia";
        Sleep(2000);
        return ;
    }
    TipoLista lista5;
    Apontador aux, ult;
    aux = lista->Primeiro->prox; //pri recebe a primeira posição
    while (aux != NULL){ //enquanto o primeiro for diferente do ultimo
        InsereListaPrimeiro(&lista5, &aux->item);
        aux = aux->prox; //irá percorrer a lista
    }
    ImprimeLista(lista5);
    Sleep(5000);
}