#include <iostream>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "lista.hpp"
 
using namespace std;

TipoLista listaEst;

void menu(){
    CriaListaVazia(&listaEst);
    cout << " *********************************************************************\n";
    cout << " **                                                                 **\n";
    cout << " *********************************************************************\n";
    cout << " **                                                                 **\n";
    cout << " **                       ESTACIONAMENTO                            **\n";
    cout << " **                                                                 **\n";
    cout << " *********************************************************************\n";
    cout << " **                                                                 **\n";
    cout << " **                  1. Incluir Carro no estacionamento             **\n";
    cout << " **                                                                 **\n";
    cout << " **                  2. Listar Carros do estacionamento             **\n";
    cout << " **                                                                 **\n";
    cout << " **                  3. Ver um carro especifico                     **\n";
    cout << " **                                                                 **\n";
    cout << " **                  4. Retirar carro do estacionamento             **\n";
    cout << " **                                                                 **\n";
    cout << " **                  5. Sair                                        **\n";
    cout << " **                                                                 **\n";
    cout << " *********************************************************************\n";
    cout << " **                                                                 **\n";
    cout << " *********************************************************************\n";
    cout << "\n\nOpção: ";
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
    Sleep(2500);//comando de espera em milisegundos
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

void InsereListaAposElemento(TipoLista *lista, TipoItem *item, char placa[7]){ //insere em qualquer lugar
    Apontador aux, pAux, x;
    bool find = false; //achou recebe false
    pAux = lista->Primeiro->prox; //o "ponteiro"
    while (pAux != NULL){// enquanto for diferente de null
        if (strcmp(pAux->item.placa, placa) == 0){ //quando a chave for igual ao valor digitado, a inserção será feita após ele
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
        cout << "Placa: " << aux->item.placa << endl;
        cout << "Data de inicio: " << aux->item.dataInicial << endl;
        cout << "Data de final: " << aux->item.dataFinal << endl;
        cout << "Preço: " << aux->item.precoCobrado;
        if(aux->item.situacao == 1) cout << "Situação: Carro no estacionamento"; 
        if(aux->item.situacao == 0) cout << "Situação: Carro não está no estacionamento"; 

        aux = aux->prox;//aux sendo 'incrementado'
    }
    Sleep(3000);
}

void ImprimeItem(TipoLista *lista, char placa[7]){ //elemento da lista
    Apontador aux;
    aux = lista->Primeiro->prox; //ele pega a variavel auxiliar e compara a chave dela, com a chave digitada
    while (aux != NULL){
        if (strcmp(aux->item.placa, placa) == 0){
            cout << "Placa: " << aux->item.placa << endl;
            cout << "Data de inicio: " << aux->item.dataInicial << endl;
            cout << "Data de final: " << aux->item.dataFinal << endl;
            cout << "Preço: " << aux->item.precoCobrado;
            if(aux->item.situacao == 1) cout << "Situação: Carro no estacionamento"; 
            if(aux->item.situacao == 0) cout << "Situação: Carro não está no estacionamento"; 
            break;
        }
        aux = aux->prox;
    }
}

bool PesquisaItemPorPlaca(TipoLista *lista, char placa[7]){
    Apontador aux;
    aux = lista->Primeiro->prox;
    while (aux != NULL){
        if (strcmp(aux->item.placa, placa) == 0){
            cout << aux->item.placa; //achou a chave
            return true;

        }
        aux = aux->prox;
        if(strcmp(aux->item.placa, placa) == -1){
            cout << "Placa não registrada!";
            return false;
        }
    }
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

void RemoveItemPorId(TipoLista *lista, char placa[7]){
    if (VerificaListaVazia(lista))  return; //verifica se o endereço da lista é true

    Apontador aux, anterior, x;
    x = lista->Primeiro; //guarda no x o primeiro lugar da lista
    while (x != NULL){
        if ((x->prox->item.placa, placa) == 0){ //quando for encontrado
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

void CalculaEstadia(time_t t1, time_t t2){
    if(difftime(t2, t1)/60 < 15 && difftime(t2, t1)/60 > 0){
        aux

    }
    if(difftime(t2, t1)/60 < 30 && difftime(t2, t1)/60 > 15){

    }
    if(difftime(t2, t1)/60 < 60 && difftime(t2, t1)/60 > 30){

    }
    if(difftime(t2, t1)/60 > 60){
    }
  0 a 15 minutos, ser´a cobrado 2,00.
15 a 30 minutos, ser´a cobrado 4,00.
30 a 60 minutos, ser´a cobrado 8,00.
Ap´os 1 hora, cada 10 minutos passados dentro do
estacionamento dever´a ser cobrado 0,10 centavos a mais. Ex.:
(1 hora de 10 minutos: 8,10).

}

void op1_IncluirCarro(){
    TipoItem itemCar;
    time_t t1 = time(NULL);
    cout << "Digite a placa do carro: ";
    cin >> itemCar.placa;
    itemCar.dataInicial = t1;
    itemCar.precoCobrado = 0.0;
    itemCar.situacao = 1;
    InsereListaUltimo(&listaEst, &itemCar);
}

void op2_ListarCarros(){
    ImprimeLista(listaEst);
}

void op3_imprimirCarro(){
    char placa[7];
    cout << "Digite a placa pesquisada: ";
    cin.getline(placa, 7);
    ImprimeItem(&listaEst, placa);
}

void op4_RetirarCarro(){
    char placa[7];
    cout << "Digite a placa pesquisada: ";
    cin.getline(placa, 7);
    if(PesquisaItemPorPlaca(&listaEst, placa)){
        Apontador aux;
        aux = listaEst.Primeiro;
        time_t t2 = time(NULL);
        aux->item.dataFinal = t2;
        CalculaEstadia(aux->item.dataFinal, aux->item.dataInicial);
        aux->item.situacao == 0;
    }
    
}



/*

typedef struct TipoItem{
    char placa[7];
    time_t dataInicial;
    time_t dataFinal;
    double precoCobrado;
    char situação;


    cout << " **                                                                 **\n";
    cout << " **                  2. Listar Carros do estacionamento             **\n";
    cout << " **                                                                 **\n";
    cout << " **                  3. Ver um carro especifico                     **\n";
    cout << " **                                                                 **\n";
    cout << " **                  4. Retirar carro do estacionamento             **\n";
    cout << " **                                                                 **\n";
    cout << " **                  5. Sair   
*/